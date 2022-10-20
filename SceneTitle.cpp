#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneIceSpein.h"
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
	m_hSceneGraphic = LoadGraph("data/MainScene.jpg");
}
void SceneTitle::end()
{
	DeleteGraph(m_hSceneGraphic);
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//SpeedPush�Ɉړ�
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}
	//IceSpin�Ɉړ�
	if (padState & PAD_INPUT_2)
	{
		return (new SceneIceSpein);
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
	//�^�C�g����ʗp�̔w�i�摜
	DrawExtendGraph(0, 0,Game::kScreenWidth,Game::kScreenHeight, m_hSceneGraphic , true);
#if false
	DrawGraph(0, 0, m_hSceneGraphic, TRUE);
#endif
	
	//�t�H���g�ύX
	ChangeFont("MS UI Gothic");
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 50,"SpeedPush���v���C�� �� A ���@", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 30,"IceSpin  ���v���C�� �� B ��  ", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 + 40,"�����̃Q�[�����[�����m�F����ɂ́@�� �� ��", GetColor(kColorWhite, kColorWhite, kColorWhite));
	
}