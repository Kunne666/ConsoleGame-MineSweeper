//=======================================================================================
// GameManager.h
// ゲーム管理のヘッダーファイル
// 制作：柳瀬 拓臣
//=======================================================================================

// 多重インクルードの防止
#ifndef INCLUDE_GameManagerHeader
#define INCLUDE_GameManagerHeader

#include "Board.h"

class GameManager
{
private:
	// データメンバの宣言
	Board* m_board;

	// メンバ関数の宣言
public:
	// コンストラクタ
	GameManager();
	// デストラクタ
	~GameManager();

	// 操作
public:
	void Initialize();
	void Update();
	void Render();
};

#endif // INCLUDE_GameManagerHeader

