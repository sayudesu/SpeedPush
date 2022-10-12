#include "SceneTitle.h"
#include "SceneGameClearResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�����̑傫��
	constexpr int kTextSise = 54;
	constexpr int kTextSiseMin = 17;
	//�F�w��
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
	DrawString(0, 0, "�Q�[���N���A���U���g��ʐ؂�ւ�", GetColor(kColorWhite, kColorWhite, kColorWhite));

	SetFontSize(kTextSise);
	DrawString(Game::kScreenWidth / 2 - 250, Game::kScreenHeight / 2 - 40, "G a m e C l e a r", GetColor(GetRand(kColorWhite), GetRand(kColorWhite), GetRand(kColorWhite)));
	SetFontSize(kTextSiseMin);

	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "�������Ƃɐ�������", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "���j���[�ɖ߂�ꍇ��< X >", GetColor(kColorWhite, kColorWhite, kColorWhite));
}