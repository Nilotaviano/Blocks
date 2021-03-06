﻿#include "MenuState.h"

#include "PlayState.h"

#include <SDL_opengl.h>
#include <GL\GLU.h>


MenuState::MenuState(StateManager* pManager)
: GameState(pManager),
//x, y, width, height, r, g, b, text, font size
playButton_(-0.2f, 0.375f, 0.4f, 0.25f, 0, 20, 168, "Play", 20),
optionsButton_(-0.2f, -0.125f, 0.4f, 0.25f, 0, 20, 168, "Options", 20),
quitButton_(-0.2f, -0.625f, 0.4f, 0.25f, 0, 20, 168, "Quit", 20)
{
  //TODO: Beautify this
  playButton_.selected = true;
  timeBuffer_ = 0;
}


MenuState::~MenuState()
{
}

MenuState* MenuState::getInstance(StateManager* pManager)
{
  static MenuState Instance(pManager);
  return &Instance;
}

void MenuState::enterState()
{
  glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  timeBuffer_ = -150; //This is to avoid instantly selecting "Play" upon going from GameOverState to this
}

void MenuState::update(InputHandler inputHandler, int interval)
{
  timeBuffer_ += interval;

  if (timeBuffer_ >= 0) {
    if (inputHandler.isKeyPressed(SDL_SCANCODE_RETURN)) {
      if (playButton_.selected) {
        pStateManager_->changeState(PlayState::getInstance(pStateManager_));
      }
      else if (optionsButton_.selected) {
        //TODO Options
      }
      else if (quitButton_.selected) {
        pStateManager_->quit();
      }
    }
  }

  if (timeBuffer_ > 150) {
    if (inputHandler.isKeyPressed(SDL_SCANCODE_W) || inputHandler.isKeyPressed(SDL_SCANCODE_UP)) {
      if (playButton_.selected) {
        playButton_.selected = false;
        quitButton_.selected = true;
      }
      else if (optionsButton_.selected) {
        optionsButton_.selected = false;
        playButton_.selected = true;
      }
      else {  //QuitButton
        quitButton_.selected = false;
        optionsButton_.selected = true;
      }
      timeBuffer_ = 0;
    }

    if (inputHandler.isKeyPressed(SDL_SCANCODE_S) || inputHandler.isKeyPressed(SDL_SCANCODE_DOWN)) {
      if (playButton_.selected) {
        playButton_.selected = false;
        optionsButton_.selected = true;
      }
      else if (optionsButton_.selected) {
        optionsButton_.selected = false;
        quitButton_.selected = true;
      }
      else {  //QuitButton
        quitButton_.selected = false;
        playButton_.selected = true;
      }
      timeBuffer_ = 0;
    }

  }
}

void MenuState::draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  playButton_.draw();
  optionsButton_.draw();
  quitButton_.draw();
}

void MenuState::resize()
{
  glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
