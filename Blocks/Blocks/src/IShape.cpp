#include "IShape.h"


IShape::IShape(float xPos, float yPos, float zPos, float width, float height, float depth)
{
  xPos_ = xPos;
  yPos_ = yPos;
  zPos_ = zPos;
  width_ = width;
  height_ = height;
  depth_ = depth;
  xAngle_ = 0;
  yAngle_ = 0;
}

IShape::IShape(float xPos, float yPos, float zPos, float width, float height, float depth, float xAngle, float yAngle, float zAngle)
{
  xPos_ = xPos;
  yPos_ = yPos;
  zPos_ = zPos;
  width_ = width;
  height_ = height;
  depth_ = depth;
  xAngle_ = xAngle;
  yAngle_ = yAngle;
  zAngle_ = zAngle;
}


IShape::~IShape()
{
}
