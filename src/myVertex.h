#pragma once

#include "myPoint3D.h"

class myHalfedge;
class myVector3D;

class myVertex
{
public:
	myPoint3D *point;
	myHalfedge *originof;

	int index;  //use as you wish.

	myVector3D *normal;

  myPoint3D overageNeib();
	void computeNormal();
	myVertex(void);
	~myVertex(void);
};
