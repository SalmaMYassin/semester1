#include <iostream>
#include <gl/glut.h>
#include <math.h>

using namespace std;

void setTransformations();
void draw();
void drawAxis();
void Bresenham(int x1, int y1, int x2, int y2);
void setPixel(int x, int y);
void KB(unsigned char key, int x, int y);
void drawCircle();
void drawSinWave();
void drawInnerCircles();
void drawYingYang();
void drawTriangle();

#define PI 3.14159

void initialize(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 400);
	glutCreateWindow("Computer Graphics - Assignment 1");
	glutDisplayFunc(draw);
	glutKeyboardFunc(KB);
	setTransformations();
	glutMainLoop();
}

void setTransformations()
{
	glClearColor(0.4, 0.7, 0.5, 1.0); // Set foreground color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void setPixel(int x, int y){
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}	

void Bresenham(int x1, int y1, int x2, int y2){
	int x = x1, y = y1;
	int dx = x2 - x1, dy = y2 - y1, dT = 2 * (dy - dx), dS = 2 * dy;
	int d = (2 * dy) - dx;
	setPixel(x, y);
	while (x < x2){
		x++;
		if (d < 0)
			d = d + dS;
		else{
			y++;
			d = d + dT;
		}
		setPixel(x, y);
	}
}


void KB(unsigned char key, int x, int y){
	switch (key){
		case '1':
			glClear(GL_COLOR_BUFFER_BIT);
			drawAxis();
			Bresenham(10, 10, 70, 70);
			glFlush();
			break;

		case '2':
			glClear(GL_COLOR_BUFFER_BIT);
			drawAxis();
			Bresenham(-10, 10, -70, 70);
			glFlush();
		 break;

		case '3':
			glClear(GL_COLOR_BUFFER_BIT);
			drawAxis();
			Bresenham(-10, -10, -70, -70);
			glFlush();
			break;

		case '4':
			glClear(GL_COLOR_BUFFER_BIT);
			drawAxis();
			Bresenham(10, -10, 70, -70);
			glFlush();
			break;
	
		default:
			glClear(GL_COLOR_BUFFER_BIT);
			drawAxis();
			glFlush();
			break;
	 }
}

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

void drawCircle(){
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_TRIANGLE_FAN);
	for (double x = 0 ; x < PI; x += 0.01){
		glVertex2f(50* cos(x), 25 * sin(x));
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	
	for (double x = PI; x < 2 *PI; x += 0.01){
		glVertex2f(50 * cos(x),25 * sin(x));
	}

	glEnd();


}
void drawInnerCircles(){
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_TRIANGLE_FAN);
	for (double x = 0; x < 2 * PI; x += 0.01){
		glVertex2f(3.5* cos(x), 7 * sin(x) + 25);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	for (double x = 0; x < 2 * PI; x += 0.01){
		glVertex2f(3.5 * cos(x), 7 * sin(x) - 25);
	}
	glEnd();
}

void drawSinWave(){
	glColor3f(1, 1, 1);
	glPointSize(1);	
	glBegin(GL_TRIANGLE_FAN);

	for (double x = 0; x <  PI; x += 0.01){
		float i = 3.35 *sin(x);
		glVertex2f(15* i, 9 *sin(i));
	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (double x = PI; x < 2 * PI; x += 0.01){
		float i = 3.35 *sin(x);
		glVertex2f(15 * i, 8 * sin(i));
	}
	glEnd();
}

void drawYingYang(){
	glPushMatrix();
	glRotated(90, 0, 0, 1);
	drawCircle();
	glPopMatrix();

	glPushMatrix();
	glRotated(91.8, 0, 0, 1);
	drawSinWave();
	glPopMatrix();

	drawInnerCircles();
}

void drawTriangle(){
	glColor3f(1, 1, 1);
	glPointSize(10);
	glBegin(GL_LINE_LOOP);

	glVertex2f(-20, 0); //drawing triangle (3 vertixes)
	glVertex2f(0, 60);
	glVertex2f(20, 0);
	glEnd();
}

void draw(){
	
	glColor3f(0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	/*drawYingYang();*/
	///*A) perform a 70 degree rotation of the triangle about the point P(0,-3)*/
	//glPushMatrix();
	//
	//glTranslated(0, -30,0);
	//glRotated(70, 0, 0, 1);
	//glTranslated(0, -30, 0);
	//
	//drawTriangle();
	//glPopMatrix();
	
	/*D) Reflect the triangle about the line given by y = 4x + 6*/
	glPushMatrix();
	
	glTranslated(0, 60, 0);
	glRotated(atan(4) * 180 / PI, 0, 0, 1);
	glScalef(1, -1, 1);
	glRotated(-(atan(4) * 180 / PI), 0, 0, 1);
	glTranslated(0, -60, 0);
	cout << atan(4) * 180 / PI;
	drawTriangle();
	glPopMatrix();

	glColor3f(4, 0, 0);
	drawTriangle();
	glColor3f(4, 0, 4);
	glBegin(GL_LINES);
	glVertex2d(10, 100);
	glVertex2d(-30, -60);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]){
	initialize(argc, argv);
	return 0;
}
