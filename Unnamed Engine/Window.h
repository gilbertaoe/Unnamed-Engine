#pragma once
#include <SDL.h>

class Window
{
public:
	SDL_Window *mainWindow;
	SDL_GLContext mainContext;

	Window();
	~Window();
	bool Init();
	bool SetOpenGLAttributes();
	void RunGame();
};