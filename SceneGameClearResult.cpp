#include "SceneTitle.h"
#include "SceneGameClearResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//文字の大きさ
	constexpr int kTextSise = 54;
	constexpr int kTextSiseMin = 17;
	//色指定
	constexpr int kColorWhite = 255;
}

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
	DrawString(0, 0, "ゲームクリアリザルト画面切り替え", GetColor(kColorWhite, kColorWhite, kColorWhite));

	SetFontSize(kTextSise);
	DrawString(Game::kScreenWidth / 2 - 250, Game::kScreenHeight / 2 - 40, "G a m e C l e a r", GetColor(GetRand(kColorWhite), GetRand(kColorWhite), GetRand(kColorWhite)));
	SetFontSize(kTextSiseMin);

	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "押すことに成功した", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "メニューに戻る場合は< X >", GetColor(kColorWhite, kColorWhite, kColorWhite));
}