#include "SceneTitle.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�F�w��
	constexpr int kColorWhite = 255;
	//�����̗�
	constexpr int kLetterLine  = 500;
	constexpr int kLetterLineB = 60;
}

void SceneRuleTable::init()
{
	m_isEnd = false;
}

SceneBase* SceneRuleTable::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_DOWN)
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneRuleTable::draw()
{
	//SpeedPush�̐���
	DrawString(0, 0, "�Q�[�����[������", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 80, "�� S p e e d P u s h ��", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 50, "SpeedPush�͉�ʂɃ{�^��������!�ƕ\�����ꂽ�牟�����ŃN���A", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 30, "�����̂��x���ƃQ�[���I�[�o�[�ƂȂ遃 B ���{�^���ő�����������B", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 10, "�t�F�C���g�Ɋ|����ƃQ�[���I�[�o�[�ƂȂ�B", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80 , Game::kScreenHeight - 80, "���j���[�ɖ߂�ꍇ��< �� >", GetColor(255, 255, 255));
	//IceSpein�̐���
	DrawString(0, 0, "�Q�[�����[������", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 + kLetterLineB, Game::kScreenHeight / 2 - 80, "�� I c e S p e i n ��", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 + kLetterLineB, Game::kScreenHeight / 2 - 50, "IceSpein�͉�ʂ̐��~(�X)����o�Ȃ��Ő������ԓ���ς���ƃN���A", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 + kLetterLineB, Game::kScreenHeight / 2 - 30, "�A�U���V���ł���̂ł���ɐH�ׂ���ƃQ�[���I�[�o�[", GetColor(255, 255, 255));
	//DrawString(Game::kScreenWidth / 2 - kLetterLineB, Game::kScreenHeight / 2 - 10, "", GetColor(255, 255, 255));
}
