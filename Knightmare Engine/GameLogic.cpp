#include "GameLogic.h"

GameLogic::GameLogic()
{
}

GameLogic::~GameLogic()
{
}

void GameLogic::Initialize()
{
	Sun.Initialize();
	Earth.Initialize();
	Moon.Initialize();
	MoonSat.Initialize();
}

void GameLogic::Load()
{
	Sun.SetModel(Content.LoadAndGetLineModel("RockOne"));
	Earth.SetModel(Content.LoadAndGetLineModel("RockTwo"));
	Moon.SetModel(Content.LoadAndGetLineModel("RockFour"));
	MoonSat.SetModel(Content.LoadAndGetLineModel("RockThree"));
}

bool GameLogic::BeginRun()
{
	Sun.Position = { -200.0f, -150.0f, 0 };
	Earth.Position = { 100.5f, 120.5f, 0 };
	Moon.Position = { -40.5f, -40.5f, 0 };
	MoonSat.Position = { 10.5f, -20.5f, 0 };
	Sun.Scale = 20.0f;
	Earth.Scale = 8.5f;
	Moon.Scale = 4.4f;
	MoonSat.Scale = 2.25f;

	Sun.AddChild(&Earth);
	Earth.AddChild(&Moon);
	Moon.AddChild(&MoonSat);

	Sun.Velocity.y = 5.75f;
	Sun.Velocity.x = 2.5f;
	Sun.RotationVelocity = 0.1f;
	Earth.RotationVelocity = 0.5f;
	Moon.RotationVelocity = 0.15f;
	MoonSat.RotationVelocity = -7.2f;

	return false;
}

void GameLogic::Input()
{

}

void GameLogic::Update(float deltaTime)
{
	Sun.Update(deltaTime);
	Earth.Update(deltaTime);
	MoonSat.Update(deltaTime);
	Moon.Update(deltaTime);

	Sun.CheckScreenEdge();
}

void GameLogic::Draw3D()
{
	Sun.Draw();
	Earth.Draw();
	MoonSat.Draw();
	Moon.Draw();
}

void GameLogic::Draw2D()
{

}
