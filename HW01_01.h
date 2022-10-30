/*
機械所碩一 王漢祺 N16110158
物件導向 HW01_01
HW01_01.h
*/
#include <iostream>

#ifndef HW01_01_H
#define HW01_01_H
namespace MyGeometry
{
	struct Point
	{
		float x, y, z;
		double Length(const Point& point) const;
	};

	struct Plane
	{
		float a, b, c, d;
	};

	std::string Coutinformation(const Point&);
	std::string Coutinformation(const Plane&);
	Point* LoadPoint(const char* filename, unsigned int& nPoint);
	Point* MinDistance(const Point*&, const Plane&, unsigned int& nPoint, double&);
	void Report(const char* filename, Point& , unsigned int& , double&);
}

#endif