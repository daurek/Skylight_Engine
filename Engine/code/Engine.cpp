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
		// Create Window
		Window window{1080, 720};

		Scene scene{ "../../assets/scene.xml", window };

		InputTask inputTask;
		Kernel::instance().Add(inputTask);
		Kernel::instance().Run();

		return 0;
	}
}
