/*
物件導向程式設計及應用 HW02
機械所碩一 王漢祺 N16110158
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
	//此項目要測試的是建構子
	cout << "NOW test Lnked_list A (File points)" << endl;
	cout << "########################################################" << endl;
	cout << "test constructor" << endl;
	Link_list test(foo_A, num);
	cout << test << endl;

	// test assignment operator
	//此項目要測試的是複製運算子
	cout << "test assignment operator" << endl;
	Link_list test_assignment;
	test_assignment = test;
	cout << test_assignment << endl;

	// test element_count()
	//此項目要測試的是回傳點的個數
	cout << "test element_count()" << endl;
	cout << "The numbers of nodes in Linked_list A is " << test.element_count() << endl << endl;

	// test copy constructor
	//此項目要測試的是複製建構子
	cout << "test copy constructor" << endl;
	Link_list test_copy_constructor = test;
	cout << test_copy_constructor << endl;

	// test insert
	//此項目要測試的是插入點, 而第二個傳參的定義是會在第幾個點插入, 也就是代表他會變成第幾個點, 且把後面的都往後推
	cout << "test insert with Point* and unsignedint" << endl;
	Point* test_insert;
	test_insert = new Point{ 100.0, 100.0, 100.0 };
	//會在第0個位置插入點
	test.insert(test_insert, 0);
	cout << test << endl;
	//會在經歷完上面步驟的串列的第3個位置插入點
	test.insert(test_insert, 3);
	cout << test << endl;

	// test insert with link_list
	//此項目要測試的是把串列插入另一個串列
	cout << "test insert with Link_list" << endl;
	test_copy_constructor.insert(&test);
	cout << test_copy_constructor << endl;

	// test erase
	//此項目要測試的是去掉點並且把點輸出出來, 而erase()裡面的值存著的是要去除的第幾個點
	cout << "test erase" << endl;
	int erase1 = 0, erase2 = 3;
	//下面會去除掉第0的點也就是開頭
	cout << "The remove node is " << erase1 << ", and the point is " << *test.erase(erase1);
	cout << test << endl;
	//要去除的是第三個點也就是做完上面步驟後的串列在去除掉第3個點
	cout << "The remove node is " << erase2 << ", and the point is " << *test.erase(erase2);
	cout << test << endl;
	// test ostream operator
	//此項目要測試的是輸出運算子
	cout << "test ostream operator" << endl;
	cout << test << endl;

	// test another linked_list
	//此項目要測試的是程式產生 8 個元素的串列 B，元素內容請以亂數產生
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
	//此項目要測試的是每次都插入一個點到Link_list的第0個位置
	//並且串列的建立也是從插入開始, 一開始並沒有給值
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
	cout << "問題回答 : 以上哪些成員函式可以使用編譯器預設的版本，為什麼？ " << endl;
	cout << "Point 部分 : " << endl;
	cout << "1.  default constructor : 不行, 沒有寫的話會不知道初始值應該給多少" << endl << endl;
	cout << "2.  constructor : 不行, 沒有寫的話會不知道該如何建構" << endl << endl;
	cout << "3.  destructor : 可以, 因為他沒有使用到動態記憶體, 所以系統會幫我們解構, 且不會出錯" << endl << endl;
	cout << "4.  subscript operator : 不行, 沒有寫的話會不知道該回傳什麼東西" << endl << endl;
	cout << "5.  bool operator : 不行, 沒有寫的話會不知道該比較什麼東西" << endl << endl;
	cout << "6.  istream operator : 不行, 沒有寫的話會不知道如何將輸入流轉換成我們所需要的資料" << endl << endl;
	cout << "7.  ostream operator : 不行, 沒有寫的話會不知道該輸出什麼" << endl << endl;
	cout << endl;

	cout << "Link_list 部分 : " << endl;
	cout << "1.  default constructor : 不行, 沒有寫的話會不知道初始值應該給多少" << endl << endl;
	cout << "2.  constructor : 不行, 沒有寫的話會不知道該如何建構" << endl << endl;
	cout << "3.  destructor : 不行, 因為他有使用到動態記憶體, 但是系統會幫我們解構, 但不一定正確" << endl << endl;
	cout << "4.  copy constructor : 不行, 沒有寫的話會不知道該如何複製他" << endl << endl;
	cout << "5.  insert function : 不行, 沒有寫的話會不知道該如何進行node插入" << endl << endl;
	cout << "6.  ielement_count function : 不行, 沒有寫的話會不知道該如何進行計算" << endl << endl;
	cout << "7.  ostream operator : 不行, 沒有寫的話會不知道該輸出什麼" << endl << endl;
	delete test_insert;
	delete[] test2;
	delete[] foo_A;
	system("pause");
	return 0;
}