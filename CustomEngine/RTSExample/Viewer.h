#include "RenderTraverser.h"
#include "LogicTraverser.h"
#include "LightTraverser.h"
#include "RenderState.h"
#include "Core.h"
#include "Scene.h"
#include "Geometry.h"
#include "Light.h"
#include <functional>

#pragma once
class Viewer
{
public:

	enum KeyInputType { Tap, Hold };

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

	void AddLightToScene(Light * light);

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

	void BindFunctionToKey(unsigned char key, std::function<void(Viewer*)>, KeyInputType inputType);

	


private:

	bool keyPressedW = false;
	bool keyPressedA = false;
	bool keyPressedS = false;
	bool keyPressedD = false;

	bool fastForward = false;

	const float moveSpeed = 0.1f;

	bool mouseLocked = false;

	std::map<unsigned char, bool> keyMap;
	std::map<unsigned char, bool> keyMapTap; // key, active

	std::map<unsigned char, std::vector<std::pair<std::function<void(Viewer*)>, KeyInputType>>> keyFunctionMap;

	std::map<unsigned char, void(*) (int)> mouseFuncMap;

	std::chrono::time_point < std::chrono::steady_clock> start_time, end_time;

	INT64 deltaTime = 0;

	float deltaTimeSeconds = 0.f;

	float mouseAxisX = 0;
	float mouseAxisY = 0;
	float mouseAxisXPre = 0, mouseAxisYPre = 0;
	float mouseAxisXDelta = 0, mouseAxisYDelta = 0;

	float lookSpeed = 0.2f;

	RenderTraverser * m_pRenderTraverser = nullptr;
	LogicTraverser * m_pLogicTraverser = nullptr;
	LightTraverser * m_pLightTraverser = nullptr;

	Scene * m_pMainScene = nullptr;
};

