#pragma once

#include "myFace.hpp"
#include "myHalfedge.hpp"
#include "myVertex.hpp"
#include <vector>
#include <string>

class myMesh
{

 public:
	std::vector<myVertex *> vertices;
	std::vector<myHalfedge *> halfedges;
	std::vector<myFace *> faces;
	std::string name;
  
	void checkMesh();
	bool readFile(std::string filename);
	void computeNormals();
	void normalize();

  void inflateMesh(double dist);
  void smoothenMesh(double dist);
  void splitFace(myFace *, std::shared_ptr<myPoint3D>);

  void subdivisionCatmullClark();

	void splitFaceTRIS(myFace *, std::shared_ptr<myPoint3D> );

	void splitEdge(myHalfedge *, std::shared_ptr<myPoint3D>);
	void splitFaceQUADS(myFace *, std::shared_ptr<myPoint3D>);

	void triangulate();
	bool triangulate(myFace *,int place);

	void clear();

	myMesh(void);
  myMesh(const myMesh& o);
	~myMesh(void);
};

