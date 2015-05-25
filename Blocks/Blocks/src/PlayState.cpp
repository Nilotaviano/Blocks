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
  bool pressedUp = inputHandler.isKeyPressed(SDL_SCANCODE_W) || inputHandler.isKeyPressed(SDL_SCANCODE_UP);
  bool pressedDown = inputHandler.isKeyPressed(SDL_SCANCODE_S) || inputHandler.isKeyPressed(SDL_SCANCODE_DOWN);
  bool pressedLeft = inputHandler.isKeyPressed(SDL_SCANCODE_A) || inputHandler.isKeyPressed(SDL_SCANCODE_LEFT);
  bool pressedRight = inputHandler.isKeyPressed(SDL_SCANCODE_D) || inputHandler.isKeyPressed(SDL_SCANCODE_RIGHT);

  for (IShape* p_shape : p_shapes_) {
    if (pressedUp) {
      p_shape->inputUp();
    }
    if (pressedDown) {
      p_shape->inputDown();
    }
    if (pressedLeft) {
      p_shape->inputLeft();
    }
    if (pressedRight) {
      p_shape->inputRight();
    }
  }

  for (IShape* p_shape : p_shapes_) {
    p_shape->update();
  }
}

void PlayState::draw()
{
  static float angle = 0;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

  camera.look();

  for (IShape* p_shape : p_shapes_) {
    p_shape->draw();
  }

  glPopMatrix();

}

void PlayState::enterState(){
  int vPort[4];
  int screenWidth, screenHeight;
  glGetIntegerv(GL_VIEWPORT, vPort);
  screenWidth = vPort[2];
  screenHeight = vPort[3];

  glClearColor(1.0, 1.0, 1.0, 1.0);  //background color and alpha
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65, screenWidth / screenHeight, 1.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);

  p_shapes_.clear();

  p_shapes_.push_front(new Cube(0, 0, 0, 1, 1, 1));
}

void PlayState::resize()
{
  int vPort[4];
  int screenWidth, screenHeight;
  glGetIntegerv(GL_VIEWPORT, vPort);
  screenWidth = vPort[2];
  screenHeight = vPort[3];

  glClearColor(1.0, 1.0, 1.0, 1.0);  //background color and alpha
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65, screenWidth / screenHeight, 1.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
}
