#pragma once
enum BorW {
	none,
	black,
<<<<<<< HEAD
	white,
	gray
=======
	white
>>>>>>> origin/master
};

class BoardNormal
{
<<<<<<< HEAD
//実際にオセロをする部分。ひっくり返したりターン制御したり。
public:
	BoardNormal();
	~BoardNormal();
	void reset();
	void BoardNormal::resetMurora();
	bool TurnChange();
=======
public:
	BoardNormal();
	~BoardNormal();
	void TurnChange();
>>>>>>> origin/master
	BorW GetBoard(int x, int y);
	void SetBoard(int x, int y, BorW bw);
	BorW GetTurn();
	int GetBoardSize();
	int CountStone(BorW color);
<<<<<<< HEAD
	bool put(int x, int y, bool checkOnly = false, BorW turn = none);
	void finish();
	void Com1();
	void Com1Murora();


private:
	BorW board[16][16];
	BorW turn;
	int boardsize = 7;
	int pass=0;
=======
	bool put(int x, int y, bool checkOnly = false);


private:
	BorW board[8][8];
	BorW turn;
	int boardsize = 7;
>>>>>>> origin/master

	int check(BorW board, int c, int turn);
};
