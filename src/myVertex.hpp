#pragma once



#include <memory>

class myPoint3D;

class myHalfedge;
class myVector3D;

class myVertex
{
public:
  
	myHalfedge *originof;

	int index;  //use as you wish.

	std::shared_ptr<myVector3D> normal;
  std::shared_ptr<myPoint3D>  point;

  myPoint3D overageNeib();
	void computeNormal();
	myVertex(void);
	~myVertex(void);
};
