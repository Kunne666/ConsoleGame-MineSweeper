//=======================================================================================
// Dice.h
// ダイス関連のヘッダーファイル
// 制作：柳瀬 拓臣
//=======================================================================================

// 多重インクルードの防止
#ifndef INCLUDE_BoardHeader
#define INCLUDE_BoardHeader

class Board
{
	// 定数
public:
	static const int NUM_BOM = 10;
	static const int BOARD_WIDTH = 9;
	static const int BOARD_HEIGHT = 9;

	// データメンバの宣言
private:
	bool m_open[BOARD_WIDTH + 2][BOARD_HEIGHT + 2];
	bool m_bom[BOARD_WIDTH + 2][BOARD_HEIGHT + 2];
	char m_borderedBom[BOARD_WIDTH + 2][BOARD_HEIGHT + 2];

	// メンバ関数の宣言
public:
	// コンストラクタ
	Board();
	// デストラクタ
	~Board();

	// 操作
public:
	void InitializeBoard();
	void OpenSquares(int x, int y);
	bool CheckSweeped();
	void BoardRender();
	// ゲッター
	bool GetBomCheck() const { return m_bom; }
	// セッター
	void SetBomCheck(bool bomCheck){}

};

#endif // INCLUDE_BoardHeader

