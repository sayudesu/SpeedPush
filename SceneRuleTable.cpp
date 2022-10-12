#include "SceneTitle.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

void SceneRuleTable::init()
{
	m_isEnd = false;
}

SceneBase* SceneRuleTable::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_DOWN)
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneRuleTable::draw()
{
	DrawString(0, 0, "SceneRuleTable", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 600, Game::kScreenHeight / 2 - 50, "早押しは画面にボタンを押せと表示されたら押す事でクリアとなり", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 600, Game::kScreenHeight / 2 - 30, "押すのが遅いとゲームオーバーとなる＜ B ＞ボタンで早押しをする。", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 600, Game::kScreenHeight / 2 - 10, "フェイントに掛かるとゲームオーバーとなる。", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "メニューに戻る場合は< ↓ >", GetColor(255, 255, 255));
}