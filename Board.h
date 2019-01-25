//=======================================================================================
// Board.h
// �{�[�h�֘A�̃w�b�_�[�t�@�C��
// ����F���� ��b
//=======================================================================================

// ���d�C���N���[�h�̖h�~
#ifndef INCLUDE_BoardHeader
#define INCLUDE_BoardHeader

#include "Tile.h"
#include "Singleton.h"

class Board:public Singleton<Board>
{
public:
	friend class Singleton<Board>;

	// �萔
public:
	static const int NUM_MINE = 10;

	// �f�[�^�����o�̐錾
private:
	Tile*** m_tiles;
	int m_width;
	int m_height;

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	Board();
	// �f�X�g���N�^
	~Board();

	// ����
public:
	void Initialize();
	void Open(int x, int y);
	bool CheckSweeped();
	void Show();
	void Show_Debug();
	// �Q�b�^�[
	bool GetIsMine(int x, int y);

private:
	void _Open(int x, int y);
};

#endif // INCLUDE_BoardHeader