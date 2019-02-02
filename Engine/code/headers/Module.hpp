/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Module
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System 
#include <map>
#include <memory>

// Libraries
#include "rapidxml.hpp"
// Project
#include "Component.hpp"
#include "Task.hpp"

namespace skylight
{
	class Scene;

	/// Base class for every Module
	class Module
	{
	public:

		/// Base class for every ModuleFactory
		class ModuleFactory
		{

		public:

			/// Base method to create a module into the given scene
			virtual std::shared_ptr< Module > CreateModule(Scene & scene) = 0;
		};

		/// Map with a string attached to a module factory
		typedef std::map< std::string, ModuleFactory * > ModuleMap;

	public:

		/// Creates a Module into the given Scene
		Module(Scene & _scene): scene(&_scene) {};

		virtual ~Module() {};

		/// Base method to create a component with the given xml node
		virtual std::shared_ptr<Component> CreateComponent(const rapidxml::xml_node<>& node) = 0;

		/// Returns the factories map
		static ModuleMap & get_module_map(){ return module_factories; }

		/// Registers the given factory and it's id into the map
		static void RegisterModule(std::string id, ModuleFactory * factory) { module_factories[id] = factory; }
		
		/// Return the module's task
		virtual Task * get_task() { return nullptr; }

		/// Scene Reference
		Scene * scene;

	private:

		/// Map of every registered module factory
		static ModuleMap module_factories;

	};

}

