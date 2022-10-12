#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

void SceneTitle::init()
{
	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//早押しゲームボタン
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}
	//ルール確認ボタン
	if (padState & PAD_INPUT_UP)
	{
		return(new SceneRuleTable);
	}

	return this;

}

void SceneTitle::draw()
{
	DrawString(0, 0, "タイトル画面", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 130, Game::kScreenHeight / 2 - 30, "ゲームルールを確認するには　＜ ↑ ＞　", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 130, Game::kScreenHeight / 2, "早押しゲームをプレイは　　　＜ A ＞　", GetColor(255, 255, 255));
	//PCの場合
	//DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "< s　p　a　c　e >", GetColor(255, 255, 255));
}