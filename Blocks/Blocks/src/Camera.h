#pragma once
class Camera
{
public:
  Camera();
  ~Camera();

  void look();

  void move_up(int interval);
  void move_down(int interval);
  void move_left(int interval);
  void move_right(int interval);

  void focus_up(int interval);
  void focus_down(int interval);
  void focus_left(int interval);
  void focus_right(int interval);

private:
  float xPos_, yPos_, zPos_;
  float xFocus_, yFocus_, zFocus_;
  float horizontalAngle_;
};

