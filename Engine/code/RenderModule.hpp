#pragma once

// Other libraries .h files
#include "SDL.h"
#include "Render_Node.hpp"
// This project .h files
#include "Module.hpp"
#include "Window.hpp"
#include "Task.hpp"

namespace engine
{
	class RenderModule : public Module
	{
		class RenderModuleFactory : public ModuleFactory
		{
		public:
			RenderModuleFactory()
			{
				Module::RegisterModule("render3d", this);
			}

			std::shared_ptr< Module > CreateModule() override
			{
				return std::shared_ptr< Module >(new RenderModule);
			};
		};

		class RenderTask : public Task
		{
			RenderModule * module;

		public:

			RenderTask() = default;
			RenderTask(RenderModule & _module) : module(&_module) {}

			void Run() override
			{
				module->graphics_scene.render();
				module->window->Display();
			}

		};

	public: 
		static RenderModuleFactory factory;
		glt::Render_Node graphics_scene;
		Window    * window;
		RenderTask task;


	//public:

		//RenderModule(Window * _window);

	public:

		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		Task * get_task() override { return &task; }

	};
}
