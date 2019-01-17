#pragma once

// System files

// Libraries .h files
#include "Math.hpp"
// Project .h files
#include "Component.hpp"

namespace skylight
{	
	class TransformComponent : public Component
	{

	public:
		typedef glm::mat4 Transformation;
		bool updated;
		Transformation local_transform;
		Transformation transform;
		TransformComponent() {};
		TransformComponent(Transformation _transformation);

	public:

		glm::mat4 & get_transform();
		void Update() override;
		void Move(glm::vec3 displacement);
	};
}

