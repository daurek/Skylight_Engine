// Header file
#include "Scene.hpp"

// Libraries .h files
#include "rapidxml_utils.hpp"
#include "SDL_log.h"
// Project .h files
#include "RenderModule.hpp"
#include "Kernel.hpp"
#include "Window.hpp"


namespace skylight
{

	Scene::Scene(const std::string & scene_content_xml, Window & given_window) : window(&given_window)
	{
		LoadScene(scene_content_xml);
		InitKernel();
	}

	void Scene::InitKernel()
	{
		for (auto module : modules)
		{
			Task * task = module.second->get_task();

			if (task)
			{
				Kernel::instance().Add(*task);
			}
		}
	}

	void Scene::LoadScene(const std::string & path)
	{
		SDL_Log("________Loading Scene________\n");

		// Load xml
		rapidxml::file<> xml_file(path.c_str());
		
		// Parse xml
		rapidxml::xml_document<> doc;
		doc.parse<0>(xml_file.data());

		// Load Entities
		LoadEntities(doc.first_node()->first_node());
		SDL_Log("\n	________Scene  Loaded________");

	}

	void Scene::LoadEntities(rapidxml::xml_node<>* entities)
	{
		SDL_Log("\n	________Loading Entities________");
		// Loop through every entity
		for (rapidxml::xml_node<>* entity_node = entities->first_node(); entity_node; entity_node = entity_node->next_sibling())
		{
			std::string entity_id = entity_node->first_attribute()->value();

			SDL_Log("\n		________Loading Entity________");
			std::string log_entity = "			" + entity_id;
			SDL_Log(log_entity.c_str());

			//for (? ? ? ) // para cada atributo de <entity>
			//{
			//	if (attribute->name() == "id") entity_id = attribute->value();
			//}

			// Check validity
			if (entity_id.empty()) continue;
			// Create the entity
			std::shared_ptr< Entity > entity(new Entity(entity_id));
			// Load it's components
			LoadComponents(entity_node, *entity);
			// Add it to the scene entities
			this->entities[entity_id] = entity;
		}
	}
	
	void Scene::LoadComponents(rapidxml::xml_node<>* components, Entity & entity)
	{
		Module::ModuleMap & factories = Module::get_module_map();

		for (rapidxml::xml_node<>* component_node = components->first_node(); component_node; component_node = component_node->next_sibling())
		{
			if (std::string(component_node->name()) == "component")
			{
				std::string component_name = component_node->first_attribute()->value();
				// CHECK VALIDITY
				
				std::shared_ptr<Module> module = nullptr;
				
				// Does that module not exist on our scene
				if (modules.count(component_name) == 0)
				{
					if (factories.size() != 0)
					{
						//SDL_Log("test");
					}
					
					// Does that factory exist
					if (factories.count(component_name) == 0)
					{
						// ERROR
					}
					else
					{
						SDL_Log("\n							[_______Created module_______]");
						std::string log_module = "								" + component_name;
						SDL_Log(log_module.c_str());
						SDL_Log("							[____________________________]");
						modules[component_name] = factories[component_name]->CreateModule(*this);
						module = modules[component_name];
					}
				}
				// If it exists then get it
				else
				{
					module = modules[component_name];
				}

				if (module)
				{
					entity.AddComponent(component_name, module->CreateComponent(*component_node));
				}

			}
			
		}
	}
}
