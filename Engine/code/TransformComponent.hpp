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
		typedef glt::Matrix44 Transformation;

		Transformation transformation;
		TransformComponent() {};
		TransformComponent(Transformation _transformation);

	public:

	};
}

