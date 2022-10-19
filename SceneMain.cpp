#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneGameClearResult.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//数字合わせ最大数
	constexpr int kTimeRand = 1000;//1000
	//数字合わせ正解数
	constexpr int kTimeStop = 500;//500
	//フェイント用の数字
	constexpr int kFeintStop = 100;//100
	//ボタンを押すまでの猶予
	constexpr int kTimeHelp = 15;
	//フェイント用
	constexpr int kFeintTimeHelp = 60;
	//色指定
	constexpr int kColorWhite = 255;
}

void SceneMain::init()
{
	m_isEnd = false;
	m_isWait = true;
	m_isPushScreen = false;
	m_isKeyPush = false;
	m_isMissText = false;
	m_isFeint = false;

	m_fadeIn = 0.0f;	//色を変更
	m_fadeOut = 0.0f;
	m_justTime = 0.0f;	//乱数を代入
	m_sphereSize = 100.0f;	//球体のサイズを変更
	m_time = 0.0f;	//制限時間をカウント
	m_feintTime = 0.0f; //フェイント時間をカウント
	m_buttonClick = 0.0f;	//クリック回数をカウント
}

SceneBase* SceneMain::update()
{
	//文字の明るさ変更フェードイン
	if (m_fadeIn >= 0.0f)
	{
		m_fadeIn++;
	}
	if (m_fadeIn >= 255.0f)
	{
		m_fadeIn = 40.0f;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isMissText = true;
		m_fadeOut = 255.0f;
	}
	
	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}
	
	//最大数からランダムに数字を代入
	m_justTime = static_cast<float>(GetRand(kTimeRand));
	//ランダムに代入された数字と照らし合わせる
	if (m_justTime == kTimeStop)
	{
		m_isPushScreen = true;
		m_isWait = false;
		m_isMissText = false;

	}

	if (m_justTime == kFeintStop)
	{
		m_isFeint = true;
	}
	//ボタンを押す判定
	if (m_isPushScreen)
	{
		//フェイントを起こさない
		m_isFeint = false;
		//経過時間
		m_time++;

		//押せた場合
		if (padState & PAD_INPUT_2)
		{
			return(new SceneGameClearResult);
		}
		//押せなかった場合
		if (m_time >= kTimeHelp)
		{
			return(new SceneGameOverResult);
		}
	}
	//フィントに掛かった場合
	if (m_isFeint)
	{
		//時間経過
		m_feintTime++;

		if (padState & PAD_INPUT_2)
		{
			return(new SceneGameOverResult);
		}
		//引っかからなかった場合
		if (m_feintTime >= kFeintTimeHelp)
		{
			m_isFeint = false;
			m_isWait = true;
		}
	}

	return this;
}

void SceneMain::draw()
{
#if false
	//乱数を表示
	DrawFormatString(0, 200, GetColor(kColorWhite, kColorWhite, kColorWhite), "NowRand%d", m_justTime);
#endif

	//テキスト表示中
	DrawString(0, 0, "＜ S p e e d P u s h ＞", GetColor(kColorWhite, kColorWhite, kColorWhite));

	DrawString(Game::kScreenWidth - 250,20, "＜ B ＞で早押し！", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth - 250, 0, "メニュー画面に戻るには＜ X ＞", GetColor(kColorWhite, kColorWhite, kColorWhite));
	//明るさ変更
	SetDrawBright(static_cast<int>(m_fadeIn), static_cast<int>(m_fadeIn), static_cast<int>(m_fadeIn));

	if (m_isWait)
	{
		//テキスト表示
		DrawString(Game::kScreenWidth / 2 - 50, Game::kScreenHeight / 2, "まだ押すな！", GetColor(kColorWhite, kColorWhite, kColorWhite));
	}

	if (m_isFeint)
	{
		DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, static_cast<int>(m_sphereSize), GetColor(kColorWhite, kColorWhite, kColorWhite), false);
		DrawString(Game::kScreenWidth / 2 - 60, Game::kScreenHeight / 2, "今は！押すな！", GetColor(kColorWhite, kColorWhite, kColorWhite));
		m_isWait = false;
	}

	//明るさ変更
	SetDrawBright(kColorWhite, kColorWhite, kColorWhite);
	//ボタンを早くに押してしまったら表示
	if (m_isMissText)
	{
		m_fadeOut--;
		SetDrawBright(static_cast<int>(m_fadeOut), static_cast<int>(m_fadeOut), static_cast<int>(m_fadeOut));
		DrawString(300, 300, "焦るな！まだだ…", GetColor(kColorWhite, kColorWhite, kColorWhite));
		SetDrawBright(kColorWhite, kColorWhite, kColorWhite);
	}
	//押すタイミングでわかりやすくカラフルに光る円を表示
	if (m_isPushScreen)
	{
		//円を表示
		DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, static_cast<int>(m_sphereSize), GetColor(GetRand(255), GetRand(255), GetRand(255)), false);
		DrawString(Game::kScreenWidth / 2 - 40, Game::kScreenHeight / 2, "今だ押せ！", GetColor(kColorWhite, kColorWhite, kColorWhite));
	}
}