#include "BoardNormal.h"
#include "DxLib.h"

BoardNormal::BoardNormal()
{
	turn = black;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SetBoard(i,j,none);
			if ((i == 4 && j == 3) || (i == 3 && j == 4)) {
				SetBoard(i, j, black);
			}
			else if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
				SetBoard(i, j, white);
			}
		}
	}
}

BoardNormal::~BoardNormal()
{
}

void BoardNormal::TurnChange()
{
	if (turn == black) {
		turn = white;
	}
	else
	{
		turn = black;
	}
}

BorW BoardNormal::GetBoard(int x, int y) {
	return board[x][y];
}

void BoardNormal::SetBoard(int x, int y, BorW bw) {
	
		board[x][y] = bw;

}

BorW BoardNormal::GetTurn() {
	return turn;
}

int BoardNormal::GetBoardSize() {
	return boardsize;
}

int BoardNormal::CountStone(BorW color) {
	int result = 0;
	for (int i = 0; i <= GetBoardSize(); i++){
		for (int j = 0; j <= GetBoardSize(); j++) {
			if (GetBoard(i, j) == color) {
				result++;
			}
		}
	}

	return result;
}

bool BoardNormal::put(int x, int y, bool checkOnly ) {
	
	int result[8] = { 2 }; //それぞれ８方向の判定結果。真上から時計回り(0:すぐ隣が同じ色だからおけない,1:おける,2:壁のせいでおけない,3:空白のせいでおけない)0,2,3の区別は動作テストでのみ用いる。
	//bool result[8];


	//置きたい場所が空白かどうか
	if (GetBoard(x,y) != 0) {
		return false;
	}

	//8方向それぞれひっくり返せるか確かめる。mode==1の時はひっくり返せるならひっくり返しちゃう
	//up
	{
		int c;
		int count;
		int i, j;

		for (i = x, j = y - 1, c = 0; j >= 0; j--, c++) {
			result[0] = check(GetBoard(i, j), c, turn);

			if (result[0] != 2) {
				break;
			}

		}
		if (checkOnly == false) {
			if (result[0] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x, j = y - 1, c = 0; c < count; j--, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}


		//upright
		for (i = x + 1, j = y - 1, c = 0; i <= boardsize && j >= 0; i++, j--, c++) {
			result[1] = check(GetBoard(i, j), c, turn);

			if (result[1] != 2) {
				break;
			}
		}
		if (checkOnly == false) {
			if (result[1] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x + 1, j = y - 1, c = 0; c < count; i++, j--, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}

		//right
		for (i = x + 1, j = y, c = 0; i <= boardsize; i++, c++) {

			result[2] = check(GetBoard(i, j), c, turn);

			if (result[2] != 2) {
				break;
			}
		}
		if (checkOnly == false) {
			if (result[2] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x + 1, j = y, c = 0; c < count; i++, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}

		//downright
		for (i = x + 1, j = y + 1, c = 0; i <= boardsize && j <= boardsize; i++, j++, c++) {

			result[3] = check(GetBoard(i, j), c, turn);

			if (result[3] != 2) {
				break;
			}
		}
		if (checkOnly == false) {
			if (result[3] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x + 1, j = y + 1, c = 0; c < count; i++, j++, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}

		//down
		for (i = x, j = y + 1, c = 0; j <= boardsize; j++, c++) {

			result[4] = check(GetBoard(i, j), c, turn);

			if (result[4] != 2) {
				break;
			}
		}
		if (checkOnly == false) {
			if (result[4] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x, j = y + 1, c = 0; c < count; i, j++, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}

		//downledt
		for (i = x - 1, j = y + 1, c = 0; i >= 0 && j <= boardsize; i--, j++, c++) {

			result[5] = check(GetBoard(i, j), c, turn);

			if (result[5] != 2) {
				break;
			}
		}
		if (checkOnly == false) {
			if (result[5] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x - 1, j = y + 1, c = 0; c < count; i--, j++, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}

		//ledt
		for (i = x - 1, j = y, c = 0; i >= 0; i--, c++) {

			result[6] = check(GetBoard(i, j), c, turn);

			if (result[6] != 2) {
				break;
			}
		}
		if (checkOnly == false) {
			if (result[6] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x - 1, j = y, c = 0; c < count; i--, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}

		//upleft
		for (i = x - 1, j = y - 1, c = 0; i >= 0 && j >= 0; i--, j--, c++) {

			result[7] = check(GetBoard(i, j), c, turn);

			if (result[7] != 2) {
				break;
			}
		}
		if (checkOnly == false) {
			if (result[7] == 1) {
				count = c;
				//printf("%d\n",count);//動作テスト用
				for (i = x - 1, j = y - 1, c = 0; c < count; i--, j--, c++) {
					//printf("%d %d\n",x,y);//動作テスト用

					SetBoard(i, j, turn);
				}
			}
		}
	}

	if (result[0] == 1 || result[1] == 1 || result[2] == 1 || result[3] == 1 || result[4] == 1 || result[5] == 1 || result[6] == 1 || result[7] == 1) {
		if (checkOnly==false) {
			SetBoard(x, y, turn);
		}
		return 1;
	}
	else {
		return 0;
	}

}

int BoardNormal::check(BorW board, int c, int turn) {
	//checkput関数のチェック処理をするところをまとめたもの。mainからは呼び出さない

	//黒の番のとき
	if (turn == black) {
		switch (board) {
		case black:
			if (c == 0) {
				return 0;
			}
			else {
				return 1;
			}
		case none:
			return 3;
		default:
			return 2;
		}

		//白の番のとき
	}
	else if (turn == white) {
		switch (board) {
		case white:
			if (c == 0) {
				return 0;
			}
			else {
				return 1;
			}
		case none:
			return 3;
		default:
			return 2;
		}
	}
	
	return 4;
}
