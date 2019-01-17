// Header file
#include "TransformModule.hpp"

// System files
#include <memory>
#include <string>

// Libraries .h files
#include "TransformComponent.hpp"
#include "SDL_log.h"
// Project .h files
#include "Scene.hpp"


namespace skylight
{

	TransformModule::TransformModuleFactory TransformModule::factory;

	TransformModule::TransformModule(Scene & _scene) : scene (&_scene)
	{
		task = TransformTask{ *this };
	}

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

		// Create component with that path
		/*std::shared_ptr< TransformComponent > transformComponent(new TransformComponent(
			{ 
				x_scale			,		0 				,  0			,		   0,
				0				,		 y_scale		,			   0,		   0,
				0				,			   0		,		 z_scale,		   0,
				x_pos			,				   y_pos,		   z_pos,		   1
			}*/

		std::shared_ptr< TransformComponent > transformComponent(new TransformComponent(
		{
			x_scale	*(cosf(z_rot) * cosf(y_rot) + sinf(z_rot) * sinf(x_rot) * sinf(y_rot))		,		-sinf(z_rot) * cosf(x_rot) 				,		sinf(z_rot) * sinf(x_rot) * cosf(y_rot) - cosf(z_rot) * sinf(z_rot)		,		   0,
			sinf(z_rot) * cosf(y_rot) - cosf(z_rot) * sinf(x_rot) * sinf(y_rot)					,		 y_scale * (cosf(z_rot) * cosf(x_rot))	,		-cosf(z_rot) * sinf(x_rot) * cosf(y_rot) - sinf(z_rot) * sinf(y_rot)	,		   0,
			cosf(x_rot) * sinf(y_rot)															,		sinf(x_rot)								,		z_scale * (cosf(x_rot) * cosf(y_rot))									,		   0,
			x_pos																				,		y_pos									,		z_pos																	,		   1
		}
			// Rotation matrix 4x4
			// cosf(z) * cosf(y) + sinf(z) * sinf(x) * sinf(y)     sinf(z) * cosf(y) - cosf(z) * sinf(x) * sinf(y)				cosf(x) * sin(y)
			// -sinf(z) * cosf(x)									cosf(z) * cosf(x)											sinf(x)
			// sinf(z) * sinf(x) * cosf(y) - cosf(z) * sinf(z)		-cosf(z) * sinf(x) * cosf(y) - sinf(z) * sinf(y)			cosf(x) * cosf(y)
			// 0
		));
		
		components.push_back(transformComponent);
		return transformComponent;
	}
	
	void TransformModule::TransformTask::Run()
	{
		for (auto component : module->components)
		{
			auto transform = std::dynamic_pointer_cast<TransformComponent >(component);
			transform->Move({ 0.0001f,-0.0001f,0.0001f });
			
			//std::dynamic_pointer_cast<std::shared_ptr< TransformComponent >>()
			/*dynamic_cast<std::shared_ptr< TransformComponent >>(component)
				stD::*/
			//component->Move({ 0,0,0,0 });
			//component->
			//component->mo
		}
	}

}
