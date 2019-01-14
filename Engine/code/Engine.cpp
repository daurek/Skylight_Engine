// ----------------------------------------------------------------------------------------------------------------------
// ENGINE
// Copyright © 2018+ Ilyass Sofi Hlimi
//
// ilyassgame@gmail.com
// ----------------------------------------------------------------------------------------------------------------------

// Header file
#include "Engine.hpp"

// Project .h files
#include "Window.hpp"
#include "Kernel.hpp"
#include "InputTask.hpp"
#include "RenderModule.hpp"
#include "Scene.hpp"

//TO Remove maybe
//#include <SDL.h>

namespace engine
{

	int Engine::init()
	{
	/*	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
			return 1;
		}*/

		// Load Data
		

		
		// Create Window

		// Window window{1080, 720};

		//RenderModule renderModule{ &window };		

		Scene scene{ "../../assets/scene.xml"};

		InputTask inputTask;
		Kernel::instance().Add(inputTask);
		//Kernel::instance().Add(*renderModule.get_task());
		Kernel::instance().Run();

		return 0;
	}
}
