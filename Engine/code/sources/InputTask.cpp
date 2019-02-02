/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::InputTask
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "InputTask.hpp"

// Libraries
#include "SDL_events.h"
#include "SDL_log.h"
// Project
#include "Kernel.hpp"
#include "MessageHandler.hpp"

namespace skylight
{
	void InputTask::Run()
	{
		SDL_Event event;

		// Get the event
		while (SDL_PollEvent(&event) > 0)
		{
			// Check type
			switch (event.type)
			{
				case SDL_KEYDOWN:
				{
					auto sdl_keycode = keyboard_mapping.find(event.key.keysym.sym);

					if (sdl_keycode != keyboard_mapping.end())
					{
						// Send Key Pressed message with Key Code
						Message message("key_pressed");
						message.AddProperty("key_code", sdl_keycode->second);
						MessageHandler::instance().multicast(message);
					}
					break;
				}
				case SDL_MOUSEMOTION:
				{
					int x, y;
					SDL_GetRelativeMouseState(&x, &y);
					Message message("mouse_motion");
					message.AddProperty("position_x", x);
					message.AddProperty("position_y", y);
					MessageHandler::instance().multicast(message);

					break;
				}

				case SDL_QUIT:
				{
					Kernel::instance().Stop();
					break;
				}

			}
		}
	}
	
	void InputTask::LoadInputMapping(const std::string & input_mapping_xml)
	{
		SDL_Log("\n________Loading Input Mapping________\n");

		// Load xml
		rapidxml::file<> xml_file(input_mapping_xml.c_str());

		// Parse xml
		rapidxml::xml_document<> doc;
		doc.parse<0>(xml_file.data());

		// Load Inputs
		for (rapidxml::xml_node<>* event_node = doc.first_node()->first_node(); event_node; event_node = event_node->next_sibling())
		{
			LoadInputEvent(event_node);
		}

		SDL_Log("\n	________Input mapping loaded________");
	}

	void InputTask::LoadInputEvent(rapidxml::xml_node<>* event_node)
	{
		std::string event_id = event_node->first_attribute()->value();
		std::string event_log = "		" + event_id;
		SDL_Log(event_log.c_str());

		for (rapidxml::xml_node<>* device_node = event_node->first_node(); device_node; device_node = device_node->next_sibling())
		{
			LoadInputDevice(device_node);
		}
	}

	void InputTask::LoadInputDevice(rapidxml::xml_node<>* device_node)
	{
		std::string device_id = device_node->first_attribute()->value();
		std::string device_log = "			" + device_id;
		SDL_Log(device_log.c_str());

		for (rapidxml::xml_node<>* key_node = device_node->first_node(); key_node; key_node = key_node->next_sibling())
		{
			std::string key_name = key_node->value();
			std::string key_log = "					" + key_name;
			SDL_Log(key_log.c_str());
			// Save key code with name
			int key_code = keycodes_numbers[key_name];
			keyboard_mapping[key_code] = ToSdlKeyCode(key_code);
		}
	}

	InputTask::Key_Code InputTask::ToSdlKeyCode(int sdl_key_code)
	{
		switch (sdl_key_code)
		{
			case SDLK_RETURN:       return KEY_RETURN;
			case SDLK_ESCAPE:       return KEY_ESCAPE;
			case SDLK_BACKSPACE:    return KEY_BACKSPACE;
			case SDLK_TAB:          return KEY_TAB;
			case SDLK_SPACE:        return KEY_SPACE;

			case SDLK_a:            return KEY_A;
			case SDLK_b:            return KEY_B;
			case SDLK_c:            return KEY_C;
			case SDLK_d:            return KEY_D;
			case SDLK_e:            return KEY_E;
			case SDLK_f:            return KEY_F;
			case SDLK_g:            return KEY_G;
			case SDLK_h:            return KEY_H;
			case SDLK_i:            return KEY_I;
			case SDLK_j:            return KEY_J;
			case SDLK_k:            return KEY_K;
			case SDLK_l:            return KEY_L;
			case SDLK_m:            return KEY_M;
			case SDLK_n:            return KEY_N;
			case SDLK_o:            return KEY_O;
			case SDLK_p:            return KEY_P;
			case SDLK_q:            return KEY_Q;
			case SDLK_r:            return KEY_R;
			case SDLK_s:            return KEY_S;
			case SDLK_t:            return KEY_T;
			case SDLK_u:            return KEY_U;
			case SDLK_v:            return KEY_V;
			case SDLK_w:            return KEY_W;
			case SDLK_x:            return KEY_X;
			case SDLK_y:            return KEY_Y;
			case SDLK_z:            return KEY_Z;

			case SDLK_0:            return KEY_0;
			case SDLK_1:            return KEY_1;
			case SDLK_2:            return KEY_2;
			case SDLK_3:            return KEY_3;
			case SDLK_4:            return KEY_4;
			case SDLK_5:            return KEY_5;
			case SDLK_6:            return KEY_6;
			case SDLK_7:            return KEY_7;
			case SDLK_8:            return KEY_8;
			case SDLK_9:            return KEY_9;

			// ...
		}

		return KEY_UNKOWN;
	}

}
