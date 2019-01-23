//=======================================================================================
//�@C++
//�@�ۑ�   �F�R���\�[���Q�[������
//         �@�y�}�C���X�C�[�p�[�z
//�@���O   �F���� ��b
//  ��o�� �F2019/01/24
//=======================================================================================
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <string>
#include "GameManager.h"

using namespace std;

// ���������[�N�̌��o�̏���
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

int main()
{
	// ���������[�N�̌��o
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	// �����V�[�h�̐���
	srand(static_cast<unsigned int>(time(nullptr)));

	GameManager* game = new GameManager;

	game->Update();

	// ���͑҂�
	cin.get();

	return 0;
}