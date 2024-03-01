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
	Square*** _Sq;  //����ָ��
	int _GameCount; //��Ϸ����
	int _WinCount;  //ʤ������
	int _Width;     //��ͼ���
	int _Length;    //��ͼ����
	int _Mode;      //��ǰ�Ѷ�
	int _BombNumber;//��������
	friend class SquareList;
public:
	//���캯��
	GameMap();
	GameMap(const int& _M);
	GameMap(const int& _W, const int& _L, const int& _N);

	//��������
	~GameMap();

	//�������ٵ�ͼ
	void DeleteMap();

	//�����ͼ
	void CreateMap(const int& m);                                //Easy,Medium,Hard
	void CreateMap(const int& _W, const int& _L, const int& _N); //Custom

	//���õ���
	void PutBomb();

	//��ʾ��ͼ
	void ShowMap();

	//SL��ͼ
	void SaveMap();
	void LoadMap();

	//��������
	void LightS(int i,int j);
	
	//��Ǹ���
	void MarkS(int i, int j);

	//����������
	bool Count();

	//��ʾ��ͼ����
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