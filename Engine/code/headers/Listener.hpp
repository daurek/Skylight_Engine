/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Listener
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// Project
#include "Message.hpp"

namespace skylight
{	
	/// Base for every Listener that handles messages
	class Listener
	{

	public:

		/// Base method that handles a message
		virtual void Handle(const Message & message) = 0;
	};
}