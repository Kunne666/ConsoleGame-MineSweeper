//=======================================================================================
// Board.cpp
// �{�[�h�֘A�̃\�[�X�t�@�C��
// ����F���� ��b
//=======================================================================================

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Board.h"
#include <iostream>

using namespace std;

const char *digitStr[] = 
{
	"�P", "�Q", "�R", "�S", "�T", "�U", "�V", "�W", "�X",
};

//================================================================
// �R���X�g���N�^
//================================================================
Board::Board()
{

}

//================================================================
// �f�X�g���N�^
//================================================================
Board::~Board()
{

}

//================================================================
// �{�[�h�̏�����
//================================================================
void Board::InitializeBoard()
{
	for (int x = 0; x < BOARD_WIDTH + 2; ++x) {
		for (int y = 0; y < BOARD_HEIGHT + 2; ++y) {
			m_bom[x][y] = false;
			m_borderedBom[x][y] = 0;
			m_open[x][y] = false;
		}
	}

	for (int i = 0; i < NUM_BOM; ++i) {
		int x, y;
		do {
			x = rand() % BOARD_WIDTH + 1;
			y = rand() % BOARD_HEIGHT + 1;
		} while (m_bom[x][y]);
		m_bom[x][y] = true;

		m_borderedBom[x - 1][y - 1] += 1;
		m_borderedBom[x][y - 1] += 1;
		m_borderedBom[x + 1][y - 1] += 1;
		m_borderedBom[x - 1][y] += 1;
		m_borderedBom[x + 1][y] += 1;
		m_borderedBom[x - 1][y + 1] += 1;
		m_borderedBom[x][y + 1] += 1;
		m_borderedBom[x + 1][y + 1] += 1;
	}
}

//================================================================
// �}�X���J��
//================================================================
void Board::OpenSquares(int x, int y)
{
	if (x < 1 || x > BOARD_WIDTH || y < 1 || y > BOARD_HEIGHT)
		return;
	if (m_open[x][y])
		return;
	m_open[x][y] = true;
	if (!m_bom[x][y] && !m_borderedBom[x][y]) {
		OpenSquares(x - 1, y - 1);
		OpenSquares(x, y - 1);
		OpenSquares(x + 1, y - 1);
		OpenSquares(x - 1, y);
		OpenSquares(x + 1, y);
		OpenSquares(x - 1, y + 1);
		OpenSquares(x, y + 1);
		OpenSquares(x + 1, y + 1);
	}
}

//================================================================
// �I�[�v���`�F�b�N
//================================================================
bool Board::CheckSweeped()
{
	for (int x = 1; x <= BOARD_WIDTH; ++x) {
		for (int y = 1; y <= BOARD_HEIGHT; ++y) {
			if (!m_bom[x][y] && !m_open[x][y])
				return false;
		}
	}
	return true;
}

//================================================================
// �{�[�h��`��
//================================================================
void Board::BoardRender()
{
	cout << "\n�@������������������\n";
	for (int y = 1; y <= BOARD_HEIGHT; ++y) {
		cout << digitStr[y - 1];
		for (int x = 1; x <= BOARD_WIDTH; ++x) {
			if (!m_open[x][y])
				cout << "��";
			else if (m_bom[x][y])
				cout << "��";
			else if (!m_borderedBom[x][y])
				cout << "�E";
			else
				cout << " " << (int)m_borderedBom[x][y];
		}
		cout << "\n";
	}
	cout << "\n";
}

