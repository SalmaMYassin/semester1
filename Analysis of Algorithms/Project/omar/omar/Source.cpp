#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<Windows.h>
#include <gl/glut.h>
#include<iostream>
#include<string>
using namespace std;
int width = 800, height = 600;
string str = "";
string res = "";
bool flag = false;

GLuint LoadTexture(const char* fileName, int wrap){
	FILE * file = fopen(fileName, "r");
	if (file == NULL)
		return 0;
	int width = 256, height = 256;
	BYTE * data = (byte*)malloc(width*height * 3);
	fread(data, width*height * 3, 1, file);
	fclose(file);
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_TEXTURE_2D);
	return texture;
}

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

	if (flag){
		str = "";
		flag = false;
	}
		
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
		if ((x > -30 && x < 30) && (y > 20 && y < 40)){ 
			res = C_F(str);
		}
		if ((x > -30 && x < 30) && (y > -10 && y < 10)){ 
			res = F_C(str);
		}
	}
	//glFlush();
	str = res;
	flag = true;
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
	glColor3f(1.0, 1.0, 1.0);
	drawQuad(-30, 50, -30, 70, 30, 70, 30, 50);

	//Buttons
	glColor3f(0.3, 0.4, 0.5);
	drawQuad(-30, 20, -30, 40, 30, 40, 30, 20);

	glColor3f(0.0, 0.0, 0.0);
	drawBitmapText("C to F", -8, 30, 0);

	glColor3f(0.3, 0.4, 0.5);
	drawQuad(-30, -10, -30, 10, 30, 10, 30, -10);

	glColor3f(0.0, 0.0, 0.0);
	drawBitmapText("F to C", -8, 0, 0);

	//Number display
	glColor3f(0.0, 0.0, 0.0);
	drawBitmapText(str, -8, 60, 0);

	////Logo
	//GLuint logo = LoadTexture("logo.bmp", 0);
	//glBindTexture(GL_TEXTURE_2D, logo);
	//drawQuad(-10, -50, -10, -20, 10, -20, 10, -50);
	//
	glFlush();
}
void setTransformations(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
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
