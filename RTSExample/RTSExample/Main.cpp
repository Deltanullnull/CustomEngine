#include "RenderTraverser.h"
#include "RenderState.h"
#include "Core.h"
#include "Scene.h"
#include "Geometry.h"

RenderTraverser * m_pRenderTraverser = nullptr;

Scene * m_pMainScene = nullptr;


GameObject * object0 = nullptr;

void ProcessMouseButton(int x, int y, int a, int b)
{

}

void ProcessKey(unsigned char key, int x, int y)
{

}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);


}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	object0->AddTranslation(glm::vec3(-0.01f, 0.f, 0.f));

	//m_pMainScene->m_pMainCamera->Move(glm::vec3(0.01f, 0, 0));

	if (m_pMainScene != nullptr && m_pRenderTraverser != nullptr)
		m_pMainScene->Accept(m_pRenderTraverser->m_pRenderer);

	glFlush();
	glFinish();
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
	glutKeyboardUpFunc(ProcessKey);
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

	glEnable(GL_CULL_FACE);
	glViewport(0, 0, width, height);

	m_pRenderTraverser = new RenderTraverser();

	m_pRenderTraverser->m_pRenderer = new Renderer();

	m_pMainScene = new Scene();

	Camera * mainCamera = new Camera();
	mainCamera->LookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
	mainCamera->CreateProjection(90.f, (float)width / (float)height, 0.1f, 100.f);
	 
	m_pMainScene->SetMainCamera(mainCamera);

	object0 = new GameObject();

	m_pMainScene->AddChild(object0);


	ShaderCore * sCore = new ShaderCore(); 
	sCore->GenerateShader("./glsl/default.vert", "", "./glsl/default.frag");
	GeometryCore * gCore = Geometry::CreatePlane(20.f, 10.f); 
	
	object0->AddCore(sCore);
	object0->AddCore(gCore);

	glutMainLoop();
}

