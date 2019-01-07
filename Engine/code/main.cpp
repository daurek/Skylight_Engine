// System files
#include <Windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
// Project .h files
#include "Engine.hpp"

// Hides SDL main on normal main
#undef main

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	// Show Console [ONLY FOR LOGGING]
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;

	// Start Engine
	engine::Engine engine;
	engine.init();

	return 0;
}

//int main()
//{
//	Engine engine;
//	engine.init();
//
//	//if (engine.init() > 0)
//	//{
//	//	//SDL_Log("Engine has not been initialized");
//	//}
//
//	return 0;
//}

