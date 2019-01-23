//=======================================================================================
// Tile.h
// タイル関連のヘッダーファイル
// 制作：柳瀬 拓臣
//=======================================================================================

// 多重インクルードの防止
#ifndef INCLUDE_TileHeader
#define INCLUDE_TileHeader

class Tile
{
	// データメンバの宣言
private:
	bool m_isOpen;
	bool m_isMine;
	int m_nearMineNum;

	// メンバ関数の宣言
public:
	// コンストラクタ
	Tile();
	// デストラクタ
	~Tile();

	// 操作
public:
	void Open();
	void IncrimentNearMineNum() { m_nearMineNum++; }
	// ゲッター
	bool GetIsOpen()const { return m_isOpen; }
	bool GetIsMine()const { return m_isMine; }
	int GetNearMineNum()const { return m_nearMineNum; }
	// セッター
	void SetOpenFlag(bool flag) { m_isOpen = flag; }
	void SetMineFlag(bool flag) { m_isMine = flag; }
	void SetNearMineNum(int num) { m_nearMineNum = num; }

};

#endif // INCLUDE_TileHeader