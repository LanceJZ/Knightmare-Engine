#pragma once
#include "Entity.h"
#include <vector>
#include <string>

class LineModel : public Entity
{
public:
	Color modelColor = WHITE;
	float Alpha = 255;

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();
	virtual void ChildDraw(Vector3 position, float rotationZ, float scale);
	virtual void AddChild(LineModel* child);

	void Load();
	void LoadModel(string fileName);
	vector <LineModel*> children;
	vector <LineModel*> parents;

	vector<Vector3> GetModel();
	vector<Vector3> lines;
	void SetModel(vector<Vector3> lines);

	LineModel();
	virtual ~LineModel();

private:
	vector<Vector3> ConvertStringToVector(string linesString);
};