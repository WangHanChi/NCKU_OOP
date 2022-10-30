/*
機械所碩一 王漢祺 N16110158
物件導向 HW01_01
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
	// #1測試
	MyGeometry::Point test = { 1.0, 2.0, 3.0 };	//可以成功宣告Point這個struct, 並且把他用Coutinformation印出來
	//應該輸出為(1.0,2.0,3.0)
	cout << "#1 測試 : " << endl << "test的點座標為 " << MyGeometry::Coutinformation(test) << endl << endl;


	// #2測試
	MyGeometry::Point test2 = { 2.0, 2.0, 3.0 };//可以成功使用Point中的成員函式length, 並且可以計算出距離且回傳
	//應該輸出為1.0
	cout << "#2 測試 : " << endl << "距離為 " << test.Length(test2) << endl << endl;


	// #3測試
	MyGeometry::Plane test3 = { 1.0, 2.0, 3.0, 4.0 };//可以成功宣告Plane這個struct, 並且把他用Coutinformation重載之後印出來
	//應該輸出為2x+2y+3z=4
	cout << "#3 測試 : " << endl << "test3的平面方程式為 " << MyGeometry::Coutinformation(test3) << endl << endl;


	// #4測試
	MyGeometry::Point test4 = { 3.0, 2.0, 5.0 };	//使用Coutinformation回傳一個字串
	//應該輸出為(3.0, 2.0, 5.0)
	cout << "#4 測試 : " << endl << "test4的點座標字串回傳測試Continformation " << MyGeometry::Coutinformation(test4) << endl << endl;


	// #5測試
	MyGeometry::Plane test5 = { 1.0, 2.0, 3.0, 4.0 };	//使用Coutinformation重載回傳方程式的字串
	//應該輸出為1x+2y+3z=4
	cout << "#5 測試 : " << endl << "test5 重載 Coutinformatio " << MyGeometry::Coutinformation(test5) << endl << endl;


	// #6測試
	unsigned int a;
	MyGeometry::Point* p;
	p = MyGeometry::LoadPoint("Point_HW1.txt", a);
	if (p == NULL)	//如果開檔錯誤, 就會收到一個空指標的回傳, 接著就結束程式, 使用的錯誤代碼是404
	{
		exit(404);
		std::cin.get();
	}
	//應該要輸出一個指標, 該指標指向的是Point陣列的第0個
	//而假如輸出p->x的話應該要輸出的是txt檔中第一個點的x值, 也就是10.25
	cout << "#6 測試 : " << endl << "測試Loadpoint函數 " << p <<endl << "p的輸出 : ("  << p->x << " " << p->y << " " << p->z  << ")" << "與第一個點相符" << endl;
	cout << "點的個數 : " << a << endl << endl;

	//#7
	double mindistance = -1;	//設定一個最小值
	const MyGeometry::Point* pp = p;	//要用reference要用const宣告
	MyGeometry::Plane plane{ 1.0, 5.2, 4.1, -1.9 };
	MyGeometry::Point* returnpointer = MyGeometry::MinDistance(pp, plane, a, mindistance);
	//應該要輸出距離 0.765117
	cout << "#7 測試 : " << endl << "測試MinDistance函數 " << mindistance << endl << endl;

	//#8
	MyGeometry::Report("HW01_output.txt", *returnpointer, a, mindistance);
	cout << "#8 測試 : " << endl << "測試Report函數 " << "請參考 HW01_output.txt " << endl << endl;


	//free the memory
	delete p;
	delete returnpointer;

	system("pause");
	return 0;
}

