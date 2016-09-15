#pragma once
enum BorW {
	none,
	black,
	white
};

class BoardNormal
{
//���ۂɃI�Z�������镔���B�Ђ�����Ԃ�����^�[�����䂵����B
public:
	BoardNormal();
	~BoardNormal();
	bool TurnChange();
	BorW GetBoard(int x, int y);
	void SetBoard(int x, int y, BorW bw);
	BorW GetTurn();
	int GetBoardSize();
	int CountStone(BorW color);
	bool put(int x, int y, bool checkOnly = false);
	void finish();


private:
	BorW board[8][8];
	BorW turn;
	int boardsize = 7;
	int pass=0;

	int check(BorW board, int c, int turn);
};
