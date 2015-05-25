#pragma once
class Camera
{
public:
  Camera();
  ~Camera();

  void look();

private:
  float xPos_, yPos_, zPos_;
  float xFocus_, yFocus_, zFocus_;
};

