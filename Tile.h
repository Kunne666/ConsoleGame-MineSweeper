//=======================================================================================
// Tile.h
// �^�C���֘A�̃w�b�_�[�t�@�C��
// ����F���� ��b
//=======================================================================================

// ���d�C���N���[�h�̖h�~
#ifndef INCLUDE_TileHeader
#define INCLUDE_TileHeader

class Tile
{
	// �f�[�^�����o�̐錾
private:
	bool m_isOpen;
	bool m_isMine;
	int m_nearMineNum;

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	Tile();
	// �f�X�g���N�^
	~Tile();

	// ����
public:
	void Open();
};

#endif // INCLUDE_TileHeader