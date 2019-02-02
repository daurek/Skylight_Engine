/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::ScriptModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "ScriptModule.hpp"

// Project
#include "ScriptComponent.hpp"

namespace skylight
{
	ScriptModule::ScriptModuleFactory ScriptModule::factory;

	std::shared_ptr< Component > ScriptModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		std::shared_ptr< ScriptComponent > scriptComponent;
		
		components.push_back(scriptComponent);
		return scriptComponent;
	}
	
	void ScriptModule::ScriptTask::Run()
	{
		// Update every script
		for (auto component : module->components)
		{
			component->Update();
		}
	}

}
