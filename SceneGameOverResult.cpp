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

	constexpr int kGraphicSize = 300;
}

void SceneGameOverResult::init()
{
	m_hOverGraphic = LoadGraph("data/text_gameover1.png");
	m_hOverGraphicNext = LoadGraph("data/text_gameover2.png");
}

void SceneGameOverResult::end()
{
	DeleteGraph(m_hOverGraphic);
	DeleteGraph(m_hOverGraphicNext);
}

SceneBase* SceneGameOverResult::update()
{
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

	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneGameOverResult::draw()
{
	if (m_isGraphicNum)
	{
		DrawExtendGraph(kGraphicSize, kGraphicSize, Game::kScreenWidth - kGraphicSize, Game::kScreenHeight - kGraphicSize, m_hOverGraphic, true);
	}
	else
	{
		DrawExtendGraph(kGraphicSize, kGraphicSize, Game::kScreenWidth - kGraphicSize, Game::kScreenHeight - kGraphicSize, m_hOverGraphicNext, true);
	}

	SetFontSize(kTextSiseMin);
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "メニューに戻る場合は< X >", GetColor(kColorWhite, kColorWhite, kColorWhite));
}