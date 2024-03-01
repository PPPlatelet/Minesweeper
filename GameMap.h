#pragma once
#ifndef GAMEMAP_H_
#define GAMEMAP_H_
#include "Square.h"
#include "SquareList.h"

class GameMap
{
private:
	enum GameMode {NOMODE = -1,EASYMODE = 0,MEDIUMMODE = 1,HARDMODE = 2,DEFAULTMODE = 3};
	enum Mode {EASY = 9,MEDIUM = 16,HARD =30};
	enum Number {EASYNUM = 10,MEDIUMNUM = 40,HARDNUM = 99};
	Square*** _Sq;  //三级指针
	int _GameCount; //游戏次数
	int _WinCount;  //胜利次数
	int _Width;     //地图宽度
	int _Length;    //地图长度
	int _Mode;      //当前难度
	int _BombNumber;//地雷数量
	friend class SquareList;
public:
	//构造函数
	GameMap();
	GameMap(const int& _M);
	GameMap(const int& _W, const int& _L, const int& _N);

	//析构函数
	~GameMap();

	//主动销毁地图
	void DeleteMap();

	//构造地图
	void CreateMap(const int& m);                                //Easy,Medium,Hard
	void CreateMap(const int& _W, const int& _L, const int& _N); //Custom

	//放置地雷
	void PutBomb();

	//显示地图
	void ShowMap();

	//SL地图
	void SaveMap();
	void LoadMap();

	//点亮格子
	void LightS(int i,int j);
	
	//标记格子
	void MarkS(int i, int j);

	//检测点亮数量
	bool Count();

	//显示地图属性
	const int& ShowGameCount() const;
	int& ShowGameCount();
	const int& ShowWinCount() const;
	int& ShowWinCount();
	const int& ShowMode() const;
	const int& ShowLength() const;
	const int& ShowWidth() const;
	const int& ShowBombNumber() const;
};
#endif