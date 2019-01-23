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
	void IncrimentNearMineNum() { m_nearMineNum++; }
	// �Q�b�^�[
	bool GetIsOpen()const { return m_isOpen; }
	bool GetIsMine()const { return m_isMine; }
	int GetNearMineNum()const { return m_nearMineNum; }
	// �Z�b�^�[
	void SetOpenFlag(bool flag) { m_isOpen = flag; }
	void SetMineFlag(bool flag) { m_isMine = flag; }
	void SetNearMineNum(int num) { m_nearMineNum = num; }

};

#endif // INCLUDE_TileHeader