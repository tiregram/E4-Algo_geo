#include "myFace.hpp"
#include "myVector3D.hpp"
#include "myHalfedge.hpp"
#include "myVertex.hpp"
#include <GL/glew.h>

myFace::myFace(void)
{
	adjacent_halfedge = NULL;
	normal = std::make_shared<myVector3D>(0,0,1);
}

myFace::~myFace(void){}

void myFace::computeNormal()
{
  auto a =this->adjacent_halfedge->source->point;
  auto b =this->adjacent_halfedge->next->source->point;
  auto c =this->adjacent_halfedge->prev->source->point;

  //myVector3D vect1 = myVector3D(b->X-a->X,b->Y-a->Y,b->Z-a->Z);
  //myVector3D vect2 = myVector3D(c->X-a->X,c->Y-a->Y,c->Z-a->Z);

  this->normal->setNormal(*a,*b,*c);
}
