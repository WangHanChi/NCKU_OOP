/*
����ҺӤ@ ���~�R N16110158
����ɦV HW01_01
useHW01_01.cpp
*/
#include <iostream>
#include "HW01_01.h"
#include <string>
#include <fstream>
#include <sstream>
#include <array>

using std::cout;
using std::string;
using std::endl;


int main(int argc, char* argv[])
{
	// #1����
	MyGeometry::Point test = { 1.0, 2.0, 3.0 };	//�i�H���\�ŧiPoint�o��struct, �åB��L��Coutinformation�L�X��
	//���ӿ�X��(1.0,2.0,3.0)
	cout << "#1 ���� : " << endl << "test���I�y�Ь� " << MyGeometry::Coutinformation(test) << endl << endl;


	// #2����
	MyGeometry::Point test2 = { 2.0, 2.0, 3.0 };//�i�H���\�ϥ�Point���������禡length, �åB�i�H�p��X�Z���B�^��
	//���ӿ�X��1.0
	cout << "#2 ���� : " << endl << "�Z���� " << test.Length(test2) << endl << endl;


	// #3����
	MyGeometry::Plane test3 = { 1.0, 2.0, 3.0, 4.0 };//�i�H���\�ŧiPlane�o��struct, �åB��L��Coutinformation��������L�X��
	//���ӿ�X��2x+2y+3z=4
	cout << "#3 ���� : " << endl << "test3��������{���� " << MyGeometry::Coutinformation(test3) << endl << endl;


	// #4����
	MyGeometry::Point test4 = { 3.0, 2.0, 5.0 };	//�ϥ�Coutinformation�^�Ǥ@�Ӧr��
	//���ӿ�X��(3.0, 2.0, 5.0)
	cout << "#4 ���� : " << endl << "test4���I�y�Цr��^�Ǵ���Continformation " << MyGeometry::Coutinformation(test4) << endl << endl;


	// #5����
	MyGeometry::Plane test5 = { 1.0, 2.0, 3.0, 4.0 };	//�ϥ�Coutinformation�����^�Ǥ�{�����r��
	//���ӿ�X��1x+2y+3z=4
	cout << "#5 ���� : " << endl << "test5 ���� Coutinformatio " << MyGeometry::Coutinformation(test5) << endl << endl;


	// #6����
	unsigned int a;
	MyGeometry::Point* p;
	p = MyGeometry::LoadPoint("Point_HW1.txt", a);
	if (p == NULL)	//�p�G�}�ɿ��~, �N�|����@�Ӫū��Ъ��^��, ���۴N�����{��, �ϥΪ����~�N�X�O404
	{
		exit(404);
		std::cin.get();
	}
	//���ӭn��X�@�ӫ���, �ӫ��Ы��V���OPoint�}�C����0��
	//�Ӱ��p��Xp->x�������ӭn��X���Otxt�ɤ��Ĥ@���I��x��, �]�N�O10.25
	cout << "#6 ���� : " << endl << "����Loadpoint��� " << p <<endl << "p����X : ("  << p->x << " " << p->y << " " << p->z  << ")" << "�P�Ĥ@���I�۲�" << endl;
	cout << "�I���Ӽ� : " << a << endl << endl;

	//#7
	double mindistance = -1;	//�]�w�@�ӳ̤p��
	const MyGeometry::Point* pp = p;	//�n��reference�n��const�ŧi
	MyGeometry::Plane plane{ 1.0, 5.2, 4.1, -1.9 };
	MyGeometry::Point* returnpointer = MyGeometry::MinDistance(pp, plane, a, mindistance);
	//���ӭn��X�Z�� 0.765117
	cout << "#7 ���� : " << endl << "����MinDistance��� " << mindistance << endl << endl;

	//#8
	MyGeometry::Report("HW01_output.txt", *returnpointer, a, mindistance);
	cout << "#8 ���� : " << endl << "����Report��� " << "�аѦ� HW01_output.txt " << endl << endl;


	//free the memory
	delete p;
	delete returnpointer;

	system("pause");
	return 0;
}

