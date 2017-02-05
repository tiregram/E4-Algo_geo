#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "myPoint3D.hpp"
#include "myVector3D.hpp"
#include "myMesh.hpp"
#include "GlobalVar.hpp"

// shaders
GLuint initshaders(GLenum type, const char *filename);
GLuint initprogram(GLuint, GLuint);

// OPENGL 
void makeBuffers(myMesh *input_mesh);
void programerrors(const GLint program);
void shadererrors(const GLint shader);
std::string textFileRead(const char * filename);
void initMesh();
void clear();

// MATH
myVector3D * constructRay(int x, int y);
bool PickedPoint(int x, int y);

// display
void menu(int item);
void initInterface(int argc, char* argv[]);
void draw_text(GLfloat x, GLfloat y, GLfloat z, std::string text, std::vector<GLfloat> color);
void display();

// input
void idle();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y) ;
void mouse(int button, int state, int x, int y);
void mousedrag(int x, int y);
void mouseWheel(int button, int dir, int x, int y);
void keyboard2(int key, int x, int y);

std::pair<double,double> ligneClosest(const myPoint3D&  a, const myVector3D& u, const myPoint3D& b, const myVector3D& v);


