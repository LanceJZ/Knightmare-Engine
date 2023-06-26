#pragma once
#include <memory>
#include <vector>
#include "Entity.h"
#include "LineModel.h"
#include "Model3D.h"

class EntityManager : Common
{
public:
	EntityManager();
	virtual ~EntityManager();

	bool Initialize();
	bool BeginRun();

	void Input();
	void Update(float deltaTime);
	void Draw();

	size_t AddEntity(std::shared_ptr<Entity> entity);
	size_t AddEntity();
	size_t AddLineModel(std::shared_ptr<LineModel> model);
	size_t AddLineModel(LineModelPoints model);
	size_t AddModel3D(std::shared_ptr<Model3D> model, Camera* camera);
	size_t AddModel3D(Model model, Camera* camera);

	std::shared_ptr<Entity> CreateEntity();
	std::shared_ptr<LineModel> CreateLineModel();
	std::shared_ptr<Model3D> CreateModel3D();

	std::vector<std::shared_ptr<Entity>> Entities;
	std::vector<std::shared_ptr<LineModel>> LineModels;
	std::vector<std::shared_ptr<Model3D>> Model3Ds;

private:
	Camera* TheCamera = {};
};

