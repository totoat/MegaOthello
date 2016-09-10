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
	
	int result[8] = { 2 }; //���ꂼ��W�����̔��茋�ʁB�^�ォ�玞�v���(0:�����ׂ������F�����炨���Ȃ�,1:������,2:�ǂ̂����ł����Ȃ�,3:�󔒂̂����ł����Ȃ�)0,2,3�̋�ʂ͓���e�X�g�ł̂ݗp����B
	//bool result[8];


	//�u�������ꏊ���󔒂��ǂ���
	if (GetBoard(x,y) != 0) {
		return false;
	}

	//8�������ꂼ��Ђ�����Ԃ��邩�m���߂�Bmode==1�̎��͂Ђ�����Ԃ���Ȃ�Ђ�����Ԃ����Ⴄ
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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x, j = y - 1, c = 0; c < count; j--, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x + 1, j = y - 1, c = 0; c < count; i++, j--, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x + 1, j = y, c = 0; c < count; i++, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x + 1, j = y + 1, c = 0; c < count; i++, j++, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x, j = y + 1, c = 0; c < count; i, j++, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x - 1, j = y + 1, c = 0; c < count; i--, j++, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x - 1, j = y, c = 0; c < count; i--, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
				//printf("%d\n",count);//����e�X�g�p
				for (i = x - 1, j = y - 1, c = 0; c < count; i--, j--, c++) {
					//printf("%d %d\n",x,y);//����e�X�g�p

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
	//checkput�֐��̃`�F�b�N����������Ƃ�����܂Ƃ߂����́Bmain����͌Ăяo���Ȃ�

	//���̔Ԃ̂Ƃ�
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

		//���̔Ԃ̂Ƃ�
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
