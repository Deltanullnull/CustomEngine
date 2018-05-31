#include "RenderTraverser.h"
#include "LogicTraverser.h"
#include "LightTraverser.h"
#include "RenderState.h"
#include "Core.h"
#include "Scene.h"
#include "Geometry.h"
#include "ObjectFactory.h"
#include "Texture.h"
#include "Light.h"
#include "Skybox.h"
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

	void ExitF(Viewer * viewer);

	void ToggleMouseLocked(Viewer * viewer);

	void AddObjectToScene(Transformation * obj);

	void AddLightToScene(Light * light);

	void KeyDown(unsigned char key, int x, int y);

	void KeyGlfw(GLFWwindow * window, int key, int scancode, int action, int mods);

	void KeyUp(unsigned char key, int x, int y);

	void SpecialFunc(int key, int x, int y);

	void SpecialFuncUp(int key, int x, int y);

	void TimerFunc(int val);


	void PassiveMotionFunc(GLFWwindow * window, double x, double y);

	void Exit();

	void InitKeyMap();

	void ProcessKey();

	void Start();

	void SetMainCamera(Camera * cam);

	void InitViewer(int argc, char ** argv);

	void BindFunctionToKey(unsigned char key, std::function<void(Viewer*)>, KeyInputType inputType);

	


private:

	bool fastForward = false;

	bool warp = false;

	const float moveSpeed = 0.1f;

	bool mouseLocked = false;

	std::map<unsigned char, bool> keyMap;
	std::map<unsigned char, bool> keyMapTap; // key, active

	std::map<unsigned char, std::vector<std::pair<std::function<void(Viewer*)>, KeyInputType>>> keyFunctionMap;

	std::chrono::time_point < std::chrono::steady_clock> start_time, end_time;

	//INT64 deltaTime = 0;

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

	GLFWwindow * m_pWindow;
};

