#pragma once
#include"BoardNormal.h"


class Hand
{
//Input�֐��œ��������g���āA�v���C���[���ǂ��ɒu���������߂�N���X
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