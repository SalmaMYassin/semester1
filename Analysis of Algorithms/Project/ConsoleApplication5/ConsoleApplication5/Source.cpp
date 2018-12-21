#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <gl/glut.h>
#define PI  3.14159
#include <cmath>
#include <fstream>
#include <cstdint>
using namespace std;

int width = 800;
int height = 600;

GLuint LoadTextureRaw(const char * filename, int wrap)
{
	GLuint texture;
	int width, height;
	unsigned char * data;
	FILE * file;

	file = fopen(filename, "r");

	if (file == NULL)
	{
		return 0;
	}

	width = 256;
	height = 256;

	data = (unsigned char *)malloc(width * height * 3);
	fread(data, width*height * 3, 1, file);
	fclose(file);
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

void drawCube(){
	GLuint text;

	text = LoadTextureRaw("board", 0);

	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2i(10, 10);

}
void draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void setTransformations()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (width / height), 1, 100);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -3, 2, 0, 0, 0, 0, 1, 0);
	glOrtho(0, width, 0, height, 0, 100);
}


void initialize(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(width, height);
	glutCreateWindow("Assignment 2");
	glutDisplayFunc(draw);
	//glutKeyboardFunc(KB);
	//glutTimerFunc(100, timer, 0);
	setTransformations();
	glutMainLoop();
}

int main(int argc, char*argv[])
{
	initialize(argc, argv);
}