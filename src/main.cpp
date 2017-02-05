
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GL/freeglut.h>


#include "myPoint3D.hpp"
#include "myVector3D.hpp"
#include "myFace.hpp"
#include "myMesh.hpp"
#include "helperFunctions.hpp"

#include "GlobalVar.hpp"

int main(int argc, char* argv[])
{
	initInterface(argc, argv);

	initMesh();

	glutMainLoop();

	return 0;
}
