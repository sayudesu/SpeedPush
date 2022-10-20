#include "SceneTitle.h"
#include "SceneGameClearResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//文字の大きさ
	constexpr int kTextSise = 54;
	constexpr int kTextSiseMin = 16;
	//色指定
	constexpr int kColorWhite = 255;

	constexpr int kGraphicSize = 300;
}

void SceneGameClearResult::init()
{
	m_hClearGraphic = LoadGraph("data/text_gameclear1.png");
	m_hClearGraphicNext = LoadGraph("data/text_gameclear2.png");
}

void SceneGameClearResult::end()
{
	DeleteGraph(m_hClearGraphic);
	DeleteGraph(m_hClearGraphicNext);

}

SceneBase* SceneGameClearResult::update()
{
	m_isTimeNum++;
	//一度だけランダムな数字を代入
	if (m_isTimeNum == 1)
	{
		m_randomScene = GetRand(1);
	}
	//どのゲームオーバー画面にするかランダムで決める。
	if (m_randomScene == 0)
	{
		m_isGraphicNum = false;
	}
	else
	{
		m_isGraphicNum = true;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//メニュー画面に移動
	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneGameClearResult::draw()
{
	//ランダムで画像を変更
	if (m_isGraphicNum)
	{
		DrawExtendGraph(kGraphicSize, kGraphicSize, Game::kScreenWidth - kGraphicSize, Game::kScreenHeight - kGraphicSize, m_hClearGraphic, true);
	}
	else
	{
		DrawExtendGraph(kGraphicSize, kGraphicSize, Game::kScreenWidth - kGraphicSize, Game::kScreenHeight - kGraphicSize, m_hClearGraphicNext, true);
	}

	SetFontSize(kTextSiseMin);
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "メニューに戻る場合は< X >", GetColor(kColorWhite, kColorWhite, kColorWhite));
}