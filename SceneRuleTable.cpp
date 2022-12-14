#include "SceneTitle.h"
#include "SceneRuleTable.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//色指定
	constexpr int kColorWhite = 255;
	//文字の列
	constexpr int kLetterLine  = 500;
	constexpr int kLetterLineB = 60;
}

void SceneRuleTable::init()
{
	m_hGraphic = LoadGraph("data/white.jpg");
}
void SceneRuleTable::end()
{
	DeleteGraph(m_hGraphic);
}

SceneBase* SceneRuleTable::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//タイトルに移動
	if (padState & PAD_INPUT_DOWN)
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneRuleTable::draw()
{
	//背景画像を表示
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hGraphic, true);

	//SpeedPushの説明
	DrawString(0, 0, "ゲームルール説明", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 80, "＜ S p e e d P u s h ＞", GetColor(0, 255, 255));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 50, "SpeedPushは画面にボタンを押せ!と表示されたら押す事でクリア", GetColor(0, 255, 255));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 30, "押すのが遅いとゲームオーバーとなる＜ B ＞ボタンで早押しをする。", GetColor(0, 255, 255));
	DrawString(Game::kScreenWidth / 2 - kLetterLine, Game::kScreenHeight / 2 - 10, "フェイントに掛かるとゲームオーバーとなる。", GetColor(0, 255, 255));
	DrawString(Game::kScreenWidth / 2 - 80 , Game::kScreenHeight - 80, "メニューに戻る場合は< ↓ >", GetColor(0, 255, 255));
	//IceSpeinの説明
	DrawString(0, 0, "ゲームルール説明", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth / 2 + kLetterLineB, Game::kScreenHeight / 2 - 80, "＜ I c e S p e i n ＞", GetColor(0, 255, 255));
	DrawString(Game::kScreenWidth / 2 + kLetterLineB, Game::kScreenHeight / 2 - 50, "IceSpeinは画面の青い円(氷)から出ないで制限時間内を耐えるとクリア", GetColor(0, 255, 255));
	DrawString(Game::kScreenWidth / 2 + kLetterLineB, Game::kScreenHeight / 2 - 30, "敵（アザラシと鳥）が飛んでくるのでそれに食べられるとゲームオーバー", GetColor(0, 255, 255));
}
