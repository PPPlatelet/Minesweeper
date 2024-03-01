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
	//构造函数
	SquareList() { _Head = nullptr; }
	SquareList(class GameMap& map, int _W, int _L);
	//析构函数
	~SquareList();
	//插入数据
	void push_back(Square* sq, int _W, int _L);
	//重载后置++
	const SquareList& operator++(int);
	//点亮地图
	void Light(class GameMap& map);
	//Flag计数
	int Count();
};
#endif 
