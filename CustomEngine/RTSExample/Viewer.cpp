#include "Viewer.h"

Viewer * view = NULL;

void DisplayCallback()
{
	if (view != nullptr)
	{
		view->Display();
	}
}

void ProcessMouseButtonCallback(int x, int y, int a, int b)
{
	if (view != nullptr)
	{
		view->ProcessMouseButton(x, y, a, b);
	}
}

void PassiveMotionFuncCallback(GLFWwindow * window, double x, double y)
{
	if (view != nullptr)
	{
		view->PassiveMotionFunc(window, x, y);
	}
}

void TimerFuncCallback(int val)
{
	if (view != nullptr)
	{
		view->TimerFunc(val);
	}
}

void SpecialFuncCallback(int key, int x, int y)
{
	if (view != nullptr)
	{
		view->SpecialFunc(key, x, y);
	}
}

void SpecialFuncUpCallback(int key, int x, int y)
{
	if (view != nullptr)
	{
		view->SpecialFuncUp(key, x, y);
	}
}

void KeyUpCallback(unsigned char key, int x, int y)
{
	if (view != nullptr)
	{
		if (key >= 'A' && key <= 'Z')
			key = key + 32;

		view->KeyUp(key, x, y);
	}
}

void KeyGlfwCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (view != nullptr)
	{
		

		if (key >= 'A' && key <= 'Z')
			key = key + 32;

		view->KeyGlfw(window, key, scancode, action, mods);
	}
}

void KeyDownCallback(unsigned char key, int x, int y)
{
	if (view != nullptr)
	{
		if (key >= 'A' && key <= 'Z')
			key = key + 32;

		view->KeyDown(key, x, y);
	}
}


Viewer::Viewer()
{
}


Viewer::~Viewer()
{
}

void Viewer::Display()
{
	//cout << "start render" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	ProcessKey();

	if (m_pMainScene != nullptr)
	{
		

		m_pMainScene->SetMouseDelta(mouseAxisXDelta, mouseAxisYDelta);

		m_pMainScene->UpdateInput();

		if (m_pLogicTraverser != nullptr)
		{
			m_pMainScene->Accept(m_pLogicTraverser);
		}

		/*if (mouseLocked)
		{
			warp = true;
			glutWarpPointer(400, 300);
			
		}*/

	

		

		

		if (m_pLightTraverser != nullptr)
		{
			// TODO set render buffer

			for (Light * light : m_pMainScene->m_pLights) // Render to each framebuffer
			{
				m_pMainScene->m_pCurrentLight = light;

				m_pMainScene->Accept(m_pLightTraverser);

				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}

			

		}

		if (m_pRenderTraverser != nullptr)
		{
			m_pMainScene->Accept(m_pRenderTraverser);
		}
	}

	

	glFlush();

	glfwSwapBuffers(m_pWindow);

	end_time = std::chrono::high_resolution_clock::now();

	auto time = end_time - start_time;

	//deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

	//deltaTimeSeconds = deltaTime / 1000.f;

	//int sleepTime = std::max(0, (int)(1000 / 60 - deltaTime));

	//deltaTimeSeconds = std::min(std::max(deltaTimeSeconds, 1.f / 30.f), 1.f);


	//Sleep(sleepTime);

	start_time = std::chrono::high_resolution_clock::now();

	mouseAxisXDelta = 0;
	mouseAxisYDelta = 0;

	//warp = false;

	//cout << "finsih render" << endl;

	glfwPollEvents();
}

void Viewer::ProcessMouseButton(int x, int y, int a, int b)
{

}

void Viewer::ToggleFastForward(Viewer * viewer)
{
	fastForward = !fastForward;
}

void Viewer::ExitF(Viewer * viewer)
{
	viewer->Exit();
}

void Viewer::ToggleMouseLocked(Viewer * viewer)
{
	mouseLocked = !mouseLocked;

	if (mouseLocked)
	{
		glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		mouseAxisX = 400;
		mouseAxisY = 300;
	}
	else
	{
		glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
}


void Viewer::AddObjectToScene(Transformation * obj)
{
	m_pMainScene->AddChild(obj);
}

void Viewer::AddLightToScene(Light * light)
{
	m_pMainScene->AddLight(light);
	m_pMainScene->AddChild(light);
}

void Viewer::KeyDown(unsigned char key, int x, int y)
{
	keyMap[key] = true;

	m_pMainScene->KeyDown(key);
}

void Viewer::KeyGlfw(GLFWwindow * window, int keyI, int scancode, int action, int mods)
{

	unsigned char key = (unsigned char)keyI;

	if (action == GLFW_RELEASE)
	{
		keyMap[key] = false;

		keyMapTap[key] = false;

		m_pMainScene->KeyUp(key);
	}
	else if (action == GLFW_PRESS)
	{
		keyMap[key] = true;

		m_pMainScene->KeyDown(key);
	}
}

void Viewer::KeyUp(unsigned char key, int x, int y)
{
	keyMap[key] = false;

	keyMapTap[key] = false;

	m_pMainScene->KeyUp(key);
}

void Viewer::SpecialFunc(int key, int x, int y)
{
	//fastForward = glutGetModifiers() & GLUT_ACTIVE_SHIFT;
}

void Viewer::SpecialFuncUp(int key, int x, int y)
{
	//fastForward = glutGetModifiers() & GLUT_ACTIVE_SHIFT;
}

void Viewer::TimerFunc(int val)
{
	//glutTimerFunc(33, ::TimerFuncCallback, 0);
	//glutPostRedisplay();
}

void Viewer::PassiveMotionFunc(GLFWwindow * window, double x, double y)
{

	mouseAxisX = x;
	mouseAxisY = 600 - y;

	mouseAxisXDelta = mouseAxisX - mouseAxisXPre;
	mouseAxisYDelta = mouseAxisY - mouseAxisYPre;

	mouseAxisXPre = mouseAxisX;
	mouseAxisYPre = mouseAxisY;

	// update mouse position
	m_pMainScene->SetMousePosition(mouseAxisX, mouseAxisY);
	

	
}

void Viewer::Exit()
{
	exit(1);
}

void Viewer::InitKeyMap()
{
	for (unsigned char letter = 0; letter < 255; letter++)
	{
		keyMap[letter] = false;
	}
}

void Viewer::ProcessKey()
{
	for (std::map<unsigned char, bool>::iterator it = keyMap.begin(); it != keyMap.end(); it++)
	{
		unsigned char key = (*it).first;

		if (keyMap[key])
		{
			if (keyFunctionMap.find(key) != keyFunctionMap.end())
			{
				for (auto func : keyFunctionMap[key])
				{
					std::function<void(Viewer*)> function = func.first;
					KeyInputType inputType = func.second;

					if (inputType == KeyInputType::Hold || (inputType == KeyInputType::Tap && !keyMapTap[key]))
						function(this);

					keyMapTap[key] = true; // key is down, won't call function again until key released
				}
			}
		}
	}
}

void Viewer::Start()
{
	mouseAxisX = 400;
	mouseAxisY = 300;


	while (!glfwWindowShouldClose(m_pWindow))
	{
		::DisplayCallback();
	}

}

void Viewer::SetMainCamera(Camera * cam)
{
	m_pMainScene->SetMainCamera(cam);
}

void Viewer::InitViewer(int argc, char ** argv)
{
	Randomizer::Init();

	if (!glfwInit())
	{
		return;
	}


	int width, height;

	width = 800;
	height = 600;

	deltaTimeSeconds = 0.03;

	m_pWindow = glfwCreateWindow(width, height, "Kwox", NULL, NULL);

	glfwMakeContextCurrent(m_pWindow);

	glfwSwapInterval(1);


	view = this;

	glfwSetCursorPosCallback(m_pWindow, ::PassiveMotionFuncCallback);
	glfwSetKeyCallback(m_pWindow, ::KeyGlfwCallback);

	//glutMouseFunc(::ProcessMouseButtonCallback);
	
	//glutSpecialFunc(::SpecialFuncCallback);
	//glutSpecialUpFunc(::SpecialFuncUpCallback);
	//glutTimerFunc(33, ::TimerFuncCallback, 0);
	//glutReshapeFunc(ReshapeWindow);

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		cerr << "Failed to initialize glew" << endl;
		exit(-1);
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glDepthFunc(GL_LESS);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//glEnable(GL_CULL_FACE);
	glViewport(0, 0, width, height);


	InitKeyMap();

	BindFunctionToKey(32, std::bind(&Viewer::ToggleMouseLocked, this, this), KeyInputType::Tap);
	BindFunctionToKey(0, std::bind(&Viewer::ExitF, this, this), KeyInputType::Tap);


	m_pRenderTraverser = new RenderTraverser();
	m_pLightTraverser = new LightTraverser();
	m_pLogicTraverser = new LogicTraverser();

	Renderer * renderer = new Renderer();

	m_pLightTraverser->m_pRenderer = m_pRenderTraverser->m_pRenderer = m_pLogicTraverser->m_pRenderer = renderer;

	m_pMainScene = new Scene();
}

void Viewer::BindFunctionToKey(unsigned char key, std::function<void(Viewer*)> func,  KeyInputType inputType)
{
	keyFunctionMap[key].push_back(std::make_pair(func, inputType));
}
