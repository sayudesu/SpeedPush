#include "SceneTitle.h"
#include "SceneGameClearResult.h"
#include "DxLib.h"
#include "game.h"

void SceneGameClearResult::init()
{
	m_isEnd = false;
}

SceneBase* SceneGameClearResult::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneGameClearResult::draw()
{
	DrawString(0, 0, "ゲームクリアリザルト画面切り替え完了", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "押すことに成功した", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "メニューに戻る場合は< X >", GetColor(255, 255, 255));
}