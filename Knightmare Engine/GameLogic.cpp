#include "GameLogic.h"

GameLogic::GameLogic()
{

}

GameLogic::~GameLogic()
{
}

void GameLogic::Load()
{
	rock1.LoadModel("Models/RockOne.vec");
	rock2.LoadModel("Models/RockTwo.vec");
	rock3.LoadModel("Models/RockThree.vec");
}

bool GameLogic::BeginRun()
{
	rock2.Position = { 2.5f, 2.5f, 0 };
	rock3.Position = { 2.5f, -2.5f, 0 };

	rock1.AddChild(&rock2);
	rock2.AddChild(&rock3);

	rock1.Velocity.x = 0.5f;
	rock1.Velocity.y = 0.75f;
	rock1.RotationVelocity.z = 0.1f;

	return false;
}

void GameLogic::Input()
{

}

void GameLogic::Update(float deltaTime)
{
	rock1.Update(deltaTime);
	rock2.Update(deltaTime);
	rock3.Update(deltaTime);
}

void GameLogic::Draw3D()
{
	rock1.Draw();
	rock2.Draw();
	rock3.Draw();
}

void GameLogic::Draw2D()
{

}
