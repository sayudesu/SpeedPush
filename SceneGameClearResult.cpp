#include "SceneTitle.h"
#include "SceneGameClearResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�����̑傫��
	constexpr int kTextSise = 54;
	constexpr int kTextSiseMin = 16;
	//�F�w��
	constexpr int kColorWhite = 255;

	constexpr int kGraphicSize = 300;
}

SceneGameClearResult::~SceneGameClearResult()
{
	m_isEnd = false;
	m_isGraphicNum = false;

	m_hClearGraphic = -1;
	m_hClearGraphicNext = -1;

	m_randomScene = GetRand(1);
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
	//�ǂ̃Q�[���I�[�o�[��ʂɂ��邩�����_���Ō��߂�B
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

void SceneGameClearResult::draw()
{
	if (m_isGraphicNum)
	{
		DrawExtendGraph(kGraphicSize, kGraphicSize, Game::kScreenWidth - kGraphicSize, Game::kScreenHeight - kGraphicSize, m_hClearGraphic, true);
	}
	else
	{
		DrawExtendGraph(kGraphicSize, kGraphicSize, Game::kScreenWidth - kGraphicSize, Game::kScreenHeight - kGraphicSize, m_hClearGraphicNext, true);
	}

	SetFontSize(kTextSiseMin);
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "���j���[�ɖ߂�ꍇ��< X >", GetColor(kColorWhite, kColorWhite, kColorWhite));
}