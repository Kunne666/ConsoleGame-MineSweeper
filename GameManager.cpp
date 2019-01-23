//=======================================================================================
// GameManager.cpp
// �Q�[���Ǘ��̃\�[�X�t�@�C��
// ����F���� ��b
//=======================================================================================

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include <iostream>
#include <string>
#include "GameManager.h"
#include "Board.h"

using namespace std;

//================================================================
// �R���X�g���N�^
//================================================================
GameManager::GameManager()
{
	m_board = new Board();
}

//================================================================
// �f�X�g���N�^
//================================================================
GameManager::~GameManager()
{
	delete m_board;
}

//================================================================
// ������
//================================================================
void GameManager::Initialize()
{
	m_board->Initialize();
}

//================================================================
// �X�V
//================================================================
void GameManager::Update()
{
	string coordinate;

	for (;;)
	{
		bool sweeped = false;

		while (!sweeped)
		{
			m_board->Show();

			int x, y;

			for (;;)
			{
				cout << "�J�����W����͂��Ă��������B" << endl;
				cout << "�͈� [a - i] [1 - 9]" << endl;
				cin >> coordinate;

				if (coordinate.size() < 2)
					continue;
				// [a - i]
				if (coordinate[0] >= 'a'&&coordinate[0] <= 'i')
					x = coordinate[0] - 'a' + 1;
				else if (coordinate[0] >= 'A'&&coordinate[0] <= 'I')
					x = coordinate[0] - 'A' + 1;
				else
					continue;
				// [1 - 9]
				if (coordinate[1] >= '1'&&coordinate[1] <= '9')
					y = coordinate[1] - '0';
				else
					continue;

				break;
			}

			m_board->Open(x, y);

			//================================================================
			// if (g_mine[x][y])
			if (false)
				break;
			//================================================================

			sweeped = m_board->CheckSweeped();
		}

		m_board->Show();

		if (sweeped)
			cout << "�����I" << endl;
		else
			cout << "���s�I" << endl;
	}
}

//================================================================
// �`��
//================================================================
void GameManager::Render()
{
	m_board->Show();
}