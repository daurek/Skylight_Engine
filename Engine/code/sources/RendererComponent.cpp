/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::RendererComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "RendererComponent.hpp"

// Libraries
#include "Model_Obj.hpp"
// Project
#include "Entity.hpp"

namespace skylight
{
	RendererComponent::RendererComponent(const std::string & path)
	{
		// Loads the obj
		model.reset(new glt::Model_Obj(path));
	}

	void RendererComponent::Update()
	{
		// Updating transform
		model->set_transformation(entity->transform->get_transform());
	}
}
