//// HW2_indirect_pointer.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
////
//
//#include <iostream>
//#include "HW02.h"
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include <limits>
//using std::cout;
//using std::endl;
//using std::string;
//using std::istream;
//using std::ostream;
//
//int main(int argc, char* argv[])
//{
//	srand(time(NULL));
//	string line, ss;
//	int temp = -1;
//	unsigned int num = 0, count = 0;
//	float temppoint_x, temppoint_y, temppoint_z;
//	std::ifstream myfile;
//	myfile.open("Point_HW2.txt");
//	if (!myfile.is_open())
//	{
//		cout << "open file error" << endl;
//		system("pause");
//		return 0;
//	}
//
//	getline(myfile, line);
//	std::istringstream stream(line);
//	stream >> ss;
//	stream >> ss;
//	stream >> temp;
//	num = temp;
//	Point* foo_A;
//	foo_A = new Point[num];
//
//	while (getline(myfile, line))
//	{
//		std::istringstream stream(line);
//		stream >> foo_A[count++];
//	}
//	myfile.close();
//
//	cout << "NOW test Lnked_list A (File points)" << endl;
//	cout << "########################################################" << endl;
//	cout << "test constructor" << endl;
//	Link_list test(foo_A, num);
//	cout << test << endl;
//
//	cout << "test copy constructor" << endl;
//	Link_list test_copy_constructor = test;
//	cout << test_copy_constructor << endl;
//
//	cout << "test assignment operator" << endl;
//	Link_list test_assignment;
//	test_assignment = test;
//	cout << test_assignment << endl;
//
//	cout << "test insert with Point* and unsignedint" << endl;
//	Point* test_insert;
//	test_insert = new Point{ 100.0, 100.0, 100.0 };
//	//會在第0個位置插入點
//	test.insert(test_insert, 0);
//	cout << test << endl;
//	//會在經歷完上面步驟的串列的第3個位置插入點
//	test.insert(test_insert, 3);
//	cout << test << endl;
//
//	cout << "test insert with Link_list" << endl;
//	test_copy_constructor.insert(&test);
//	cout << test_copy_constructor << endl;
//
//	Point* test_erase;
//	cout << "test erase" << endl;
//	int erase1 = 0, erase2 = 3;
//	//下面會去除掉第0的點也就是開頭
//	test_erase = test.erase(erase1);
//	cout << "The remove node is " << erase1 << ", and the point is " << *test_erase;
//	cout << test << endl;
//	delete test_erase;
//	//要去除的是第三個點也就是做完上面步驟後的串列在去除掉第3個點
//	Point* test_erase2;
//	test_erase2 = test.erase(erase2);
//	cout << "The remove node is " << erase2 << ", and the point is " << *test_erase2;
//	cout << test << endl;
//	delete test_erase2;
//
//
//	system("pause");
//	return 0;
//}
//
