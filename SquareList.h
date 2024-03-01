#pragma once
#ifndef SQUARELIST_H_
#define SQUARELIST_H_
#include"GameMap.h"

class SquareList
{
private:
	struct Node
	{
		Square* _S;
		int _Width;
		int _Length;
		Node* _Next;
	};
	Node* _Head;
public:
	//���캯��
	SquareList() { _Head = nullptr; }
	SquareList(class GameMap& map, int _W, int _L);
	//��������
	~SquareList();
	//��������
	void push_back(Square* sq, int _W, int _L);
	//���غ���++
	const SquareList& operator++(int);
	//������ͼ
	void Light(class GameMap& map);
	//Flag����
	int Count();
};
#endif 
