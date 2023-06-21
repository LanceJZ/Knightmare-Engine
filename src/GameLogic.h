#pragma once
#include <memory>
#include "raylib.h"
#include "LineModel.h"
#include "ContentManager.h"
#include "EntityManager.h"
#include "Rock.h"

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
	std::shared_ptr<Rock> Sun;
	std::shared_ptr<LineModel> Earth;
	std::shared_ptr<LineModel> Moon;
	std::shared_ptr<LineModel> MoonSat;

	ContentManager Content;
	EntityManager Entities;
};