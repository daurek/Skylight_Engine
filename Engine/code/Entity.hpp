#pragma once

// System files
#include <map>
#include <memory>

// Project .h files
#include "Component.hpp"

namespace engine
{
	class Entity
	{

		std::map< uint16_t, std::shared_ptr< Component > > components;
		std::map< uint16_t, std::shared_ptr< Entity > > children;

	public:
		Entity();

	};
}

