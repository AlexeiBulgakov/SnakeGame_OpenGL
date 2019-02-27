#include "stdafx.h"
#include "SnakeGame.h"

using namespace std;

SnakeGame SG;

void Display()
{
	SG.GameDraw();
};


void Reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	SG.GameDraw();
};


void KeyPress(u_char key, int x, int y)
{
	SG.ChangeSD(key);
};


void Timer(int tic)
{
	SG.GameDraw();

	XY x_y = SG.GetSnakeHeadPosition();
	cout << "\nsnake head: (x = " << x_y.X << "; y = " << x_y.Y << ")";
	
	if (int white_time{ MinGS - SG.GetSnakeLenght() }; white_time > MaxGS)
		glutTimerFunc(white_time, Timer, 0);
	else
		glutTimerFunc(MaxGS, Timer, 0);
};


void Init()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, DP_W, 0, DP_H);
};


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);

	srand(time(NULL));

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(DP_W / 4, DP_H / 4);
	glutInitWindowSize(DP_W / 2, DP_H / 2);
	glutCreateWindow("Snake Game");
	
	Init();

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyPress);
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();

	return 0;
};