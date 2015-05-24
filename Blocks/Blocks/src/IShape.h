#pragma once
class IShape
{
public:
  IShape(float xPos, float yPos, float zPos, float width, float height, float depth);
  virtual ~IShape();

  virtual void draw() {}
  virtual void update() {}

protected:
  float xPos_, yPos_, zPos_;
  float width_, height_, depth_;
  float angle_;
};

