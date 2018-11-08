#ifndef ZMIJA_H_INCLUDED
#define ZMIJA_H_INCLUDED

typedef struct Snake
{
	int x, y ;
}Snake;

class zmija
{
	private:
		int n, m, x, y, xf, yf ;
		char mapa[100][100] ;
		Snake snake[10000] ;
		int d, dir, eat ;
		float speed, speedlim ;
		char z ;
	public:
		zmija();
		void draw();
		void move();
		bool gameover();
		void food();
		void eatf();
		void pravac();
		void gameoverprint();
	//	~zmija();
};

#endif // ZMIJA_H_INCLUDED
