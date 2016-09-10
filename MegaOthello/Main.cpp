#include "DxLib.h"
#include "Input.h"
#include "BoardNormal.h"

void Init();

const int SCREEN_SIZE_X = 1280;
const int SCREEN_SIZE_Y = 720;
const int COLORBIT = 16;
// プログラムは WinMain から始まります
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

		if (board.GetTurn() == black) {
			DrawFormatString(800, 300, GetColor(0, 0, 0), "黒の番です");
		}
		else {
			DrawFormatString(800, 300, GetColor(0, 0, 0), "白の番です");
		}
		

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

		//DrawCircle(mouseX, mouseY, 50, GetColor(0, 0, 0));

		if (Input.getMouseClick() == false && click == true) {
			if (board.put(pointX,pointY,true) == 1) {
				board.put(pointX, pointY);
				board.TurnChange();
			}
		}

		click = Input.getMouseClick();
	}

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void Init() {
	// 画面モードの設定
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, COLORBIT);//画面サイズの指定
														 //SetBackgroundColor(255, 255, 255);
	ChangeWindowMode(TRUE);//ウィンドウモード設定

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		exit;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画

	SetMouseDispFlag(TRUE);
}