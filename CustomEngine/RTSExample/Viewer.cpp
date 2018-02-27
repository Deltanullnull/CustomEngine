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

void PassiveMotionFuncCallback(int x, int y)
{
	if (view != nullptr)
	{
		view->PassiveMotionFunc(x, y);
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	ProcessKey();

	if (m_pMainScene != nullptr)
	{
		

		m_pMainScene->UpdateInput();

		if (m_pLogicTraverser != nullptr)
		{
			m_pMainScene->Accept(m_pLogicTraverser);
		}

		

		if (m_pMainScene->m_pMainCamera && mouseLocked)
		{
			//m_pMainScene->m_pMainCamera->Rotate(-mouseAxisXDelta * deltaTimeSeconds * lookSpeed, mouseAxisYDelta * deltaTimeSeconds* lookSpeed);

			glutWarpPointer(400, 300);
		}

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
	glFinish();

	end_time = std::chrono::high_resolution_clock::now();

	auto time = end_time - start_time;

	deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

	deltaTimeSeconds = deltaTime / 1000.f;

	int sleepTime = std::max(0, (int)(1000 / 60 - deltaTime));

	deltaTimeSeconds = std::min(std::max(deltaTimeSeconds, 1.f / 30.f), 1.f);


	Sleep(sleepTime);

	start_time = std::chrono::high_resolution_clock::now();
}

void Viewer::ProcessMouseButton(int x, int y, int a, int b)
{

}

void Viewer::ToggleFastForward(Viewer * viewer)
{
	fastForward = !fastForward;
}

void Viewer::MoveForward(Viewer * viewer)
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	float speed = fastForward ? moveSpeed * 2.0 : moveSpeed;

	if (camera)
	{
		//camera->Move(camera->GetForwardVector()  * deltaTimeSeconds * speed);
	}
}

void Viewer::MoveBackwards(Viewer * viewer)
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	float speed = fastForward ? moveSpeed * 2.0 : moveSpeed;

	if (camera)
	{
		//camera->Move(-camera->GetForwardVector()  * deltaTimeSeconds* speed);
	}
}

void Viewer::MoveUp(Viewer * viewer)
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	float speed = fastForward ? moveSpeed * 2.0 : moveSpeed;

	if (camera)
	{
		//camera->Move(camera->GetUpVector()  * deltaTimeSeconds* speed);
	}
}

void Viewer::MoveDown(Viewer * viewer)
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	float speed = fastForward ? moveSpeed * 2.0 : moveSpeed;

	if (camera)
	{
		//camera->Move(-camera->GetUpVector()  * deltaTimeSeconds* speed);
	}
}

void Viewer::MoveLeft(Viewer * viewer)
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	float speed = fastForward ? moveSpeed * 2.0 : moveSpeed;

	if (camera)
	{
		//camera->Move(-camera->GetRightVector() * deltaTimeSeconds* speed);
	}
}

void Viewer::MoveRight(Viewer * viewer)
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	float speed = fastForward ? moveSpeed * 2.0 : moveSpeed;

	if (camera)
	{
		//camera->Move(camera->GetRightVector() * deltaTimeSeconds * speed);
	}
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
		mouseAxisX = 400;
		mouseAxisY = 300;
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

void Viewer::KeyUp(unsigned char key, int x, int y)
{
	keyMap[key] = false;

	keyMapTap[key] = false;

	m_pMainScene->KeyUp(key);
}

void Viewer::SpecialFunc(int key, int x, int y)
{
	fastForward = glutGetModifiers() & GLUT_ACTIVE_SHIFT;
}

void Viewer::SpecialFuncUp(int key, int x, int y)
{
	fastForward = glutGetModifiers() & GLUT_ACTIVE_SHIFT;
}

void Viewer::PassiveMotionFunc(int x, int y)
{
	mouseAxisX = x;
	mouseAxisY = 600 - y;

	mouseAxisXDelta = mouseAxisX - mouseAxisXPre;
	mouseAxisYDelta = mouseAxisY - mouseAxisYPre;

	mouseAxisXPre = mouseAxisX;
	mouseAxisYPre = mouseAxisY;


	//cout << "Mouse: " << mouseAxisX << ", " << mouseAxisY << endl;
	
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
	glutWarpPointer(400, 300);

	glutMainLoop();
}

void Viewer::SetMainCamera(Camera * cam)
{
	m_pMainScene->SetMainCamera(cam);
}

void Viewer::InitViewer(int argc, char ** argv)
{
	Randomizer::Init();

	glutInit(&argc, argv);

	int width, height;

	width = 800;
	height = 600;

	deltaTimeSeconds = 0.03;

	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGBA);

	glutCreateWindow("Kwox");

	view = this;
	glutDisplayFunc(::DisplayCallback);
	glutIdleFunc(::DisplayCallback);
	glutMouseFunc(::ProcessMouseButtonCallback);
	glutPassiveMotionFunc(::PassiveMotionFuncCallback);
	glutKeyboardUpFunc(::KeyUpCallback);
	glutKeyboardFunc(::KeyDownCallback);
	glutSpecialFunc(::SpecialFuncCallback);
	glutSpecialUpFunc(::SpecialFuncUpCallback);
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

	BindFunctionToKey('a', std::bind(&Viewer::MoveLeft, this, this), KeyInputType::Hold);
	BindFunctionToKey('d', std::bind(&Viewer::MoveRight, this, this), KeyInputType::Hold);

	BindFunctionToKey('w', std::bind(&Viewer::MoveForward, this, this), KeyInputType::Hold);
	BindFunctionToKey('s', std::bind(&Viewer::MoveBackwards, this, this), KeyInputType::Hold);

	BindFunctionToKey('q', std::bind(&Viewer::MoveDown, this, this), KeyInputType::Hold);
	BindFunctionToKey('e', std::bind(&Viewer::MoveUp, this, this), KeyInputType::Hold);

	BindFunctionToKey(32, std::bind(&Viewer::ToggleMouseLocked, this, this), KeyInputType::Tap);
	BindFunctionToKey(27, std::bind(&Viewer::ExitF, this, this), KeyInputType::Tap);


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
