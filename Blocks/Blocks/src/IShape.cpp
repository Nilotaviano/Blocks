#include "IShape.h"


IShape::IShape(float xPos, float yPos, float zPos, float width, float height, float depth)
: angle_(0)
{
  xPos_ = xPos;
  yPos_ = yPos;
  zPos_ = zPos;
  width_ = width;
  height_ = height;
  depth_ = depth;
}


IShape::~IShape()
{
}
