#pragma once
#include "InputHandler.h"
#include "GameState.h"
#include "StateManager.h"

class PlayState : 
	public GameState
{
public:
	~PlayState();
	void update(InputHandler inputHandler, int interval);
	void draw();
	static PlayState* getInstance(StateManager* pManager);
  void enterState();

protected:
	PlayState(StateManager* pManager);
private:

};

