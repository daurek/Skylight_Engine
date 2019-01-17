// Header file
#include "TransformComponent.hpp"

// Other libraries .h files
#include "Entity.hpp"

namespace skylight
{
	TransformComponent::TransformComponent(Transformation _transform) : transform(_transform)
	{

	}

	glm::mat4 & TransformComponent::get_transform()
	{
		if (updated) return transform;
		//auto parent_entity = entity->get_component("")
		/*if (parent_entity)
		{
			transform = parent_entity->get_transform_component()->get_transform() * local_tranform;
		}
		else*/
		//transform = local_transform;
		//reset = updated;
		return transform;
	}

	void TransformComponent::Update()
	{
		updated = false;
	}

	void TransformComponent::Move(glm::vec3 displacement)
	{
		get_transform() += glm::mat4{ 0,0,0,0,0,0,0,0,0,0,0,0,displacement.x,displacement.y,displacement.z,0 }; ;
	}
}
