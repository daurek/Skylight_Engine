#pragma once

// System files
#include <map>
#include <memory>
#include <functional>

// Libraries .h files
#include "rapidxml.hpp"
// Project .h files
#include "Component.hpp"

namespace engine
{
	class ComponentFactory
	{

	protected:
		typedef std::shared_ptr<Component>(*Function) (const rapidxml::xml_node<>& node);

	private:

		std::map< std::string, Function > component_factories;

	public:

		static ComponentFactory & instance()
		{ 
			static ComponentFactory componentFactory;
			return componentFactory;
		}

		void RegisterFactory(std::string id, Function factory );
		void print() {};
		std::shared_ptr< Component > CreateComponent(std::string id, const rapidxml::xml_node<> & node);
	};
}

