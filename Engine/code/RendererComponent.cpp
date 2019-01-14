// Header file
#include "RendererComponent.hpp"

#include "Model_Obj.hpp"

namespace engine
{
	RendererComponent::RendererComponent(const std::string & path)
	{
		model.reset(new glt::Model_Obj(path));
	}
}
