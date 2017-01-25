#pragma once

#include <math.h>

class myVector3D;

class myPoint3D
{
  //The x,y,z coordinates of this point.
public:
	union
	{
		double components[3];
		struct { double X, Y, Z; };
	};


  myPoint3D();

  myPoint3D(double x, double y, double z);
  myPoint3D(const myPoint3D & p);
  double dist(myPoint3D p1);
  myPoint3D operator+(const myVector3D & v1);
  myPoint3D operator+(const myPoint3D & v1);
  myPoint3D & operator+=(const myVector3D & v1);
  myPoint3D & operator+=(const myPoint3D & v1);

  myPoint3D & operator/=(double d);
  myPoint3D & operator*=(double d);

  myPoint3D operator/(double d);
  myPoint3D operator*(double d);

  myVector3D operator-(myPoint3D & p1);
  void rotate(myVector3D & lp, double theta);
  void print(char *s);
  double dist(myPoint3D *p1, myPoint3D *p2);
  double dist(myPoint3D *p1, myVector3D *v2);
  double dist(myPoint3D *p1, myPoint3D *p2, myPoint3D *p3);
  void circumcenter(myPoint3D *p1, myPoint3D *p2, myPoint3D *p3, myPoint3D *p4);
};



