#include "SceneTitle.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

void SceneGameOverResult::init()
{
	m_isEnd = false;
}

SceneBase* SceneGameOverResult::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneGameOverResult::draw()
{
	DrawString(0, 0, "ゲームオーバーリザルト画面切り替え完了", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "押すことに失敗した", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "メニューに戻る場合は< X >", GetColor(255, 255, 255));
}