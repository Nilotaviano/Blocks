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
  float size = 1.0;
  glRotatef(angle_, 1.0, 1.0, 1.0);   // angle, x-axis, y-axis, z-axis

  glBegin(GL_QUADS);
  // front face
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(size / 2, size / 2, size / 2);
  glVertex3f(-size / 2, size / 2, size / 2);
  glVertex3f(-size / 2, -size / 2, size / 2);
  glVertex3f(size / 2, -size / 2, size / 2);
  // left face
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(-size / 2, size / 2, size / 2);
  glVertex3f(-size / 2, -size / 2, size / 2);
  glVertex3f(-size / 2, -size / 2, -size / 2);
  glVertex3f(-size / 2, size / 2, -size / 2);
  // back face
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(size / 2, size / 2, -size / 2);
  glVertex3f(-size / 2, size / 2, -size / 2);
  glVertex3f(-size / 2, -size / 2, -size / 2);
  glVertex3f(size / 2, -size / 2, -size / 2);
  // right face
  glColor3f(1.0, 1.0, 0.0);
  glVertex3f(size / 2, size / 2, size / 2);
  glVertex3f(size / 2, -size / 2, size / 2);
  glVertex3f(size / 2, -size / 2, -size / 2);
  glVertex3f(size / 2, size / 2, -size / 2);
  // top face
  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(size / 2, size / 2, size / 2);
  glVertex3f(-size / 2, size / 2, size / 2);
  glVertex3f(-size / 2, size / 2, -size / 2);
  glVertex3f(size / 2, size / 2, -size / 2);
  // bottom face
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(size / 2, -size / 2, size / 2);
  glVertex3f(-size / 2, -size / 2, size / 2);
  glVertex3f(-size / 2, -size / 2, -size / 2);
  glVertex3f(size / 2, -size / 2, -size / 2);
  glEnd();
}

void Cube::update()
{
  angle_ += 0.1f;
}
