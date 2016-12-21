#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

static const int DISPLAY_WIDTH = 1200;
static const int DISPLAY_HEIGHT = 800;
static const GLfloat g_vertex_buffer_data[] = {

	   -200, -200, 0,

	    200, -200, 0,

	   -200,  200, 0,



	    200,  200, 0,

	   -200,  200, 0,

	    200, -200, 0

	};
 float xc=1.0f;

int main(int argc, char** argv)
{
	 Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "LAB8_SUBTSELNYI");

	Vertex vertices[] =
	{
		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(0, 0, -1)),

		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 1), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 1), glm::vec3(0, 0, 1)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(0, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(0, 0), glm::vec3(0, -1, 0)),

		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(1, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 1, 0)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 1), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(-1, 0, 0)),

		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(1, 0, 0)),
	};

	unsigned int indices[] = {0, 1, 2,
							  0, 2, 3,

							  6, 5, 4,
							  7, 6, 4,

							  10, 9, 8,
							  11, 10, 8,

							  12, 13, 14,
							  12, 14, 15,

							  16, 17, 18,
							  16, 18, 19,

							  22, 21, 20,
							  23, 22, 20
	                          };

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	Mesh monkey("./res/retro_rocket.obj");
	Mesh m_background ("./res/hexagon.obj");
	Shader shader("./res/basicShader");
	Shader shader1("./res/basicShader");
	Texture textures("./res/flag.jpg");
	Texture  background("./res/cos.jpg");
	Transform transform;
	Transform transform1;
	Camera camera(glm::vec3(0.0f, 0.0f, -90.0f), 58.0f, (float)DISPLAY_WIDTH/(float)DISPLAY_HEIGHT, 0.1f, 100.0f);


        SDL_Surface * image = SDL_LoadBMP("./res/cosmos.bmp");

	SDL_Event e;
	bool isRunning = true;
	float counter = 0.0f;
	float starter = 0.0f;
	float actiony = 0.0f;
	float mult = 0.000000001f;
	float scal = 0.1f;
//if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS)

	while(isRunning)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
				isRunning = false;
		}
//display.m_glContext = SDL_GL_CreateContext(display.m_window);
		display.Clear(0.9f, 0.9f, 0.9f, 1.0f);



        //painting

        transform1.GetScale()->x = 200.0f;
		transform1.GetScale()->y=200.0f;
		transform1.GetScale()->z = 80.0f;
        transform1.GetRot()->x = 80.0f;
        transform1.GetPos()->y = -4.0f;



        shader1.Bind();
        background.Bind();
        shader1.Update(transform1, camera);
        m_background.Draw();

		starter+=0.1f;
		actiony+=0.0001f;
        if (starter>200.0f) scal=scal-0.00001f;
        if (starter>20.0f) if (mult<0.5f)  mult=mult*1.01;
        if (starter>20.0f) counter=counter+mult/5;
		float sinCounter = sinf(counter);
		float absSinCounter = abs(sinCounter);

        transform.GetPos()->x = 60.0f ;
        if(counter<400.0f)
		transform.GetRot()->x = counter/600;
		transform.GetPos()->y = -30.0f + starter/7;
        if (starter>20.0f)
            transform.GetPos()->x = 60.0f -counter/50;
		//transform.GetRot()->y = counter/800 ;
        //transform.GetRot()->z = 0.0f ;
        if (starter>200.0f){
		transform.GetScale()->x = scal;
		transform.GetScale()->y= scal;
		transform.GetScale()->z = scal;
        }
        else{
        transform.GetScale()->x = 0.1f;
		transform.GetScale()->y= 0.1f;
		transform.GetScale()->z = 0.1f;
        }
		//transform.GetScale()->y = absSinCounter;
       // background.Bind();

		shader.Bind();


		textures.Bind();

		shader.Update(transform, camera);



		monkey.Draw();
		//mesh.Draw();


		display.SwapBuffers();
		SDL_Delay(1);
		//counter += 0.01f;
	}

	return 0;
}
