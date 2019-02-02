/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Entity
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <map>
#include <memory>

// Project
#include "TransformComponent.hpp"


namespace skylight
{
	/// Gameobject with Components and properties that exists on the Scene
	class Entity
	{

	public:

		/// Default Constructor
		Entity() = default;
		
		/// Creates an entity with the given name
		Entity(std::string _name) : name(_name) {};

				/// Adds the given component to the entity 
		void AddComponent(std::string id, const std::shared_ptr< Component > & component);
		
		/// ---
		void AddChild(const std::shared_ptr< Entity> & entity)
		{
			entity->parent = this;
			children[entity->name] = entity;
		}

		/// --
		std::shared_ptr< Component	> get_component(const std::string & name) { return components[name]; }
		
		/// Returns a map of this Entity's children
		std::map< std::string, std::shared_ptr< Entity		> > & get_children() { return children; }

		/// Entity Name
		std::string name;

		/// Transform component, a must on every Entity
		TransformComponent * transform;

		/// Entity Parent
		Entity * parent = nullptr;
	
	private: 
		
		/// Component list, Transform not included
		std::map< std::string, std::shared_ptr< Component	> > components;

		/// Children list
		std::map< std::string, std::shared_ptr< Entity		> > children;

	};

}

