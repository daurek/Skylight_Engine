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
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		window = SDL_CreateWindow
		(
			"Engine",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			window_width,
			window_height,
			SDL_WINDOW_OPENGL //| SDL_WINDOW_SHOWN
		);

		// Create context
		gl_context = SDL_GL_CreateContext(window);

		// Load OpenGL through glad
		gladLoadGLLoader(SDL_GL_GetProcAddress);
		
		// Set Vsync
		SDL_GL_SetSwapInterval(1);

		// Disabling culling TO REMOVE
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);

		
		glClearColor(0.1f, 0.1f, 0.1f, 0.0f);



		
	}

	Window::~Window()
	{
		// destruir contexto
		SDL_GL_DeleteContext(gl_context);
		//// destruir ventana
		SDL_DestroyWindow(window);

		SDL_Quit();
	}

	void Window::Display()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//);
		//glViewport(0, 0, 1080, 720);
		//glLoadIdentity();
		//glTranslatef(400.f, 300.f, 0.f);
		
		//glBegin(GL_TRIANGLES);
		//{
		//	glColor3f(1.f, 0.f, 0.f);
		//	glVertex3f(-200.f, -200.f, 0.f);
		//	glColor3f(0.f, 1.f, 0.f);
		//	glVertex3f(+200.f, -200.f, 0.f);
		//	glColor3f(0.f, 0.f, 1.f);
		//	glVertex3f(0.f, 200.f, 0.f);
		//}
		//glEnd();
		
		SDL_GL_SwapWindow(window);
	}

}


