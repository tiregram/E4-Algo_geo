#include "myMesh.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>
#include <GL/glew.h>
#include "myPoint3D.h"

using namespace std;

myMesh::myMesh(void)
{
	/**** TODO ****/
}


myMesh::~myMesh(void)
{
	/**** TODO ****/
}

void myMesh::clear()
{
	for (unsigned int i = 0; i < vertices.size(); i++) if (vertices[i]) delete vertices[i];
	for (unsigned int i = 0; i < halfedges.size(); i++) if (halfedges[i]) delete halfedges[i];
	for (unsigned int i = 0; i < faces.size(); i++) if (faces[i]) delete faces[i];

	vector<myVertex *> empty_vertices;    vertices.swap(empty_vertices);
	vector<myHalfedge *> empty_halfedges; halfedges.swap(empty_halfedges);
	vector<myFace *> empty_faces;         faces.swap(empty_faces);
}


void myMesh::checkMesh()
{

	bool error;
	unsigned int count;

	cout << "Checking mesh for errors...\n";
	cout << "\tNumber of vertices: " << vertices.size() << endl;
	cout << "\tNumber of halfedges: " << halfedges.size() << endl;
	cout << "\tNumber of faces: " << faces.size() << endl << endl;

	cout << "\tChecking for NULL vertices. " << endl;
	for (unsigned int i = 0;i < vertices.size();i++)
	{
		if (vertices[i] == NULL)
			cout << "\t\tError: vertex " << i << " is NULL.\n";
		else if (vertices[i]->originof == NULL)
			cout << "\t\tError: the originof halfedge of vertex " << i << " is NULL.\n";
	}
	cout << "\t  Ended check.\n\n";

	cout << "\tChecking the halfedges. " << endl;
	error = false;
	count = 0;
	for (unsigned int i = 0;i < halfedges.size();i++)
	{
		if (halfedges[i]->source == NULL)
			cout << "\tError: Source is NULL for halfedge " <<  i << endl;
		if (halfedges[i]->twin == NULL) count++;
		if (halfedges[i]->next == NULL || halfedges[i]->prev == NULL)
			cout << "\tError: Next/prev NULL for halfedge " << i << endl;
		if (halfedges[i]->next->prev != halfedges[i] || halfedges[i]->prev->next != halfedges[i])
			cout << "\tError: Next/prev not set properly for halfedge " << i << endl;
		if (halfedges[i]->twin != NULL && halfedges[i] != halfedges[i]->twin->twin)
			cout << "\tError: Twin pair not set properly for halfedge " << i << endl;
	}
	if (count > 0) cout << "\tThis mesh has boundary edges.\n";
	cout << "\t  Ended check.\n\n";

	cout << "\tChecking fans of each vertex.\n";
	for (unsigned int i = 0;i<vertices.size();i++) {
		myVertex *v = vertices[i];

		myHalfedge *e1 = v->originof;

		unsigned int k = 0;
		do {
			k++;
      // cout << e1 << ","<<e1->prev << "\n";
			e1 = e1->prev->twin;
			if (k > 100000) cout << "\t\tError: Infinite loop when checking adjacent edges for vertex " << i << endl;
		} while (e1 != NULL && e1 != v->originof);
	}
	cout << "\t  Ended check.\n\n";

	cout << "\tChecking edges of each face.\n";
	unsigned int num_incidentedgesoverallfaces = 0;
	bool istriangular = true;
	for (unsigned i = 0;i<faces.size();i++) {
		myHalfedge *e1 = faces[i]->adjacent_halfedge;
		unsigned int k = 0;
		do {
			k++;
			if (e1 == NULL) cout << "\t\tError: Found NULL edge on boundary of face " << i << endl;
			e1 = e1->next;
			if (k > 100000) cout << "\t\tError: Infinite loop when checking adjacent edges for face " << i << endl;
		} while (e1 != faces[i]->adjacent_halfedge);
		num_incidentedgesoverallfaces += k;
		if (k>3) istriangular = false;
	}
	if (istriangular) cout << "\t\tThe mesh is triangular.\n";
	else cout << "\t\tThe mesh is not triangular.\n";
	if (num_incidentedgesoverallfaces != halfedges.size())
		cout << "\t\tSuspicious: the total number of halfedges is not equal to the sum at each face.\n";
	cout << "\t  Ended check.\n\n";

	cout << "  Ended check of mesh.\n";
}

bool myMesh::readFile(std::string filename)
{
 
	string s, t, u;
	vector<int> faceids;
	myHalfedge **hedges;

	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Unable to open file!\n";
		return false;
	}
	name = filename;

	map<pair<int, int>, myHalfedge *> twin_map;
	map<pair<int, int>, myHalfedge *>::iterator it;

	while (getline(fin, s))
	{
		stringstream myline(s);
		myline >> t;
		if (t == "g") 
		{}
		else if (t == "v")
		{
			double x, y, z;
			myline >> x; myline >> y; myline >> z;

			myVertex *v = new myVertex();
			v->point = new myPoint3D(x, y, z);
      vertices.push_back(v);
		}
		else if (t == "mtllib") {}
		else if (t == "usemtl") {}
		else if (t == "s") {}
		else if (t == "f")
		{
			vector<int> indices;
			vector<myHalfedge *> hedges;

			string u;
			while (myline >> u) 
			{
				indices.push_back(atoi(u.substr(0, u.find("/")).c_str()) -1);
				hedges.push_back(new myHalfedge());
			}

			myFace *f = new myFace();
			f->adjacent_halfedge = hedges[0];

			for (int i = 0; i < indices.size(); i++)
			{
				hedges[i]->source = vertices[indices[i]];
        hedges[i]->source->originof = hedges[i];
				hedges[i]->adjacent_face = f;
        hedges[i]->next = hedges[(i + 1) % indices.size()];
				hedges[i]->prev = hedges[(i - 1 + indices.size()) % indices.size()];

        twin_map[std::pair<int,int>(indices[i],indices[(i+1)%indices.size()]) ] = hedges[i];

				halfedges.push_back(hedges[i]);
			}

      faces.push_back(f);
		}

    for(auto oneHalfEdje : twin_map)
      {
        auto elem = twin_map.find(std::make_pair(oneHalfEdje.first.second , oneHalfEdje.first.first));
        if(elem == twin_map.end())
          continue;

        oneHalfEdje.second->twin = elem->second;
        // cout << "(" << oneHalfEdje.first.first <<","<< oneHalfEdje.first.second << ")"
        //      << oneHalfEdje.second << " link to "
        //      << "(" << elem->first.first <<","<< elem->first.second << ")"
        //      <<elem->second << "\n";
      }
	}


	checkMesh();
	normalize();

	return true;
}


void myMesh::computeNormals()
{


  for (auto face : this->faces) {
    face->computeNormal();
  }

  for (auto vert : this->vertices) {
    vert->computeNormal();
  }


}

void myMesh::normalize()
{
	if (vertices.size() < 1) return;

	int tmpxmin = 0, tmpymin = 0, tmpzmin = 0, tmpxmax = 0, tmpymax = 0, tmpzmax = 0;

	for (unsigned int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->point->X < vertices[tmpxmin]->point->X) tmpxmin = i;
		if (vertices[i]->point->X > vertices[tmpxmax]->point->X) tmpxmax = i;

		if (vertices[i]->point->Y < vertices[tmpymin]->point->Y) tmpymin = i;
		if (vertices[i]->point->Y > vertices[tmpymax]->point->Y) tmpymax = i;

		if (vertices[i]->point->Z < vertices[tmpzmin]->point->Z) tmpzmin = i;
		if (vertices[i]->point->Z > vertices[tmpzmax]->point->Z) tmpzmax = i;
	}

	double xmin = vertices[tmpxmin]->point->X, xmax = vertices[tmpxmax]->point->X,
		ymin = vertices[tmpymin]->point->Y, ymax = vertices[tmpymax]->point->Y,
		zmin = vertices[tmpzmin]->point->Z, zmax = vertices[tmpzmax]->point->Z;

	double scale = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	scale = scale > (zmax - zmin) ? scale : (zmax - zmin);

	for (unsigned int i = 0; i < vertices.size(); i++) {
		vertices[i]->point->X -= (xmax + xmin) / 2;
		vertices[i]->point->Y -= (ymax + ymin) / 2;
		vertices[i]->point->Z -= (zmax + zmin) / 2;

		vertices[i]->point->X /= scale;
		vertices[i]->point->Y /= scale;
		vertices[i]->point->Z /= scale;
	}
}


void myMesh::splitFaceTRIS(myFace *f, myPoint3D *p)
{
	/**** TODO ****/
}

void myMesh::splitEdge(myHalfedge *e1, myPoint3D *p)
{

	/**** TODO ****/
}

void myMesh::splitFaceQUADS(myFace *f, myPoint3D *p)
{
	/**** TODO ****/
}


void myMesh::subdivisionCatmullClark()
{
	/**** TODO ****/
}


void myMesh::triangulate()
{
  unsigned int size = this->faces.size();
  for(int i = 0; i< size;i++)
    {
      // pass i for swap
      this->triangulate(this->faces[i],i);
    }

}

//return false if already triangle, true othewise.
bool myMesh::triangulate(myFace *f,int place)
{
  // check if it is a triangle
  if( f->adjacent_halfedge->next->next == f->adjacent_halfedge or // 2 
      f->adjacent_halfedge->next->next->next == f->adjacent_halfedge)//3
    {
      return false;
    }

  myHalfedge * ed = f->adjacent_halfedge->next->next;
  std::vector<myFace*> fv;

  std::vector<myHalfedge*> in;
  std::vector<myHalfedge*> out;


  in.push_back(f->adjacent_halfedge);
  fv.push_back(new myFace());

  while (f->adjacent_halfedge->prev != ed )
    {
      fv.push_back(new myFace());
      in.push_back(new myHalfedge());
      out.push_back(new myHalfedge());

      ed = ed->next;
    }

  out.push_back(f->adjacent_halfedge->prev);

  myHalfedge*  e =  f->adjacent_halfedge->next;
  myHalfedge*  next_e = NULL;

  for (int i = 0; i < in.size(); i++) {
    next_e = e->next;

    // next
    in[i]->next = e;
    e->next = out[i];
    out[i]->next = in[i];

    // prev
    in[i]->prev = out[i];
    out[i]->prev = e;
    e->prev = in[i];

    // source
    in[i]->source = f->adjacent_halfedge->source;
    out[i]->source = e->twin->source;

    // twin of out
    if(i != in.size()-1){
      out[i]->twin = in[i+1];
    }

    // twin of in
    if(i != 0){
      in[i]->twin = out[i-1];
    }

    // adjacentface
    in[i]->adjacent_face = fv[i];
    out[i]->adjacent_face = fv[i];
    e->adjacent_face = fv[i];

    e = next_e;
  }



  for (int i = 0; i < fv.size(); i++) {
    fv[i]->adjacent_halfedge = in[i];
  }

  // swap faces
  this->faces[place] = fv[0];

  // add faces
  for (int i = 1; i < fv.size(); i++) {
    this->faces.push_back(fv[i]);
  }

  // add in
  for (int i = 1; i < in.size(); i++) {
    this->halfedges.push_back(in[i]);
  }

  // add out
  for (int i = 0; i < out.size()-1; i++) {
    this->halfedges.push_back(out[i]);
  }

  delete(f);
}

