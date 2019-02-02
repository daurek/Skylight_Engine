/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Scene
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <map>

// Libraries
#include "Render_Node.hpp"
#include "rapidxml.hpp"
// Project
#include "Entity.hpp"
#include "Module.hpp"
#include "Window.hpp"
#include "MessageHandler.hpp"

namespace skylight
{
	class Window;

	/// Game Scene with every Entity and Module
	class Scene : public Listener
	{



	public:

		/// Creates a Scene with the given xml 
		Scene(const std::string & scene_content_xml, Window & given_window);

		/// Window Reference
		Window * window;

		/// Graphics scene where every Render is connected (CameraComponent, LightComponent, RenderComponent)
		glt::Render_Node graphics_scene;

	private:

		/// Initializes the Kernel by adding every Task from the Module map to the Task list
		void InitKernel();

		/// Loads the given xml file path to create a Scene
		void LoadScene(const std::string & file);
		
		/// Loads Scene Entities with the given entities node
		void LoadEntities(rapidxml::xml_node<> * entities);

		/// Loads the given Scene Components with the given components node into the given Entity
		void LoadComponents(rapidxml::xml_node<> * components, Entity & entity);

		/// Initializes Scene members
		virtual void InitializeScene() = 0;

		/// Handles messaging to the Scene
		virtual void Handle(const Message & message) = 0;

	protected:

		/// Map of every Module in the Scene
		std::map< std::string, std::shared_ptr< Module >> modules;

		/// Map of every Entity in the Scene
		std::map< std::string, std::shared_ptr< Entity >> entities;		

		/// Scene root
		Entity     root;
	};
}