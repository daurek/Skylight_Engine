#pragma once

// System files
#include <map>

// Project .h files
#include "Message.hpp"

namespace skylight
{
	class Listener
	{
	public:
		virtual void handle(const Message &) = 0;
	};
}

