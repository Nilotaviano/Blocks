#pragma once
class Camera
{
public:
  Camera();
  ~Camera();

  void look();

  void moveUp(int interval);
  void moveDown(int interval);
  void moveLeft(int interval);
  void moveRight(int interval);

  void focusUp(int interval);
  void focusDown(int interval);
  void focusLeft(int interval);
  void focusRight(int interval);

private:
  float xPos_, yPos_, zPos_;
  float xFocus_, yFocus_, zFocus_;
  float horizontalAngle_;
};

