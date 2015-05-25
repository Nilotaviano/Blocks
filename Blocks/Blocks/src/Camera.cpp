#include "Camera.h"

#include <math.h>

#include <SDL_opengl.h>
#include <GL\GLU.h>

Camera::Camera()
{
  horizontalAngle_ = 0;
  xPos_ = 0;
  yPos_ = 0;
  zPos_ = 5;
  xFocus_ = sin(horizontalAngle_);
  yFocus_ = 0;
  zFocus_ = -cos(horizontalAngle_);
}

Camera::~Camera()
{
}

void Camera::look()
{
  gluLookAt(xPos_, yPos_, zPos_,
    xPos_ + xFocus_, yPos_ + yFocus_, zPos_ + zFocus_,
    0, 1, 0); // positive Y up vector
}

void Camera::moveUp(int interval)
{
  xPos_ += xFocus_ * 0.01f * interval;
  zPos_ += zFocus_ * 0.01f * interval;
}

void Camera::moveDown(int interval)
{
  xPos_ -= xFocus_ * 0.01f * interval;
  zPos_ -= zFocus_ * 0.01f * interval;
}

void Camera::moveLeft(int interval)
{
  xPos_ += zFocus_ * 0.01f * interval;
  zPos_ -= xFocus_ * 0.01f * interval;
}

void Camera::moveRight(int interval)
{
  xPos_ -= zFocus_ * 0.01f * interval;
  zPos_ += xFocus_ * 0.01f * interval;
}

void Camera::focusUp(int interval)
{
  if (yFocus_ < 1) {
    yFocus_ += 0.0025f * interval;
  }
}

void Camera::focusDown(int interval)
{
  if (yFocus_ > -1) {
    yFocus_ -= 0.0025f * interval;
  }
}

void Camera::focusLeft(int interval)
{
  horizontalAngle_ -= 0.0025f * interval;
  xFocus_ = sin(horizontalAngle_);
  zFocus_ = -cos(horizontalAngle_);
}

void Camera::focusRight(int interval)
{
  horizontalAngle_ += 0.0025f * interval;
  xFocus_ = sin(horizontalAngle_);
  zFocus_ = -cos(horizontalAngle_);
}
