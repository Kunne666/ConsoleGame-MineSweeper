//=======================================================================================
// GameManager.cpp
// ゲーム管理のソースファイル
// 制作：柳瀬 拓臣
//=======================================================================================

// ヘッダファイルの読み込み ================================================
#include <iostream>
#include <string>
#include "GameManager.h"
#include "Board.h"

using namespace std;

//================================================================
// コンストラクタ
//================================================================
GameManager::GameManager()
{
	m_board = new Board();
}

//================================================================
// デストラクタ
//================================================================
GameManager::~GameManager()
{
	delete m_board;
}

//================================================================
// 初期化
//================================================================
void GameManager::Initialize()
{
	m_board->Initialize();
}

//================================================================
// 更新
//================================================================
void GameManager::Update()
{
	string coordinate;

	for (;;)
	{
		m_board->Initialize();

		bool sweeped = false;

		while (!sweeped)
		{
			m_board->Show();

			int x, y;

			for (;;)
			{
				cout << "座標を入力してください。" << endl;
				cout << "範囲 [a - i] [1 - 9]" << endl;
				cin >> coordinate;

				if (coordinate.size() < 2)
					continue;
				// [a - i]
				if (coordinate[0] >= 'a'&&coordinate[0] <= 'i')
					x = coordinate[0] - 'a' + 1;
				else if (coordinate[0] >= 'A'&&coordinate[0] <= 'I')
					x = coordinate[0] - 'A' + 1;
				else
					continue;
				// [1 - 9]
				if (coordinate[1] >= '1'&&coordinate[1] <= '9')
					y = coordinate[1] - '0';
				else
					continue;

				break;
			}

			m_board->Open(x, y);

			if (m_board->GetIsMine(x,y))
				break;

			sweeped = m_board->CheckSweeped();
		}

		m_board->Show();

		if (sweeped)
			cout << "成功！" << endl;
		else
			cout << "失敗！" << endl;
			
		cout << "もう一度プレイしますか？" << endl;
		cout << "はい[Y] / いいえ[N]" << endl;
		cin >> coordinate;
		if (coordinate == "n" || coordinate == "N")
			break;
	}
}

//================================================================
// 描画
//================================================================
void GameManager::Render()
{
	m_board->Show();
}