/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::LightModule
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

	/// Module that creates the LightComponent
	class LightModule : public Module
	{

	public:

		/// Factory that creates every LightModule
		class LightModuleFactory : public ModuleFactory
		{

		public:

			/// Registers the LightModule into the Module map
			LightModuleFactory()
			{
				Module::RegisterModule("light", this);
			}

			/// Creates the LightModule into the given Scene
			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new LightModule(scene));
			};
		};

		/// Task that updates the CameraComponents positions
		class LightTask : public Task
		{

		public:

			/// Default constructor
			LightTask() {}

			/// Creates a LightTask with the given priority
			LightTask(int priority, LightModule & _module) : Task(priority), module(&_module) {}

			/// ---
			void Run() override;

		private:

			/// Reference to the LightModule
			LightModule * module;
		};

		/// Creates a LightModule and a LightTask with a priority into the given Scene 
		LightModule(Scene & _scene) : Module(_scene), task(LightTask{ 5, *this }) {}

		/// Creates a LightComponent with the given node and properties
		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		
		/// Returns the current LightTask
		Task * get_task() override { return &task; }
		
		static LightModuleFactory factory;
		
		/// List of every LightComponent on the Scene
		std::list< std::shared_ptr< Component > > components;

	private:

		LightTask task;

	};
}
