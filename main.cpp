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

	game->Initialize();
	game->Update();
	game->Render();

	//Board* board = new Board();
	//string buffer;

	//for (;;) {

	//	board->InitializeBoard();

	//	bool sweeped = false;

	//	while (!sweeped) {

	//		board->BoardRender();

	//		int x, y;
	//		for (;;) {
	//			cout << "���W����͂��Ă��������B [a-i][1-9]\n";
	//			cin >> buffer;

	//			if (buffer == "q") return 0;

	//			if (buffer.size() < 2) continue;

	//			if (buffer[0] >= 'a' && buffer[0] <= 'i')
	//				x = buffer[0] - 'a' + 1;
	//			else if (buffer[0] >= 'A' && buffer[0] <= 'I')
	//				x = buffer[0] - 'A' + 1;
	//			else
	//				continue;
	//			if (buffer[1] >= '1' && buffer[1] <= '9')
	//				y = buffer[1] - '0';
	//			else
	//				continue;
	//			break;
	//		}
	//		board->OpenSquares(x, y);

	//		if (g_mine[x][y])
	//			break;

	//		sweeped = board->CheckSweeped();
	//	}
	//	board->BoardRender();
	//	if (sweeped == true)
	//		cout << "Good-Job !!!  you've sweeped all Mines in success.\n";
	//	else
	//		cout << "Oops !!! You've stepped on a Mine...\n\n";
	//	cout << "\ntry again ?[Y/N]";
	//	cin >> buffer;
	//	if (buffer == "n" || buffer == "N")
	//		break;
	//}

	// ���͑҂�
	cin.get();

	return 0;
}