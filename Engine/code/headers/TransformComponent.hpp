/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::TransformComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// Libraries
#include "Math.hpp"
// Project
#include "Component.hpp"

namespace skylight
{	
	/// Component that is present on every Entity as Position, Scale and Rotation
	class TransformComponent : public Component
	{

		typedef glm::mat4 Transformation;

	public:

		TransformComponent() {};

		/// Creates a node with the given matrix
		TransformComponent(Transformation _transformation);

		/// --
		void Update() override;

		/// Translates the entity with the given displacement
		void Move(glm::vec3 displacement);

		/// Rotates the entity with the given angle and axis
		void Rotate(float angle,glm::vec3 axis);

		glm::vec3 get_position();

		void set_position(glm::vec3 position);

		/// Returns the current transformation
		glm::mat4 & get_transform();

	private:

		bool updated;

		/// Global Transformation matrix
		Transformation transform;

		/// Local Transformation matrix
		Transformation local_transform;
	};
}

