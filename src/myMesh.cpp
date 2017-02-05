#include "myMesh.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>
#include <GL/glew.h>

#include "myPoint3D.hpp"
#include "myVector3D.hpp"


using namespace std;

myMesh::myMesh(void)
{
  this->name = std::string("struct mesh whith no name");
}

myMesh::myMesh(const myMesh& o):vertices(o.vertices.size()),faces(o.faces.size()),halfedges(o.halfedges.size())

{
	this->name = o.name;

  for(int i = 0; i < o.vertices.size(); i++)
    {
      this->vertices.push_back(new myVertex());

      o.vertices[i]->index = i;
      this->vertices[i]->index = i;
    }

  for(int i = 0; i < o.halfedges.size(); i++)
    {
      this->halfedges.push_back(new myHalfedge());

      o.halfedges[i]->index = i;
      this->halfedges[i]->index = i;

    }

  for(int i = 0; i < o.faces.size(); i++)
    {
      this->faces.push_back(new myFace());

      o.faces[i]->index = i;
      this->faces[i]->index = i;

    }

  for(int i = 0; i < o.faces.size(); i++)
    {
      *this->faces[i]->normal = *o.faces[i]->normal;
      this->faces[i]->adjacent_halfedge = this->halfedges[o.faces[i]->adjacent_halfedge->index];
    }


  for(int i = 0; i < o.halfedges.size(); i++)
    {
      this->halfedges[i]->adjacent_face = this->faces[o.halfedges[i]->adjacent_face->index];
      this->halfedges[i]->next = this->halfedges[o.halfedges[i]->next->index];
      this->halfedges[i]->prev = this->halfedges[o.halfedges[i]->prev->index];
      this->halfedges[i]->twin = this->halfedges[o.halfedges[i]->twin->index];

      this->halfedges[i]->source = this->vertices[o.halfedges[i]->source->index];
    }

  for(int i = 0; i < o.vertices.size(); i++)
    {
      this->vertices[i]->point = std::make_shared<myPoint3D>(*o.vertices[i]->point);
      this->vertices[i]->originof = this->halfedges[o.vertices[i]->originof->index];
      this->vertices[i]->normal = std::make_shared<myVector3D>(*o.vertices[i]->normal);
    }



}

myMesh::~myMesh(void)
{

  this->clear();
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

  // test add by and for myself
  for (int i = 0; i < this->vertices.size(); i++) {
    if (this->vertices[i]->index != i)
      {
        // never be ok because of teacher make buffer
        // cout << "ERREUR indice vertice "<< i <<" is "<< this->vertices[i]->index << "\n";
      }
  }

  for (int i = 0; i < this->faces.size(); i++) {
    if (this->faces[i]->index != i)
      {
        cout << "ERREUR faces " << i <<" is "<< this->faces[i]->index << "\n";
      }
  }

  for (int i = 0; i < this->halfedges.size(); i++) {
    if (this->halfedges[i]->index != i)
      {
        cout << "ERREUR edje " << i <<" is "<< this->halfedges[i]->index << "\n";
      }

    if (this->halfedges[i]->twin->twin != this->halfedges[i])
      {
        cout << "Twin of twin is not me at " << i <<" as "<< this->halfedges[i] << "\n";
      }

    if (this->halfedges[this->halfedges[i]->twin->index] != this->halfedges[i]->twin)
      {
        cout << "erreur: Twin  are delete " << i <<" is "<< this->halfedges[i]->index << "\n";
      }
  }


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

			if (k > 100000)
        cout << "\t\tError: Infinite loop when checking adjacent edges for vertex " << i <<" avec e="<< e1<<" index="<< e1->index <<endl;
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
			v->point = std::make_shared<myPoint3D>(x, y, z);

      v->index = vertices.size();
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

        hedges[i]->index = halfedges.size();
				halfedges.push_back(hedges[i]);
			}

      f->index = this->faces.size();
      faces.push_back(f);
		}

    for(auto oneHalfEdje : twin_map)
      {
        auto elem = twin_map.find(std::make_pair(oneHalfEdje.first.second , oneHalfEdje.first.first));
        if(elem == twin_map.end())
          continue;

        oneHalfEdje.second->twin = elem->second;

      }
	}


	this->checkMesh();
	this->normalize();

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


void myMesh::splitFaceTRIS(myFace *f, std::shared_ptr<myPoint3D> p)
{
	this->splitFace(f,p);
}



void myMesh::splitFaceQUADS(myFace *f, std::shared_ptr<myPoint3D> p)
{


   std::vector<myHalfedge*> ex;
   std::vector<myFace*> nface;
   std::vector<myHalfedge*> in;
   std::vector<myHalfedge*> out;
   myHalfedge* e = f->adjacent_halfedge;

   myVertex* nv = new myVertex();
   nv->point = p;

   do
     {
       nface.push_back(new myFace());
       out.push_back(new myHalfedge());
       in.push_back(new myHalfedge());
       ex.push_back(e);
       e = e->next->next;
     }
   while(e != f->adjacent_halfedge and e != f->adjacent_halfedge->next);

   int count = ex.size();
      nv->originof = out[0];

   for (int i = 0; i < count; i++)
     {
       out[i]->adjacent_face = nface[i];
       in[i]->adjacent_face  = nface[i];
       ex[i]->adjacent_face  = nface[i];
       ex[i]->next->adjacent_face  = nface[i];


       out[i]->next = ex[i];
       ex[i]->next->next  = in[i];
       in[i]->next  = out[i];

       out[i]->prev = in[i];
       in[i]->prev  = ex[i]->next;
       ex[i]->prev  = out[i];

       nface[i]->adjacent_halfedge = out[i];

       out[i]->source = nv;
       in[i]->source  = ex[i]->next->twin->source;

       // twin
       in[i]->twin = out[(i+1)%count];
       out[i]->twin = in[(i-1+count)%count];

     }


   //add faces
   nface[0]->index = f->index;
      this->faces[nface[0]->index] = nface[0];

   for (int i = 1; i < nface.size(); i++)
     {
     nface[i]->index = this->faces.size();
     this->faces.push_back(nface[i]);
     }

   // add in and out
   for (int i = 0; i < in.size(); i++)
     {
     out[i]->index = this->halfedges.size();
     this->halfedges.push_back(out[i]);

     in[i]->index = this->halfedges.size();
     this->halfedges.push_back(in[i]);
   }

  nv->index =  this->vertices.size();
  this->vertices.push_back(nv);

  delete f ;
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

void myMesh::splitFace(myFace *f,std::shared_ptr<myPoint3D> p)
{



   std::vector<myHalfedge*> ex;
   std::vector<myFace*> nface;
   std::vector<myHalfedge*> in;
   std::vector<myHalfedge*> out;
   myHalfedge* e = f->adjacent_halfedge;

   myVertex* nv = new myVertex();
   nv->point = p;

   do
     {
       nface.push_back(new myFace());
       out.push_back(new myHalfedge());
       in.push_back(new myHalfedge());
       ex.push_back(e);
       e = e->next;
          }
   while(e != f->adjacent_halfedge);

   int count = ex.size();
      nv->originof = out[0];

   for (int i = 0; i < count; i++)
     {
       out[i]->adjacent_face = nface[i];
       in[i]->adjacent_face  = nface[i];
       ex[i]->adjacent_face  = nface[i];

       out[i]->next = ex[i];
       ex[i]->next  = in[i];
       in[i]->next  = out[i];

       out[i]->prev = in[i];
       in[i]->prev  = ex[i];
       ex[i]->prev  = out[i];

       nface[i]->adjacent_halfedge = out[i];

       out[i]->source = nv;
       in[i]->source  = ex[i]->twin->source;

       // twin
       in[i]->twin = out[(i+1)%count];
       out[i]->twin = in[(i-1+count)%count];

     }


   //add faces
   nface[0]->index = f->index;
      this->faces[nface[0]->index] = nface[0];

   for (int i = 1; i < nface.size(); i++)
     {
     nface[i]->index = this->faces.size();
     this->faces.push_back(nface[i]);
     }




   // add in and out
   for (int i = 0; i < in.size(); i++)
     {
     out[i]->index = this->halfedges.size();
     this->halfedges.push_back(out[i]);

     in[i]->index = this->halfedges.size();
     this->halfedges.push_back(in[i]);
   }

   nv->index =  this->vertices.size();
   this->vertices.push_back(nv);


   delete f ;

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
  fv[0]->index = f->index;
  this->faces[f->index] = fv[0];

  // add faces
  for (int i = 1; i < fv.size(); i++) {
    fv[i]->index = this->faces.size();
    this->faces.push_back(fv[i]);
  }

  // add in
  for (int i = 1; i < in.size(); i++) {
    in[i]->index = this->halfedges.size();
    this->halfedges.push_back(in[i]);
  }

  // add out
  for (int i = 0; i < out.size()-1; i++) {
    out[i]->index = this->halfedges.size();
    this->halfedges.push_back(out[i]);
  }

  delete(f);
}

void myMesh::inflateMesh(double dist)
{
  for (auto v : this->vertices) {
    *(v->point) =*(v->point)+ ((*(v->normal))*dist);
 }
}

void myMesh::smoothenMesh(double dist)
{
  std::vector<myPoint3D> copy(this->vertices.size());

  for (int i = 0; i < this->vertices.size(); i++) {
    auto X = this->vertices[i]->overageNeib();
    copy[i] = (*(this->vertices[i]->point))*(1-dist) + (X)*dist;
  }

  for (int i = 0; i < this->vertices.size(); i++) {
    *(this->vertices[i]->point) = copy[i];
  }

}

void myMesh::splitEdge(myHalfedge *e, std::shared_ptr<myPoint3D> p)
{

  // se_fi = 
  // se_la =
  auto v = new myVertex();
  v->point = p;


  auto b_p = new myHalfedge();
  b_p->source = e->source;
  b_p->adjacent_face = e->adjacent_face;

  auto p_b = new myHalfedge();
  p_b->source = v;
  p_b->adjacent_face = e->twin->adjacent_face;

  auto p_e = new myHalfedge();
  p_e->source = v;
  p_e->adjacent_face = e->adjacent_face;

  auto e_p = new myHalfedge();
  e_p->source = e->twin->source;
  e_p->adjacent_face = e->twin->adjacent_face;

  e->source->originof = b_p;
  e->twin->source->originof = e_p;

  // TWIN
  p_b->twin = b_p;
  b_p->twin = p_b;

  p_e->twin = e_p;
  e_p->twin = p_e;

  // next and prev
  e->next->prev = p_e;
  p_e->prev = b_p;
  b_p->prev = e->prev;

  e->prev->next = b_p;
  b_p->next = p_e;
  p_e->next = e->next;

  e->twin->next->prev = p_b;
  p_b->prev = e_p;
  e_p->prev =e->twin->prev;

  e->twin->prev->next = e_p;
  e_p->next = p_b;
  p_b->next = e->twin->next;

  //// after this point dont read e;

  v->originof = p_e;

  //indice
  //and check if e is
  if(e == e->adjacent_face->adjacent_halfedge)
    {
      e->adjacent_face->adjacent_halfedge = b_p;
    }

  if(e->twin == e->twin->adjacent_face->adjacent_halfedge)
    {
      e->twin->adjacent_face->adjacent_halfedge = e_p;
    }


  b_p->index = e->index;
  this->halfedges[b_p->index] = b_p;

  e_p->index = e->twin->index;
  this->halfedges[e_p->index] = e_p;

  p_e->index = this->halfedges.size();
  this->halfedges.push_back(p_e);

  p_b->index = this->halfedges.size();
  this->halfedges.push_back(p_b);

  v->index = this->vertices.size();
  this->vertices.push_back(v);

  delete(e->twin);
  delete(e);
}


void myMesh::subdivisionCatmullClark()
{





  cout <<"start"  << "\n";
  this->checkMesh();
  ////
  // centroid
  ///
  std::vector<std::shared_ptr<myPoint3D>> centroid = std::vector<std::shared_ptr<myPoint3D>>(this->faces.size());

  int size =  this->faces.size();

  for(int i = 0; i < size; i++ )
    {
      auto faceCentroid = std::make_shared<myPoint3D>(0,0,0);

      auto f = this->faces[i]->adjacent_halfedge;
      auto itef = this->faces[i]->adjacent_halfedge;

      int count = 0;
      do
        {
          *faceCentroid += *itef->source->point;
          count++;
          itef = itef->next;
        }while( itef != f);

      *faceCentroid = *faceCentroid/count;
      centroid[i] = faceCentroid;
    }


  if( this->halfedges.size() % 2 != 0)
    {cout<<"error"<<std::endl;
      exit(2);}

  int nbHalfedges = this->halfedges.size() / 2;
  auto mapii = std::map<std::pair<int,int>, std::shared_ptr<myPoint3D> >();

  for (auto i : this->halfedges)
    {
      int min = std::min(i->index, i->twin->index);
      int max = std::max(i->index, i->twin->index);
      auto pair = std::make_pair(min,max);
      auto result = mapii.find(pair);

      //deja fais
      if(result != mapii.end())
        {
          continue;
        }



      mapii[pair] = std::make_shared<myPoint3D>((  *centroid[i->adjacent_face->index]
                                   + *centroid[i->twin->adjacent_face->index]
                                   + *i->source->point
                                   + *i->twin->source->point) / 4);

      //      cout <<"edje "<< mapii[pair]->X <<","<< mapii[pair]->Y <<","<< mapii[pair]->Z << "\n";

    }


  /// vertices compute
  auto newVerticePosition = std::vector<std::shared_ptr<myPoint3D> >(this->vertices.size());

  for(int i = 0 ; i < this->vertices.size(); i++)
    {
      // compute N
      auto q = myPoint3D(0,0,0);
      auto r = myPoint3D(0,0,0);

      myHalfedge* f    = this->vertices[i]->originof;
      myHalfedge* itef = this->vertices[i]->originof;
      int n = 0;

      do{
        r += (*itef->source->point + *itef->twin->source->point) /2;

        q += *centroid[itef->twin->adjacent_face->index] ;

        n++;

        itef = itef->twin->next;

        }while( itef != f);

      // compute Q
      // cout << "n = "<< n << "\n";
      q = q/n;

      // compute R
      r = r/n;

      // compute
      myPoint3D vv =  (q  +  r * 2  +  *(this->vertices[i]->point) * (n-3))/n;

      newVerticePosition[i] = std::make_shared<myPoint3D>(vv);
    }

   // apply position
   for(int i = 0 ; i < this->vertices.size(); i++)
     {

       this->vertices[i]->point = newVerticePosition[i];
       //cout << this->vertices[i]->point->X << this->vertices[i]->point->Y <<this->vertices[i]->point->Z << "\n";
     }


  // split
  for(auto splitedge: mapii)
    {
      this->splitEdge(this->halfedges[splitedge.first.second],splitedge.second);
    }

  for(int i = 0; i < centroid.size(); i++)
    {
      // cout << "face at "<< i << " is "<< this->faces[i] << " with " << this->faces[i]->index<<"\n ";
      this->faces[i]->adjacent_halfedge = this->faces[i]->adjacent_halfedge->next;
      this->
        splitFaceQUADS(this->faces[i], centroid[i]);
    }

}
