#include "SquareList.h"

//构造函数
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

//析构函数
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

//插入数据
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

//重载后置++
const SquareList& SquareList::operator++(int)
{
	Node* _P = this->_Head->_Next;
	while (_P != nullptr)
	{
		(*(_P->_S))++; //调用Square后置++
		_P = _P->_Next;//指针移动到下一个节点
	}
	return *this;
}

//点亮地图
void SquareList::Light(class GameMap& map)
{
	Node* _P = this->_Head->_Next;
	while (_P != nullptr)
	{
		if (!_P->_S->ShowL()) //检查Square不亮
			map.LightS(_P->_Width, _P->_Length);
		_P = _P->_Next; //_P指向下一个节点
	}
}

//Flag计数
int SquareList::Count()
{
	int _N = 0;
	Node* _P = this->_Head->_Next;
	while (_P != nullptr)
	{
		if (_P->_S->ShowF())
			_N++;
		_P = _P->_Next; //_P指向下一个节点
	}
	return _N;
}