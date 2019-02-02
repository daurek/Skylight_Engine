/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Scene
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "Scene.hpp"

// Libraries
#include "rapidxml_utils.hpp"
#include "SDL_log.h"
// Project
#include "Kernel.hpp"
#include "Window.hpp"
#include "InputTask.hpp"
#include "RenderModule.hpp"
#include "TransformModule.hpp"
#include "AudioModule.hpp"
#include "CameraModule.hpp"
#include "LightModule.hpp"

namespace skylight
{

	Scene::Scene(const std::string & scene_content_xml, Window & given_window) : window(&given_window)//, InputTask(1)
	{
		LoadScene(scene_content_xml);
		InitKernel();

		// Logging Scene
		SDL_Log("Logging Scene | All Entities and their children");
		entities["player"]->AddChild(entities["bunny"]);
		for (auto it = entities.cbegin(); it != entities.cend(); ++it)
		{
			SDL_Log(it->first.c_str());

			auto entity_children = it->second->get_children();

			for (auto child = entity_children.cbegin(); child != entity_children.cend(); ++child)
			{
				SDL_Log(std::string("  " + child->first).c_str());
			}
		}
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
		SDL_Log("\n________Loading Scene________\n");

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
			//entity->parent = &root;
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
				
				std::shared_ptr<Module> module = nullptr;
				
				// Creating factories since static objects do not get created in libs
				if (factories.count(component_name) == 0)
				{
					if (component_name == "render3d")
						factories[component_name] = &RenderModule::factory;
					else if (component_name == "transform")
						factories[component_name] = &TransformModule::factory;
					else if (component_name == "audio")
						factories[component_name] = &AudioModule::factory;
					else if (component_name == "camera")
						factories[component_name] = &CameraModule::factory;
					else if (component_name == "light")
						factories[component_name] = &LightModule::factory;
				}

				// Does that module not exist on our scene
				if (modules.count(component_name) == 0)
				{
					modules[component_name] = factories[component_name]->CreateModule(*this);
					module = modules[component_name];
					SDL_Log("\n							[_______Created module_______]");
					std::string log_module = "								" + component_name;
					SDL_Log(log_module.c_str());
					SDL_Log("							[____________________________]");
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
