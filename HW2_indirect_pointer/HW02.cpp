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

	////size = (unsigned int)num;	//設定size進去
	//LNode* current;
	//head = makenode(point);		//new一個新的node出來
	//LNode* tmp = head;

	//for (int i = 1; i < num; i++)
	//{
	//	current = makenode(point + i);
	//	tmp->next = current;
	//	tmp = current;
	//	//新增一個node, 並且將指向next指向正確的node
	//}
	//tmp->next = head;	//將最後一個node指向head
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
	//head = makenode(foo.head->data);
	//LNode* tmp = foo.head;
	//LNode* tmp2 = head;
	//
	//for (int i = 1; i < foo.element_count(); i++)
	//{
	//	tmp = tmp->next;
	//	LNode* current = makenode(tmp->data);
	//	tmp2->next = current;
	//	tmp2 = current;
	//	//將foo的每個點都加入到自己裡面
	//}
	//tmp2->next = head;
	////將最後一個node指向head
}

// destructor
Link_list::~Link_list()
{
	/*LNode** indirect = &head, *tmp;
	while ((*indirect)->next != NULL)
	{
		tmp = (*indirect);
		indirect = &(*indirect)->next;
		cout << "delete node : " << *(tmp->data) << endl;
		cout << "the next node is : " << *((*indirect)->data) << endl;
		delete tmp->data;
		delete tmp;
	}
	return;*/
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
	//if (this == &foo)	return *this;		//如果等於自己, 就回傳回去
	//int count = this->element_count();
	//
	//if (count != 0)
	//{
	//	LNode* tmp = head, *del;
	//	for (int i = 0; i < count; i++)
	//	{
	//		del = tmp;
	//		tmp = tmp->next;
	//		delete del->data;
	//		delete del;
	//		//先釋放node裡面的data, 在釋放node
	//	}
	//	count = 0;
	//}
	//
	//LNode* ptr = makenode(foo.head->data);
	//head = ptr;			//先設定head
	//LNode* tmp = foo.head;
	//LNode* tmp2 = head;
	//LNode* ori2 = foo.head;
	//int count2 = foo.element_count();
	//for (int i = 1; i < count2; i++)
	//{
	//	tmp = tmp->next;
	//	LNode* current = makenode(tmp->data);
	//	tmp2->next = current;
	//	tmp2 = current;
	//}
	//tmp2->next = head;
	////將最後一個node指向head

	//return *this;
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
	//int count = this->element_count();
	//
	//if (foo > count)
	//{
	//	cout << "The insert place cannot be larger than itself!!!" << endl;
	//	return;
	//	//如果要輸入的位置大於node個數的話, 就輸出提醒並且回傳
	//}	
	//LNode* add_node = makenode(point);
	//LNode* old_head = head;
	//LNode* tmp = head, *tmp2, *tmp3;
	//if (foo == 0)		//假如insert的位置是head的話
	//{
	//	cout << count << endl;
	//	if (count == 0)
	//	{
	//		head = add_node;
	//		return;
	//	}
	//	if (count == 1)
	//	{
	//		head->next = add_node;
	//		add_node->next = head;
	//		head = add_node;

	//		return;
	//	}
	//	else if(count >= 2)
	//	{
	//		add_node->next = head;
	//		tmp2 = head;
	//		tmp = tmp2->next;
	//		while (tmp2->next != head)
	//		{
	//			tmp2 = tmp2->next;
	//		}
	//		tmp2->next = add_node;
	//		head = add_node;

	//		return;
	//	}
	//	
	//}
	//else if(foo >= 1)				//假如insert的位置不是head的話
	//{
	//	tmp = head;
	//	for (int i = 0; i < foo - 1; i++)
	//	{
	//		tmp = tmp->next;
	//	}
	//	tmp3 = tmp->next;
	//	tmp->next = add_node;
	//	add_node->next = tmp3;
	//	return;
	//}
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

	//if (input->element_count() == 0)
	//{
	//	cout << "The insert linked_list cannot be zero node" << endl;
	//	return;
	//	//假如輸入進來的linked_list的node數量是0的話, 就輸出提醒並且回傳
	//}
	//LNode* tmp = head;
	//int count = this->element_count();
	//
	//for (int i = 0; i < count - 1 ; i++)
	//{
	//	tmp = tmp->next;
	//}			//	先把指到自己的最後一個node
	//LNode* ptr = makenode(input->head->data);
	//LNode* input_tmp = input->head;
	//tmp->next = ptr;
	//tmp = ptr;
	//input_tmp = input_tmp->next;
	//for (int i = 1; i < input->element_count(); i++)
	//{
	//	ptr = makenode(input_tmp->data);
	//	tmp->next = ptr;
	//	tmp = ptr;
	//	input_tmp = input_tmp->next;
	//}
	//tmp->next = head;
	////size += input->size;
}



// erase function
Point* Link_list::erase(const unsigned int foo)
{
	/*if (foo > element_count()) return NULL;
	Point* ra;
	LNode** indirect = &head, *del;
	if (foo == 0)
	{
		del = head;
		ra = new Point{ *head->data };
		while ((*indirect)->next != head)
			indirect = &(*indirect)->next;
		indirect = &(*indirect)->next;
		head = head->next;
		head = (*indirect)->next;
		delete del->data;
		delete del;
		return ra;
	}
	for (int i = 0; i < foo - 1; i++)
		indirect = &(*indirect)->next;
	del = (*indirect)->next;
	(*indirect)->next->next = (*indirect)->next;
	ra = new Point{ *del->data };
	delete del->data;
	delete del;
	return ra;*/

	int count = this->element_count();
	if (foo > count)
	{
		cout << "The erase place cannot be larger than isself" << endl;
		return NULL;
	}
	LNode* remove, * after_next;
	LNode* tmp = head;
	if (foo == 0)		//假如要移除的點是head的話
	{
		for(int i = 0 ;i < count - 1; i++)
		{
			tmp = tmp->next;
		}
		remove = head;
		Point* ra = new Point{*remove->data};
		after_next = head->next;
		tmp->next = after_next;
		head = after_next;
		delete remove;
		return ra;
	}
	//假如要移除的點不是head的話
	for (int i = 0; i < foo - 1; i++)
	{
		tmp = tmp->next;
	}
	after_next = tmp->next->next;
	remove = tmp->next;
	Point* ra = new Point{ *remove->data };
	tmp->next = after_next;
	delete remove;
	//size--;
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
