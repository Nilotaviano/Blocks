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
  if (inputHandler.isKeyPressed(SDL_SCANCODE_W)) {
    camera.move_up(interval);
  }
  if (inputHandler.isKeyPressed(SDL_SCANCODE_S)) {
    camera.move_down(interval);
  }
  if (inputHandler.isKeyPressed(SDL_SCANCODE_A)) {
    camera.move_left(interval);
  }
  if (inputHandler.isKeyPressed(SDL_SCANCODE_D)) {
    camera.move_right(interval);
  }
  if (inputHandler.isKeyPressed(SDL_SCANCODE_UP)) {
    camera.focus_up(interval);
  }
  if (inputHandler.isKeyPressed(SDL_SCANCODE_DOWN)) {
    camera.focus_down(interval);
  }
  if (inputHandler.isKeyPressed(SDL_SCANCODE_LEFT)) {
    camera.focus_left(interval);
  }
  if (inputHandler.isKeyPressed(SDL_SCANCODE_RIGHT)) {
    camera.focus_right(interval);
  }

  for (IShape* p_shape : p_shapes_) {
    p_shape->update(interval);
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

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65, screenWidth / screenHeight, 1.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);

  p_shapes_.clear();

  for (int i = 0; i < 250; i++) {
    p_shapes_.push_front(new Cube((rand() % 100 - 50), (rand() % 100 - 50), (rand() % 100 - 50) // Position
                                  , 1, 1, 1,                                                    // Dimension
                                  (rand() % 360), (rand() % 360), (rand() % 360)));             // Rotation
  }
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
