#include"DxLib.h"
#include"Input.h"
#include"BoardNormal.h"
#include"Hand.h"
#include<string>
#include<stdio.h>

void Init();

const int SCREEN_SIZE_X = 1280;
const int SCREEN_SIZE_Y = 720;
const int COLORBIT = 16;

const int MESSAGEWAIT = 180;
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Input input;
	BoardNormal board;
	Hand hand;
	char TurnMsg[20];

	int timer = 0;
	bool messageFlag = false;

	Init();
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		input.GetMouseInfo();
		hand.SetClick(input.getMouseClick());

		DrawBox(0, 0, 720, 720, GetColor(0, 255, 0), TRUE);//盤面の背景

		DrawBox(721, 0, 1280, 720, GetColor(150, 150, 255), TRUE);

		for (int i = 0; i < board.GetBoardSize()+1; i++) {
			for (int j = 0; j < (board.GetBoardSize()+1); j++) {
				if (i*(720 / (board.GetBoardSize()+1)) < input.getMouseX() && j*(720 / (board.GetBoardSize()+1)) < input.getMouseY()&& input.getMouseX() < (i + 1)*(720 / (board.GetBoardSize()+1)) && input.getMouseY() < (j + 1)*(720 / (board.GetBoardSize()+1))) {
					DrawBox(i*(720 / (board.GetBoardSize()+1)), j*(720 / (board.GetBoardSize()+1)), (i + 1)*(720 / (board.GetBoardSize()+1)), (j + 1)*(720 / (board.GetBoardSize()+1)), GetColor(255, 255, 0), TRUE);
				}
			}
		}
		hand.CheckPoint(input.getMouseX(),input.getMouseY());


		//縦の線を引く
		for (int i = 0; i < board.GetBoardSize()+1 + 1; i++) {
			DrawLine(i*(720 / (board.GetBoardSize()+1)), 0, i*(720 / (board.GetBoardSize()+1)), 720, GetColor(0, 0, 0), 2);
		}

		//横の線を引く
		for (int i = 0; i < board.GetBoardSize()+1 + 1; i++) {
			DrawLine(0, i*(720 / (board.GetBoardSize()+1)), 720, i*(720 / (board.GetBoardSize()+1)), GetColor(0, 0, 0), 2);
		}

		SetFontSize(64);
		DrawFormatString(800, 45, GetColor(0, 0, 0), "黒　%d個",board.CountStone(black));
		DrawFormatString(800, 125, GetColor(0, 0, 0), "白　%d個",board.CountStone(white));

		//DrawFormatString(800, 45, GetColor(0, 0, 0), "X　%d個",input.getMouseX());
		//DrawFormatString(800, 125, GetColor(0, 0, 0), "Y　%d個",input.getMouseY());

		if (board.GetTurn() == black) {
			sprintf_s(TurnMsg, "黒の番です");
		}
		else if (board.GetTurn() == white) {
			sprintf_s(TurnMsg, "白の番です");
		}
		DrawFormatString(800, 300, GetColor(0, 0, 0), TurnMsg);
		

		DrawBox(990, 590, 1202, 674, GetColor(255, 50, 50), TRUE);
		DrawBox(990, 590, 1202, 674, GetColor(0, 0, 0), FALSE);
		DrawFormatString(1000, 600, GetColor(0, 0, 0), "ポーズ");

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

		if (messageFlag == true) {
			DrawBox(576, 320, 704, 384, GetColor(0, 255, 255), true);
			DrawString(576, 320, "パス", GetColor(0, 0, 0));

			timer++;
			if (timer > MESSAGEWAIT) {
				messageFlag = false;
				hand.SetInputFlag(true);
				timer = 0;
			}

		}

		if (hand.CheckMouseDown() == true) {
			if (board.put(hand.GetPointX(), hand.GetPointY())==true) {
				if (board.TurnChange() == false) {
					if (board.TurnChange() == false) {
						if (board.CountStone(black) > board.CountStone(white)) {
							sprintf_s(TurnMsg, "黒の勝ちです");
						}
						else if (board.CountStone(black) > board.CountStone(white)) {
							sprintf_s(TurnMsg, "白の勝ちです");
						}else{
							sprintf_s(TurnMsg, "引き分けです");
						}
						board.finish();
						//break;
					
					}else{
						hand.SetInputFlag(false);
						messageFlag = true;
					}
				}
			}
		}

		
	}

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void Init() {
	// 画面モードの設定
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, COLORBIT);//画面サイズの指定
	//SetBackgroundColor(255, 255, 255);
	ChangeWindowMode(true);//ウィンドウモード設定

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		exit(0);			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画

	SetMouseDispFlag(TRUE);
}