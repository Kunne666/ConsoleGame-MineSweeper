//=======================================================================================
// Board.cpp
// ボード関連のソースファイル
// 制作：柳瀬 拓臣
//=======================================================================================

// ヘッダファイルの読み込み ================================================
#include "Board.h"
#include <iostream>

using namespace std;

const char *digitStr[] = 
{
	"１", "２", "３", "４", "５", "６", "７", "８", "９",
};

//================================================================
// コンストラクタ
//================================================================
Board::Board()
{

}

//================================================================
// デストラクタ
//================================================================
Board::~Board()
{

}

//================================================================
// ボードの初期化
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
// マスを開く
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
// オープンチェック
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
// ボードを描画
//================================================================
void Board::BoardRender()
{
	cout << "\n　ａｂｃｄｅｆｇｈｉ\n";
	for (int y = 1; y <= BOARD_HEIGHT; ++y) {
		cout << digitStr[y - 1];
		for (int x = 1; x <= BOARD_WIDTH; ++x) {
			if (!m_open[x][y])
				cout << "■";
			else if (m_bom[x][y])
				cout << "※";
			else if (!m_borderedBom[x][y])
				cout << "・";
			else
				cout << " " << (int)m_borderedBom[x][y];
		}
		cout << "\n";
	}
	cout << "\n";
}

