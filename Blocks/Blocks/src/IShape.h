#pragma once
class IShape
{
public:
  IShape(float xPos, float yPos, float zPos, float width, float height, float depth);
  virtual ~IShape();

  virtual void draw() {}
  virtual void update() {}

  virtual void inputUp() {}
  virtual void inputDown() {}
  virtual void inputLeft() {}
  virtual void inputRight() {}

protected:
  float xPos_, yPos_, zPos_;
  float width_, height_, depth_;
  float xAngle_, yAngle_;
};