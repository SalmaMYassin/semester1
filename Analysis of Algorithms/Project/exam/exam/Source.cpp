#include <iostream>
#include <math.h>
#include <gl/glut.h>
using namespace std;

#define PI 3.14159

void c();
void draw();
void drawTriangle();
void drawAxis();
void SpKeys(int k, int x, int y);
void setTransformations();
//void drawCircleOutlined();
//void drawSinWave();
void drawRectangle();
//void KB(unsigned char key, int x, int y);
//void drawCircle();
void mouseclick(int key, int state, int x, int y);
void timer(int x);
int angle = 1;
int tri = 1;
bool flag = false;

void initialize(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 400);
	glutCreateWindow("Computer Graphics Lab 2");
	glutDisplayFunc(draw);
	/*glutKeyboardFunc(KB);*/
	glutMouseFunc(mouseclick);
	glutTimerFunc(1000, timer, 0);
	glutSpecialFunc(SpKeys);
	setTransformations();
	glutMainLoop();
}

void setTransformations()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	drawRectangle();
	drawTriangle();
	glFlush();
}

void timer(int x){
	if (flag){
		glClear(GL_COLOR_BUFFER_BIT);
		drawAxis();
		angle++;;
		tri--;

		glPushMatrix();

		glTranslated(35, 35, 0);
		glRotated(angle, 0, 0, 1);
		glTranslated(-35, -35, 0);

		drawRectangle();


		glPopMatrix();

		glPushMatrix();

		glTranslated(35, 35, 0);
		glRotated(tri, 0, 0, 1);
		glTranslated(-35, -35, 0);
		drawTriangle();


		glPopMatrix();

	}

	glFlush();
	glutTimerFunc(100, timer, 0);
}
void SpKeys(int k, int x, int y){
	if (k == GLUT_KEY_F1){
		flag = true;
	}
}
void mouseclick(int key, int state, int x, int y){
	x = x / 4 - 100;
	y = 100 - y / 2;

	if (key == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if (x <= -20 && x >= -50 && y <= -20 && y >= -50){
			glColor3f(0.0, 0.0, 0.0);
			glPointSize(5);
			glBegin(GL_POINTS);
			glVertex2f(x, y);
			glEnd();
			glFlush();

		}
	}
}

//void KB(unsigned char key, int x, int y){
// switch (key){
// case '1':
// glClear(GL_COLOR_BUFFER_BIT);
// drawAxis();
// drawTriangle();
// glFlush();
// break;
// case '2':
// glClear(GL_COLOR_BUFFER_BIT);
// drawAxis();
// drawCircleOutlined();
// glFlush();
// break;
// case'3':
// glClear(GL_COLOR_BUFFER_BIT);
// drawAxis();
// drawCircle();
// glFlush();
// break;
// case '4':
// glClear(GL_COLOR_BUFFER_BIT);
// drawAxis();
// drawRectangle();
// glFlush();
// break;
// case '5':
// glClear(GL_COLOR_BUFFER_BIT);
// drawAxis();
// drawSinWave();
// glFlush();
// break;
// default:
// glClear(GL_COLOR_BUFFER_BIT);
// drawAxis();
// glFlush();
// break;
// }
//}

//void drawCircleOutlined(){
// glColor3f(5.5, 0.0, 0.0);
// glPointSize(1);
//
// /*glBegin(GL_TRIANGLE_FAN);*/
	// glBegin(GL_POINTS);
	// for (double x = 0; x < 2 * PI; x += 0.01){
	//
	// glVertex2f(20 * cos(x), 20 * sin(x));
	//
	// }
	// glEnd();
// /*glVertex3f(0, 5, 0.0);
// glVertex3f(60, 10, 0.0);
// glVertex3f(60, 20, 0.0);*/
// /*glVertex3f(60, 60, 0.0);
// glVertex3f(10, 60, 0.0);
// glVertex3f(0.0, 30, 0.0);*/
// /*for (double x = 30; x < 100; x += 10){
// double y = x + 10;
// /* glVertex3f(x, y, 0);
// }*/
// /*glEnd();*/
//}

//void drawCircle(){
// glColor3f(0.0, 0.0, 0.0);
// glPointSize(10);
//
// glBegin(GL_TRIANGLE_FAN);
// for (double x = 0; x < 2 * PI; x += 0.01){
//
// glVertex2f(20 * cos(x), 20 * sin(x));
//
// }
// glEnd();
//
//}

void drawAxis(){
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_LINES);
	glVertex2f(-100, 0);
	glVertex2f(100, 0);
	glVertex2f(0, 100);
	glVertex2f(0, -100);
	glEnd();
}

void drawTriangle(){
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_TRIANGLES);

	glVertex2f(20, 50); //drawing triangle (3 vertixes)
	glVertex2f(35, 70);
	glVertex2f(50, 50);

	glVertex2f(50, 20); //drawing triangle (3 vertixes)
	glVertex2f(50, 50);
	glVertex2f(70, 35);

	glVertex2f(20, 20); //drawing triangle (3 vertixes)
	glVertex2f(50, 20);
	glVertex2f(35, 0);

	glVertex2f(0, 35); //drawing triangle (3 vertixes)
	glVertex2f(20, 50);
	glVertex2f(20, 20);

	glEnd();
}

//void drawSinWave(){
// glColor3f(0.0, 0.0, 0.0);
// glPointSize(1);
// glBegin(GL_POINTS);
// for (double x = -5; x < 2 * PI; x += 0.01){
//
// glVertex2f(5 * x, 5 * sin(x));
//
// }
// glEnd();
//}

void drawRectangle(){
	glColor3f(5.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_QUADS);
	glVertex2f(20, 20);
	glVertex2f(20, 50);
	glVertex2f(50, 50);
	glVertex2f(50, 20);
	glEnd();
}

int main(int argc, char *argv[]){
	initialize(argc, argv);
	return 0;
}