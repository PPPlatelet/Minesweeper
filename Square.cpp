#include "Square.h"

//构造函数
Square::Square()
{
	this->_Bomb = false;
	this->_Flag = false;
	this->_Light = false;
	this->_BNumber = 0;
}
Square::Square(bool _B)
{
	this->_Bomb = _B;
	this->_Flag = false;
	this->_Light = false;
	this->_BNumber = 0;
}
Square::Square(bool _B, bool _F, bool _L, int _N)
{
	this->_Bomb = _B;
	this->_Flag = _F;
	this->_Light = _L;
	this->_BNumber = _N;
}

//显示是否为炸弹
bool Square::ShowB() const
{
	return this->_Bomb;
}
void Square::ChangeB()
{
	this->_Bomb ^= 1;
}

//显示是否被标记
bool Square::ShowF() const
{
	return this->_Flag;
}
void Square::ChangeF()
{
	this->_Flag ^= 1;
}

//显示是否被点亮
bool Square::ShowL() const
{
	return this->_Light;
}
void Square::ChangeL()
{
	this->_Light ^= 1;
}

//显示周围炸弹数量
const int& Square::ShowBN() const
{
	return this->_BNumber;
}
const Square& Square::operator++(int)
{
	if (!this->ShowB())
	{
		this->_BNumber++;
	}
	return *this;
}

//重载<<运算符
ostream& operator<<(ostream& os, const Square& _S)
{
	cout.setf(ios_base::internal, ios_base::adjustfield);
	if (_S.ShowL()) //如果被点亮,打印周围地雷数量
	{
		os << setfill('0') << setw(2) << _S.ShowBN() << setfill(' ');
	}
	else            //未被点亮则先检查是否被标记
	{
		if (_S.ShowF())
		{
			os << "FF";
		}
		else
		{
			os << "??";
		}
	}
	return os;
}
ofstream& operator<<(ofstream& ofs, const Square& _S)
{
	ofs.setf(ios::app);
	if (_S.ShowB())
	{
		if (_S.ShowF())
		{
			ofs.write("1 1 0 0",7);
		}
		else
		{
			ofs.write("1 0 0 0",7);
		}
	}
	else
	{
		if (_S.ShowL())
		{
			ofs.write("0 0 1 ", 6) << _S._BNumber;
		}
		else
		{
			if (_S.ShowF())
			{
				ofs.write("0 1 0 ", 6) << _S._BNumber;
			}
			else
			{
				ofs.write("0 0 0 ", 6) << _S._BNumber;
			}
		}
	}
	ofs << endl;
	return ofs;
}