#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

minesweeper::minesweeper()
{
	gameintro();
	x=n/2;
	y=m/2;
	over=false;
	if(mina==0)
	mina=n*m*15/100;
	p='#';
	f='@';
	mc='X';
	nt='N';
	z=219;
	flags=0;
}

void minesweeper::reset()
{
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			mapa[i][j]=0;
			o[i][j]=0;
		}
}

/*minesweeper::~minesweeper()
{
	for(int i=0; i<n; ++i)
	{
		delete []o[i];
		delete []mapa[i];
	}
}*/

void minesweeper::otvori_advanced(int x1, int y1)
{
	int s=0;
	int p=0;
	for(int i=x1-1; i<=x1+1; ++i)
		for(int j=y1-1; j<=y1+1; ++j)
		if((!i!=x1 || !j!=y1) && o[i][j]==2) s++;

	if(s==mapa[x1][y1])
	{
		s=0;
		for(int i=x1-1; i<=x1+1; ++i)
			for(int j=y1-1; j<=y1+1; ++j)
			if(o[i][j]==0 && x>0 && y>0 && y<=m && x<=n) p++;
		pobeda-=p;
		for(int i=x1-1; i<=x1+1; ++i)
			for(int j=y1-1; j<=y1+1; ++j)
			if((!i!=x1 || !j!=y1) && o[i][j]==2 && x>0 && y>0 && y<=m && x<=n) s++;
			pobeda+=8-s;
		if(o[x1-1][y1-1]!=2)
		{
			o[x1-1][y1-1]=0;
			otvori(x1-1,y1-1);
		}
		if(o[x1-1][y1]!=2)
		{
			o[x1-1][y1]=0;
			otvori(x1-1,y1);
		}
		if(o[x1-1][y1+1]!=2)
		{
			o[x1-1][y1+1]=0;
			otvori(x1-1,y1+1);
		}
		if(o[x1][y1-1]!=2)
		{
			o[x1][y1-1]=0;
			otvori(x1,y1-1);
		}
		if(o[x1][y1+1]!=2)
		{
			o[x1][y1+1]=0;
			otvori(x1,y1+1);
		}
		if(o[x1+1][y1-1]!=2)
		{
			o[x1+1][y1-1]=0;
			otvori(x1+1,y1-1);
		}
		if(o[x1+1][y1]!=2)
		{
			o[x1+1][y1]=0;
			otvori(x1+1,y1);
		}
		if(o[x1+1][y1+1]!=2)
		{
			o[x1+1][y1+1]=0;
			otvori(x1+1,y1+1);
		}
	}


}

int minesweeper::brojminaoko(int i, int j)
{
	int s=0;
	for(int x=i-1; x<=i+1; ++x)
		for(int y=j-1; y<=j+1; ++y)
		if(mapa[x][y]==-1) s++;
	return s;
}

int minesweeper::otvori(int x, int y)
{
	if(o[x][y]==0 && x>0 && y>0 && y<=m && x<=n)
	{
		o[x][y]=1;
		if(mapa[x][y]==-1)
		{
			over=true;
			return 0;
		}
		pobeda--;
		if(mapa[x][y]==0)
		{
			otvori(x-1,y-1);
			otvori(x-1,y);
			otvori(x-1,y+1);
			otvori(x,y-1);
			otvori(x,y+1);
			otvori(x+1,y-1);
			otvori(x+1,y);
			otvori(x+1,y+1);
		}
	}

}

void minesweeper::draw()
{
	system("CLS");
	cout<<pobeda<<endl;
	for(int i=0; i<=n+1; ++i)
	{
		for(int j=0; j<=m+1; ++j)
		{
			if(i==x && j==y)
			cout<<" "<<z;
			else
			if(j==0 || j==m+1) cout<<z;
			else
			if(i==0 || i==n+1) cout<<z<<z;
			else
			if(o[i][j]==2)
			printf("%2c",f);
			else
			if(o[i][j]==0)
			printf("%2c",p);
			else
			if(mapa[i][j]!=0)
			printf("%2d",mapa[i][j]);
			else
			cout<<"  ";
		}
		if(i==0) cout<<" Preostalo mina: "<<mina-flags;
		cout<<endl;
	}
}

bool minesweeper::gameover()
{
	if(over)
	return 1;
	return 0;
}

void minesweeper::flagf(int i, int j)
{
	if(o[i][j]==0)
	{
		o[i][j]=2;
		flags++;
	}
	else
	if(o[i][j]!=1)
	{
		o[i][j]=0;
		flags--;
	}
}

bool minesweeper::pobedaf()
{
	if(!pobeda) return 1;
	return 0;
}

void minesweeper::setup()
{
	while(1)
	{
		draw();
		cout<<endl;
		cout<<"MENU"<<endl;
		cout<<"Space\t\tOtvorite polje"<<endl;
		char c;
		c=getch();
		if(c=='8' && x>1) x--;
		else
		if(c=='5' || c=='2' && x<n) x++;
		else
		if(c=='4' && y>1) y--;
		else
		if(c=='6' && y<m) y++;
		else
		if(c==' ')
		{
			break;
		}
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			mapa[i][j]=0;
			o[i][j]=0;
		}
	srand(time(NULL));
	pobeda=m*n-mina;
	for(int i=0; i<mina; )
	{
		int x1=rand()%n+1;
		int y1=rand()%m+1;
		if(mapa[x1][y1]!=-1 && x1!=x && y1!=y)
		{
			mapa[x1][y1]=-1;
			++i;
		}
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		if(mapa[i][j]!=-1)
		mapa[i][j]=brojminaoko(i,j);
	otvori(x,y);
}

void minesweeper::input()
{
	cout<<endl;
	cout<<"MENU"<<endl;
	cout<<"F\t\tPostavite zastavicu"<<endl;
	cout<<"Space\t\tOtvorite polje"<<endl;
	char c;
	c=getch();
	if(c=='8' && x>1) x--;
	else
	if((c=='5' || c=='2') && x<n) x++;
	else
	if(c=='4' && y>1) y--;
	else
	if(c=='6' && y<m) y++;
	else
	if(c=='f' || c=='F')
	{
		flagf(x,y);
	}
	else
	if(c==' ')
	{
		if(o[x][y]==0)
		{
			otvori(x,y);
			if(mapa[x][y]==-1)
			over=true;
		}
		else
		if(o[x][y]==1)
		{
			otvori_advanced(x,y);
		}
	}
}

void minesweeper::gameintro()
{
	cout<<"Dobrodosli u Minesweeper!"<<endl;
	cout<<"Pre nego sto pocnete igru, unesite velicinu mape na kojoj cete igrati."<<endl;
	cout<<"Sirina: "; cin>>m;
	cout<<"Visina: "; cin>>n;
	cout<<"Unesite broj mina koji zelite. Ako zelite da igrica sama to odradi unesite 0."<<endl;
	cin>>mina;
	cout<<"Kada pocnete igru odaberite polje. Mine ce se automatski rasporediti."<<endl;
	cout<<"Prvo polje nikada nece biti mina."<<endl;
	cout<<"Koristite brojeve 8, 4, 5 (ili 2), 6 na NumPad-u da pomerate kursor."<<endl;
	cout<<"Sada ste spremni za igru. Srecno!"<<endl;
	system("Pause");

}

void minesweeper::pobedaprint()
{
	draw();
	cout<<"Svaka cast, pobedili ste!"<<endl;
	Sleep(3000);
}

void minesweeper::gameoverprint()
{
	for(int i=0; i<=n+1; ++i)
	{
		for(int j=0; j<=m+1; ++j)
		{
			if(j==0 || j==m+1) cout<<z;
			else
			if(i==0 || i==n+1) cout<<z<<z;
			else
			if(o[i][j]==2 && mapa[i][j]==-1)
			printf("%2c",f);
			else
			if(o[i][j]==2 && mapa[i][j]!=-1)
			printf("%2c",nt);
			else
			if(o[i][j]==0 && mapa[i][j]==-1)
			printf("%2c",mc);
			else
			if(o[i][j]==0)
			printf("%2c",p);
			else
			if(mapa[i][j]!=0)
			printf("%2d",mapa[i][j]);
			else
			cout<<"  ";
		}
		if(i==0) cout<<"   Preostalo mina: "<<mina-flags;
		cout<<endl;
	}
	cout<<endl;
	cout<<"-1\t\tMesto smrti :D"<<endl;
	cout<<"X\t\tMina"<<endl;
	cout<<"N\t\tNetacno obelezena mina"<<endl;
	cout<<f<<"\t\tTacno obelezena mina"<<endl;
	Sleep(3000);
}
