#include "BoardNormal.h"
#include "DxLib.h"

BoardNormal::BoardNormal()
{
<<<<<<< HEAD
}

BoardNormal::~BoardNormal()
{
}

void BoardNormal::reset() {
	turn = black;
	boardsize = 7;

	for (int i = 0; i < boardsize+1; i++) {
		for (int j = 0; j < boardsize+1; j++) {
			SetBoard(i, j, none);
=======
	turn = black;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SetBoard(i,j,none);
>>>>>>> origin/master
			if ((i == 4 && j == 3) || (i == 3 && j == 4)) {
				SetBoard(i, j, black);
			}
			else if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
				SetBoard(i, j, white);
			}
		}
	}
}

<<<<<<< HEAD
void BoardNormal::resetMurora(){
	turn = black;
	boardsize = 9;

	for (int i = 0; i < boardsize+1; i++) {
		for (int j = 0; j < boardsize+1; j++) {
			SetBoard(i, j, none);
			if ((i == 5 && j == 4) || (i == 4 && j == 5)) {
				SetBoard(i, j, black);
			}
			else if ((i == 4 && j == 4) || (i == 5 && j == 5)) {
				SetBoard(i, j, white);
			}
			else if ((i == 0 || i == 9) && (j == 0 || j == 9)) {
				SetBoard(i, j, gray);
			}
		}
	}
}

bool BoardNormal::TurnChange()
//ターン交代。ついでに次に置く方がパスしなくても大丈夫かも返す。
{
	bool result = false;

=======
BoardNormal::~BoardNormal()
{
}

void BoardNormal::TurnChange()
{
>>>>>>> origin/master
	if (turn == black) {
		turn = white;
	}
	else
	{
		turn = black;
	}
<<<<<<< HEAD

	for (int i = 0; i <= GetBoardSize(); i++) {
		for (int j = 0; j <= GetBoardSize(); j++) {
			if (put(i, j, true) == true) {
				result = true;
			}
		}
	}


	return result;

=======
>>>>>>> origin/master
}

BorW BoardNormal::GetBoard(int x, int y) {
	return board[x][y];
<<<<<<< HEAD

}

void BoardNormal::SetBoard(int x, int y, BorW bw) {

	board[x][y] = bw;
=======
}

void BoardNormal::SetBoard(int x, int y, BorW bw) {
	
		board[x][y] = bw;
>>>>>>> origin/master

}

BorW BoardNormal::GetTurn() {
	return turn;
}

int BoardNormal::GetBoardSize() {
	return boardsize;
}

int BoardNormal::CountStone(BorW color) {
	int result = 0;
<<<<<<< HEAD
	for (int i = 0; i <= GetBoardSize(); i++) {
=======
	for (int i = 0; i <= GetBoardSize(); i++){
>>>>>>> origin/master
		for (int j = 0; j <= GetBoardSize(); j++) {
			if (GetBoard(i, j) == color) {
				result++;
			}
		}
	}

	return result;
}

<<<<<<< HEAD
bool BoardNormal::put(int x, int y, bool checkOnly, BorW turn) {

	int result[8] = { 2 }; //それぞれ８方向の判定結果。真上から時計回り(0:すぐ隣が同じ色だからおけない,1:おける,2:壁のせいでおけない,3:空白のせいでおけない)0,2,3の区別は動作テストでのみ用いる。
						   //bool result[8];

	if (turn == none) {
		turn = GetTurn();
	}

	//置きたい場所が空白かどうか
	if (GetBoard(x, y) != 0 || (x == -1 || y == -1)) {
=======
bool BoardNormal::put(int x, int y, bool checkOnly ) {
	
	int result[8] = { 2 }; //それぞれ８方向の判定結果。真上から時計回り(0:すぐ隣が同じ色だからおけない,1:おける,2:壁のせいでおけない,3:空白のせいでおけない)0,2,3の区別は動作テストでのみ用いる。
	//bool result[8];


	//置きたい場所が空白かどうか
	if (GetBoard(x,y) != 0) {
>>>>>>> origin/master
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
<<<<<<< HEAD
		if (checkOnly == false) {
			SetBoard(x, y, turn);

			pass = 0;
		}
		return true;
	}
	else {
		return false;
=======
		if (checkOnly==false) {
			SetBoard(x, y, turn);
		}
		return 1;
	}
	else {
		return 0;
>>>>>>> origin/master
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
<<<<<<< HEAD

	return 4;
}

void BoardNormal::finish() {
	turn = none;
}

void BoardNormal::Com1() {
	//COMの思考ルーチン。自分のおける場所がどれくらいあるか、相手のおける場所がどれくらいあるかを基準に考える。相手のおける場所をなくす傾向強め
	//たぶん少なくともりんなよりは強い
	int boardcopy[16][16];//シミュレート用の盤面のコピー
	int mytecount, usertecount;//置ける場所がどれくらいあるか覚えとく
	int score[16][16] = { -1000 };//マスごとの得点。これが一番高いところに置く。
	int memox, memoy, memos = -1000;//スコア比較用変数

	BorW userturn;

	if (GetTurn() == black) {
		userturn = white;
	}
	else if (GetTurn() == white) {
		userturn = black;
	}

	for (int j = 0; j<8; j++) {
		for (int i = 0; i<8; i++) {
			score[i][j] = -1001;
		}
	}

	for (int y = 0; y<boardsize+1; y++) {
		for (int x = 0; x<boardsize+1; x++) {
			//いじくってもいいように盤面をコピーする
			for (int j = 0; j<boardsize+1; j++) {
				for (int i = 0; i<boardsize+1; i++) {
					boardcopy[i][j] = GetBoard(i, j);
				}
			}
			//コピーした盤面に試しに置いてみて自分と相手のおける場所を数える
			mytecount = 0;
			usertecount = 0;



			if (put(x, y, true) == 1) {

				for (int j = 0; j<boardsize+1; j++) {
					for (int i = 0; i<boardsize+1; i++) {
						if (put(i, j, true, GetTurn())) {
							mytecount++;
						}
						if (put(i, j, true), userturn) {
							usertecount++;
						}

					}
				}
				//採点
				score[x][y] = mytecount - 2 * usertecount;
				if ((x == 0 || x == 7) && (y == 0 || y == 7)) {
					score[x][y] += 20;
				}
				else if ((x <= 1 || x >= 6) && (y <= 1 || y >= 6)) {
					score[x][y] -= 20;
				}
			}
			else {
				score[x][y] = -1000;
			}

		}
	}

	//点数比較
	for (int y = 0; y<boardsize+1; y++) {
		for (int x = 0; x<boardsize+1; x++) {
			//printf("%d %d %d \n",x,y,score[x][y]);//動作確認用
			if (score[x][y]>memos) {
				memox = x;
				memoy = y;
				memos = score[x][y];
			}
		}
	}

	put(memox, memoy);

}

void BoardNormal::Com1Murora() {
	//COMの思考ルーチン。自分のおける場所がどれくらいあるか、相手のおける場所がどれくらいあるかを基準に考える。相手のおける場所をなくす傾向強め
	//たぶん少なくともりんなよりは強い
	int boardcopy[16][16];//シミュレート用の盤面のコピー
	int mytecount, usertecount;//置ける場所がどれくらいあるか覚えとく
	int score[16][16] = { -1000 };//マスごとの得点。これが一番高いところに置く。
	int memox, memoy, memos = -1000;//スコア比較用変数

	BorW userturn;

	if (GetTurn() == black) {
		userturn = white;
	}
	else if (GetTurn() == white) {
		userturn = black;
	}

	for (int j = 0; j<8; j++) {
		for (int i = 0; i<8; i++) {
			score[i][j] = -1001;
		}
	}

	for (int y = 0; y<boardsize + 1; y++) {
		for (int x = 0; x<boardsize + 1; x++) {
			//いじくってもいいように盤面をコピーする
			for (int j = 0; j<boardsize + 1; j++) {
				for (int i = 0; i<boardsize + 1; i++) {
					boardcopy[i][j] = GetBoard(i, j);
				}
			}
			//コピーした盤面に試しに置いてみて自分と相手のおける場所を数える
			mytecount = 0;
			usertecount = 0;



			if (put(x, y, true) == 1) {

				for (int j = 0; j<boardsize + 1; j++) {
					for (int i = 0; i<boardsize + 1; i++) {
						if (put(i, j, true, GetTurn())) {
							mytecount++;
						}
						if (put(i, j, true), userturn) {
							usertecount++;
						}

					}
				}
				//採点
				score[x][y] = mytecount - 2 * usertecount;
				if (((x == 1 || x == 8) && (y == 0 || y == 9)) || ((x == 0 || x == 9) && (y == 1 || y == 8))) {
					score[x][y] += 20;
				}
				else if (((x <= 2 || x >= 7) && (y <= 1 || y >= 8)) || ((x <= 1 || x >= 8) && (y <= 2 || y >= 7))) {
					score[x][y] -= 20;
				}
			}
			else {
				score[x][y] = -1000;
			}

		}
	}

	//点数比較
	for (int y = 0; y<boardsize + 1; y++) {
		for (int x = 0; x<boardsize + 1; x++) {
			//printf("%d %d %d \n",x,y,score[x][y]);//動作確認用
			if (score[x][y]>memos) {
				memox = x;
				memoy = y;
				memos = score[x][y];
			}
		}
	}

	put(memox, memoy);

}
=======
	
	return 4;
}
>>>>>>> origin/master
