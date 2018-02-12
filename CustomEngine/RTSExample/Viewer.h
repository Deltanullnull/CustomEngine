#include "RenderTraverser.h"
#include "LogicTraverser.h"
#include "RenderState.h"
#include "Core.h"
#include "Scene.h"
#include "Geometry.h"
#include <functional>

#pragma once
class Viewer
{
public:
	Viewer();
	~Viewer();

	void Display();

	void ProcessMouseButton(int x, int y, int a, int b);

	void ToggleFastForward(Viewer * viewer);

	void MoveForward(Viewer * viewer);

	void MoveBackwards(Viewer * viewer);

	void MoveUp(Viewer * viewer);

	void MoveDown(Viewer * viewer);

	void MoveLeft(Viewer * viewer);

	void MoveRight(Viewer * viewer);

	void ExitF(Viewer * viewer);

	void ToggleMouseLocked(Viewer * viewer);

	void AddObjectToScene(GameObject * obj);

	void CreateSampleObject();

	void KeyDown(unsigned char key, int x, int y);

	void KeyUp(unsigned char key, int x, int y);

	void SpecialFunc(int key, int x, int y);

	void SpecialFuncUp(int key, int x, int y);


	void PassiveMotionFunc(int x, int y);

	void Exit();

	void InitKeyMap();

	void ProcessKey();

	void Start();

	void InitViewer(int argc, char ** argv);

	void BindFunctionToKey(unsigned char key, std::function<void(Viewer*)>);

	std::map<unsigned char, std::vector<std::function<void(Viewer*)>>> keyFu;


private:

	bool keyPressedW = false;
	bool keyPressedA = false;
	bool keyPressedS = false;
	bool keyPressedD = false;

	bool fastForward = false;

	const float moveSpeed = 0.1f;

	bool mouseLocked = true;

	std::map<unsigned char, bool> keyMap;

	
	std::map<unsigned char, void(*) ()> keyFuncMap;

	std::map<unsigned char, void(*) (int)> mouseFuncMap;

	std::chrono::time_point < std::chrono::steady_clock> start_time, end_time;

	INT64 deltaTime = 0;

	float deltaTimeSeconds = 0.f;

	float mouseAxisX = 0;
	float mouseAxisY = 0;
	float mouseAxisXPre = 0, mouseAxisYPre = 0;
	float mouseAxisXDelta = 0, mouseAxisYDelta = 0;

	float cameraYaw = 0;

	RenderTraverser * m_pRenderTraverser = nullptr;
	LogicTraverser * m_pLogicTraverser = nullptr;

	Scene * m_pMainScene = nullptr;
};

