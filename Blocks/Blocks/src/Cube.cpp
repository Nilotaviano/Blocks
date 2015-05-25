#include "Cube.h"

#include <SDL_opengl.h>
#include <GL\GLU.h>


Cube::Cube(float xPos, float yPos, float zPos, float width, float height, float depth)
: IShape(xPos, yPos, zPos, width, height, depth)
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
  // left face
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(-0.5, 0.5, 0.5);
  glVertex3f(-0.5, -0.5, 0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(-0.5, 0.5, -0.5);
  // back face
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(0.5, 0.5, -0.5);
  glVertex3f(-0.5, 0.5, -0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(0.5, -0.5, -0.5);
  // right face
  glColor3f(0.0, 1.0, 0.0);
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
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.5, -0.5, 0.5);
  glVertex3f(-0.5, -0.5, 0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(0.5, -0.5, -0.5);
  glEnd();

  glPopMatrix();
}

void Cube::update()
{
  
}