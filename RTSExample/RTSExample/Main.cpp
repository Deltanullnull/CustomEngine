#include "RenderTraverser.h"
#include "RenderState.h"
#include "Core.h"

RenderState * m_pRenderState;
RenderTraverser * m_pRenderTraverser;

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

	m_pRenderState = new RenderState();
	m_pRenderTraverser = new RenderTraverser();

	glutMainLoop();
}

