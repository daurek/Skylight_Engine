#pragma once

// System files

// Libraries .h files
// Project .h files
#include "Component.hpp"

namespace skylight
{	
	class ScriptComponent : public Component
	{

	public:

		ScriptComponent() = default;

		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}

