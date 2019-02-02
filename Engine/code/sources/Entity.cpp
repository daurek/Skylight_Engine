/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Entity
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "Entity.hpp"

namespace skylight
{
	void Entity::AddComponent(std::string id, const std::shared_ptr<Component>& component)
	{
		// Set's the Component's Entity reference and saves it into the Component list
		component->entity = this;
		components[id] = component;

		// If it's a TransformComponent cache it into Transform
		if (id == "transform")
		{
			transform = std::dynamic_pointer_cast<TransformComponent>(component).get();
		}
	}
}
