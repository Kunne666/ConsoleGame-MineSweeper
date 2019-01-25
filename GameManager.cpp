//=======================================================================================
// GameManager.cpp
// �Q�[���Ǘ��̃\�[�X�t�@�C��
// ����F���� ��b
//=======================================================================================

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include <iostream>
#include <string>
#include <Windows.h>
#include "Console.h"
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
		m_board->Initialize();

		// Debug�p(���g��S�ĕ\��)
		//m_board->Show_Debug();

		bool sweeped = false;

		while (!sweeped)
		{
			ClearScreen();
			Sleep(600);
			m_board->Show();

			int x, y;

			for (;;)
			{
				Sleep(600);
				SetTextColor(COLOR_DARK_GREEN);
				cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
				cout << "���@���W����͂��Ă��������B ��" << endl;
				cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
				cout << "���@�w��͈� [a - i] [1 - 9] ��" << endl;
				cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
				cin >> coordinate;

				if (coordinate.size() < 2)
					continue;
				// [a - i]
				if (coordinate[0] >= 'a'&&coordinate[0] <= 'i')
					x = coordinate[0] - 'a';
				else if (coordinate[0] >= 'A'&&coordinate[0] <= 'I')
					x = coordinate[0] - 'A';
				else {
					Sleep(600);
					SetTextColor(COLOR_DARK_MAGENTA);
					cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
					cout << "�� ���� �w��͈͊O�ł��B  �� ����" << endl;
					cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
					continue;
				}

				// [1 - 9]
				if (coordinate[1] >= '1'&&coordinate[1] <= '9')
					y = coordinate[1] - '1';
				else{
					Sleep(600);
					SetTextColor(COLOR_DARK_MAGENTA);
					cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
					cout << "�� ���� �w��͈͊O�ł��B  �� ����" << endl;
					cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
					continue;
				}

				break;
			}

			m_board->Open(x, y);

			if (m_board->GetIsMine(x,y))
				break;

			sweeped = m_board->CheckSweeped();
		}

		ClearScreen();
		Sleep(600);
		m_board->Show();

		if (sweeped)
		{
			Sleep(800);
			SetTextColor(COLOR_DARK_RED);
			cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
			cout << "�� �Z��        �����I     �� �Z��" << endl;
			cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
		}
		else 
		{
			Sleep(800);
			SetTextColor(COLOR_DARK_BLUE);
			cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
			cout << "�� �~��        ���s�I     �� �~��" << endl;
			cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
		}
			
		Sleep(800);
		SetTextColor(COLOR_DARK_GREEN);
		cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
		cout << "���@������x�v���C���܂����H ��" << endl;
		cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
		cout << "���@  �͂�[Y] / ������[N]    ��" << endl;
		cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
		cin >> coordinate;
		if (coordinate == "n" || coordinate == "N")
			break;
	}
}

//================================================================
// �`��
//================================================================
void GameManager::Render()
{
	m_board->Show();
}