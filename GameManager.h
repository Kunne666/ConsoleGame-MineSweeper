//=======================================================================================
// GameManager.h
// �Q�[���Ǘ��̃w�b�_�[�t�@�C��
// ����F���� ��b
//=======================================================================================

// ���d�C���N���[�h�̖h�~
#ifndef INCLUDE_GameManagerHeader
#define INCLUDE_GameManagerHeader

#include "Board.h"

class GameManager
{
private:
	// �f�[�^�����o�̐錾
	Board* m_board;

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	GameManager();
	// �f�X�g���N�^
	~GameManager();

	// ����
public:
	void Initialize();
	void Update();
	void Render();
};

#endif // INCLUDE_GameManagerHeader

