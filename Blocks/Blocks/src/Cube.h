#pragma once
#include "IShape.h"
class Cube :
  public IShape
{
public:
  Cube(float xPos, float yPos, float zPos, float width, float height, float depth);
  ~Cube();

  void draw();
  void update();
};

