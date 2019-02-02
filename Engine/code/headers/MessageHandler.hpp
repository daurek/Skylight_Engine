/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::MessageHandler
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <unordered_map>

// Project
#include "Listener.hpp"

namespace skylight
{
	/// Handles Engine Messaging and Listeners
	class MessageHandler
	{

	public:

		/// MessageHandle singleton instance
		static MessageHandler & instance()
		{
			static MessageHandler message_handler;
			return message_handler;
		}

		/// Singlecast Listener map 
		std::unordered_map< std::string, Listener * > singlecast_targets;

		/// Multicast Listener map 
		std::unordered_map< std::string, std::list< Listener * > > multicast_targets;

	public:

		/// Send a Message to the given Listener
		void singlecast(std::string id, const Message & message)
		{
			auto iterator = singlecast_targets.find(id);

			if (iterator != singlecast_targets.end())
			{
				iterator->second->Handle(message);
			}
		}

		/// Send a Message to all the map Listeners
		void multicast(const Message & message)
		{
			auto iterator = multicast_targets.find(message.get_id());

			if (iterator != multicast_targets.end())
			{
				for (auto & listener : iterator->second)
				{
					listener->Handle(message);
				}
			}
		}
	};
}

