#include "InputHandler.h"
#include <stdio.h>

#include "Game.h"


InputHandler::InputHandler(bool* quit, std::function<void()> resize_function)
: p_quit_(quit),
p_resize_function_(resize_function)
{
  for (int i = 0; i < KEYBOARD_SIZE; i++) {
    keys_[i] = false;
  }
}

InputHandler::~InputHandler(void)
{
}

void InputHandler::handleInput(SDL_Event event)
{
  switch (event.type)
  {
  case SDL_KEYUP:
  case SDL_KEYDOWN:
    handleKeyboard(event.key);
    break;
  case SDL_WINDOWEVENT:
    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
      p_resize_function_();
    }
    break;
  case SDL_MOUSEMOTION:
    break;
  case SDL_QUIT:
    *p_quit_ = true;
    break;
  default:
    printf("Unhandled Event: %i\n", event.type);
    break;
  }
}

void InputHandler::handleKeyboard(SDL_KeyboardEvent kbEvent)
{

  switch (kbEvent.type){
  case SDL_KEYUP:
    keys_[kbEvent.keysym.scancode] = false;
    break;
  case SDL_KEYDOWN:
    keys_[kbEvent.keysym.scancode] = true;
    break;
  }
}

bool InputHandler::isKeyPressed(SDL_Keycode key)
{
  if (key < KEYBOARD_SIZE) {
    return keys_[key];
  }
  else {
    return false;
  }
}