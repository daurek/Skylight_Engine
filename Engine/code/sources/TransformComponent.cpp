/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::TransformComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "TransformComponent.hpp"

// Libraries
#include "Entity.hpp"
#include "SDL_log.h"
#include <string>

namespace skylight
{
	TransformComponent::TransformComponent(Transformation _transform) : transform(_transform), local_transform(_transform)
	{
		//updated = true;
	}

	glm::mat4 & TransformComponent::get_transform()
	{
		if (updated) return transform;
		
		auto parent_entity = entity->parent;

		if (parent_entity)
		{
			//SDL_Log(std::to_string(entity->transform->get_position().x).c_str());


			//transform = parent_entity->transform->get_transform() *local_transform;
		}
		else
		{
		//	SDL_Log("no kid");
			//transform = local_transform;
		}

		//Transformation rotated = glm::translate(;
		//Transformation TR = glm::translate(, T->Position);
		//reset = updated;
		//transform *= result;
		return transform;
	}

	void TransformComponent::Update()
	{
		updated = false;
	}

	void TransformComponent::Move(glm::vec3 displacement)
	{
		transform = glm::translate(transform, displacement);
	}

	void TransformComponent::Rotate(float angle, glm::vec3 axis)
	{
		transform = glm::rotate(transform, glm::radians(angle), axis);
	}

	glm::vec3 TransformComponent::get_position()
	{
		return glm::vec3({ transform[3].x,transform[3].y,transform[3].z });
	}

	void TransformComponent::set_position(glm::vec3 position)
	{
		transform[3] = { position.x,position.y,position.z, 1 };
	}

}
