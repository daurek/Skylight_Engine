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

		std::map< std::string, std::shared_ptr< Component	> > components;
		std::map< std::string, std::shared_ptr< Entity		> > children;

	public:
		Entity();

		void AddComponent(std::string id,const std::shared_ptr< Component > & component)
		{
			components[id] = component;
		}

	};
}

