#pragma once

// System files
#include <list>

// Other libraries .h files
// This project .h files
#include "Module.hpp"
#include "Task.hpp"



namespace skylight
{
	class Scene;

	class ScriptModule : public Module
	{

	public:

		class ScriptModuleFactory : public ModuleFactory
		{

		public:

			ScriptModuleFactory()
			{
				Module::RegisterModule("script", this);
			}

			std::shared_ptr< Module > CreateModule(Scene & scene) override
			{
				return std::shared_ptr< Module >(new ScriptModule(scene));
			};
		};

		class ScriptTask : public Task
		{
			ScriptModule * module;

		public:

			ScriptTask() = default;
			ScriptTask(ScriptModule & _module) : module(&_module) {}

			void Run() override;
		

		};

	public: 

		static ScriptModuleFactory factory;
		ScriptTask task;
		std::list<std::shared_ptr< Component > > components;
		Scene * scene;
		ScriptModule(Scene & _scene);

	public:

		std::shared_ptr< Component > CreateComponent(const rapidxml::xml_node<> & node) override;
		Task * get_task() override { return &task; }

	};
}
