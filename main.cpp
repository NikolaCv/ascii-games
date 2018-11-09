#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "Minesweeper.h"
#include "Minesweeper.cpp"
#include "Snake.h"
#include "Snake.cpp"

int menu()
{
	cout<<"Dobrodosli!"<<endl;
	cout<<"Odaberite jednu od igara:"<<endl;
	cout<<"1. Minesweeper"<<endl;
	cout<<"2. Zmijica"<<endl;
	cout<<"0. Exit"<<endl;
	int m;
	cin>>m;
	while(m<0 || m>2)
	{
		cout<<"Unesite validan broj!"<<endl;
		cin>>m;
	}
	system("CLS");
	return m;
}

int kraj()
{
	cout<<"Mozete ponovo igrati ili izaci."<<endl;
	cout<<"1. Minesweeper"<<endl;
	cout<<"2. Zmijica"<<endl;
	cout<<"0. Exit"<<endl;
	int m;
	cin>>m;
	while(m<0 || m>2)
	{
		cout<<"Unesite validan broj!"<<endl;
		cin>>m;
	}
	system("CLS");
	return m;
}

int main()
{
	int meni;
	meni=menu();
	while(meni)
	{
		switch(meni)
		{
			case 1:
				{
					minesweeper mine;
					mine.reset();
					mine.setup();
					if(mine.pobedaf())
					mine.pobedaprint();
					else
					while(1)
					{
						mine.draw();
						mine.input();
						if(mine.gameover())
						{
							system("CLS");
							cout<<"Izgubili ste!"<<endl<<endl;
							mine.gameoverprint();
							break;
						}
						if(mine.pobedaf())
						{
							mine.pobedaprint();
							break;
						}
					}
						cout<<endl;
						system("pause");
						system("CLS");
						meni=kraj();
						break;
				}
			case 2:
				{
					zmija zmijica;
					while(1)
					{
						zmijica.draw();
						zmijica.pravac();
						zmijica.move();
						zmijica.eatf();
						if(zmijica.gameover())
						{
							zmijica.gameoverprint();
							break;
						}
					}
						cout<<endl;
						system("pause");
						system("CLS");
						meni=kraj();
						break;
				}
		}
	}
	cout<<endl<<"Hvala na igranju!"<<endl;
	system("pause");
}
