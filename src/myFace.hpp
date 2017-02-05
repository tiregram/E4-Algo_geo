#pragma once
#include <memory>

class myHalfedge;
class myVector3D;

class myFace
{
public:
	myHalfedge *adjacent_halfedge;

  std::shared_ptr<myVector3D> normal;

	int index; //use this variable as you wish.

	void computeNormal();
	myFace(void);
	~myFace(void);
};
