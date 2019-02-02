/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::CameraComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "CameraComponent.hpp" 

// Project
#include "TransformComponent.hpp"
#include "Entity.hpp"

namespace skylight
{
	void CameraComponent::Update()
	{
		// Updating transform
		camera->set_transformation(entity->transform->get_transform());
	}
}
