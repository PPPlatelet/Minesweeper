#include "SquareList.h"

//���캯��
SquareList::SquareList(class GameMap& map,int _W, int _L)
{
	this->_Head = new Node{ nullptr,0,0,nullptr };
	if (_W-1>=0)
	{
		if (_L-1>=0)          this->push_back(map._Sq[_W-1][_L-1],_W-1,_L-1);
		if (_L+1<map._Length) this->push_back(map._Sq[_W-1][_L+1],_W-1,_L+1);
		                      this->push_back(map._Sq[_W-1][ _L ],_W-1, _L );
	}
	if (_L-1>=0)              this->push_back(map._Sq[ _W ][_L-1], _W ,_L-1);
	if (_L+1<map._Length)     this->push_back(map._Sq[ _W ][_L+1], _W ,_L+1);
	if (_W+1<map._Width)
	{
		if (_L-1>=0)          this->push_back(map._Sq[_W+1][_L-1],_W+1,_L-1);
		if (_L+1<map._Length) this->push_back(map._Sq[_W+1][_L+1],_W+1,_L+1);
		                      this->push_back(map._Sq[_W+1][ _L ],_W+1, _L );
	}
}

//��������
SquareList::~SquareList()
{
	if (this->_Head != nullptr)
	{
		Node* pf = this->_Head;
		Node* pl = this->_Head;
		while (pl != nullptr)
		{
			pf = pl->_Next;
			delete pl;
			pl = pf;
		}
		this->_Head = nullptr;
	}
}

//��������
void SquareList::push_back(Square* sq, int _W, int _L)
{
	Node* node = new Node{ sq, _W, _L, nullptr };
	if (this->_Head->_Next == nullptr)
	{
		this->_Head->_Next = node;
		return;
	}
	node->_Next = this->_Head->_Next;
	this->_Head->_Next = node;
}

//���غ���++
const SquareList& SquareList::operator++(int)
{
	Node* _P = this->_Head->_Next;
	while (_P != nullptr)
	{
		(*(_P->_S))++; //����Square����++
		_P = _P->_Next;//ָ���ƶ�����һ���ڵ�
	}
	return *this;
}

//������ͼ
void SquareList::Light(class GameMap& map)
{
	Node* _P = this->_Head->_Next;
	while (_P != nullptr)
	{
		if (!_P->_S->ShowL()) //���Square����
			map.LightS(_P->_Width, _P->_Length);
		_P = _P->_Next; //_Pָ����һ���ڵ�
	}
}

//Flag����
int SquareList::Count()
{
	int _N = 0;
	Node* _P = this->_Head->_Next;
	while (_P != nullptr)
	{
		if (_P->_S->ShowF())
			_N++;
		_P = _P->_Next; //_Pָ����һ���ڵ�
	}
	return _N;
}