/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Window
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header file
#include "Window.hpp"

// Libraries .h files
#include "SDL.h"
#include "glad/glad.h"
#include "OpenGL.hpp"

namespace skylight
{
	
	Window::Window(const std::string & _window_name, int _windowWidth, int _windowHeight, bool _fullscreen) : window_name(_window_name), window_width(_windowWidth), window_height(_windowHeight), fullscreen(_fullscreen)
	{
		// Initialize as nullptr to protect against errors
		window = nullptr;
		gl_context = nullptr;

		// Set gl attributes
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

		// Initializing SDL Video
		if (SDL_Init(SDL_INIT_VIDEO) >= 0)
		{
			// Creating window
			window = SDL_CreateWindow
			(
				_window_name.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				window_width,
				window_height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			if (window)
			{
				// Creating context
				gl_context = SDL_GL_CreateContext(window);

				if (gl_context)
				{
					// Initializes opengl
					glt::initialize_opengl_extensions();
					// Set screen scolor
					glClearColor(0.3f, 0.3f, 0.6f, 0.3f);

					if (fullscreen)
					{
						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
				}
				
				// Set Vsync
				SDL_GL_SetSwapInterval(1);
			}
		}
	}

	Window::~Window()
	{
		// Destroy context
		if (gl_context) SDL_GL_DeleteContext(gl_context);
		// Destroy Window
		if (window) SDL_DestroyWindow(window);
	}

	void Window::Clear()
	{
		// Clears gl Buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Display()
	{
		// Swaps windows
		SDL_GL_SwapWindow(window);
	}

}


