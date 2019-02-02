/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::InputTask
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <map>
#include <unordered_map>

// Libraries
#include "rapidxml_utils.hpp"
#include "SDL_mouse.h"
// Project
#include "Task.hpp"

namespace skylight
{
	/// Task that handles user input
	class InputTask : public Task
	{

	public:

		/// Creates an Input Task with the given priority
		InputTask(int priority) : Task(priority) { SDL_SetRelativeMouseMode(SDL_TRUE); }

		/// Input events loop
		void Run() override;
		
		/// Loads the Input mapping xml file with the given path
		void LoadInputMapping(const std::string & input_mapping_xml);
		
		/// Loads the given node input event properties
		void LoadInputEvent(rapidxml::xml_node<> * event_node);

		/// Loads the given node input device properties
		void LoadInputDevice(rapidxml::xml_node<> * device_node);

		/// Keycode codes
		enum Key_Code
		{
			KEY_UNKOWN,

			KEY_RETURN,
			KEY_ESCAPE,
			KEY_BACKSPACE,
			KEY_TAB,
			KEY_SPACE,

			KEY_A, KEY_B, KEY_C, KEY_D, KEY_E,
			KEY_F, KEY_G, KEY_H, KEY_I, KEY_J,
			KEY_K, KEY_L, KEY_M, KEY_N, KEY_O,
			KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T,
			KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y,
			KEY_Z,

			KEY_0,
			KEY_1,
			KEY_2,
			KEY_3,
			KEY_4,
			KEY_5,
			KEY_6,
			KEY_7,
			KEY_8,
			KEY_9,

			//...
		};

		/// Translates the given SDL key codes into SkylightEngine keycodes
		Key_Code ToSdlKeyCode(int sdl_key_code);
	
	private:

		/// Map to translate from string (xml) to int key codes
		std::unordered_map< std::string, int > keycodes_numbers =
		{
			{"tab"	, 9 },
			{"escape", 27 },
			{"space", 32 },

			{ "0"	, 48 },
			{ "1"	, 49 },
			{ "2"	, 50 },
			{ "3"	, 51 },
			{ "4"	, 52 },
			{ "5"	, 53 },
			{ "6"	, 54 },
			{ "7"	, 55 },
			{ "8"	, 56 },
			{ "9"	, 57 },

			{ "a"	, 97 },
			{ "b"	, 98 },
			{ "c"	, 99 },
			{ "d"	, 100},
			{ "e"	, 101},
			{ "f"	, 102},
			{ "g"	, 103},
			{ "h"	, 104},
			{ "i"	, 105},
			{ "j"	, 106},
			{ "k"	, 107},
			{ "l"	, 108},
			{ "m"	, 109},
			{ "n"	, 110},
			{ "o"	, 111},
			{ "p"	, 112},
			{ "q"	, 113},
			{ "r"	, 114},
			{ "s"	, 115 },
			{ "t"	, 116 },
			{ "u"	, 117 },
			{ "v"	, 118 },
			{ "w"	, 119 },
			{ "x"	, 120 },
			{ "y"	, 121 },
			{ "z"	, 122 },

		};

		/// Current keycode mapping
		std::map< int, Key_Code > keyboard_mapping;

	};
}

