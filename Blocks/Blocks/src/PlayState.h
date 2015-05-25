#pragma once
#include "InputHandler.h"
#include "GameState.h"
#include "StateManager.h"
#include "IShape.h"
#include "Camera.h"

#include <list>

class PlayState : 
	public GameState
{
public:
	~PlayState();
	void update(InputHandler inputHandler, int interval);
	void draw();
	static PlayState* getInstance(StateManager* pManager);
  void enterState();
  void resize();

protected:
	PlayState(StateManager* pManager);
private:
  std::list<IShape*> p_shapes_;
  Camera camera;
};

