#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

typedef struct Snake
{
	int x, y ;
}Snake;

class zmija
{
	private:
		int n, m, x, y, xf, yf ;
		char mapa[100][100], c ;
		Snake snake[10000] ;
		int d, dir, eat ;
		float speed, speedlim ;
		char z ;
		bool pobeda ;
	public:
		zmija();
		void draw();
		void move();
		bool gameover();
		void food();
		void eatf();
		void pravac();
		void gameoverprint();
		bool pobedaf();
		void pobedaprint();

	//	~zmija();
};

#endif // SNAKE_H_INCLUDED
