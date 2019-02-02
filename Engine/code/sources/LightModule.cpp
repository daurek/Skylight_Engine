/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::LightModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "LightModule.hpp"

// System
#include <memory>
#include <string>

// Libraries
#include "SDL.h"
// Project
#include "LightComponent.hpp" 
#include "Scene.hpp"


namespace skylight
{
	LightModule::LightModuleFactory LightModule::factory;

	std::shared_ptr< Component > LightModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		// Get Light strings
		std::string light_name = node.first_node("camera_name")->value();
		std::string red_string = node.first_node("red")->value();
		std::string green_string = node.first_node("green")->value();
		std::string blue_string = node.first_node("blue")->value();
		// Parse to float
		float red = std::stof(red_string);
		float green = std::stof(green_string);
		float blue = std::stof(blue_string);

		// Camera logging
		SDL_Log("			Component __ Light");
		std::string name_log =	"				Name: " + light_name;
		std::string fov_log = "				red: " + red_string;
		std::string near_log = "				green: " + green_string;
		std::string far_log = "				blue: " + blue_string;

		SDL_Log(name_log.c_str());
		SDL_Log(red_string.c_str());
		SDL_Log(green_string.c_str());
		SDL_Log(blue_string.c_str());

		// Create component with the data
		std::shared_ptr< LightComponent > lightComponent(new LightComponent(red, green, blue));
		// Add light to the graphics scene
		scene->graphics_scene.add(light_name, lightComponent->light);

		components.push_back(lightComponent);
		return lightComponent;
	}
	
	void LightModule::LightTask::Run()
	{
		// Update Light components
		for (auto component : module->components)
		{
			component->Update();
		}
	}

}
