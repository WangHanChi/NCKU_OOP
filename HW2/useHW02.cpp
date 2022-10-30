/*
����ɦV�{���]�p������ HW02
����ҺӤ@ ���~�R N16110158
useHW02.cpp
*/

#include <iostream>
#include "HW02.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;


int main(int argc, char* argv[])
{
	srand(time(NULL));
	string line, ss;
	int temp = -1;
	unsigned int num = 0, count = 0;
	float temppoint_x, temppoint_y, temppoint_z;
	std::ifstream myfile;
	myfile.open("Point_HW2.txt");
	if (!myfile.is_open())
	{
		cout << "open file error" << endl;
		system("pause");
		return 0;
	}

	getline(myfile, line);
	std::istringstream stream(line);
	stream >> ss;
	stream >> ss;
	stream >> temp;
	num = temp;
	Point* foo_A;
	foo_A = new Point[num];

	while (getline(myfile, line))
	{
		std::istringstream stream(line);
		stream >> foo_A[count++];
	}
	myfile.close();


	// Point
	// test Point ostream operator
	cout << "NOW test Point ostream opertaor" << endl << endl;;
	float sub1 = (*(foo_A + 2))[0];
	float sub2 = (*(foo_A + 2))[4];
	cout << "test1 : " << endl;
	if (sub1 != FLT_MIN)
	{
		cout << "THe subscript is correct, and x of the point is " << sub1 << endl;
	}
	else
	{
		cout << "OH, NO, there is something wrong" << endl;
	}
	// test and it will be return NAN
	cout << endl;
	cout << "test2 : " << endl;
	if (sub2 != FLT_MIN)
	{
		cout << "THe subscript is correct, and x of the point is " << sub2 << endl;
	}
	else
	{
		cout << "OH, NO, there is something wrong" << endl;
		cout << "subscript operator should be in 0 ~2 " << endl;
	}
	cout << endl << endl;
	// Linked_list A

	// test constructor
	//�����حn���ժ��O�غc�l
	cout << "NOW test Lnked_list A (File points)" << endl;
	cout << "########################################################" << endl;
	cout << "test constructor" << endl;
	Link_list test(foo_A, num);
	cout << test << endl;

	// test assignment operator
	//�����حn���ժ��O�ƻs�B��l
	cout << "test assignment operator" << endl;
	Link_list test_assignment;
	test_assignment = test;
	cout << test_assignment << endl;

	// test element_count()
	//�����حn���ժ��O�^���I���Ӽ�
	cout << "test element_count()" << endl;
	cout << "The numbers of nodes in Linked_list A is " << test.element_count() << endl << endl;

	// test copy constructor
	//�����حn���ժ��O�ƻs�غc�l
	cout << "test copy constructor" << endl;
	Link_list test_copy_constructor = test;
	cout << test_copy_constructor << endl;

	// test insert
	//�����حn���ժ��O���J�I, �ӲĤG�ӶǰѪ��w�q�O�|�b�ĴX���I���J, �]�N�O�N��L�|�ܦ��ĴX���I, �B��᭱���������
	cout << "test insert with Point* and unsignedint" << endl;
	Point* test_insert;
	test_insert = new Point{ 100.0, 100.0, 100.0 };
	//�|�b��0�Ӧ�m���J�I
	test.insert(test_insert, 0);
	cout << test << endl;
	//�|�b�g�����W���B�J����C����3�Ӧ�m���J�I
	test.insert(test_insert, 3);
	cout << test << endl;

	// test insert with link_list
	//�����حn���ժ��O���C���J�t�@�Ӧ�C
	cout << "test insert with Link_list" << endl;
	test_copy_constructor.insert(&test);
	cout << test_copy_constructor << endl;

	// test erase
	//�����حn���ժ��O�h���I�åB���I��X�X��, ��erase()�̭����Ȧs�۪��O�n�h�����ĴX���I
	cout << "test erase" << endl;
	int erase1 = 0, erase2 = 3;
	//�U���|�h������0���I�]�N�O�}�Y
	cout << "The remove node is " << erase1 << ", and the point is " << *test.erase(erase1);
	cout << test << endl;
	//�n�h�����O�ĤT���I�]�N�O�����W���B�J�᪺��C�b�h������3���I
	cout << "The remove node is " << erase2 << ", and the point is " << *test.erase(erase2);
	cout << test << endl;
	// test ostream operator
	//�����حn���ժ��O��X�B��l
	cout << "test ostream operator" << endl;
	cout << test << endl;

	// test another linked_list
	//�����حn���ժ��O�{������ 8 �Ӥ�������C B�A�������e�ХH�üƲ���
	cout << "########################################################" << endl;
	cout << "NOW test Link_list B (radnom points)" << endl;
	Point* test2;
	test2 = new Point[8];
	for (int i = 0; i < 8; i++)
	{
		float x, y, z;
		x = (float)(rand() % 100) / 7;
		y = (float)(rand() % 200) / 7;
		z = (float)(rand() % 300) / 7;
		test2[i] = { x, y, z };
	}

	Link_list test2_constructor(test2, 8);
	cout << test2_constructor << endl;
	// test copy constructor
	cout << "test copy constructor" << endl;
	Link_list test2_copy = test2_constructor;
	cout << test2_copy << endl;
	// test insert
	cout << "test insert node" << endl;
	test2_constructor.insert(test_insert, 0);
	test2_constructor.insert(test_insert, 3);
	cout << test2_constructor << endl;
	cout << "test erase node" << endl;
	cout << "The remove node is " << erase1 << ", and the point is " << *test2_constructor.erase(erase1);
	cout << "The remove node is " << erase2 << ", and the point is " << *test2_constructor.erase(erase2);
	cout << test2_constructor << endl;
	 
	 
	// test another linked_list
	//�����حn���ժ��O�C�������J�@���I��Link_list����0�Ӧ�m
	//�åB��C���إߤ]�O�q���J�}�l, �@�}�l�èS������
	cout << "########################################################" << endl;
	cout << "NOW test Link_list C (insert radnom point to create Link_list)" << endl;
	Link_list test3;
	for (int i = 0; i < 8; i++)
	{
		float x, y, z;
		x = (float)(rand() % 100) / 7;
		y = (float)(rand() % 200) / 7;
		z = (float)(rand() % 300) / 7;
		Point* test3_insert = new Point{ x, y, z };
		cout << i << "\t" << *test3_insert << endl;
		test3.insert(test3_insert, 0);
		cout << test3.element_count() << endl;
		delete test3_insert;
	}
	cout << test3 << endl;
	cout << "The test3's element count should be 8, and he output is " << test3.element_count()  << ". Therefore the function is correct!" << endl;


	cout << endl << endl;
	cout << "���D�^�� : �H�W���Ǧ����禡�i�H�ϥνsĶ���w�]�������A������H " << endl;
	cout << "Point ���� : " << endl;
	cout << "1.  default constructor : ����, �S���g���ܷ|�����D��l�����ӵ��h��" << endl << endl;
	cout << "2.  constructor : ����, �S���g���ܷ|�����D�Ӧp��غc" << endl << endl;
	cout << "3.  destructor : �i�H, �]���L�S���ϥΨ�ʺA�O����, �ҥH�t�η|���ڭ̸Ѻc, �B���|�X��" << endl << endl;
	cout << "4.  subscript operator : ����, �S���g���ܷ|�����D�Ӧ^�Ǥ���F��" << endl << endl;
	cout << "5.  bool operator : ����, �S���g���ܷ|�����D�Ӥ������F��" << endl << endl;
	cout << "6.  istream operator : ����, �S���g���ܷ|�����D�p��N��J�y�ഫ���ڭ̩һݭn�����" << endl << endl;
	cout << "7.  ostream operator : ����, �S���g���ܷ|�����D�ӿ�X����" << endl << endl;
	cout << endl;

	cout << "Link_list ���� : " << endl;
	cout << "1.  default constructor : ����, �S���g���ܷ|�����D��l�����ӵ��h��" << endl << endl;
	cout << "2.  constructor : ����, �S���g���ܷ|�����D�Ӧp��غc" << endl << endl;
	cout << "3.  destructor : ����, �]���L���ϥΨ�ʺA�O����, ���O�t�η|���ڭ̸Ѻc, �����@�w���T" << endl << endl;
	cout << "4.  copy constructor : ����, �S���g���ܷ|�����D�Ӧp��ƻs�L" << endl << endl;
	cout << "5.  insert function : ����, �S���g���ܷ|�����D�Ӧp��i��node���J" << endl << endl;
	cout << "6.  ielement_count function : ����, �S���g���ܷ|�����D�Ӧp��i��p��" << endl << endl;
	cout << "7.  ostream operator : ����, �S���g���ܷ|�����D�ӿ�X����" << endl << endl;
	delete test_insert;
	delete[] test2;
	delete[] foo_A;
	system("pause");
	return 0;
}