/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::RenderModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <list>
#include <memory>

// Project
#include "Module.hpp"
#include "Task.hpp"

namespace skylight
{
	class Scene;

	/// Module that creates every RendererComponent
	class RenderModule : public Module
	{

	public:

		/// Factory that creates the RenderModule
		class RenderModuleFactory : public ModuleFactory
		{

		public:

			/// Registers the RenderModule into the Module map
			RenderModuleFactory()
			{
				Module::RegisterModule("render3d", this);
			}

			/// Creates the RenderModule into the given Scene
			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new RenderModule(scene));
			};
		};

		/// Task that renders the graphics scene into the Window
		class RenderTask : public Task
		{

		public:
				
			/// Default Constructor
			RenderTask() {}

			/// Creates a RenderTask with the given priority
			RenderTask(int priority, RenderModule & _module) : Task(priority), module(&_module) {}

			/// ---
			void Run() override;

		private:

			/// Reference to the RenderModule
			RenderModule * module;
		};

		/// Creates a RenderModule and a RenderTask with a priority into the given Scene 
		RenderModule(Scene & _scene) : Module(_scene), task(RenderTask{ 7, *this }) {}

		/// Creates a RenderComponent with the given node and properties
		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;

		/// Returns the current RenderTask
		Task * get_task() override { return &task; }
	
		/// Static factory
		static RenderModuleFactory factory;

		/// List of every RenderComponent on the Scene
		std::list<std::shared_ptr< Component > > components;

	private:

		RenderTask task;

	};
}
