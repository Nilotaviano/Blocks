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

  void inputUp() { xAngle_ -= 0.45f; }
  void inputDown() { xAngle_ += 0.45f; }
  void inputLeft() { yAngle_ -= 0.45f; }
  void inputRight() { yAngle_ += 0.45f; }
};