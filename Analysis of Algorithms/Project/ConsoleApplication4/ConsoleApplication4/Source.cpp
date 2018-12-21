#include<gl/glut.h>
#include <math.h>

#define PI 3.14159

void setTransformations(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);

}

void dc(){
	glColor3f(0, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (float x = 0; x < 2 * PI; x += 0.01){
		glVertex2f(cos(x), sin(x));
	}
	glEnd();
}
void Draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	dc();
	glFlush();
}
void initialize(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GL_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 400);
	glutCreateWindow("Salma 3beta ^_^");
	glutDisplayFunc(Draw);
	setTransformations();
	glutMainLoop();
}
void main(int argc, char *argv[])
{
	initialize(argc, argv);
}