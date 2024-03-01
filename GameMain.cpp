#include "Game.h"


int main()
{
	system("title Minesweeper");
	cout << "Welcome to Minesweeper!" << endl;
	Game game;

	//开启地图
	if (game.CheckFile())
	{
		cout << "A game is not finished!" << endl
			 << "Do you want to load this?" << endl
			 << "or open a new game?(\"Y\"to load)" << endl
			 << "_____\b\b\b\b";
		char s;
		cin >> s;
		if (s == 'Y' || s == 'y')
		{
			game.Load();
		}
		else
		{
			game.RunNewGame();
		}
	}
	else
	{
		cout << "Do you want to open a new game?(\"Y\"to open):_____\b\b\b\b";
		char ch2;
		cin.get(ch2);
		cin.clear();
		if (ch2 == 'Y' || ch2 == 'y')
		{
			game.RunNewGame();
		}
		else
		{
			cout << "Bye." << endl;
			system("pause");
			exit(EXIT_SUCCESS);
		}
	}

	//打印菜单
	game.ShowMenu();
	//提供选择
	while (true)
	{
		cout << "Time to make your choice." << endl;
		char ch[8];
		cin.getline(ch, 8);
		if (isdigit(ch[0]))
		{
			int a = 0, b = 0;
			char* p = &ch[0];
			while (*p != ' ')
			{
				a = a * 10 + *p - 48;
				p++;
			}
			p++;
			while (*p != ' ')
			{
				b = b * 10 + *p - 48;
				p++;
			}
			p++;
			if (*p == 'L' || *p == 'l') // number number L
				game.Light(a, b);
			else if (*p == 'F' || *p == 'f') //number number F
				game.Flag(a, b);
			else // number number NaN
			{
				char c;
				cout << "Please make your choice:_____\b\b\b" ;
				cin.get(c);
				if (c == 'L' || c == 'l')
					game.Light(a, b);
				else if (c == 'F' || c == 'f')
					game.Flag(a, b);
				else
				{
					cout << "No answer!" << endl;
					continue;
				}
			}
		}
		else
		{
			if (ch[0] == 'Q' || ch[0] == 'q')
			{
				char c;
				cout << "Are you sure to quit?" << endl;
				cin >> c;
				if (c == 'Y' || c=='y')
				{
					cout << "Do you want to save the game?" << endl;
					char b;
					cin >> b;
					if (b == 'Y' || b == 'y')
					{
						system("cls");
						game.Save();
						cout << "Bye." << endl;
						Sleep(2000);
						exit(EXIT_SUCCESS);
					}
					else
					{
						system("cls");
						cout << "Bye." << endl;
						Sleep(2000);
						exit(EXIT_SUCCESS);
					}
				}
				else if (c == 'N' || c == 'n')
				{
					system("pause");
					system("cls");
					game.ShowGame();
					continue;
				}
				else
				{
					system("pause");
					system("cls");
					game.ShowGame();
					continue;
				}
			}
			else if (ch[0] == 'H' || ch[0] == 'h')
			{
				game.ShowStats();
				system("pause");
				system("cls");
				game.ShowGame();
			}
			else if (ch[0] == 'F' || ch[0] == 'f')
			{
				game.Flag();
				system("pause");
				system("cls");
				game.ShowGame();
			}
			else if (ch[0] == 'L' || ch[0] == 'l')
			{
				game.Light();
				system("pause");
				system("cls");
				game.ShowGame();
			}
		}
	}

	system("pause");
	return 0;
}