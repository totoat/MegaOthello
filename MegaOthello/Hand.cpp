#include"Hand.h"



Hand::Hand()
{
}

Hand::~Hand()
{
}

void Hand::CheckPoint(int MouseX,int MouseY) {
	pointX = -1;
	pointY = -1;
	for (int i = 0; i < board.GetBoardSize() + 1; i++) {
		for (int j = 0; j < (board.GetBoardSize() + 1); j++) {
			if (i*(720 / (board.GetBoardSize() + 1)) < MouseX && j*(720 / (board.GetBoardSize() + 1)) < MouseY && MouseX < (i + 1)*(720 / (board.GetBoardSize() + 1)) && MouseY < (j + 1)*(720 / (board.GetBoardSize() + 1))) {
				 
				pointX = i;
				pointY = j;
			}
		}
	}
}

void Hand::SetClick(bool input) {
	clickOld = click;
	click = input;
}

bool Hand::CheckMouseDown() {
	if (clickOld == false && click == true) {
		return true;
	}else{
		return false;
	}
}

bool Hand::CheckMouseLeave() {
	if (clickOld == true && click == false) {
		return true;
	}else{
		return false;
	}
}

int Hand::GetPointX() {
	return pointX;
}

int Hand::GetPointY() {
	return pointY;
}