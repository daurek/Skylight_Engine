#pragma once

// Other libraries .h files
#include "Render_Node.hpp"
// This project .h files
#include "Module.hpp"
#include "Task.hpp"


namespace skylight
{
	class Scene;

	class TransformModule : public Module
	{

	public:

		class TransformModuleFactory : public ModuleFactory
		{

		public:

			TransformModuleFactory()
			{
				Module::RegisterModule("transform", this);
			}

			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new TransformModule(scene));
			};
		};

		class TransformTask : public Task
		{
			TransformModule * module;

		public:

			TransformTask() = default;
			TransformTask(TransformModule & _module) : module(&_module) {}

			void Run() override;
		

		};

	public: 

		static TransformModuleFactory factory;
		TransformTask task;
		std::list<std::shared_ptr< Component > > components;
		Scene * scene;
		TransformModule(Scene & _scene);

	public:

		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		Task * get_task() override { return &task; }

	};
}
