/*
����ɦV�{���]�p������ HW02
����ҺӤ@ ���~�R N16110158
HW02.h
*/
#ifndef HW02_H
#define HW02_H

#include <iostream>
using std::cout;
using std::istream;
using std::ostream;



class Point
{
private:
	float x, y, z;

public:
	Point();
	Point(float, float, float);
	~Point();

	const float& operator[](int i) const;
	float& operator[](int i);
	bool operator==(const Point&)const;
	friend istream& operator>>(istream&, Point&);
	friend ostream& operator<<(ostream&, const Point&);
};

struct LNode
{
	Point* data;
	LNode* next;
};

class Link_list
{
private:
	LNode* head;

public:
	Link_list() : head(NULL) {}
	Link_list(Point*, int);
	Link_list(const Link_list&);
	~Link_list();
	Link_list& operator=(const Link_list&);
	void insert(Point*, const unsigned int);
	void insert(Link_list*);	// insert to the last node
	Point* erase(const unsigned int);
	unsigned int element_count()const ;
	// �ڱN�o�䪺element_count()�᭱�[�F�@const�A���F����L�����禡�b�ǰѬ� const link_list ���ɭԥi�H�I�s 
	friend ostream& operator<<(ostream&, const Link_list&);
};

LNode* makenode(const Point*);


#endif // !HW02_H


