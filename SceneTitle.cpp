#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneIceSpein.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//色指定
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
	//SpeedPushに移動
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}
	//IceSpinに移動
	if (padState & PAD_INPUT_2)
	{
		return (new SceneIceSpein);
	}
	//ルール確認ボタン
	if (padState & PAD_INPUT_UP)
	{
		return(new SceneRuleTable);
	}

	return this;
}

void SceneTitle::draw()
{
	//タイトル画面用の背景画像
	DrawExtendGraph(0, 0,Game::kScreenWidth,Game::kScreenHeight, m_hSceneGraphic , true);
#if false
	DrawGraph(0, 0, m_hSceneGraphic, TRUE);
#endif
	
	//フォント変更
	ChangeFont("MS UI Gothic");
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 50,"SpeedPushをプレイは ＜ A ＞　", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 - 30,"IceSpin  をプレイは ＜ B ＞  ", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - 170, Game::kScreenHeight / 2 + 40,"これらのゲームルールを確認するには　＜ ↑ ＞", GetColor(kColorWhite, kColorWhite, kColorWhite));
	
}