#include "GameMap.h"

//���캯��
GameMap::GameMap() //Ĭ�Ϲ��캯��
{
	this->_Sq = nullptr;
	this->_GameCount = 0;
	this->_WinCount=0;
	this->_Mode = NOMODE;
	this->_Length = 0;
	this->_Width = 0;
	this->_BombNumber = 0;
}
GameMap::GameMap(const int& _M)
{
	this->CreateMap(_M);
	this->_GameCount = 0;
	this->_WinCount = 0;
}
GameMap::GameMap(const int& _W, const int& _L, const int& _N)
{
	this->CreateMap(_W, _L, _N);
	this->_GameCount = 0;
	this->_WinCount = 0;
}

//��������
GameMap::~GameMap() //��������
{
	if (this->_Sq != nullptr)
	{
		for (int i = 0; i < this->_Width; i++)
		{
			for (int j = 0; j < this->_Length; j++)
			{
				delete this->_Sq[i][j];
			}
			delete[] this->_Sq[i];
		}
		delete this->_Sq;
		this->_Sq = nullptr;
		this->_GameCount = 0;
		this->_WinCount = 0;
		this->_Mode = 0;
		this->_Length = 0;
		this->_Width = 0;
		this->_BombNumber = 0;
	}
}

//�������ٵ�ͼ
void GameMap::DeleteMap()
{
		for (int i = 0; i < this->_Width; i++)
		{
			for (int j = 0; j < this->_Length; j++)
			{
				delete this->_Sq[i][j];
			}
			delete[] this->_Sq[i];
		}
		delete this->_Sq;
		this->_Sq = nullptr;
		//�����ͼ����
		this->_Mode = NOMODE;
		this->_Length = 0;
		this->_Width = 0;
		this->_BombNumber = 0;
}

//�����ͼ
void GameMap::CreateMap(const int& _M) //Easy,Medium,Hard
{
	switch (_M)
	{
	case 0: //��ģʽ
		this->_GameCount++;
		this->_Width = EASY;
		this->_Length = EASY;
		this->_BombNumber = EASYNUM;
		this->_Mode = EASYMODE;
		this->CreateMap(EASY, EASY, EASYNUM);
		break;
	case 1: //��ͨģʽ
		this->_GameCount++;
		this->_Width = MEDIUM;
		this->_Length = MEDIUM;
		this->_BombNumber = MEDIUMNUM;
		this->_Mode = MEDIUMMODE;
		this->CreateMap(MEDIUM, MEDIUM, MEDIUMNUM);
		break;
	case 2: //����ģʽ
		this->_GameCount++;
		this->_Width = MEDIUM;
		this->_Length = HARD;
		this->_BombNumber = HARDNUM;
		this->_Mode = HARDMODE;
		this->CreateMap(MEDIUM, HARD, HARDNUM);
		break;
	}
}
void GameMap::CreateMap(const int& _W,const int& _L,const int& _N) //DefaultMode
{
	//�����Ϸģʽ
	if (this->_Mode == NOMODE)
	{
		this->_Mode = DEFAULTMODE;
	}
	//����ָ�봴����ά����
	this->_Sq = new Square * *[_W];
	for (int i = 0; i < _W; i++)
	{
		this->_Sq[i] = new Square * [_L];
		for (int j = 0; j < _L; j++)
		{
			Square * square = new Square(false);
			this->_Sq[i][j] = square;
		}
	}
	//���õ���
	this->PutBomb();
}

//���õ���
void GameMap::PutBomb()
{
	int i = 0;
	srand((unsigned)time(NULL));
	while (i<this->_BombNumber)
	{
		int x = rand() % this->_Width;
		int y = rand() % this->_Length;
		if (this->_Sq[x][y]->ShowB() == false)
		{
			i++;
			this->_Sq[x][y]->ChangeB();
			//�޸���Χ���׼���
			SquareList* S = new SquareList(*this,x, y);
			(*S)++;
			delete S;
		}
	}
}

//��ʾ��ͼ
void GameMap::ShowMap()
{
	cout.setf(ios_base::internal, ios_base::adjustfield);
	cout << "   ";
	for (int i = 0; i < _Length; i++)
	{
		cout << setfill('0') << setw(2) << i << setfill(' ') << ' ';
	}
	cout << endl;
	for (int i = 0; i < _Width; i++)
	{
		cout << setfill('0') << setw(2) << setbase(10)
			<< i << setfill(' ') << ' ';
		for (int j = 0; j < _Length; j++)
		{
			cout << *(this->_Sq[i][j]) << ' ';
		}
		cout << endl;
	}
}

//SL��ͼ
void GameMap::SaveMap()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	ofs << _Width << " " << _Length << " " << _Mode << " " << _BombNumber << endl;
	for (int i = 0; i < _Width; i++)
	{
		for (int j = 0; j < _Length; j++)
		{
			ofs << *(this->_Sq[i][j]);
		}
	}
	ofs.close();
}
void GameMap::LoadMap()
{
	ifstream ifs;
	ifs.open(FILENAME, ios_base::in);
	int w, l, m, b;
	ifs >> w >> l >> m >> b;
	this->_Width = w; this->_Length = l; this->_Mode = m; this->_BombNumber = b;
	//����ָ�봴����ά����
	this->_Sq = new Square * *[this->_Width];
	for (int i = 0; i < this->_Width; i++)
	{
		this->_Sq[i] = new Square * [this->_Length];
		int B, F, L, N;
		for (int j = 0; j < this->_Length; j++)
		{
			ifs >> B >> F >> L >> N;
			Square* square = new Square(B,F,L,N);
			this->_Sq[i][j] = square;
		}
	}
	this->_GameCount++;
	//�رյ�ͼ
	ifs.close();
}

//��������
void GameMap::LightS(int i, int j)
{
	try
	{
		if (i < 0 || i >= this->_Width || j < 0 || j >= this->_Length)
			throw out_of_range(0);
		if (_Sq[i][j]->ShowF()) return; //010N,1100 // ���Flag
		else 
		{
			if (_Sq[i][j]->ShowB()) throw runtime_error(0); //1000 //���Bomb
			else 
			{
				if (!_Sq[i][j]->ShowL()) //000N //���Light
				{
					_Sq[i][j]->ChangeL();
					if (_Sq[i][j]->ShowBN()) return; //N!=0 //���BN
					else //N==0
					{
						SquareList* S =new SquareList(*this,i, j);
						S->Light(*this);
						delete S;
					}
				}
				else //001N
				{
					if (!_Sq[i][j]->ShowBN()) return; //0010
					else //001N
					{
						SquareList* S = new SquareList(*this, i, j);
						if (_Sq[i][j]->ShowBN() == S->Count()) //���Flag��������������Ƿ����
						{
							S->Light(*this);
							delete S;
						} 
						else { delete S; return; }
					}
				}
			}
		}
	}
	catch (const out_of_range&) { return; };
}

//��Ǹ���
void GameMap::MarkS(int i, int j)
{
	try
	{
		if (!this->_Sq[i][j]->ShowL())
		{
			this->_Sq[i][j]->ChangeF();
			return;
		}
	}
	catch (const std::exception&)
	{
		return;
	}
}

//����������
bool GameMap::Count()
{
	int x = 0;
	//��¼������������
	for (int i = 0; i < this->_Width; i++)
		for (int j = 0; j < this->_Length; j++)
			if (this->_Sq[i][j]->ShowL())
				x++;
	return this->_Width * this->_Length - this->_BombNumber == x;
}

//��ʾ��ͼ����
const int& GameMap::ShowGameCount() const
{
	return this->_GameCount;
}
int& GameMap::ShowGameCount()
{
	return this->_GameCount;
}
const int& GameMap::ShowWinCount() const
{
	return this->_WinCount;
}
int& GameMap::ShowWinCount()
{
	return this->_WinCount;
}
const int& GameMap::ShowMode() const
{
	return this->_Mode;
}
const int& GameMap::ShowLength() const
{
	return this->_Length;
}
const int& GameMap::ShowWidth() const
{
	return this->_Width;
}
const int& GameMap::ShowBombNumber() const
{
	return _BombNumber;
}