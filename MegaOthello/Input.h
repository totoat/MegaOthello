#pragma once
class Input
{
<<<<<<< HEAD
//�}�E�X����̏����擾����N���X�B
=======
>>>>>>> origin/master
public:
	Input();
	~Input();
	void GetMouseInfo();
	int getMouseX();
	int getMouseY();
	bool getMouseClick();

private:
	int mouseX;
	int mouseY;
	bool mouseClick;
};