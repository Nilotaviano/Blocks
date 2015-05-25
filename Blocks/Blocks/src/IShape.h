#pragma once
class IShape
{
public:
  IShape(float xPos, float yPos, float zPos, float width, float height, float depth);
  IShape(float xPos, float yPos, float zPos, float width, float height, float depth, float xAngle, float yAngle, float zAngle);
  virtual ~IShape();

  virtual void draw() {}
  virtual void update(int interval) {}

  virtual void inputUp() {}
  virtual void inputDown() {}
  virtual void inputLeft() {}
  virtual void inputRight() {}

protected:
  float xPos_, yPos_, zPos_;
  float width_, height_, depth_;
  float xAngle_, yAngle_, zAngle_;
};