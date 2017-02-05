#pragma once

#include <math.h>

class myPoint3D;

class myVector3D
{
  //The dx,dy,dz of this vector.
public:
	union
	{
		double components[3];
		struct { double dX, dY, dZ; };
	};

  myVector3D();
  myVector3D(const myVector3D& p);

  myVector3D(double dx, double dy, double dz);
  double operator*(const myVector3D & v1) const;

  myVector3D operator+(const myVector3D& v1) const;

  myVector3D operator+=(const myVector3D v);
  myVector3D operator+=(const  myVector3D & v);
  myVector3D operator-();
  myVector3D operator-(const myVector3D & v1)const;
  myVector3D operator*(double s) const;
  myVector3D operator/(double s) const;
  void crossproduct(const myVector3D &, const myVector3D &) ;
  myVector3D crossproduct(const myVector3D &) const;
  void setNormal(const myPoint3D& p1,const myPoint3D& p2, const myPoint3D & p3);
  void rotate(myVector3D & lp, double theta);
  double length( ) const;
  void clear();
  void normalize( );
  void print(char *s);
};

