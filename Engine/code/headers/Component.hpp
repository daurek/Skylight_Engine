/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Component
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
/// 
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

namespace skylight
{
	class Entity;

	/// Base class for every Component
	class Component
	{

	public:

		/// Base update for every Component
		virtual void Update() = 0;

		/// Reference to it's own Entity
		Entity * entity;
	};
}

