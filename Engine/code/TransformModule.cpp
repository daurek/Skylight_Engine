// Header file
#include "TransformModule.hpp"

// System files
#include <memory>

// Libraries .h files
#include "TransformComponent.hpp"
// Project .h files
#include "Scene.hpp"

#include "SDL_log.h"

namespace skylight
{

	TransformModule::TransformModuleFactory TransformModule::factory;

	TransformModule::TransformModule(Scene & _scene) : scene (&_scene)
	{
		task = TransformTask{ *this };
	}

	std::shared_ptr< Component > TransformModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		// Get the obj path
		std::string position = node.first_node()->value();
		glt::Matrix44 transform{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

		SDL_Log("			Component __ Tranform");
		std::string log_component = "				Position: " + position;
		SDL_Log(log_component.c_str());
		// Create component with that path
		std::shared_ptr< TransformComponent > transformComponent(new TransformComponent(transform));
		
		return transformComponent;
	}
	
	void TransformModule::TransformTask::Run()
	{
		
	}

}
