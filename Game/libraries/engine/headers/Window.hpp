
#pragma once

struct SDL_Window;
typedef void * SDL_GLContext;

namespace engine
{

	class Window
	{

		SDL_Window  * window;
		SDL_GLContext gl_context;

	public:

		Window();
		~Window();

	};

}