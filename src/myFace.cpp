#include "myFace.h"
#include "myVector3D.h"
#include "myHalfedge.h"
#include "myVertex.h"
#include <GL/glew.h>

myFace::myFace(void)
{
	adjacent_halfedge = NULL;
	normal = new myVector3D(0,0,1);
}

myFace::~myFace(void)
{
	if (normal) delete normal;
}

void myFace::computeNormal()
{
  myPoint3D *a =this->adjacent_halfedge->source->point;
  myPoint3D *b =this->adjacent_halfedge->next->source->point;
  myPoint3D *c =this->adjacent_halfedge->prev->source->point;

  //myVector3D vect1 = myVector3D(b->X-a->X,b->Y-a->Y,b->Z-a->Z);
  //myVector3D vect2 = myVector3D(c->X-a->X,c->Y-a->Y,c->Z-a->Z);

  this->normal->setNormal(a,b,c);
}
