#include "PlayState.h"
#include "GameOverState.h"
#include "Cube.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>

PlayState::PlayState(StateManager* pManager)
:GameState(pManager)
{
}

PlayState::~PlayState()
{

}

PlayState* PlayState::getInstance(StateManager* pManager)
{
	static PlayState Instance(pManager);
	return &Instance;
}

void PlayState::update(InputHandler inputHandler, int interval)
{
	//ball.detectCollision(bar1);
	//ball.detectCollision(bar2);

	if (inputHandler.isKeyPressed(SDLK_a)) {
		//bar1.moveLeft(interval);
	}
	if (inputHandler.isKeyPressed(SDLK_d)) {
		//bar1.moveRight(interval);
	}

  for (IShape* p_shape : p_shapes_) {
    p_shape->update();
  }
}

void PlayState::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.0);

  for (IShape* p_shape : p_shapes_) {
    p_shape->draw();
  }
}

void PlayState::enterState(){
  glClearColor(0.0, 0.0, 0.0, 1.0);  //background color and alpha
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 640.0 / 480.0, 1.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);


  p_shapes_.push_front(new Cube(0, 0, 0, 0.5, 0.5, 0.5));
}