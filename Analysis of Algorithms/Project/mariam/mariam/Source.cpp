#include <iostream>
#include <gl/glut.h>
#include <math.h>

using namespace std;

void setTranformations();
void draw();
void drawRectangle();
void drawAxis();

void intialize(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 400);
	glutCreateWindow("Exam");
	glutDisplayFunc(draw);

	setTranformations();
	glutMainLoop();
}

void setTransformations(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	drawRectangle();
	glFlush();
}

void drawAxis(){
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_LINES);
	glVertex2f(-100, 0);
	glVertex2f(100, 0);
	glVertex2f(0, -100);
	glVertex2f(0, 100);
	glEnd();
	glFlush();
}
void drawRectangle(){
	glColor3f(5.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_QUADS);
	glVertex2f(30, 30);
	glVertex2f(30, 60);
	glVertex2f(60, 60);
	glVertex2f(60, 30);
	glEnd();
	glFlush();

}

int main(int argc, char *argv[]){
	intialize(argc, argv);
	return 0;
}