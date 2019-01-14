#pragma once

// System files
#include <map>

// Libraries .h files
#include "rapidxml.hpp"
// Project .h files
#include "Entity.hpp"
#include "Module.hpp"
#include "Window.hpp"

namespace engine
{
	class Window;

	class Scene
	{
		std::map< std::string, std::shared_ptr< Module >> modules;
		std::map< std::string, std::shared_ptr< Entity >> entities;		

	public:
		Scene(const std::string & scene_content_xml, Window & given_window);
		Window * window;
	private:

		void InitKernel();
		void LoadScene(const std::string & file);
		void LoadEntities(rapidxml::xml_node<> * entities);
		void LoadComponents(rapidxml::xml_node<> * components, Entity & entity);
	};
}