// Header file
#include "RendererComponent.hpp"

// Libraries .h files
#include "Model_Obj.hpp"
// Project .h files
#include "TransformComponent.hpp"
#include "Entity.hpp"

namespace skylight
{
	RendererComponent::RendererComponent(const std::string & path)
	{
		model.reset(new glt::Model_Obj(path));
	}

	void RendererComponent::Update()
	{
		auto transform_component = std::dynamic_pointer_cast<TransformComponent>(entity->get_component("transform"));
		auto transform = transform_component->get_transform();
		model->set_transformation(transform);
	}
}
