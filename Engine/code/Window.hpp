#pragma once

struct SDL_Window;
typedef void * SDL_GLContext;

namespace skylight
{
	class Window
	{
		SDL_Window  *	window;
		SDL_GLContext	gl_context;

		int				window_width;
		int				window_height;
		bool			fullscreen;

	public:

		Window() : Window(1080, 720, false) {};
		Window(int _window_width, int _window_height, bool _fullscreen);
		~Window();

	public:

		void	Clear();
		void	Display();
		int		get_window_width()				{ return window_width;	}
		int		get_window_height()				{ return window_height;	}
		bool	get_fullscren()					{ return fullscreen;	}
	};
}