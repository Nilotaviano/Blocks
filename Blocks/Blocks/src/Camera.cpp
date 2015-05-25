#include "Camera.h"

#include <SDL_opengl.h>
#include <GL\GLU.h>


Camera::Camera()
{
  xPos_ = 0;
  yPos_ = 0;
  zPos_ = 5;
  xFocus_ = 0;
  yFocus_ = 0;
  zFocus_ = 0;
}


Camera::~Camera()
{
}

void Camera::look()
{
  gluLookAt(xPos_, yPos_, zPos_,
    xFocus_, yFocus_, zFocus_,
    0, 1, 0); // positive Y up vector
}
