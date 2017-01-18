#include "myVertex.h"
#include "myVector3D.h"
#include "myHalfedge.h"
#include "myFace.h"
#include <vector>
#include <iostream>

myVertex::myVertex(void)
{
	point = NULL;
	originof = NULL;
	normal = new myVector3D(1.0,1.0,1.0);
}

myVertex::~myVertex(void)
{
	if (normal) delete normal;
}

void myVertex::computeNormal()
{

  myHalfedge* first = this->originof;

  *(this->normal) = *(this->originof->adjacent_face->normal);

  int count = 0;
  for(myHalfedge* f = this->originof->twin->next;
        f != first;
        f = f->twin->next )
      {
               *(this->normal) = *(this->normal) + *(f->adjacent_face->normal);
      }


    this->normal->normalize();
}

myPoint3D myVertex::overageNeib()
{

  myHalfedge* first = this->originof;

  int count = 1;
  myPoint3D ret = *this->originof->twin->source->point;


  for(myHalfedge* f = this->originof->twin->next;
      f != first;
      f = f->twin->next )
    {
      count++;
      ret = ret + *f->twin->source->point;
    }

  ret =  ret / count;

  return ret;
}
