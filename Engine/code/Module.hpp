#pragma once

// System files
#include <map>
#include <memory>

// Libraries .h files
#include "rapidxml.hpp"
// Project .h files
#include "Component.hpp"
#include "Task.hpp"

namespace engine
{
	class Module
	{
	public:

		class ModuleFactory
		{
		public:

			virtual std::shared_ptr< Module > CreateModule() = 0;
		};

		typedef std::map< std::string, ModuleFactory * > ModuleMap;

	private:


		static ModuleMap module_factories;

	public:

		Module() = default;

		virtual ~Module() {};

		virtual std::shared_ptr<Component> CreateComponent(const rapidxml::xml_node<>& node) = 0;

		static ModuleMap & get_module_map(){ return module_factories; }

		static void RegisterModule(std::string id, ModuleFactory * factory) { module_factories[id] = factory; }
		
		virtual Task * get_task() { return nullptr; }
	};

}

