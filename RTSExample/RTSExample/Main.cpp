#include "RenderTraverser.h"
#include "RenderState.h"
#include "Core.h"
#include "Scene.h"
#include "Geometry.h"

RenderTraverser * m_pRenderTraverser;

Scene * m_pMainScene;

void ProcessMouseButton(int x, int y, int a, int b)
{

}

void ProcessKey(unsigned char key, int x, int y)
{

}

void ReshapeWindow(int width, int height)
{

}

void Display()
{
	m_pMainScene->Accept(m_pRenderTraverser->m_pRenderer);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	int width, height;

	width = 800;
	height = 600;

	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGBA);

	glutCreateWindow("Trainer");

	//init(width, height);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(ProcessMouseButton);
	glutKeyboardUpFunc(ProcessKey);
	glutReshapeFunc(ReshapeWindow);

	glewInit();

	m_pRenderTraverser = new RenderTraverser();

	m_pRenderTraverser->m_pRenderer = new Renderer();

	m_pMainScene = new Scene();

	Camera * mainCamera = new Camera();
	mainCamera->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));
	mainCamera->CreateProjection(90.f, (float)width / (float)height, 0.1f, 100.f);

	m_pMainScene->SetMainCamera(mainCamera);

	Object * transformation0 = new Object();

	m_pMainScene->AddChild(transformation0);

	ShaderCore * sCore = new ShaderCore();
	sCore->GenerateShader("vertex.glsl", "", "fragment.glsl");
	GeometryCore * gCore = Geometry::CreatePlane(10.f, 10.f);

	transformation0->AddCore(sCore);
	transformation0->AddCore(gCore);

	glutMainLoop();
}

