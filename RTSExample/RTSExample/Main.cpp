#include "Model.h"

Model * model0;
Renderer * renderer;

void processMouseButton(int x, int y, int a, int b)
{

}

void processKey(unsigned char key, int x, int y)
{

}

void reshapeWindow(int width, int height)
{

}

void display()
{
	model0->render(renderer);
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

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMouseFunc(processMouseButton);
	glutKeyboardUpFunc(processKey);
	glutReshapeFunc(reshapeWindow);

	glewInit();

	renderer = new Renderer();

	glutMainLoop();
}

