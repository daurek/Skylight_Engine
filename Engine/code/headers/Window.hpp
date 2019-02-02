/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Window
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <string>

//Predefinitions
struct SDL_Window;
typedef void * SDL_GLContext;

namespace skylight
{
	/// SDL Window container that displays the current viewport
	class Window
	{

	public:

		/// Default constructor which calls the other constructor with default parameters
		Window() : Window("Skylight Engine", 1080, 720, false) {};

		/// Creates a Window with the given parameters
		Window(const std::string & _window_name,int _window_width, int _window_height, bool _fullscreen);

		/// Deletes the window and the context
		~Window();

		/// Clears the OpenGL buffers
		void			Clear();

		/// Swaps buffers in order to display
		void			Display();

		/// Returns the Window name
		std::string&	get_window_name()				{ return window_name;	}

		/// Returns the Window width
		int				get_window_width()				{ return window_width;	}
		
		/// Returns the Window height
		int				get_window_height()				{ return window_height;	}
		
		/// Returns if the window is in fullscreen
		bool			get_fullscreen()				{ return fullscreen;	}
		
	private:

		/// Reference to the window
		SDL_Window  *	window;
		/// Reference to the open gl context
		SDL_GLContext	gl_context;

		std::string		window_name;
		int				window_width;
		int				window_height;
		bool			fullscreen;
	};
}