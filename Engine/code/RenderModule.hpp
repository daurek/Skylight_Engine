#pragma once

// Other libraries .h files
#include "Render_Node.hpp"
// This project .h files
#include "Module.hpp"
#include "Task.hpp"


namespace skylight
{
	class Scene;

	class RenderModule : public Module
	{
	public:
		class RenderModuleFactory : public ModuleFactory
		{
		public:
			RenderModuleFactory()
			{
				Module::RegisterModule("render3d", this);
			}

			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new RenderModule(scene));
			};
		};

		class RenderTask : public Task
		{
			RenderModule * module;

		public:

			RenderTask() = default;
			RenderTask(RenderModule & _module) : module(&_module) {}

			void Run() override;
		

		};

	public: 

		static RenderModuleFactory factory;
		glt::Render_Node graphics_scene;
		std::list<std::shared_ptr< Component > > components;
		RenderTask task;
		Scene * scene;
		RenderModule(Scene & _scene);

	public:

		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		Task * get_task() override { return &task; }

	};
}
