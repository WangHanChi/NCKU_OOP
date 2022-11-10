/*
物件導向程式設計及應用 HW02
機械所碩一 王漢祺 N16110158
HW02.cpp
*/

#include <iostream>
#include "HW02.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;


// Point

// default constructor
Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

// constructor with three arguments
Point::Point(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

// destrucotr
Point::~Point()
{
	//cout << "call Point destructor" << endl;
}

// const subscript operator
const float& Point::operator[](int i) const
{
	switch (i)
	{
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	case 2:
		return this->z;
		break;
	default:
		//cout << "subscript operator should be in 0 ~ 2 " << endl;
		return FLT_MIN;
	}
	//我的防呆就是假如輸入0~2之外的數字的話，就回傳NAN
}

// subscript operator
float& Point::operator[](int i)
{
	float gg = FLT_MIN;

	switch (i)
	{
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	case 2:
		return this->z;
		break;
	default:
		//cout << "subscript operator should be in 0 ~2 " << endl;
		return gg;
	}	
	//我的防呆就是假如輸入0~2之外的數字的話，就回傳float的最小值
}

// bool function, to check the two points which is the same
bool Point::operator==(const Point& point) const
{
	if (this->x == point.x)
	{
		if (this->y == point.y)
		{
			if (this->z == point.z) return true;
			return false;
		}
		return false;
	}
	return false;
	//如果兩個點是相同的話, 就回傳treu, 否則就回傳false
}

// firend function of istreeam
istream& operator >>(istream& in, Point& point)
{
	in >> point.x;
	in >> point.y;
	in >> point.z;
	if (!in)
	{		// 輸入運算子的防呆
		cout << "istream occur error!!!" << endl;
	}
	return in;
	//可以將輸入流輸入給點
}

ostream& operator <<(ostream& out, const Point& point)
{
	out << "Point : ( " << point.x << ", " << point.y << ", " << point.z << " )" << endl;
	return out;
	//輸出點, 順便輸出括號以及逗號
}



// Link_list

// make LNode
LNode* makenode(Point* point)
{
	Point* pptr = new Point{  (* point)[0],(* point)[1],(* point)[2]};
	LNode *ptr = new LNode{pptr, NULL};
	return ptr;
	//用來新增節點的的函式, 把把指向下一個node的指標先設定為NULL
}



// constructor with Point* and int
Link_list::Link_list(Point* point, int num)
{
	head = makenode(point);
	LNode** indirect = &(head);
	int count = 1;
	while (count < num)
	{
		(*indirect)->next = makenode(point + count);
		indirect = &(*indirect)->next;
		count++;
	}
	(*indirect)->next = head;
}


// copy constructor
Link_list::Link_list(const Link_list& foo)
{
	if (foo.head == NULL)
	{
		cout << "The Linked_list is NULL, cannot be copy!!" << endl;
		return;
	}
	head = makenode(foo.head->data);
	LNode** ptr = &head;
	LNode* tmp = foo.head;
	while (tmp->next != foo.head)
	{
		tmp = tmp->next;
		(*ptr)->next = makenode(tmp->data);
		ptr = &(*ptr)->next;
	}
	(*ptr)->next = head;
}

// destructor
Link_list::~Link_list()
{
	if (head == NULL)
	{
		cout << "There is empty in the linked_list, and cannot be destruct!!! " << endl;
		return;
	}
	LNode* tmp = head;
	LNode* del;
	int count = this->element_count();
	
	for (int i = 0; i < count; i++)
	{
		del = tmp;
		tmp = tmp->next;
		delete del->data;
		delete del;
		//先釋放node裡面的data, 在釋放node
	}
	//cout << "call the Linked_list destructor" << endl;
}

// assignment operator
Link_list& Link_list::operator=(const Link_list& foo)
{
	if (this == &foo)	return *this;

	// TODO : change into indirect pointer
	// start
	int count = this->element_count();
	if (count != 0)
	{
		LNode* tmp = head, *del;
		for (int i = 0; i < count; i++)
		{
			del = tmp;
			tmp = tmp->next;
			delete del->data;
			delete del;
			//先釋放node裡面的data, 在釋放node
		}
		count = 0;
	}
	// end

	if (foo.head == NULL)
	{
		cout << "The Linked_list is NULL, cannot be assigned!!" << endl;
		return *this;
	}
	head = makenode(foo.head->data);
	LNode** ptr = &head;
	LNode* tmp = foo.head;
	while (tmp->next != foo.head)
	{
		tmp = tmp->next;
		(*ptr)->next = makenode(tmp->data);
		ptr = &(*ptr)->next;
	}
	(*ptr)->next = head;
	return *this;
}

// insert function with Point* and unsigned int
void Link_list::insert(Point* point, const unsigned int foo = 0)
{
	if (foo > element_count())
	{
		cout << "The insert place cannot be larger than itself!!!" << endl;
		return;
	}
	LNode* add_node = makenode(point);
	LNode** indirect = &head;
	if (foo == 0)
	{
		if (element_count() == 0)
		{
			head = add_node;
			head->next = head;
			return;
		}
		
		while ((*indirect)->next != head)
			indirect = &((*indirect)->next);
		add_node->next = head;
		(*indirect)->next = add_node;
		head = add_node;
		return;
	}
	for (int i = 1; i < foo - 1; i++)
		indirect = &((*indirect)->next);
	add_node->next = (*indirect)->next;
	(*indirect)->next = add_node;
	
	return;
}

// insert function with link_list
void Link_list::insert(Link_list* input)
{
	if (input->element_count() == 0) return;
	LNode** indirect = &head, *add_node;
	LNode** idt = &input->head;
	while ((*indirect)->next != head)
		indirect = &(*indirect)->next;
	while ((*idt)->next != input->head)
	{
		add_node = makenode((*idt)->data);
		(*indirect)->next = add_node;
		idt = &(*idt)->next;
		indirect = &(*indirect)->next;
	}
	// 這邊應該可以寫得更好看一點
	add_node = makenode((*idt)->data);
	(*indirect)->next = add_node;
	idt = &(*idt)->next;
	indirect = &(*indirect)->next;
	(*indirect)->next = head;
}



// erase function
Point* Link_list::erase(const unsigned int foo)
{
	if (foo > element_count()) return NULL;
	Point* ra;
	LNode** indirect = &head, *del;
	if (foo == 0)
	{
		del = head;
		ra = new Point{ *(head->data) };
		while ((*indirect)->next != head)
			indirect = &(*indirect)->next;
		cout << *(*indirect)->data << endl;
		//indirect = &(*indirect)->next;
		(*indirect)->next = head->next;
		cout << "&&" << *(head->data) << endl;
		head = head->next;
		cout << "$$" << *(head->data) << endl;
		
		delete del->data;
		delete del;
		return ra;
	}
	for (int i = 0; i < foo - 1; i++)
		indirect = &(*indirect)->next;
	del = (*indirect)->next;
	(*indirect)->next = (*indirect)->next->next;
	ra = new Point{ *del->data };
	delete del->data;
	delete del;
	return ra;
}



// element_count function
unsigned int Link_list::element_count() const 
{
	int count = 0;
	if (head == NULL) return count;
	LNode* ptr = head;
	count++;
	while (ptr->next != head)
	{
		ptr = ptr->next;
		count++;
	}
	//從頭到頭遍歷一次並且得出node個數
	return count;
}

// firend ostream function
ostream& operator <<(ostream& out, const Link_list& link_list)
{
	LNode* current = link_list.head;
	int count = link_list.element_count();
	out << "Now there is/are " << count << " in circular_linked_list" << endl;
	out << "The head is \t0 : " << *current->data << endl;
	current = current->next;
	
	for (int i = 1; i < count; i++)
	{
		out << "\t\t" << i << " : " << *current->data << endl;
		current = current->next;
	}
	
	
	out << endl;
	out << "----------------------------------------------------" << endl;
	return out;
}
