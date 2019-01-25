//=======================================================================================
// Board.h
// ボード関連のヘッダーファイル
// 制作：柳瀬 拓臣
//=======================================================================================

// 多重インクルードの防止
#ifndef INCLUDE_BoardHeader
#define INCLUDE_BoardHeader

#include "Tile.h"
#include "Singleton.h"

class Board:public Singleton<Board>
{
public:
	friend class Singleton<Board>;

	// 定数
public:
	static const int NUM_MINE = 10;

	// データメンバの宣言
private:
	Tile*** m_tiles;
	int m_width;
	int m_height;

	// メンバ関数の宣言
public:
	// コンストラクタ
	Board();
	// デストラクタ
	~Board();

	// 操作
public:
	void Initialize();
	void Open(int x, int y);
	bool CheckSweeped();
	void Show();
	void Show_Debug();
	// ゲッター
	bool GetIsMine(int x, int y);

private:
	void _Open(int x, int y);
};

#endif // INCLUDE_BoardHeader