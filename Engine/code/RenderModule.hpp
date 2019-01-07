#pragma once

// Other libraries .h files
#include "SDL.h"
#include "Render_Node.hpp"
// This project .h files
#include "ComponentFactory.hpp"
#include "Window.hpp"
#include "Task.hpp"

namespace engine
{
	class RenderModule : public ComponentFactory
	{
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

		glt::Render_Node graphics_scene;
		Window    * window;
		RenderTask task;

	public:

		RenderModule(Window * _window);

	public:

		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node);
		Task * get_task() { return &task; }

	};
}
