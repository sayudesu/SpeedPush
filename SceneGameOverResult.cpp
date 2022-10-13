#include "SceneTitle.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�����̑傫��
	constexpr int kTextSise = 54;
	constexpr int kTextSiseMin = 16;
	//�F�w��
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
	DrawString(0, 0, "�Q�[���I�[�o�[���U���g��ʐ؂�ւ�", GetColor(kColorWhite, kColorWhite, kColorWhite));
	SetFontSize(kTextSise);
	DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 40, "G a m e O v e r", GetColor(kColorWhite, kColorWhite, kColorWhite));
	SetFontSize(kTextSiseMin);

	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "�������ƂɎ��s����", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "���j���[�ɖ߂�ꍇ��< X >", GetColor(kColorWhite, kColorWhite, kColorWhite));
}