#pragma once
class Input
{
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