/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::CameraModule
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

	/// Module that creates every CameraComponent
	class CameraModule : public Module
	{

	public:

		/// Factory that creates the CameraModule
		class CameraModuleFactory : public ModuleFactory
		{

		public:

			/// Registers the CameraModule into the Module map
			CameraModuleFactory()
			{
				Module::RegisterModule("camera", this);
			}

			/// Creates the CameraModule into the given Scene
			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new CameraModule(scene));
			};
		};

		/// Task that updates the CameraComponents positions
		class CameraTask : public Task
		{

		public:

			/// Default constructor
			CameraTask() {}

			/// Creates a CameraTask with the given priority
			CameraTask(int priority, CameraModule & _module) : Task(priority), module(&_module) {}

			/// --- 
			void Run() override;

		private:

			/// Reference to the CameraModule
			CameraModule * module;
		};

		/// Creates a CameraModule and a CameraTask with a priority into the given Scene 
		CameraModule(Scene & _scene) : Module(_scene), task(CameraTask{ 4, *this }) {};

		/// Creates a CameraComponent with the given node and properties
		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		
		/// Returns the current CameraTask
		Task * get_task() override { return &task; }
		
		/// Static factory
		static CameraModuleFactory factory;

		/// List of every TransformComponent on the Scene
		std::list< std::shared_ptr< Component > > components;

	private:

		CameraTask task;

	};
}
