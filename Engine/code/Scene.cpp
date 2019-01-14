// Header file
#include "Scene.hpp"

// Libraries .h files
#include "rapidxml_utils.hpp"
#include "SDL.h"
// Project .h files
#include "RenderModule.hpp"
#include "Kernel.hpp"

#include <iostream>

namespace engine
{

	Scene::Scene(const std::string & scene_content_xml)
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
		// Load xml
		const char *char_path = path.c_str();
		rapidxml::file<> xml_file(char_path);
		
		// Parse xml
		rapidxml::xml_document<> doc;
		doc.parse<0>(xml_file.data());

		// Load Entities
		LoadEntities(doc.first_node()->first_node());
	}

	void Scene::LoadEntities(rapidxml::xml_node<>* entities)
	{
		// Loop through every entity
		for (rapidxml::xml_node<>* entity_node = entities->first_node(); entity_node; entity_node = entity_node->next_sibling())
		{
			std::string entity_id = entity_node->first_attribute()->value();

			//for (? ? ? ) // para cada atributo de <entity>
			//{
			//	if (attribute->name() == "id") entity_id = attribute->value();
			//}

			// Check validity
			if (entity_id.empty()) continue;
			// Create the entity
			std::shared_ptr< Entity > entity(new Entity);
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
				std::string componentName = component_node->first_attribute()->value();
				// CHECK VALIDITY
				
				std::shared_ptr<Module> module = nullptr;
				
				// Does that module exist on our scene
				if (modules.count(componentName) == 0)
				{
					if (factories.size() != 0)
					{
						SDL_Log("allo");
					}
					
					// Does that factory exist
					if (factories.count(componentName) == 0)
					{
						
						if (componentName == "render3d")
						{
							
							factories[componentName] = &RenderModule::RenderModuleFactory{};
							modules[componentName] = factories[componentName]->CreateModule();
							module = modules[componentName];
						}
						
					}
					else
					{
						modules[componentName] = factories[componentName]->CreateModule();
						module = modules[componentName];
					}
				}
				else
				{
					module = modules[componentName];
				}

				if (module)
				{
					module->CreateComponent(*component_node);
					SDL_Log("Component Created");
				}

			}
			
		}
	}
}
