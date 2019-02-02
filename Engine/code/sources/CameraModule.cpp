/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::CameraModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "CameraModule.hpp"

// System
#include <memory>

// Libraries
#include "SDL.h"
// Project
#include "CameraComponent.hpp" 
#include "Scene.hpp"

namespace skylight
{

	CameraModule::CameraModuleFactory CameraModule::factory;

	std::shared_ptr< Component > CameraModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		// Get Camera strings
		std::string camera_name = node.first_node("camera_name")->value();
		std::string fov_string = node.first_node("fov")->value();
		std::string near_string = node.first_node("near")->value();
		std::string far_string = node.first_node("far")->value();
		std::string aspect_ratio_string = node.first_node("aspect_ratio")->value();
		// Parse to float
		float fov = std::stof(fov_string);
		float near = std::stof(near_string);
		float far = std::stof(far_string);
		float aspect_ratio = std::stof(aspect_ratio_string);

		// Camera logging
		SDL_Log("			Component __ Camera");
		std::string name_log =	"				Name: " + camera_name;
		std::string fov_log = "				fov: " + fov_string;
		std::string near_log = "				near: " + near_string;
		std::string far_log = "				far: " + far_string;
		std::string aspect_ratio_log = "				aspect ratio: " + aspect_ratio_string;

		SDL_Log(name_log.c_str());
		SDL_Log(fov_log.c_str());
		SDL_Log(near_log.c_str());
		SDL_Log(far_log.c_str());
		SDL_Log(aspect_ratio_log.c_str());

		// Create component with the data
		std::shared_ptr< CameraComponent > cameraComponent(new CameraComponent(fov, near, far, aspect_ratio));
		// Add to the graphic scene
		scene->graphics_scene.add(camera_name, cameraComponent->camera);

		components.push_back(cameraComponent);
		return cameraComponent;
	}
	
	void CameraModule::CameraTask::Run()
	{
		// Update every camera component
		for (auto component : module->components)
		{
			component->Update();
		}
	}

}
