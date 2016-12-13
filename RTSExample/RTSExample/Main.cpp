#include "ShaderClass.h"

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	int width, height;

	width = 800;
	height = 600;

	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGBA);

	glutCreateWindow("Trainer");

	/*init(width, height);

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMouseFunc(processMouseButton);
	glutKeyboardUpFunc(processKey);
	glutReshapeFunc(reshapeWindow);*/

	glewInit();



	glutMainLoop();
}

