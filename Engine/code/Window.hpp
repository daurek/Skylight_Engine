#pragma once

struct SDL_Window;
typedef void * SDL_GLContext;

namespace engine
{
	class Window
	{
		SDL_Window  *	window;
		SDL_GLContext	gl_context;

		int				window_width;
		int				window_height;

	public:

		Window() : Window(1080, 720) {};
		Window(int _window_width, int _window_height);
		~Window();

	public:

		void	Clear();
		void	Display();
		int		get_window_width()				{ return window_width;	}
		int		get_window_height()				{ return window_height;	}

	};
}