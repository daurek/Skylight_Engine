#pragma once

// System files
#include <map>
#include <memory>

// Project .h files
#include "Component.hpp"

namespace skylight
{

	class Entity
	{

		std::string name;
		std::map< std::string, std::shared_ptr< Component	> > components;
		std::map< std::string, std::shared_ptr< Entity		> > children;

	public:
		Entity(std::string _name) : name(_name) {};
		//TransformComponent  transform;

		void AddComponent(std::string id,const std::shared_ptr< Component > & component)
		{
			component->entity = this;
			components[id] = component;
		}

		std::shared_ptr< Component	> get_component(const std::string & name) { return components[name]; }
		

		//virtual void Update() = 0;

	};

}

