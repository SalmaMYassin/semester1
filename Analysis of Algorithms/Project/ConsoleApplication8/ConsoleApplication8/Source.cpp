#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
/*
1) Draw a quad / or know point of starting
2) give coords of starting point of text
3) Specify color of text
drawBitmapText(string input, int x, int y, int z){ //z is always 0
glRasterPos3f(x,y,z);
for(int i = 0; i < input.length(); i++){
glutBitmapCharacter(Glut_BITMAP_Times_Roman_24, input[i]); //FontType_size, arr
}
}
4)Keyboard function --> after entry of each num --> glPostRedisplay();
5)Mouse function --> on button click --> glPostRedisplay();
6) string to double --> double r = stod(str);
7) C to F --> (val * 1.8 + 32)
8) F to C --> (val -32) / 1.8;
*/
#include<Windows.h>
#include <gl/glut.h>
#include<iostream>
#include<string>
using namespace std;
int width = 800, height = 600;
string str = "";
string res = "";
void drawBitmapText(string input, int x, int y, int z){
	glRasterPos3f(x, y, z);
	for (int i = 0; i < input.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, input[i]);
	}
}
string C_F(string val){
	double r = stod(val);
	r = (r * 1.8 + 32.0);
	return to_string(r);
}
string F_C(string val){
	double r = stod(val);
	r = (r - 32.0) / 1.8;
	return to_string(r);
}
void KeyEvent(unsigned char key, int x, int y){
	switch (key){
	case '0': str += "0"; break;
	case '1': str += "1"; break;
	case '2': str += "2"; break;
	case '3': str += "3"; break;
	case '4': str += "4"; break;
	case '5': str += "5"; break;
	case '6': str += "6"; break;
	case '7': str += "7"; break;
	case '8': str += "8"; break;
	case '9': str += "9"; break;
	}
	//glFlush();
	glutPostRedisplay();
}
void mouseEvent(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		x = (x / 4) - 100; //4 --> 800 window size / 100 --> cartesian
		y = 100 - (y / 3); //3 --> 600 window size / 100 --> cartesian
		if ((x > -30 && x < -10) && (y > 20 && y < 40)){
			res = C_F(str);
		}
		if ((x > 10 && x < 30) && (y > 20 && y < 40)){
			res = F_C(str);
		}
	}
	//glFlush();
	str = "0";
	glutPostRedisplay();
}
void drawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	glBegin(GL_QUADS);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glVertex2d(x3, y3);
	glVertex2d(x4, y4);
	glEnd();
}
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);

	//First text box
	glColor3f(0.3, 0.4, 0.5);
	drawQuad(-30, 50, -30, 70, 30, 70, 30, 50);
	
	//Buttons
	glColor3f(1.0, 0.0, 0.0);
	drawQuad(-30, 20, -30, 40, -10, 40, -10, 20);

	glColor3f(0.0, 0.0, 0.0);
	drawBitmapText("C to F", -28, 30, 0);
	
	glColor3f(0.0, 1.0, 0.0);
	drawQuad(10, 20, 10, 40, 30, 40, 30, 20);
	
	glColor3f(0.0, 0.0, 0.0);
	drawBitmapText("F to C", 12, 30, 0);
	
	//Second text box
	glColor3f(0.3, 0.4, 0.5);
	drawQuad(-30, -10, -30, 10, 30, 10, 30, -10);
	glColor3f(1.0, 1.0, 1.0);
	drawBitmapText(str, -30, 60, 0);
	glColor3f(1.0, 1.0, 1.0);
	drawBitmapText(res, -30, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	drawBitmapText(res, -30, 0, 0);
	glFlush();
}
void setTransformations(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}
void initialize(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Weather converter");
	glutDisplayFunc(draw);
	glutKeyboardFunc(KeyEvent);
	glutMouseFunc(mouseEvent);
	setTransformations();
	glutMainLoop();
}
void main(int argc, char *argv[]){
	initialize(argc, argv);
}
