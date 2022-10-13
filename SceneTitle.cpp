#include "SceneTitle.h"
#include "SceneMain.h"
#include "ScenePlayer.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�F�w��
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
	//���[���m�F�{�^��
	if (padState & PAD_INPUT_UP)
	{
		return(new SceneRuleTable);
	}

	return this;

}

void SceneTitle::draw()
{
	//�t�H���g�ύX
	ChangeFont("MS UI Gothic");

	DrawString(0, 0, "�^�C�g�����", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 50,"SpeedPush���v���C�� �� A ���@", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 30,"IceSpin  ���v���C�� �� B ��  ", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 + 40,"�����̃Q�[�����[�����m�F����ɂ́@�� �� ��", GetColor(kColorWhite, kColorWhite, kColorWhite));
	//PC�̏ꍇ
	//DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "< s�@p�@a�@c�@e >", GetColor(255, 255, 255));
}