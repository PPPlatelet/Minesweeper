#pragma once
#ifndef SQUARE_H_
#define SQUARE_H_
#include<ctime>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<cctype>
#define FILENAME "Map File.txt"
using namespace std;

class Square
{
private:
	//000N,001N,010N,1000,1100
	//是否为炸弹
	bool _Bomb;
	//是否被标记
	bool _Flag;
	//是否被点亮
	bool _Light;
	//周围地雷的数量(如果不是地雷)
	int _BNumber;
public:
	//构造函数
	explicit Square();
	Square(bool _B);
	Square(bool _B, bool _F, bool _L, int _N);
	//显示是否为炸弹
	bool ShowB() const;
	void ChangeB();
	//显示是否被flag标记
	bool ShowF() const;
	void ChangeF();
	//显示是否被点亮
	bool ShowL() const;
	void ChangeL();
	//显示周围地雷的数量
	const int& ShowBN() const;
	const Square& operator++(int);
	//重载<<运算符
	friend ostream& operator<<(ostream& os,const Square& _S);
	friend ofstream& operator<<(ofstream& ofs, const Square& _S);
};
#endif