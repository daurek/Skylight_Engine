#pragma once

// System files
#include <unordered_map>

// Project .h files
#include "Listener.hpp"

namespace skylight
{
	class MessageHandler
	{
	public:

		static MessageHandler & instance()
		{
			static MessageHandler message_handler;
			return message_handler;
		}

		std::unordered_map< uint32_t, Listener * > singlecast_targets;

		std::unordered_map< uint32_t, std::list< Listener * > > multicast_targets;

	public:

		void singlecast(uint32_t id, const Message & message)
		{
			auto iterator = singlecast_targets.find(id);

			if (iterator != singlecast_targets.end())
			{
				iterator->second->handle(message);
			}
		}

		void multicast(const Message & message)
		{
			auto iterator = multicast_targets.find(message.get_id());

			if (iterator != multicast_targets.end())
			{
				for (auto & listener : iterator->second)
				{
					listener->handle(message);
				}
			}
		}
	};
}

