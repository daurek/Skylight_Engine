/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::LightComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "LightComponent.hpp" 

// Project
#include "Entity.hpp"

namespace skylight
{
	LightComponent::LightComponent(float r, float g, float b)
	{
		// Create a light and set the given color
		light = std::make_shared<glt::Light> ();
		light->set_color({ r, g, b });
	}

	void LightComponent::Update()
	{
		// Updating transform
		light->set_transformation(entity->transform->get_transform());
	}
}
