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
	//�Ƿ�Ϊը��
	bool _Bomb;
	//�Ƿ񱻱��
	bool _Flag;
	//�Ƿ񱻵���
	bool _Light;
	//��Χ���׵�����(������ǵ���)
	int _BNumber;
public:
	//���캯��
	explicit Square();
	Square(bool _B);
	Square(bool _B, bool _F, bool _L, int _N);
	//��ʾ�Ƿ�Ϊը��
	bool ShowB() const;
	void ChangeB();
	//��ʾ�Ƿ�flag���
	bool ShowF() const;
	void ChangeF();
	//��ʾ�Ƿ񱻵���
	bool ShowL() const;
	void ChangeL();
	//��ʾ��Χ���׵�����
	const int& ShowBN() const;
	const Square& operator++(int);
	//����<<�����
	friend ostream& operator<<(ostream& os,const Square& _S);
	friend ofstream& operator<<(ofstream& ofs, const Square& _S);
};
#endif