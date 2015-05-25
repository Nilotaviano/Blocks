#include "Cube.h"

#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <random>


Cube::Cube(float xPos, float yPos, float zPos, float width, float height, float depth)
: IShape(xPos, yPos, zPos, width, height, depth)
{

}

Cube::Cube(float xPos, float yPos, float zPos, float width, float height, float depth, float xAngle, float yAngle, float zAngle)
: IShape(xPos, yPos, zPos, width, height, depth, xAngle, yAngle, zAngle)
{

}

Cube::Cube(float xPos, float yPos, float zPos,
           float width, float height, float depth,
           float xAngle, float yAngle, float zAngle,
           float xRotationRatio, float yRotationRatio, float zRotationRatio)
 : IShape(xPos, yPos, zPos,
          width, height, depth,
          xAngle, yAngle, zAngle,
          xRotationRatio, yRotationRatio, zRotationRatio)
{

}

Cube::~Cube()
{
}

void Cube::draw()
{
  glPushMatrix();

  glTranslatef(xPos_, yPos_, zPos_);
  glRotatef(xAngle_, 1.0, 0.0, 0.0);
  glRotatef(yAngle_, 0.0, 1.0, 0.0);
  glScalef(width_, height_, depth_);

  glBegin(GL_QUADS);
  // front face
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(0.5, 0.5, 0.5);
  glVertex3f(-0.5, 0.5, 0.5);
  glVertex3f(-0.5, -0.5, 0.5);
  glVertex3f(0.5, -0.5, 0.5);
  // back face
  glVertex3f(0.5, 0.5, -0.5);
  glVertex3f(-0.5, 0.5, -0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(0.5, -0.5, -0.5);
  // left face
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(-0.5, 0.5, 0.5);
  glVertex3f(-0.5, -0.5, 0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(-0.5, 0.5, -0.5);
  // right face
  glVertex3f(0.5, 0.5, 0.5);
  glVertex3f(0.5, -0.5, 0.5);
  glVertex3f(0.5, -0.5, -0.5);
  glVertex3f(0.5, 0.5, -0.5);
  // top face
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.5, 0.5, 0.5);
  glVertex3f(-0.5, 0.5, 0.5);
  glVertex3f(-0.5, 0.5, -0.5);
  glVertex3f(0.5, 0.5, -0.5);
  // bottom face
  glVertex3f(0.5, -0.5, 0.5);
  glVertex3f(-0.5, -0.5, 0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(0.5, -0.5, -0.5);
  glEnd();

  glPopMatrix();
}

void Cube::update(int interval)
{
  xAngle_ += xRotationRatio_ * interval;
  yAngle_ += yRotationRatio_ * interval;
  zAngle_ += zRotationRatio_ * interval;
}