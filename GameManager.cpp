//=======================================================================================
// GameManager.cpp
// ゲーム管理のソースファイル
// 制作：柳瀬 拓臣
//=======================================================================================

// ヘッダファイルの読み込み ================================================
#include <iostream>
#include <string>
#include <Windows.h>
#include "Console.h"
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

		// Debug用(中身を全て表示)
		//m_board->Show_Debug();

		bool sweeped = false;

		while (!sweeped)
		{
			ClearScreen();
			Sleep(600);
			m_board->Show();

			int x, y;

			for (;;)
			{
				Sleep(600);
				SetTextColor(COLOR_DARK_GREEN);
				cout << "┏ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┓" << endl;
				cout << "┃　座標を入力してください。 ┃" << endl;
				cout << "┠ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┨" << endl;
				cout << "┃　指定範囲 [a - i] [1 - 9] ┃" << endl;
				cout << "┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┛" << endl;
				cin >> coordinate;

				if (coordinate.size() < 2)
					continue;
				// [a - i]
				if (coordinate[0] >= 'a'&&coordinate[0] <= 'i')
					x = coordinate[0] - 'a';
				else if (coordinate[0] >= 'A'&&coordinate[0] <= 'I')
					x = coordinate[0] - 'A';
				else {
					Sleep(600);
					SetTextColor(COLOR_DARK_MAGENTA);
					cout << "┏ ━ ┳ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┳ ━ ┓" << endl;
					cout << "┃ ※┃ 指定範囲外です。  ┃ ※┃" << endl;
					cout << "┗ ━ ┻ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┻ ━ ┛" << endl;
					continue;
				}

				// [1 - 9]
				if (coordinate[1] >= '1'&&coordinate[1] <= '9')
					y = coordinate[1] - '1';
				else{
					Sleep(600);
					SetTextColor(COLOR_DARK_MAGENTA);
					cout << "┏ ━ ┳ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┳ ━ ┓" << endl;
					cout << "┃ ※┃ 指定範囲外です。  ┃ ※┃" << endl;
					cout << "┗ ━ ┻ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┻ ━ ┛" << endl;
					continue;
				}

				break;
			}

			m_board->Open(x, y);

			if (m_board->GetIsMine(x,y))
				break;

			sweeped = m_board->CheckSweeped();
		}

		ClearScreen();
		Sleep(600);
		m_board->Show();

		if (sweeped)
		{
			Sleep(800);
			SetTextColor(COLOR_DARK_RED);
			cout << "┏ ━ ┳ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┳ ━ ┓" << endl;
			cout << "┃ 〇┃        成功！     ┃ 〇┃" << endl;
			cout << "┗ ━ ┻ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┻ ━ ┛" << endl;
		}
		else 
		{
			Sleep(800);
			SetTextColor(COLOR_DARK_BLUE);
			cout << "┏ ━ ┳ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┳ ━ ┓" << endl;
			cout << "┃ ×┃        失敗！     ┃ ×┃" << endl;
			cout << "┗ ━ ┻ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┻ ━ ┛" << endl;
		}
			
		Sleep(800);
		SetTextColor(COLOR_DARK_GREEN);
		cout << "┏ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┓" << endl;
		cout << "┃　もう一度プレイしますか？ ┃" << endl;
		cout << "┣ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┫" << endl;
		cout << "┃　  はい[Y] / いいえ[N]    ┃" << endl;
		cout << "┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┛" << endl;
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