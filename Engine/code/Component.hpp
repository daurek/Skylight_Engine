#pragma once

namespace skylight
{
	class Entity;

	class Component
	{
	public:
		Component();
		Entity * entity;

		virtual void Update() = 0;
	};
}

