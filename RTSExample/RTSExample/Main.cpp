#include "RenderTraverser.h"
#include "RenderState.h"
#include "Core.h"
#include "Scene.h"
#include "Geometry.h"

RenderTraverser * m_pRenderTraverser = nullptr;

Scene * m_pMainScene = nullptr;


GameObject * object0 = nullptr;
GameObject * object1 = nullptr;

bool keyPressedW = false;
bool keyPressedA = false;
bool keyPressedS = false;
bool keyPressedD = false;

std::map<unsigned char, bool> keyMap;

std::map<unsigned char, void(*) ()> keyFuncMap;

std::map<unsigned char, void(*) (int)> mouseFuncMap;

std::chrono::time_point < std::chrono::steady_clock> start_time, end_time;

INT64 deltaTime = 0;

float deltaTimeSeconds = 0.f;

float mouseAxisX = 0, mouseAxisY = 0;
float mouseAxisXPre = 0, mouseAxisYPre = 0;
float mouseAxisXDelta = 0, mouseAxisYDelta = 0;

float cameraYaw = 0;


void ProcessMouseButton(int x, int y, int a, int b)
{

}

void PassiveMotionFunc(int x, int y)
{
	mouseAxisX = x ;
	mouseAxisY = 600 - y;

	cout << x << ", " << y << endl;
}

void MoveForward()
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	if (camera)
	{
		camera->Move(camera->GetForwardVector()  * deltaTimeSeconds);
	}
}

void MoveBackwards()
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	if (camera)
	{
		camera->Move(-camera->GetForwardVector()  * deltaTimeSeconds);
	}
}

void MoveUp()
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	if (camera)
	{
		camera->Move(camera->GetUpVector()  * deltaTimeSeconds);
	}
}

void MoveDown()
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	if (camera)
	{
		camera->Move(-camera->GetUpVector()  * deltaTimeSeconds);
	}
}

void MoveLeft()
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	if (camera)
	{
		camera->Move(-camera->GetRightVector() * deltaTimeSeconds);
	}
}

void MoveRight()
{
	Camera * camera = m_pMainScene->m_pMainCamera;

	if (camera)
	{
		camera->Move(camera->GetRightVector() * deltaTimeSeconds);
	}
}

void KeyDown(unsigned char key, int x, int y)
{
	keyMap[key] = true;
}

void KeyUp(unsigned char key, int x, int y)
{
	keyMap[key] = false;
}

void InitKeyMap()
{
	for (unsigned char letter = 'a'; letter <= 'z'; letter++)
	{
		keyMap[letter] = false;
	}
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}

void Exit()
{
	exit(1);
}

void ProcessKey()
{
	for (std::map<unsigned char, bool>::iterator it = keyMap.begin(); it != keyMap.end(); it++)
	{
		unsigned char key = (*it).first;

		if (keyMap[key])
		{
			if (keyFuncMap.find(key) != keyFuncMap.end())
				keyFuncMap[key]();
		}
	}


	
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	ProcessKey();

	mouseAxisXDelta = mouseAxisX - 400;
	mouseAxisYDelta = mouseAxisY - 300;

	if (m_pMainScene->m_pMainCamera)
	{
		//m_pMainScene->m_pMainCamera->Rotate(-mouseAxisXDelta * 0.005f, mouseAxisYDelta * 0.005f);

		m_pMainScene->m_pMainCamera->Rotate(-mouseAxisXDelta * deltaTimeSeconds, mouseAxisYDelta * deltaTimeSeconds);
	}

	if (m_pMainScene != nullptr && m_pRenderTraverser != nullptr)
	{
		m_pMainScene->UpdateInput();
	}

	if (m_pMainScene != nullptr && m_pRenderTraverser != nullptr)
	{
		m_pMainScene->Accept(m_pRenderTraverser);
	}

	glFlush();
	glFinish();

	end_time = std::chrono::high_resolution_clock::now();

	auto time = end_time - start_time;

	deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

	deltaTimeSeconds = deltaTime / 1000.f;

	int sleepTime = std::max(0, (int) (1000 / 60 - deltaTime));

	glutWarpPointer(400, 300);

	Sleep(sleepTime);

	start_time = std::chrono::high_resolution_clock::now();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	int width, height;

	width = 800;
	height = 600;

	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGBA);

	glutCreateWindow("Kwox");

	
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(ProcessMouseButton);
	glutPassiveMotionFunc(PassiveMotionFunc);
	glutKeyboardUpFunc(KeyUp);
	glutKeyboardFunc(KeyDown);
	glutReshapeFunc(ReshapeWindow);

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

	keyFuncMap['a'] = &MoveLeft;
	keyFuncMap['d'] = &MoveRight;

	keyFuncMap['w'] = &MoveForward;
	keyFuncMap['s'] = &MoveBackwards;

	keyFuncMap['q'] = &MoveDown;
	keyFuncMap['e'] = &MoveUp;

	keyFuncMap[27] = &Exit;

	m_pRenderTraverser = new RenderTraverser();

	m_pRenderTraverser->m_pRenderer = new Renderer();

	m_pMainScene = new Scene();

	Camera * mainCamera = new Camera();
	mainCamera->LookAt(glm::vec3(0, 0, 30), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
	mainCamera->CreateProjection(45.f, (float)width / (float)height, 0.1f, 1000.f);
	 
	m_pMainScene->SetMainCamera(mainCamera);

	object0 = new GameObject();

	m_pMainScene->AddChild(object0->m_transformation);

	object1 = new GameObject();

	object0->m_transformation->AddChild(object1->m_transformation);
	//object0->AddInput('w', &GameObject::MoveForward);

	object1->AddTranslation(glm::vec3(5.f, 10.f, 0.f));


	ShaderCore * sCore = new ShaderCore(); 
	sCore->GenerateShader("./glsl/default.vert", "", "./glsl/default.frag");
	GeometryCore * gCore = Geometry::CreatePlane(20.f, 10.f); 
	
	object0->AddCore(sCore);
	object0->AddCore(gCore);

	object1->AddCore(sCore);
	object1->AddCore(gCore);

	glutWarpPointer(400, 300);

	start_time = std::chrono::high_resolution_clock::now();

	glutMainLoop();
}

