#pragma once

// System files
#include <map>

namespace skylight
{
	class Message
	{
		uint32_t id;
		std::map<uint32_t, int> properties;

	public:

		Message(uint32_t given_id) : id(given_id) { }
		uint32_t get_id() const { return id; }

	};
}

