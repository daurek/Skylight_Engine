#pragma once

// System files
#include <map>

// Libraries .h files
#include "rapidxml_utils.hpp"
// Project .h files
#include "Task.hpp"

namespace skylight
{
	class InputTask : public Task
	{

	private: 

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

		std::map< int, Key_Code > keyboard_mapping;

	public:

		InputTask() = default;

		void Run() override;
		
		void LoadInputMapping(const std::string & input_mapping_xml);
		void LoadInputEvent(rapidxml::xml_node<> * event_node);
		void LoadInputDevice(rapidxml::xml_node<> * device_node);
		//void LoadInputKeys(rapidxml::xml_node<> * key	_node);

	
		Key_Code ToSdlKeyCode(int sdl_key_code);

	};
}

