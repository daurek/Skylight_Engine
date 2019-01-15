// Header file
#include "InputTask.hpp"

// Libraries .h files
#include "SDL.h"
// Project .h files
#include "Kernel.hpp"

namespace skylight
{
	void InputTask::Run()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
				{
					SDL_Log(SDL_GetScancodeName(event.key.keysym.scancode));

					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							Kernel::instance().Stop();
							break;
						default:
							break;
					}

					// DO IT LIKE THIS
					auto item = keyboard_mapping.find(event.key.keysym.sym);
					
					if (item != keyboard_mapping.end())
					{
						/*Message message(item->second);

						Message_Handler::instance().multicast(message);*/
					}
					break;
				}

				case SDL_QUIT:
				{
					SDL_Log("Quit");
					Kernel::instance().Stop();
					break;
				}
			}
		}
	}
}
