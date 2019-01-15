#pragma once

// System files
#include <string>

// Libraries .h files
#include "Model.hpp"
// Project .h files
#include "Component.hpp"

namespace skylight
{	
	class RendererComponent : public Component
	{
		std::shared_ptr< glt::Model > model;

	public:

		RendererComponent(const std::string & path);

	public:

		std::shared_ptr< glt::Model > get_model() { return model; }
	};
}

