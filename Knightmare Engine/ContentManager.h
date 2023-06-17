#pragma once
#include "Common.h"
#include <string>

typedef struct LineModelPoints
{
	std::vector<Vector3> linePoints;
} LineModelPoints;

class ContentManager : Common
{
public:
	ContentManager();
	virtual ~ContentManager();

	bool Initialize();
	bool BeginRun();

	int LoadTheModel(std::string modelFileName); //Without path or ext.
	int LoadTheLineModel(std::string modelFileName); //Without path or ext.
	int LoadTheSound(std::string soundFileName); //Without path or ext.
	int LoadTheTexture(std::string textureFileName); //Without path or ext.
	Model& GetModel(int modelNumber);
	Model LoadAndGetModel(std::string modelFileName); //Without path or ext.
	LineModelPoints& GetLineModel(int modelNumber);
	LineModelPoints LoadAndGetLineModel(std::string modelFileName);
	Sound& GetSound(int soundNumber);
	Sound LoadAndGetSound(std::string soundFileName); //Without path or ext.
	Texture& GetTexture(int textureNumber);
	Texture LoadAndGetTexture(std::string textureFileName); //Without path or ext.

private:
	std::vector<Model> LoadedModels;
	std::vector<LineModelPoints> LoadedLineModels;
	std::vector<Sound> LoadedSounds;
	std::vector<Texture> LoadedTextures;
	LineModelPoints ThePoints;

	Model LoadModelWithTexture(std::string modelFileName);
	Model SetTextureToModel(Model model, Texture2D texture);
	Sound LoadSoundFile(std::string soundFileName);
	Texture LoadTextureFile(std::string textureFileName);

	LineModelPoints LoadLineModel(std::string fileName);
	std::vector<Vector3> ConvertStringToPoints(std::string fileName);
};

