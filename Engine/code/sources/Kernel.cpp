/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Kernel
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "Kernel.hpp"

// Libraries
#include "SDL.h"

namespace skylight
{
	//// FPS 
	//Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
	//Uint32 fps_current; //the current FPS.
	//Uint32 fps_frames = 0; //frames passed since the last recorded fps.

	void Kernel::Add(Task & task)
	{
		// Add given task into the list
		tasks.insert(&task);
	}

	void Kernel::Run()
	{
		SDL_Log("Engine loaded succesfully ____ Kernel Loop Started");
		// Engine Loop
		do
		{

			// Task Loop
			for (Task * task : tasks)
			{
				task->Run();
			}

			//// FPS count
			//fps_frames++;
			//if (fps_lasttime < SDL_GetTicks() - 1 * 1000)
			//{
			//	fps_lasttime = SDL_GetTicks();
			//	fps_current = fps_frames;
			//	fps_frames = 0;
			//}
			//SDL_Log(std::to_string(fps_current).c_str());
		}
		while (running);
	}

	void Kernel::Stop()
	{
		// Stops Engine Loop
		running = false;
		SDL_Quit();
	}
}
