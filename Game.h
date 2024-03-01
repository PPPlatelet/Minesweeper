#pragma once
#ifndef GAME_H_
#define GAME_H_
#include "GameMap.h"

class Game
{
private:
	GameMap* Map;
public:
	//���캯��
	Game();
	//��������
	~Game();
	//��������Ϸ
	void RunNewGame();
	//����ļ�
	bool CheckFile();
	//���ص�ͼ
	void Load();
	void Save();
	//��������
	void Light();
	void Light(int i, int j);
	//��Ǹ���
	void Flag();
	void Flag(int i, int j);
	//��ӡ�˵�
	void ShowGame() { this->Map->ShowMap(); }
	void ShowMenu();
	//��ʾ��Ϸͳ������
	void ShowStats();
	//ʤ���ж�
	void Win();
	void Fail();
};
#endif