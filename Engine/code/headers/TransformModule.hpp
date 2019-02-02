/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::TransformModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// Libraries
#include "Render_Node.hpp"
// Project
#include "Module.hpp"
#include "Task.hpp"

namespace skylight
{
	class Scene;

	/// Module that creates every TransformComponent
	class TransformModule : public Module
	{

	public:

		/// Factory that creates the TransformModule
		class TransformModuleFactory : public ModuleFactory
		{

		public:

			/// Registers the TransformModule into the Module map
			TransformModuleFactory()
			{
				Module::RegisterModule("transform", this);
			}

			/// Creates the TransformModule into the given Scene
			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new TransformModule(scene));
			};
		};

		/// ---
		class TransformTask : public Task
		{

		public:

			/// Default Constructor
			TransformTask() {}

			/// Creates a TransformTask with the given priority
			TransformTask(int priority, TransformModule & _module) : Task(priority), module(&_module) {}

			/// ---
			void Run() override;

		private:

			/// Reference to the TransformModule
			TransformModule * module;
		};

		/// Creates a TransformModule and a TransformTask with a priority into the given Scene 
		TransformModule(Scene & _scene) : Module(_scene), task(TransformTask{ 2, *this }) {}

		/// Creates a TransformComponent with the given node and properties
		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;

		/// Returns the current TransformTask
		Task * get_task() override { return &task; }

		/// Static factory
		static TransformModuleFactory factory;

		/// List of every TransformComponent on the Scene
		std::list< std::shared_ptr< Component > > components;

	private:

		TransformTask task;
	};
}
