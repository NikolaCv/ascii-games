#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>

zmija::zmija()
{
	float s;
	cout<<"Dobrodosli u zmijicu!"<<endl;
	cout<<"Unesite velicinu mape, vecu od 10x10. Sto je mapa veca to manje bodova dobijate."<<endl;
	cout<<"Sirina: "; cin>>m;
	cout<<"Visina: "; cin>>n;
	while(m<10 || n<10)
	{
		cout<<"Unesite validne brojeve!"<<endl;
		cout<<"Sirina: "; cin>>m;
		cout<<"Visina: "; cin>>n;
	}
	cout<<"Unesite brzinu od 1 (sporo) do 5 (brzo). Sto je brzina manja to manje bodova dobijate."<<endl;
	cout<<"Brzina: "; cin>>s;
	while(s>5 || s<=0)
	{
		cout<<"Uneti broj nije u opsegu! Unesite ponovo: "; cin>>s;
	}
	speed=(10/s)*50;
	speedlim=speed/2;
	for(int i=0; i<=n+1; ++i)
	{
		for(int j=0; j<=m+1; ++j)
		mapa[i][j]=' ';
		snake[i].x=0;
		snake[i].y=0;
	}
	srand(time(NULL));
	int x=rand()%n+1;
	int y=rand()%m+1;
	snake[0].x=x;
	this->x=x;
	snake[0].y=y;
	this->y=y;
	xf=x;
	yf=y;
	mapa[x][y]='@';
	while(xf==x && yf==y)
	{
		xf=rand()%n+1;
		yf=rand()%m+1;
		if(xf!=x || yf!=y)
		mapa[xf][yf]='%';
	}
	cout<<"Koristite brojeve 8, 4, 5 (ili 2), 6 na NumPad-u da se krecete. Srecno!"<<endl;
	system("pause");
	d=1;
	dir=0;
	z=219;
}

/*zmija::~zmija()
{
	for(int i=0; i<n; ++i)
	delete []mapa[i];
	delete []snake;
}*/

void zmija::draw()
{
	system("CLS");
	cout<<"Score: "<<setprecision(2)<<fixed<<1.0*(d-1)/(m*n)*(600-speed)<<"\t"<<"Duzina: "<<d-1<<endl;
	for(int i=0; i<=n+1; ++i)
	{
		for(int j=0; j<=m+1; ++j)
		{
			if(j==0 || j==m+1) cout<<z;
			else
			if(i==0 || i==n+1) cout<<z<<z;
			else
			printf("%2c",mapa[i][j]);
		}
		cout<<endl;
	}
	Sleep(speed);
}

void zmija::move()
{
	if(dir==1) x--;
	else
	if(dir==2) y++;
	else
	if(dir==3) x++;
	else
	if(dir==4) y--;
	snake[0].x=x;
	snake[0].y=y;
	if(eat)
	{
		snake[d+1].x=snake[d].x;
		snake[d+1].y=snake[d].y;
	}
	for(int i=d; i>0; --i)
	{
		snake[i].x=snake[i-1].x;
		snake[i].y=snake[i-1].y;
	}
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=m; ++j)
		mapa[i][j]=' ';
		mapa[xf][yf]='%';
	for(int i=1; i<=d; ++i)
	mapa[snake[i].x][snake[i].y]='o';
	mapa[snake[0].x][snake[0].y]='@';
}

void zmija::pravac()
{
	char c;
	if(kbhit())
	{
		c=getch();
		if((c=='8') && snake[2].x!=x-1) dir=1;
		else
		if((c=='6') && snake[2].y!=y+1) dir=2;
		else
		if((c=='5' || c=='2') && snake[2].x!=x+1) dir=3;
		else
		if((c=='4') && snake[2].y!=y-1) dir=4;
	}
}

void zmija::eatf()
{
	if(xf==x && yf==y)
	{
		if(speed>speedlim)
		speed-=speed/50;
		d++;
		eat=1;
		mapa[x][y]='@';
		food();
	}
	else
	eat=0;
}

void zmija::food()
{
	bool t=false;
	int a,b;
	while(!t)
	{
		a=rand()%n+1;
		b=rand()%m+1;
		for(int i=0; i<=d; ++i)
		if(snake[i].x!=a || snake[i].y!=b)
		t=true;
		else
		{
			t=false;
			break;
		}
	}
	xf=a;
	yf=b;
	mapa[xf][yf]='%';
}

bool zmija::gameover()
{
	if(x==0 || y==0 || x==n+1 || y==m+1) return 1;
	for(int i=4; i<=d; ++i)
	if(x==snake[i].x && y==snake[i].y) return 1;
	return 0;
}

void zmija::gameoverprint()
{
	draw();
	cout<<endl;
	cout<<"Game Over"<<endl;
	std::cout << std::setprecision(2);
	cout<<"Score: "<<setprecision(2)<<fixed<<1.0*(d-1)/(m*n)*(600-speed)<<"\t"<<"Duzina: "<<d-1<<endl;
	Sleep(3000);
}
