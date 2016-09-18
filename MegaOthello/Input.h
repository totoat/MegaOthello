#pragma once
class Input
{
<<<<<<< HEAD
//マウスからの情報を取得するクラス。
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