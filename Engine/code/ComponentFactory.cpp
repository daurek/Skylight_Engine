// Header file
#include "ComponentFactory.hpp"
#include "RenderModule.hpp"

namespace engine
{
	void ComponentFactory::RegisterFactory(std::string id, Function factory)
	{
		component_factories[id] = factory;
	}

	std::shared_ptr< Component > ComponentFactory::CreateComponent(std::string id, const rapidxml::xml_node<>& node)
	{
		std::shared_ptr< Component > component;

		auto factory = component_factories.find(id);

		if (factory != component_factories.end())
		{
			component = factory->second(node);
		}

		//factory.
		return component;
	}
}
