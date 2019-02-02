/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::LightComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// Libraries
#include "Light.hpp"
// Project
#include "Component.hpp"

namespace skylight
{	

	/// Component that emits light
	class LightComponent : public Component
	{

	public:

		/// Creates a light with the given color values
		LightComponent(float r, float g, float b);

		/// Updates it's transform with the entity's transform
		void Update() override;

		/// Reference to the light object
		std::shared_ptr< glt::Light > light;

	};
}

