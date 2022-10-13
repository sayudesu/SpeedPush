#include "SceneTitle.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//文字の大きさ
	constexpr int kTextSise = 54;
	constexpr int kTextSiseMin = 16;
	//色指定
	constexpr int kColorWhite = 255;
}

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
	DrawString(0, 0, "ゲームオーバーリザルト画面切り替え", GetColor(kColorWhite, kColorWhite, kColorWhite));
	SetFontSize(kTextSise);
	DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 40, "G a m e O v e r", GetColor(kColorWhite, kColorWhite, kColorWhite));
	SetFontSize(kTextSiseMin);

	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "押すことに失敗した", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "メニューに戻る場合は< X >", GetColor(kColorWhite, kColorWhite, kColorWhite));
}