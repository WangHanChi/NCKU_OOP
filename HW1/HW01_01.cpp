/*
機械所碩一 王漢祺 N16110158
物件導向 HW01_01
HW01_01.cpp
*/

#include <iostream>
#include "HW01_01.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::cout;
using std::string;
using std::endl;
using std::setprecision;

string MyGeometry::Coutinformation(const MyGeometry::Point& point)
{
    string output = "(" + std::to_string(point.x) + "," + std::to_string(point.y) + "," + std::to_string(point.z) + ")";

    return output;
}
//輸入Point之後, 再做字串處理並且回傳

string MyGeometry::Coutinformation(const MyGeometry::Plane& plane)
{
    string output = std::to_string(plane.a) + "x+" + std::to_string(plane.b) + "y+" + std::to_string(plane.c) + "z-" + std::to_string(plane.d) + "=0";

    return output;
}
//輸入Plane之後, 再做字串處理並且回傳

double MyGeometry::Point::Length(const MyGeometry::Point& point) const
{
    double output = abs(x - point.x) * abs(x - point.x) + abs(y - point.y) * abs(y - point.y) + abs(z - point.z) * abs(z - point.z);
    output = sqrt(output);

    return output;
}
//輸入Point之後, 計算出點與點之間的距離之後再回傳

MyGeometry::Point* MyGeometry::LoadPoint(const char* filename, unsigned int& nPoint)
{
    string line, ss;
    int i, count = 0;
    float temppoint_x, temppoint_y, temppoint_z;

    std::ifstream myfile;               
    myfile.open(filename);                  //開檔
    if (!myfile.is_open())                  //如果開檔失敗, 就輸出字串告知, 並且回傳一個空指標
    {
        cout << "the file occurred error when opening!!" << endl;
        return NULL;
    }
    
    
    getline(myfile, line);              //讀取第一行, 並儲存進line裡面
    std::istringstream stream(line);    
    stream >> ss;                       //由於istringstream會遇到空格就停止讀取, 因此就把前面兩個字串丟給ss, 再把我們所要的資訊(個數)讀入i之中
    stream >> ss;
    stream >> i;
    nPoint = i;                         //把個數放進nPoint中, 可以讓主函式讀取的到
    MyGeometry::Point* foo;
    foo = new MyGeometry::Point[i];     //動態配置一個Point陣列, 並且把Point指標foo指向陣列的[0]
    //cout << foo << endl;

    while (getline(myfile, line))
    {
        std::istringstream stream(line);//讀取每行, 並且把x, y, z分別放進對應的變數之中
        string s1, s2, s3;
        stream >> s1;
        stream >> s2;
        stream >> s3;
        temppoint_x = std::stof(s1);    //將字串型別轉換成單精度浮點數
        temppoint_y = std::stof(s2);
        temppoint_z = std::stof(s3);

        foo[count].x = temppoint_x;     //把數值放入每個Point的x, y, ,z 之中
        foo[count].y = temppoint_y;
        foo[count].z = temppoint_z;
        cout << endl << "Point "  << (count + 1) << ": " << foo[count].x << " " << foo[count].y << " " << foo[count].z << endl << endl;
        count++;                        //每讀取完一行就增加, 也就是換到下一個Point
    }
    //cout << foo << endl;
    myfile.close();                     //讀檔完關閉檔案
    return foo;
    


}

MyGeometry::Point* MyGeometry::MinDistance(const MyGeometry::Point*& point, const MyGeometry::Plane& plane, unsigned int& nPoint, double& dis)
{
    double den = sqrt(plane.a * plane.a + plane.b * plane.b + plane.c * plane.c);   //點到面的距離公式的分母
    double min = 10000.0;                                                           //設定一個最小值變數(min)
    float output_x = 0.0, output_y = 0.0, output_z = 0.0;
    for (int i = 0; i < nPoint; ++i)
    {
        double num = abs(point->x * plane.a + point->y * plane.b + point->z * plane.c - plane.d);   //點到面的距離公式的分子
        if ((num / den) < min)          //假如計算出來的值小於最小值變數(min), 就把值丟給最小值變數(min)                                             
        {
            output_x = point->x;        
            output_y = point->y;
            output_z = point->z;
            dis = (num / den);          //計算距離
            min = (num / den);   
        }
        point++;                        //指標指向下一個Point
    }
    MyGeometry::Point* p;
    p = new MyGeometry::Point{ output_x, output_y, output_z };  //動態新增一個點, 並且將此點回傳
    return p;
}

void MyGeometry::Report(const char* filename, MyGeometry::Point& point, unsigned int& nPoint, double& mindistance)
{
    std::ofstream outputfile;       //設定輸出串流ofstream
    outputfile.open(filename);      //開檔

    if(!outputfile.is_open())
    {                               //假如開檔失敗, 就輸出錯誤碼 , 並且return
        cout << "Failed to open the output txt file." << endl;
        return;
    }
    
    outputfile << "物件導向程式設計第一次作業" << endl;
    outputfile << "N16110158 王漢祺" << endl;
    outputfile << "點數目 : " << nPoint << endl;
    outputfile << "最接近 x+5.2y+4.1z = -1.9的點 : (" << point.x << ", " << point.y << ", " << point.z << ")、距離為 : " << mindistance << endl;
    outputfile << "//////////" << "\\\\\\\\\\\\\\\\\\\\" << endl;
    string s4 = "8-1\n#4  std::string Coutinformation(const Point&); \n引數傳入為不可變動的結構(Point)參考(pass by reference)\n回傳值為字串(string)型別的值(pass by value), 也就是複製他的值到新的記憶體區域\n\n";
    string s5 = "#5  std::string Coutinformation(const Plane&); \n引數傳入為不可變動的結構(Plane)參考(pass by reference)\n回傳值為字串(string)型別的值(pass by value), 也就是複製他的值到新的記憶體區域\n\n";
    string s6 = "#6  Point* LoadPoint(const char* filename, unsigned int& nPoint); \n引數傳入為不可變動的字元指標(char*)(pass by pointer)以及無號整數(unsigned int)的參考(pass by reference)\n回傳值為結構指標(Point*)(pass by pointer)\n\n";
    string s7 = "#7  Point* MinDistance(const Point*&, const Plane&, unsigned int& nPoint, double&); \n引數傳入的是不可變動的結構指標(Point*)參考(pass by reference), 不可改變的結構(Plane)參考(pass by reference), 無號整數(unsigned int)的參考(pass by reference)以及雙精度浮點數(double)的參考(pass by reference)\n回傳值為結構指標(Point*)(pass by pointer)\n\n";
    string s8 = "#8  void Report(const char* filename, Point& , unsigned int& , double&); \n引數傳入為不可變動的字元指標(char*)(pass by pointer), 無號整數(unsigned int)的參考(pass by reference)以及雙精度浮點數(double)的參考(pass by reference)\n而回傳值則為空(void)";
    string s9 = "\n\n8-2\n可行, 使用reference的上手難易度比起使用指標低, 並且使用reference在傳入參數(call function)的時候需要使用const宣告的變數\n但是這兩個都不會再複製一個新的值到其他記憶體空間";
    outputfile << s4 << s5 << s6 << s7 << s8 << s9;
    //把字串寫入進輸出串流之中
    outputfile.close();     //關檔
}
