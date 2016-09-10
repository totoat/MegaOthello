#include "DxLib.h"
#include "Input.h"
#include "BoardNormal.h"

void Init();

const int SCREEN_SIZE_X = 1280;
const int SCREEN_SIZE_Y = 720;
const int COLORBIT = 16;
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Input Input;
	BoardNormal board;

	bool click = false;
	int pointX, pointY;

	Init();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		Input.GetMouseInfo();

		DrawBox(0, 0, 720, 720, GetColor(0, 255, 0), TRUE);
		DrawBox(721, 0, 1280, 720, GetColor(150, 150, 255), TRUE);

		for (int i = 0; i < board.GetBoardSize()+1; i++) {
			for (int j = 0; j < (board.GetBoardSize()+1); j++) {
				if (i*(720 / (board.GetBoardSize()+1)) < Input.getMouseX() && j*(720 / (board.GetBoardSize()+1)) < Input.getMouseY()&& Input.getMouseX() < (i + 1)*(720 / (board.GetBoardSize()+1)) && Input.getMouseY() < (j + 1)*(720 / (board.GetBoardSize()+1))) {
					DrawBox(i*(720 / (board.GetBoardSize()+1)), j*(720 / (board.GetBoardSize()+1)), (i + 1)*(720 / (board.GetBoardSize()+1)), (j + 1)*(720 / (board.GetBoardSize()+1)), GetColor(255, 255, 0), TRUE);

					pointX = i;
					pointY = j;
				}
			}
		}

		//�c�̐�������
		for (int i = 0; i < board.GetBoardSize()+1 + 1; i++) {
			DrawLine(i*(720 / (board.GetBoardSize()+1)), 0, i*(720 / (board.GetBoardSize()+1)), 720, GetColor(0, 0, 0), 2);
		}

		//���̐�������
		for (int i = 0; i < board.GetBoardSize()+1 + 1; i++) {
			DrawLine(0, i*(720 / (board.GetBoardSize()+1)), 720, i*(720 / (board.GetBoardSize()+1)), GetColor(0, 0, 0), 2);
		}

		SetFontSize(64);
		DrawFormatString(800, 45, GetColor(0, 0, 0), "���@%d��",board.CountStone(black));
		DrawFormatString(800, 125, GetColor(0, 0, 0), "���@%d��",board.CountStone(white));

		if (board.GetTurn() == black) {
			DrawFormatString(800, 300, GetColor(0, 0, 0), "���̔Ԃł�");
		}
		else {
			DrawFormatString(800, 300, GetColor(0, 0, 0), "���̔Ԃł�");
		}
		

		DrawBox(990, 590, 1202, 674, GetColor(255, 50, 50), TRUE);
		DrawBox(990, 590, 1202, 674, GetColor(0, 0, 0), FALSE);
		DrawFormatString(1000, 600, GetColor(0, 0, 0), "�|�[�Y");

		for (int i = 0; i < board.GetBoardSize()+1; i++) {
			for (int j = 0; j < board.GetBoardSize()+1; j++) {
				if (board.GetBoard(i,j) == black) {
					DrawCircle((i + 0.5)*(720 / (board.GetBoardSize()+1)), (j + 0.5)*(720 / (board.GetBoardSize()+1)), (720 / (board.GetBoardSize()+1)) / 2 * 0.8, GetColor(0, 0, 0), TRUE);
				}
				else if (board.GetBoard(i,j) == white) {
					DrawCircle((i + 0.5)*(720 / (board.GetBoardSize()+1)), (j + 0.5)*(720 / (board.GetBoardSize()+1)), (720 / (board.GetBoardSize()+1)) / 2 * 0.8, GetColor(255, 255, 255), TRUE);
					DrawCircle((i + 0.5)*(720 / (board.GetBoardSize()+1)), (j + 0.5)*(720 / (board.GetBoardSize()+1)), (720 / (board.GetBoardSize()+1)) / 2 * 0.8, GetColor(0, 0, 0), FALSE);
				}
			}
		}

		//DrawCircle(mouseX, mouseY, 50, GetColor(0, 0, 0));

		if (Input.getMouseClick() == false && click == true) {
			if (board.put(pointX,pointY,true) == 1) {
				board.put(pointX, pointY);
				board.TurnChange();
			}
		}

		click = Input.getMouseClick();
	}

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void Init() {
	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, COLORBIT);//��ʃT�C�Y�̎w��
														 //SetBackgroundColor(255, 255, 255);
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ݒ�

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		exit;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);//����ʂɕ`��

	SetMouseDispFlag(TRUE);
}