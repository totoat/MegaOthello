<<<<<<< HEAD
#include"DxLib.h"
#include"Input.h"
#include"BoardNormal.h"
#include"Hand.h"
#include<string>
#include<stdio.h>

enum scene {
	TITLE,
	GAME,
	PAUSE
};

enum ComType {
	com1,
	com1murora
};

void Init();

int font128;
int font100;

enum scene scene = TITLE;
BorW ComFlag = white;
ComType comtype = com1murora;

void Title();
void Game();


Input input;
BoardNormal board;
Hand hand;

const int SCREEN_SIZE_X = 1280;
const int SCREEN_SIZE_Y = 720;
const int COLORBIT = 16;

const int MESSAGEWAIT = 120;
const int COMWAIT = 60;
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	Init();
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		input.GetMouseInfo();
		hand.SetClick(input.getMouseClick());
		switch (scene)
		{
		case TITLE:
			Title();
			break;
		case GAME:
			Game();
			break;
		case PAUSE:
			break;
		default:
			break;
		}
		
		
	}

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void Init() {
	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, COLORBIT);//��ʃT�C�Y�̎w��
	//SetBackgroundColor(255, 255, 255);
	ChangeWindowMode(true);//�E�B���h�E���[�h�ݒ�

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		exit(0);			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);//����ʂɕ`��

	SetMouseDispFlag(TRUE);

	SetFontSize(64);

	font128 = CreateFontToHandle(NULL, 128, 3);
	font100 = CreateFontToHandle(NULL, 100, 3);


	board.resetMurora();
}

void Title() {
	static int step = 1;
	static int point;
	static bool com;
	static bool murora;
	static BorW comturn;
	static char button1[15] = "�ЂƂ�Ńv���C";
	static char button2[15] = "�ӂ���Ńv���C";

	static bool oldclick = false;

	point = 0;

	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(255, 180, 200), true);

	//�^�C�g��
	DrawStringToHandle((SCREEN_SIZE_X / 2) - (128 * 2), 50, "���o�[�V", GetColor(0, 0, 0), font128);

	//�{�^������1
	if ((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 280 < input.getMouseX() && input.getMouseX() < (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20 && 280 < input.getMouseY()&&input.getMouseY() < 420) {
		DrawBox((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 280, (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20, 420, GetColor(255, 255, 0), true);
		point = 1;
	}else{
		DrawBox((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 280, (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20, 420, GetColor(0, 255, 0), true);
	}
	DrawBox((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 280, (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20, 420, GetColor(0, 0, 0), false);
	DrawStringToHandle((SCREEN_SIZE_X / 2) - (100 * 3.5), 300, button1, GetColor(0, 0, 0), font100);

	//�{�^������2
	if ((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 280 < input.getMouseX() && input.getMouseX() < (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20 && 480 < input.getMouseY() && input.getMouseY() < 620) {
		DrawBox((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 480, (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20, 620, GetColor(255, 255, 0), true);
		point = 2;
	}else{
		DrawBox((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 480, (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20, 620, GetColor(0, 255, 0), true);
	}
	DrawBox((SCREEN_SIZE_X / 2) - (100 * 3.5) - 20, 480, (SCREEN_SIZE_X / 2) + (100 * 3.5) + 20, 620, GetColor(0, 0, 0), false);
	DrawStringToHandle((SCREEN_SIZE_X / 2) - (100 * 3.5), 500, button2, GetColor(0, 0, 0), font100);

	if (input.getMouseClick() == true && oldclick == false) {
		switch (step)
		{
		case 1:if (point == 1) {
				com = true;
			}
			else if (point == 2) {
				com = false;
				
			}
			if (point == 1 || point == 2) {
				step = 2;
			}
			break;

		case 2:
			if (point == 1) {
				murora = false;
			}
			else if (point == 2) {
				murora = true;

			}
			if (point == 1 || point == 2) {
				if (com == true) {
					step = 3;
				}
				else {
					step = 4;
				}
			}
			break;

		case 3:
			if (point == 1) {
				comturn = white;
			}
			else if (point == 2) {
				comturn = black;
			}
			if (point == 1 || point == 2) {
				step = 4;
			}
			break;
		}

		switch (step)
		{
		case 1:
			sprintf_s(button1, "�ЂƂ�Ńv���C");
			sprintf_s(button2, "�ӂ���Ńv���C");
			break;
		case 2:
			sprintf_s(button1, "���ʂ̃��o�[�V");
			sprintf_s(button2, "�ւ�ȃ��o�[�V");
			break;
		case 3:
			sprintf_s(button1, " ��U�Ŏn�߂�");
			sprintf_s(button2, " ��U�Ŏn�߂�");
			break;
		case 4:
			if (com == true) {
				ComFlag = comturn;
				if (ComFlag == black) {
					hand.SetInputFlag(false);
				}
			}
			else {
				ComFlag = none;
				
			}
			if (murora == false) {
				board.reset();
				comtype = com1;
			}
			else {
				board.resetMurora();
				comtype = com1murora;
			}

			step = 1;

			
			scene = GAME;

			break;
		}
	}

	point = 0;
	oldclick = input.getMouseClick();
}

void Game() {
	static char TurnMsg[20];

	static int timer = 0;
	static bool messageFlag = false;

	
	//�Ֆʕ`��----------------------------------------------------
	DrawBox(0, 0, 720, 720, GetColor(0, 255, 0), true);//�Ֆʂ̔w�i

	//�u����ꏊ�̐F��ς���
	if (hand.GetInputFlag() == true) {
		for (int i = 0; i < board.GetBoardSize() + 1; i++) {
			for (int j = 0; j < (board.GetBoardSize() + 1); j++) {
				if (board.put(i,j,true)) {
					DrawBox(i*(720 / (board.GetBoardSize() + 1)), j*(720 / (board.GetBoardSize() + 1)), (i + 1)*(720 / (board.GetBoardSize() + 1)), (j + 1)*(720 / (board.GetBoardSize() + 1)), GetColor(255, 186, 216), TRUE);
				}
			}
		}
	}

	//�J�[�\��
	if (hand.GetInputFlag() == true) {
		for (int i = 0; i < board.GetBoardSize() + 1; i++) {
			for (int j = 0; j < (board.GetBoardSize() + 1); j++) {
				if (i*(720 / (board.GetBoardSize() + 1)) < input.getMouseX() && j*(720 / (board.GetBoardSize() + 1)) < input.getMouseY() && input.getMouseX() < (i + 1)*(720 / (board.GetBoardSize() + 1)) && input.getMouseY() < (j + 1)*(720 / (board.GetBoardSize() + 1))) {
					DrawBox(i*(720 / (board.GetBoardSize() + 1)), j*(720 / (board.GetBoardSize() + 1)), (i + 1)*(720 / (board.GetBoardSize() + 1)), (j + 1)*(720 / (board.GetBoardSize() + 1)), GetColor(255, 255, 0), TRUE);
				}
			}
		}
	}

	hand.CheckPoint(input.getMouseX(), input.getMouseY(),board.GetBoardSize());


	//�c�̐�������
	for (int i = 0; i < board.GetBoardSize() + 1 + 1; i++) {
		DrawLine(i*(720 / (board.GetBoardSize() + 1)), 0, i*(720 / (board.GetBoardSize() + 1)), 720, GetColor(0, 0, 0), 2);
	}

	//���̐�������
	for (int i = 0; i < board.GetBoardSize() + 1 + 1; i++) {
		DrawLine(0, i*(720 / (board.GetBoardSize() + 1)), 720, i*(720 / (board.GetBoardSize() + 1)), GetColor(0, 0, 0), 2);
	}

	//�΂�u��
	for (int i = 0; i < board.GetBoardSize() + 1; i++) {
		for (int j = 0; j < board.GetBoardSize() + 1; j++) {
			if (board.GetBoard(i, j) == black) {
				DrawCircle((i + 0.5)*(720 / (board.GetBoardSize() + 1)), (j + 0.5)*(720 / (board.GetBoardSize() + 1)), (720 / (board.GetBoardSize() + 1)) / 2 * 0.8, GetColor(0, 0, 0), TRUE);
			}
			else if (board.GetBoard(i, j) == white) {
				DrawCircle((i + 0.5)*(720 / (board.GetBoardSize() + 1)), (j + 0.5)*(720 / (board.GetBoardSize() + 1)), (720 / (board.GetBoardSize() + 1)) / 2 * 0.8, GetColor(255, 255, 255), TRUE);
				DrawCircle((i + 0.5)*(720 / (board.GetBoardSize() + 1)), (j + 0.5)*(720 / (board.GetBoardSize() + 1)), (720 / (board.GetBoardSize() + 1)) / 2 * 0.8, GetColor(0, 0, 0), FALSE);
			}
			else if (board.GetBoard(i, j) == gray) {
				//DrawCircle((i + 0.5)*(720 / (board.GetBoardSize() + 1)), (j + 0.5)*(720 / (board.GetBoardSize() + 1)), (720 / (board.GetBoardSize() + 1)) / 2 * 0.8, GetColor(100, 100, 100), TRUE);
				//DrawCircle((i + 0.5)*(720 / (board.GetBoardSize() + 1)), (j + 0.5)*(720 / (board.GetBoardSize() + 1)), (720 / (board.GetBoardSize() + 1)) / 2 * 0.8, GetColor(0, 0, 0), FALSE);
			
				DrawBox(i*(720 / (board.GetBoardSize() + 1)), j*(720 / (board.GetBoardSize() + 1)), (i + 1)*(720 / (board.GetBoardSize() + 1)), (j + 1)*(720 / (board.GetBoardSize() + 1)), GetColor(0, 0, 0), TRUE);

			}
		}
	}

	//���`��----------------------------------------------
	DrawBox(721, 0, 1280, 720, GetColor(150, 150, 255), TRUE);
	
	DrawFormatString(800, 45, GetColor(0, 0, 0), "���@%d��", board.CountStone(black));
	DrawFormatString(800, 125, GetColor(0, 0, 0), "���@%d��", board.CountStone(white));

	//DrawFormatString(800, 45, GetColor(0, 0, 0), "X�@%d��",hand.GetPointX());
	//DrawFormatString(800, 125, GetColor(0, 0, 0), "Y�@%d��",hand.GetPointY());

	if (board.GetTurn() == black) {
		sprintf_s(TurnMsg, "���̔Ԃł�");
	}
	else if (board.GetTurn() == white) {
		sprintf_s(TurnMsg, "���̔Ԃł�");
	}
	DrawFormatString(800, 300, GetColor(0, 0, 0), TurnMsg);


	DrawBox(990, 590, 1202, 674, GetColor(255, 50, 50), TRUE);
	DrawBox(990, 590, 1202, 674, GetColor(0, 0, 0), FALSE);
	DrawFormatString(1000, 600, GetColor(0, 0, 0), "�|�[�Y");

	

	if (messageFlag == true) {
		DrawBox(576, 320, 704, 384, GetColor(0, 255, 255), true);
		DrawBox(576, 320, 704, 384, GetColor(0, 0, 0), false);
		DrawString(576, 320, "�p�X", GetColor(0, 0, 0));

		timer++;
		if (timer > MESSAGEWAIT) {
			messageFlag = false;
			if (board.GetTurn() != ComFlag) {
				hand.SetInputFlag(true);
			}
			timer = 0;
		}

	}
	else if (messageFlag == false && (board.GetTurn() == ComFlag)) {
		timer++;
		if (timer > COMWAIT) {
			if (comtype == com1) {
				board.Com1();
			}else if(comtype==com1murora){
				board.Com1Murora();
			}
			/*if (1) {
				if (0) {*/
			if (board.TurnChange() == false) {
				if (board.TurnChange() == false) {
			
					if (board.CountStone(black) > board.CountStone(white)) {
						sprintf_s(TurnMsg, "���̏����ł�");
					}
					else if (board.CountStone(black) < board.CountStone(white)) {
						sprintf_s(TurnMsg, "���̏����ł�");
					}
					else {
						sprintf_s(TurnMsg, "���������ł�");
					}
					board.finish();
					//break;

				}
				else {
					hand.SetInputFlag(false);
					messageFlag = true;
				}
			}
			else {
				hand.SetInputFlag(true);
			}

			
			timer = 0;
		}
	}


	if (hand.CheckMouseDown() == true) {
		if (board.put(hand.GetPointX(), hand.GetPointY()) == true) {
			if (board.TurnChange() == false) {
				if (board.TurnChange() == false) {
					if (board.CountStone(black) > board.CountStone(white)) {
						sprintf_s(TurnMsg, "���̏����ł�");
					}
					else if (board.CountStone(black) < board.CountStone(white)) {
						sprintf_s(TurnMsg, "���̏����ł�");
					}
					else {
						sprintf_s(TurnMsg, "���������ł�");
					}
					board.finish();
					//break;

				}
				else {
					hand.SetInputFlag(false);
					messageFlag = true;
				}
			}
		}

		if (board.GetTurn() == ComFlag) {
			hand.SetInputFlag(false);
		}
	}

}

=======
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
>>>>>>> origin/master
