/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::ScriptComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// Project
#include "Component.hpp"

namespace skylight
{	
	/// Component that loads and plays audio files
	class ScriptComponent : public Component
	{

	public:

		/// ---
		ScriptComponent() = default;

		/// ---
		virtual void Start() = 0;

		/// ---
		virtual void Update() = 0;
	};
}

