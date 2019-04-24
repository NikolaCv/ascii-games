#ifndef MINESWEEPER_H_INCLUDED
#define MINESWEEPER_H_INCLUDED

class minesweeper
{
	private:
		int o[100][100];
		int mapa[100][100];
		int n, m, x, y;
		char p, f, mc, nt, z;
		int mina, pobeda, flags;
		bool over;
	public:
		minesweeper();
		int otvori(int i, int j);
		void draw();
		bool gameover();
		void flagf(int i, int j);
		bool pobedaf();
		int brojminaoko(int i, int j);
		void setup();
		void input();
		void gameintro();
		void gameoverprint();
		void pobedaprint();
		void reset();
		void otvori_advanced(int i, int j);
	//	~minesweeper();
};

#endif // MINESWEEPER_H_INCLUDED

