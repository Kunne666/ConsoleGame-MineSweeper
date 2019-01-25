//=======================================================================================
// Board.cpp
// �{�[�h�֘A�̃\�[�X�t�@�C��
// ����F���� ��b
//=======================================================================================

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include <iostream>
#include "Console.h"
#include "Board.h"
#include "Tile.h"

using namespace std;

const char* digitStr[] =
{
	"�P", "�Q", "�R", "�S", "�T", "�U", "�V", "�W", "�X",
};

//================================================================
// �R���X�g���N�^
//================================================================
Board::Board()
{
	this->m_width = 9;
	this->m_height = 9;

	m_tiles = new Tile**[m_width];

	for (int i = 0; i < m_width; i++)
	{
		m_tiles[i] = new Tile*[m_height];
		for (int j = 0; j < m_height; j++)
		{
			m_tiles[i][j] = new Tile();
		}
	}
}

//================================================================
// �f�X�g���N�^
//================================================================
Board::~Board()
{
	for (int i = 0; i < m_width; i++)
		delete m_tiles[i];
}

//================================================================
// ������
//================================================================
void Board::Initialize()
{
	for (int x = 0; x < m_width; ++x)
	{
		for (int y = 0; y < m_height; ++y)
		{
			m_tiles[x][y]->SetNearMineNum(0);
			m_tiles[x][y]->SetMineFlag(false);
			m_tiles[x][y]->SetOpenFlag(false);
		}
	}

	for (int i = 0; i < NUM_MINE; ++i)
	{
		int x, y;

		do {
			x = rand() % (m_width - 2) + 1;
			y = rand() % (m_height - 2) + 1;
		} while (m_tiles[x][y]->GetIsMine());
		m_tiles[x][y]->SetMineFlag(true);

		m_tiles[x - 1][y - 1]->IncrimentNearMineNum();
		m_tiles[x][y - 1]->IncrimentNearMineNum();
		m_tiles[x + 1][y - 1]->IncrimentNearMineNum();
		m_tiles[x - 1][y]->IncrimentNearMineNum();
		m_tiles[x + 1][y]->IncrimentNearMineNum();
		m_tiles[x - 1][y + 1]->IncrimentNearMineNum();
		m_tiles[x][y + 1]->IncrimentNearMineNum();
		m_tiles[x + 1][y + 1]->IncrimentNearMineNum();
	}
}

//================================================================
// �}�X���J���F�ċA����֐��̍ŏ��̌Ăяo��
//================================================================
void Board::Open(int x, int y)
{
	_Open(x, y);
}

//================================================================
// �}�X���J���F�ċA
//================================================================
void Board::_Open(int x, int y)
{
	if (x < 0 || x >= m_width || y < 0 || y >= m_height)
		return;

	if (m_tiles[x][y]->GetIsOpen())
		return;

	m_tiles[x][y]->SetOpenFlag(true);

	if (!m_tiles[x][y]->GetIsMine() && m_tiles[x][y]->GetNearMineNum() == 0)
	{
		_Open(x - 1, y - 1);
		_Open(x, y - 1);
		_Open(x + 1, y - 1);
		_Open(x - 1, y);
		_Open(x + 1, y);
		_Open(x - 1, y + 1);
		_Open(x, y + 1);
		_Open(x + 1, y + 1);
	}
}

//================================================================
// �I�[�v���`�F�b�N
//================================================================
bool Board::CheckSweeped()
{
	for (int x = 0; x < m_width; ++x)
	{
		for (int y = 0; y < m_height; ++y)
		{
			if (!m_tiles[x][y]->GetIsMine() && !m_tiles[x][y]->GetIsOpen())
				return false;
		}
	}
	return true;
}

//================================================================
// �\��
//================================================================
void Board::Show()
{
	SetTextColor(COLOR_BLACK);
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
	cout << "��     �� MineSweeper ��     ��" << endl;
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��";
	cout << "\n��     ������������������    ��\n";

	for (int y = 0; y < m_height; ++y)
	{
		cout << "��   " << digitStr[y];

		for (int x = 0; x < m_width; ++x)
		{
			if (!m_tiles[x][y]->GetIsOpen())
				cout << "��";
			else if (m_tiles[x][y]->GetIsMine())
				cout << "��";
			else if (!m_tiles[x][y]->GetNearMineNum())
				cout << "�E";
			else
				cout << " " << m_tiles[x][y]->GetNearMineNum();
		}
		cout << "    ��\n";
	}
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n";
}

//================================================================
// �\��(Debug�p�A���g�����ׂČ�����悤�ɕ\������)
//================================================================
void Board::Show_Debug()
{
	cout << "\n�@������������������\n";

	for (int y = 0; y < m_height; ++y)
	{
		cout << digitStr[y];

		for (int x = 0; x < m_width; ++x)
		{
			// false��ǉ�����ɔ�΂�
			if (false && !m_tiles[x][y]->GetIsOpen())
				cout << "��";
			else if (m_tiles[x][y]->GetIsMine())
				cout << "��";
			else if (!m_tiles[x][y]->GetNearMineNum())
				cout << "�E";
			else
				cout << " " << m_tiles[x][y]->GetNearMineNum();
		}
		cout << "\n";
	}
	cout << "\n";
}

//================================================================
// �n���̗L���F�擾
//================================================================
bool Board::GetIsMine(int x, int y)
{
	if (m_tiles[x][y]->GetIsMine())
		return true;
	return false;
}
