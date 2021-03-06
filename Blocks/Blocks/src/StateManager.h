﻿#pragma once

#include "GameState.h"

class StateManager
{
public:
	StateManager(bool* quit);
	~StateManager();

	void update(InputHandler inputHandler, int interval);
	void draw();
  void resize();
	void changeState(GameState* pNewState);
	void quit();
	GameState* getActiveState() { return pActiveState_; }
private:
	GameState* pActiveState_;
	bool* quit_;
};