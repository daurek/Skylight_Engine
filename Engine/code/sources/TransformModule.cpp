/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::TransformModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "TransformModule.hpp"

// System
#include <memory>

// Libraries
#include "TransformComponent.hpp"
#include "SDL_log.h"
// Project
#include "Scene.hpp"


namespace skylight
{
	TransformModule::TransformModuleFactory TransformModule::factory;

	std::shared_ptr< Component > TransformModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		// Get position
		rapidxml::xml_node<> * position_node = node.first_node("position");
		// Position string values
		std::string x_pos_str = position_node->first_node("x")->value();
		std::string y_pos_str = position_node->first_node("y")->value();
		std::string z_pos_str = position_node->first_node("z")->value();
		// Position float values
		float x_pos = std::stof(x_pos_str);
		float y_pos = std::stof(y_pos_str);
		float z_pos = std::stof(z_pos_str);

		// Get Rotation
		rapidxml::xml_node<> * rotation_node = node.first_node("rotation");
		// Rotation string values
		std::string x_rot_str = rotation_node->first_node("x")->value();
		std::string y_rot_str = rotation_node->first_node("y")->value();
		std::string z_rot_str = rotation_node->first_node("z")->value();
		// Rotation float values
		float x_rot = std::stof(x_rot_str);
		float y_rot = std::stof(y_rot_str);
		float z_rot = std::stof(z_rot_str);

		// Get Scale
		rapidxml::xml_node<> * scale_node = node.first_node("scale");
		// Scale string values
		std::string x_scale_str = scale_node->first_node("x")->value();
		std::string y_scale_str = scale_node->first_node("y")->value();
		std::string z_scale_str = scale_node->first_node("z")->value();
		// Scale float values
		float x_scale = std::stof(x_scale_str);
		float y_scale = std::stof(y_scale_str);
		float z_scale = std::stof(z_scale_str);

		// Transform logging
		SDL_Log("			Component __ Transform");
		// Position logging
		std::string log_position =	"				Position:	x = " + x_pos_str	+	"| y = " + y_pos_str	+	"| z = " + z_rot_str;
		SDL_Log(log_position.c_str());
		// Rotation logging
		std::string log_rotation =  "				Rotation:	x = " + x_rot_str	+	"| y = " + y_rot_str	+	"| z = " + z_rot_str;
		SDL_Log(log_rotation.c_str());
		// Scale logging
		std::string log_scale =		"				Scale:		x = " + x_scale_str +	"| y = " + y_scale_str	+	"| z = " + z_scale_str;
		SDL_Log(log_scale.c_str());

		glm::mat4 transform
		{
			x_scale		,		0.f,	0.f		,		   0.f,
			0.f			, y_scale	,	0.f		,		   0.f,
			0.f			,		0.f	,	z_scale	,		   0.f,
			x_pos		, y_pos		,	z_pos	,		   1.f
		};
		transform = glm::rotate(transform, glm::radians(x_rot), { 1,0,0 });
		transform = glm::rotate(transform, glm::radians(y_rot), { 0,1,0 });
		transform = glm::rotate(transform, glm::radians(z_rot), { 0,0,1 });

		// Create component with the data
		std::shared_ptr< TransformComponent > transformComponent(new TransformComponent(transform));
		
		components.push_back(transformComponent);
		return transformComponent;
	}
	
	void TransformModule::TransformTask::Run()
	{
		for (auto component : module->components)
		{
			component->Update();
		}
	}

}
