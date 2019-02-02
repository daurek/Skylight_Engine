/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::AudioModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System 
#include <list>

// Libraries
#include "SDL.h"
// Project
#include "Module.hpp"
#include "Task.hpp"

namespace skylight
{
	class Scene;

	/// Module that creates every AudioComponent
	class AudioModule : public Module
	{

	public:

		/// Factory that creates the AudioModule
		class AudioModuleFactory : public ModuleFactory
		{

		public:

			/// Registers the AudioModule into the Module map
			AudioModuleFactory()
			{
				Module::RegisterModule("audio", this);
				SDL_Init(SDL_INIT_AUDIO);
			}

			/// Creates the AudioModule into the given Scene
			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new AudioModule(scene));
			};
		};

		/// ---
		class AudioTask : public Task
		{

		public:

			/// Default constructor
			AudioTask() {}

			/// Creates a AudioTask with the given priority
			AudioTask(int priority, AudioModule & _module) : Task(priority), module(&_module) {}

			/// ---
			void Run() override;

		private:

			/// Reference to the AudioModule
			AudioModule * module;
		};

		/// Creates a AudioModule and a AudioTask with a priority into the given Scene 
		AudioModule(Scene & _scene) : Module(_scene), task(AudioTask{ 3, *this }) {};

		/// Creates a AudioComponent with the given node and properties
		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		
		/// Returns the current AudioTask
		Task * get_task() override { return &task; }

		static AudioModuleFactory factory;

		/// List of every AudioComponent on the Scene
		std::list< std::shared_ptr< Component > > components;

	private:

		AudioTask task;

	};
}
