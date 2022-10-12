#include "SceneTitle.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

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
	DrawString(0, 0, "�Q�[���I�[�o�[���U���g��ʐ؂�ւ�����", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 100, "�������ƂɎ��s����", GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80, Game::kScreenHeight - 80, "���j���[�ɖ߂�ꍇ��< X >", GetColor(255, 255, 255));
}