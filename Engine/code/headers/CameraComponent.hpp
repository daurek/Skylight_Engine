/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::CameraComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// Libraries
#include "Camera.hpp"
// Project
#include "Component.hpp"

namespace skylight
{	
	
	/// Component that displays with a camera
	class CameraComponent : public Component
	{

	public:
				
		/// Creates a camera with the given properties
		CameraComponent(float fov, float near, float far, float aspect_ratio) : camera(std::make_shared<glt::Camera>(fov, near, far, aspect_ratio)) {}

		/// Updates it's transform with the entity's transform
		void Update() override;

		/// Reference to the camera object
		std::shared_ptr< glt::Camera > camera;
	};
}

