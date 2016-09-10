#pragma once
enum BorW {
	none,
	black,
	white
};

class BoardNormal
{
public:
	BoardNormal();
	~BoardNormal();
	void TurnChange();
	BorW GetBoard(int x, int y);
	void SetBoard(int x, int y, BorW bw);
	BorW GetTurn();
	int GetBoardSize();
	int CountStone(BorW color);
	bool put(int x, int y, bool checkOnly = false);


private:
	BorW board[8][8];
	BorW turn;
	int boardsize = 7;

	int check(BorW board, int c, int turn);
};
