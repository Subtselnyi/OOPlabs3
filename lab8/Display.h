#ifndef DISPLAY_INCLUDED_H
#define DISPLAY_INCLUDED_H

#include <string>
#include <SDL2/SDL.h>
#define  GLEW_STATIC
#include <GL/glew.h>

class Display
{
public:
	 Display(int width, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	void SwapBuffers();

	virtual ~Display();
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
protected:
private:
	void operator=(const Display& display) {}
	Display(const Display& display) {}


	GLuint texture;


	SDL_Surface * image = SDL_LoadBMP("./res/cosmos.bmp");

};

#endif
