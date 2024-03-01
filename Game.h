#pragma once
#ifndef GAME_H_
#define GAME_H_
#include "GameMap.h"

class Game
{
private:
	GameMap* Map;
public:
	//构造函数
	Game();
	//析构函数
	~Game();
	//创建新游戏
	void RunNewGame();
	//检查文件
	bool CheckFile();
	//加载地图
	void Load();
	void Save();
	//点亮方块
	void Light();
	void Light(int i, int j);
	//标记格子
	void Flag();
	void Flag(int i, int j);
	//打印菜单
	void ShowGame() { this->Map->ShowMap(); }
	void ShowMenu();
	//显示游戏统计数据
	void ShowStats();
	//胜负判定
	void Win();
	void Fail();
};
#endif