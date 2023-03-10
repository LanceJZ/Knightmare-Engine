#pragma once
#include "raylib.h"
#include "LineModel.h"

enum GameState
{
	PlayerHit,
	Over,
	InPlay,
	Pause,
	HighScores,
	MainMenu
};

class GameLogic
{

public:
	GameLogic();
	virtual ~GameLogic();

	void Load();
	bool BeginRun();

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw3D();
	virtual void Draw2D();

private:
	LineModel rock1;
	LineModel rock2;
	LineModel rock3;
	LineModel rock4;
};

