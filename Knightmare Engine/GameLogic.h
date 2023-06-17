#pragma once
#include "raylib.h"
#include "LineModel.h"
#include "ContentManager.h"

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

	void Initialize();
	void Load();
	bool BeginRun();

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw3D();
	virtual void Draw2D();

private:
	LineModel Sun;
	LineModel Earth;
	LineModel MoonSat;
	LineModel Moon;

	ContentManager Content;
};

