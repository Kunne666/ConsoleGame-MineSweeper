//=======================================================================================
// Dice.h
// �_�C�X�֘A�̃w�b�_�[�t�@�C��
// ����F���� ��b
//=======================================================================================

// ���d�C���N���[�h�̖h�~
#ifndef INCLUDE_BoardHeader
#define INCLUDE_BoardHeader

class Board
{
	// �萔
public:
	static const int NUM_BOM = 10;
	static const int BOARD_WIDTH = 9;
	static const int BOARD_HEIGHT = 9;

	// �f�[�^�����o�̐錾
private:
	bool m_open[BOARD_WIDTH + 2][BOARD_HEIGHT + 2];
	bool m_bom[BOARD_WIDTH + 2][BOARD_HEIGHT + 2];
	char m_borderedBom[BOARD_WIDTH + 2][BOARD_HEIGHT + 2];

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	Board();
	// �f�X�g���N�^
	~Board();

	// ����
public:
	void InitializeBoard();
	void OpenSquares(int x, int y);
	bool CheckSweeped();
	void BoardRender();
	// �Q�b�^�[
	bool GetBomCheck() const { return m_bom; }
	// �Z�b�^�[
	void SetBomCheck(bool bomCheck){}

};

#endif // INCLUDE_BoardHeader

