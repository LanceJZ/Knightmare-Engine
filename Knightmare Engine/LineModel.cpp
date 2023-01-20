#include "LineModel.h"
#include "rlgl.h"

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

	rlPushMatrix();

	if (isChild)
	{
		for (auto parent : parents)
		{
			rlTranslatef(parent->Position.x, parent->Position.y, 0);
			rlRotatef(parent->RotationZ * (float)(180.0f / PI), 0, 0, 1);
		}
	}

	rlTranslatef(Position.x, Position.y, 0);
	rlRotatef(RotationZ * (float)(180.0f / PI), 0, 0, 1);
	rlScalef(Scale, Scale, Scale);
	rlBegin(RL_LINES);
	rlColor4ub(modelColor.r, modelColor.g, modelColor.b, modelColor.a);

	for (int i = 0; i < lines.size() - 1; i++)
	{
		rlVertex3f(lines[i].x, lines[i].y, lines[i].z);
		rlVertex3f(lines[i + 1].x, lines[i + 1].y, lines[i + 1].z);
	}

	rlEnd();
	rlPopMatrix();
}

void LineModel::AddChild(LineModel* child)
{

	for (auto parent : parents)
	{
		parent->AddChildren(child);
	}

	children.push_back(child);
	child->parents.push_back(this);
	child->isChild = true;
	isParent = true;
}

void LineModel::AddChildren(LineModel* child)
{
	child->parents.push_back(this);
	isParent = true;
	child->isChild = true;
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

void LineModel::DrawLines(vector <Vector3> points, Vector3 rotationAxis, Color color)
{
	if (points.size() >= 2)
	{
		//if (rlCheckBufferLimit(pointsCount)) rlglDraw();

		rlPushMatrix();
		rlTranslatef(Position.x, Position.y, 0);
		rlRotatef(RotationZ * (float)(180.0f / PI), rotationAxis.x, rotationAxis.y, rotationAxis.z);
		rlBegin(RL_LINES);
		rlColor4ub(color.r, color.g, color.b, color.a);

		for (int i = 0; i < points.size() - 1; i++)
		{
			rlVertex3f(points[i].x, points[i].y, points[i].z);
			rlVertex3f(points[i + 1].x, points[i + 1].y, points[i + 1].z);
		}

		rlEnd();
		rlPopMatrix();
	}
}

void LineModel::DrawLines(Color color)
{
	rlBegin(RL_LINES);
	rlColor4ub(color.r, color.g, color.b, color.a);

	for (int i = 0; i < lines.size() - 1; i++)
	{
		rlVertex3f(lines[i].x, lines[i].y, lines[i].z);
		rlVertex3f(lines[i + 1].x, lines[i + 1].y, lines[i + 1].z);
	}

	rlEnd();
}
