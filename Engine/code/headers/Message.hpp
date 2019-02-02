/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Message
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <map>
#include <variant>

namespace skylight
{

	/// Message Event that can be sent to any Listener with the given properties
	class Message
	{

	public:

		/// Creates a Message with the given name
		Message(std::string given_id) : id(given_id) { }

		typedef std::variant<int, bool, float, std::string> Variant;

		/// Creates a property with the given name and Variant
		void AddProperty(const std::string & name, const Variant & value)
		{
			properties[name] = value;
		}

		/// Returns the current name
		std::string get_id() const { return id; }

		/// Message properties map
		std::map<std::string, Variant > properties;

		//const std::any & operator [] ( std::string id) const
		//{
		//	return properties[id];
		//}

		/*const std::any & operator [] (std::string _id) const
		{
			return properties[_id];
		}*/

	private:

		/// Message name
		std::string id;

	};
}

