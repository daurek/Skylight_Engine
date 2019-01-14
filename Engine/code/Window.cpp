// Header file
#include "Window.hpp"

// Libraries .h files
#include "SDL.h"
#include "glad/glad.h"
#include "OpenGL.hpp"


namespace engine
{
	
	Window::Window(int _windowWidth, int _windowHeight) : window_width(_windowWidth), window_height(_windowHeight)
	{
		window = nullptr;
		gl_context = nullptr;

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);


		if (SDL_Init(SDL_INIT_VIDEO) >= 0)
		{
			window = SDL_CreateWindow
			(
				"Engine",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				window_width,
				window_height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			if (window)
			{

				// Create context
				gl_context = SDL_GL_CreateContext(window);

				if (gl_context)
				{
					glt::initialize_opengl_extensions();
				}
				
				// Set Vsync
				//SDL_GL_SetSwapInterval(1);

				//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
			}
		}
		

		
	}

	Window::~Window()
	{
		// Destroy context
		if (gl_context) SDL_GL_DeleteContext(gl_context);
		// Destroy Window
		if (window) SDL_DestroyWindow(window);

		SDL_Quit();
	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Display()
	{
		SDL_GL_SwapWindow(window);
	}

}


