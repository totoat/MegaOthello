#pragma once
#include"BoardNormal.h"


class Hand
{
//Input関数で得た情報を使って、プレイヤーがどこに置くかを決めるクラス
public:
	Hand();
	~Hand();
	void CheckPoint(int MouseX, int MouseY);
	void SetClick(bool input);
	bool CheckMouseDown();
	bool CheckMouseLeave();
	int GetPointX();
	int GetPointY();
	void SetInputFlag(bool input);
	bool GetInputFlag();

private:
	BoardNormal board;
	int pointX;
	int pointY;
	bool click = false;
	bool clickOld = false;
	bool inputFlag = true;
};