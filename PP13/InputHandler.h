#pragma once
#include "SDL.h"

class InputHandler
{
public:
	const Uint8* m_keystates;
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	bool isKeyDown(SDL_Scancode key);
	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;
