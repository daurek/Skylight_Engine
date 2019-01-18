// ----------------------------------------------------------------------------------------------------------------------
// SKYLIGHT ENGINE
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
#include <SDL.h>

namespace skylight
{
	int Engine::init()
	{
		// Initialize SDL
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);

		// Create window
		Window window{1080, 720, false};
		// Load scene with window
		Scene scene{ "../../assets/scene.xml", window };

		// Prepare input
		InputTask inputTask;
		inputTask.LoadInputMapping("../../assets/input_mapping.xml");
		Kernel::instance().Add(inputTask);

		// Start kernel loop
		Kernel::instance().Run();

		return 0;
	}
}
