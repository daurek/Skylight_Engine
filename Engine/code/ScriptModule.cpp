// Header file
#include "ScriptModule.hpp"

// System files

// Libraries .h files
#include "SDL_log.h"
// Project .h files
#include "ScriptComponent.hpp"


namespace skylight
{

	ScriptModule::ScriptModuleFactory ScriptModule::factory;

	ScriptModule::ScriptModule(Scene & _scene) : scene (&_scene)
	{
		task = ScriptTask{ *this };
	}

	std::shared_ptr< Component > ScriptModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		std::shared_ptr< ScriptComponent > scriptComponent;
		
		components.push_back(scriptComponent);
		return scriptComponent;
	}
	
	void ScriptModule::ScriptTask::Run()
	{
		for (auto component : module->components)
		{
			component->Update();
		}
	}

}
