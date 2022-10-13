#include "SceneTitle.h"
#include "SceneMain.h"
#include "ScenePlayer.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//色指定
	constexpr int kColorWhite = 255;
}

void SceneTitle::init()
{
	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//SpeedPush
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}
	//IceSpin
	if (padState & PAD_INPUT_2)
	{
		return (new ScenePlayer);
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
	//フォント変更
	ChangeFont("MS UI Gothic");

	DrawString(0, 0, "タイトル画面", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 50,"SpeedPushをプレイは ＜ A ＞　", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 30,"IceSpin  をプレイは ＜ B ＞  ", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 + 40,"これらのゲームルールを確認するには　＜ ↑ ＞", GetColor(kColorWhite, kColorWhite, kColorWhite));
	//PCの場合
	//DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "< s　p　a　c　e >", GetColor(255, 255, 255));
}