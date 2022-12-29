#include "LineModel.h"
#include "rlgl.h"

void LineModel::Input()
{

}

void LineModel::Update(float deltaTime)
{
	Entity::Update(deltaTime);

	modelColor.a = (char)Alpha;
}

void LineModel::Draw()
{
	if (!Enabled)
	{
		return;
	}

	if (lines.size() < 2)
	{
		return;
	}

	if (!isChild)
	{
		rlPushMatrix();
		rlTranslatef(Position.x, Position.y, 0);
		rlRotatef(RotationZ * (float)(180.0f/PI), 0, 0, 1);
		rlScalef(Scale, Scale, Scale);

		for (int i = 0; i < lines.size() - 1; i = i + 2)
		{
			DrawLine3D(lines[i], lines[i + 1], modelColor);
		}

		rlPopMatrix();
	}

	if (isParent)
	{
		for (auto child : children)
		{
			child->ChildDraw(Position, RotationZ, Scale);
		}
	}

	Entity::Draw();
}

void LineModel::ChildDraw(Vector3 position, float rotationZ, float scale)
{
	rlPushMatrix();
	rlTranslatef(position.x, position.y, 0);
	rlRotatef(rotationZ * (float)(180.0f/PI), 0, 0, 1);
	rlPushMatrix();
	rlTranslatef(Position.x, Position.y, 0);
	rlRotatef(RotationZ * (float)(180.0f/PI), 0, 0, 1);
	rlScalef(scale, scale, scale);

	for (int i = 0; i < lines.size() - 1; i = i + 2)
	{
		DrawLine3D(lines[i], lines[i + 1], modelColor);
	}

	rlPopMatrix();
	rlPopMatrix();
}

void LineModel::AddChild(LineModel* child)
{
	children.push_back(child);
	child->isChild = true;
	isParent = true;
}

void LineModel::Load()
{

}

void LineModel::LoadModel(string fileName)
{
	if (FileExists(const_cast<char*>(fileName.c_str())))
	{
		string linestemp = LoadFileText(const_cast<char*>(fileName.c_str()));
		lines = ConvertStringToVector(linestemp);
	}
}

vector<Vector3> LineModel::GetModel()
{
	return lines;
}

void LineModel::SetModel(vector<Vector3> lines)
{
	LineModel::lines = lines;
}

LineModel::LineModel()
{

}

LineModel::~LineModel()
{
}

vector<Vector3> LineModel::ConvertStringToVector(string linesString)
{
	vector<Vector3> linesConverted;
	bool isNumber = false;
	float x = 0;
	float y = 0;
	float z = 0;
	string number;
	string onAxis;
	Vector3 line = { 0 };

	for (auto character : linesString)
	{
		if (character > 44 && character < 58)
		{
			number.append(1, character);
		}
		else
		{
			if (character == 88)
			{
				onAxis = "X";
			}
			else if (character == 89)
			{
				onAxis = "Y";

				line.x = stof(number);
				number = "";
			}
			else if (character == 90)
			{
				onAxis = "Z";

				line.y = stof(number);
				number = "";
			}
			else if (character == 125)
			{
				line.z = stof(number);
				number = "";

				linesConverted.push_back(line);
			}
		}
	}

	return linesConverted;
}
