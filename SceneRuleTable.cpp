#include "SceneTitle.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

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
	DrawString(0, 0, "SceneRuleTable", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 600, Game::kScreenHeight / 2 - 50, "�������͉�ʂɃ{�^���������ƕ\�����ꂽ�牟�����ŃN���A�ƂȂ�", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 600, Game::kScreenHeight / 2 - 30, "�����̂��x���ƃQ�[���I�[�o�[�ƂȂ遃 B ���{�^���ő�����������B", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth - 600, Game::kScreenHeight / 2 - 10, "�t�F�C���g�Ɋ|����ƃQ�[���I�[�o�[�ƂȂ�B", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "���j���[�ɖ߂�ꍇ��< �� >", GetColor(255, 255, 255));
}