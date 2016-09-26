#pragma once
enum BorW {
	none,
	black,
	white,
	gray
};

class BoardNormal
{
//実際にオセロをする部分。ひっくり返したりターン制御したり。
public:
	BoardNormal();
	~BoardNormal();
	void reset();
	void BoardNormal::resetMurora();
	bool TurnChange();
	BorW GetBoard(int x, int y);
	void SetBoard(int x, int y, BorW bw);
	BorW GetTurn();
	int GetBoardSize();
	int CountStone(BorW color);
	bool put(int x, int y, bool checkOnly = false, BorW turn = none);
	void finish();
	void Com1();
	void Com1Murora();
	void Com2();
	void Com2Murora();


private:
	BorW board[16][16];
	BorW turn;
	int boardsize = 7;
	int pass=0;

	int check(BorW board, int c, int turn);
};
