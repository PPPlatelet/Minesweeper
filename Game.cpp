#include "Game.h"

//构造函数
Game::Game()
{
	Map = nullptr;
}

//析构函数
Game::~Game()
{
	if (this->Map != nullptr)
	{
		delete this->Map;
		this->Map = nullptr;
	}
}

//开启新游戏
void Game::RunNewGame()
{
	cout << "Choose your Mode:" << endl
		 << "\"0\" to EASY mode" << endl
		 << "\"1\" to MEDIUM mode" << endl
		 << "\"2\" to HARD mode" << endl
		 << "or \'D\' to DEFAULT mode" << endl;
	while (true)
	{
		char ch;
		cin >> ch;
		if (ch == '0')
		{
			this->Map = new GameMap(0);
			break;
		}
		else if (ch == '1')
		{
			this->Map = new GameMap(1);
			break;
		}
		else if (ch == '2')
		{
			this->Map = new GameMap(2);
			break;
		}
		else if (ch == 'D' || ch == 'd')
		{
			int width, length, number;
			cout << "Please set map's width(10~50),length(10~60),and the bomb's number(10~1000)" << endl;
			cout << "Please enter map's width:____\b\b\b";
			cin >> width;
			while (!isdigit(width) || width < 10 || width > 50)
			{
				cout << "Wrong answer!Please enter again:____\b\b\b";
				cin >> width;
			}
			cout << "Please enter map's length:____\b\b\b";
			cin >> length;
			while (!isdigit(length) || length < 10 || length > 60)
			{
				cout << "Wrong answer!Please enter again:____\b\b\b";
				cin >> length;
			}
			cout << "Please enter bomb's number:____\b\b\b";
			cin >> number;
			while (!isdigit(number) || number < 10 || number > 60)
			{
				cout << "Wrong answer!Please enter again:____\b\b\b";
				cin >> number;
			}
			this->Map = new GameMap(length, width, number);
			break;
		}
		else
		{
			cout << "Wrong answer!Please enter again:____\b\b\b";
			continue;
		}
	}
	system("cls");
	cout << "Creating map." << endl;
	Sleep(1000);
	system("cls");
	cout << "Creating map.." << endl;
	Sleep(1000);
	system("cls");
	cout << "Creating map..." << endl;
	Sleep(1000);
	system("cls");
	this->Map->ShowMap();
}

//检查文件
bool Game::CheckFile()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		ifs.close();
		return false;
	}

	//文件存在，但是没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		ifs.close();
		return false;
	}

	//文件存在
	return true;
}

//加载游戏
void Game::Load()
{
	system("cls");
	this->Map = new GameMap();
	this->Map->LoadMap();
	this->Map->ShowMap();
}
void Game::Save()
{
	this->Map->SaveMap();
}

//点亮方块
void Game::Light()
{
	int a, b;
	cout << "Please enter the position:_____\b\b\b";
	cin >> a >> b;
	try
	{
		this->Map->LightS(a, b);
		system("cls");
		this->Map->ShowMap();
		this->Win();
	}
	catch (runtime_error&)
	{
		cout << "A Bomb is exploded!" << endl;
		this->Fail();
	}
}
void Game::Light(int i, int j)
{
	try
	{
		this->Map->LightS(i, j);
		system("cls");
		this->Map->ShowMap();
		this->Win();
	}
	catch (runtime_error&)
	{
		cout << "A Bomb is exploded!" << endl;
		this->Fail();
	}
}

//标记格子
void Game::Flag()
{
	int a, b;
	cout << "Please enter the position:_____\b\b\b";
	cin >> a >> b;
	this->Map->MarkS(a, b);
	system("cls");
	this->Map->ShowMap();
}
void Game::Flag(int i, int j)
{
	this->Map->MarkS(i, j);
	system("cls");
	this->Map->ShowMap();
}

//展示菜单
void Game::ShowMenu()
{
	cout << "Input \"\'number\' \'number\' (\'L\' or \'F\')\" to choice A square." << endl;
	cout << "Or press \'F\' to make a flag,\'L\' to light a square,\'Q\' to quit,\'H\' to view statistics." << endl;
}

//显示游戏统计数据
void Game::ShowStats()
{
	cout << "Gamecount:" << this->Map->ShowGameCount() << endl;
	cout << "Wincount:" << this->Map->ShowWinCount() << endl;
	cout << "Gamemode:" << this->Map->ShowMode() << endl;
	cout << "Mapwidth:" << this->Map->ShowWidth() << endl;
	cout << "Maplength:" << this->Map->ShowLength() << endl;
}

//胜负判定
void Game::Win()
{
	if (this->Map->Count())
	{
		cout << "All the bombs was been defused!You win!" << endl;
		this->Map->DeleteMap();
		(this->Map->ShowWinCount())++;
		cout << "Do you want to run a new game?" << endl;
		char c;
		cin >> c;
		if (c == 'Y' || c == 'y')
			this->RunNewGame();
		else
		{
			system("cls");
			cout << "Bye." << endl;
			Sleep(2000);
			exit(EXIT_SUCCESS);
		}
	}
}
void Game::Fail()
{
	cout << "You Failed!Please run a new game!" << endl;
	char c;
	cin >> c;
	if (c == 'Y' || c == 'y')
		this->RunNewGame();
	else
	{
		system("cls");
		cout << "Bye." << endl;
		Sleep(2000);
		exit(EXIT_SUCCESS);
	}
}
