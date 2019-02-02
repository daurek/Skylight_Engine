/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::ScriptModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <list>

// Project
#include "Module.hpp"
#include "Task.hpp"

namespace skylight
{
	class Scene;

	/// Module that creates every ScriptComponent
	class ScriptModule : public Module
	{

	public:

		/// Factory that creates the ScriptModule
		class ScriptModuleFactory : public ModuleFactory
		{

		public:

			/// Registers the ScriptModule into the Module map
			ScriptModuleFactory()
			{
				Module::RegisterModule("script", this);
			}

			/// Creates the ScriptModule into the given Scene
			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new ScriptModule(scene));
			};
		};

		/// Task that updates every ScriptComponent behaviour
		class ScriptTask : public Task
		{

		public:

			/// Default constructor
			ScriptTask() {}

			/// Creates a ScriptTask with the given priority
			ScriptTask(int priority, ScriptModule & _module) : Task(priority), module(&_module) {}

			/// ---
			void Run() override;
		
		private:

			/// Reference to the ScriptModule
			ScriptModule * module;

		};

	public: 

		/// Creates a ScriptModule and a ScriptTask with a priority into the given Scene 
		ScriptModule(Scene & _scene) : Module(_scene), task(ScriptTask{ 2, *this }) {};

		/// Creates a ScriptComponent with the given node and properties
		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		
		/// Returns the current ScriptTask
		Task * get_task() override { return &task; }

		/// Static factory
		static ScriptModuleFactory factory;

		/// List of every ScriptComponent on the Scene
		std::list<std::shared_ptr< Component > > components;

	private:

		ScriptTask task;

	};
}
