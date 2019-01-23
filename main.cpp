//=======================================================================================
//　C++
//　課題   ：コンソールゲーム制作
//         　【マインスイーパー】
//　名前   ：柳瀬 拓臣
//  提出日 ：2019/01/24
//=======================================================================================
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <string>
#include "GameManager.h"

using namespace std;

// メモリリークの検出の準備
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

int main()
{
	// メモリリークの検出
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	// 乱数シードの生成
	srand(static_cast<unsigned int>(time(nullptr)));

	GameManager* game = new GameManager;

	game->Update();

	// 入力待ち
	cin.get();

	return 0;
}