#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneGameClearResult.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//数字合わせ最大数
	constexpr int kTimeRand = 1000;
	//数字合わせ正解数
	constexpr int kTimeStop = 500;
	//ボタンを押すまでの猶予
	constexpr int kTimeHelp = 15;
}

void SceneMain::init()
{
	m_isEnd = false;
	m_isWait = true;
	m_isPushScreen = false;
	m_isKeyPush = false;
	m_isMissText = false;

	m_fadeIn = 0;	//色を変更
	m_fadeOut = 0;
	m_justTime = 0;	//乱数を代入
	m_sphereSize = 100;	//球体のサイズを変更
	m_time = 0;	//制限時間をカウント
	m_buttonClick = 0;	//クリック回数をカウント
}

SceneBase* SceneMain::update()
{
	//文字の明るさ変更フェードイン
	if (m_fadeIn >= 0)
	{
		m_fadeIn++;

	}
	if (m_fadeIn >= 255)
	{
		m_fadeIn = 40;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isMissText = true;
		m_fadeOut = 255;
	}

	//最大数からランダムに数字を代入
	m_justTime = GetRand(kTimeRand);
	//ランダムに代入された数字と照らし合わせる
	if (m_justTime == kTimeStop)
	{
		m_isPushScreen = true;
		m_isWait = false;
		m_isMissText = false;

	}
	//ボタンを押す判定
	if (m_isPushScreen)
	{
		//制限時間を設定
		m_time++;

		//押せた場合
		if (padState & PAD_INPUT_2)//////////////ここからボタンを押してリザルト画面と秒数表示
		{
			return(new SceneGameClearResult);
		}
		//押せなかった場合
		if (m_time >= kTimeHelp)
		{
			return(new SceneGameOverResult);
		}
	}

	return this;
}

void SceneMain::draw()
{
	DrawFormatString(0, 200, GetColor(255, 255, 255), "NowRand%d", m_justTime);
	DrawFormatString(0, 250, GetColor(255, 255, 255), "NowTime%d", m_time);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "焦ってボタン押している回数%d", m_buttonClick);

	//明るさ変更
	SetDrawBright(m_fadeIn, m_fadeIn, m_fadeIn);

	if (m_isWait)
	{
		//テキスト表示
		DrawString(Game::kScreenWidth / 2 - 50, Game::kScreenHeight / 2, "まだ押すな！", GetColor(255, 255, 255));
	}

	//明るさ変更
	SetDrawBright(255, 255, 255);

	if (m_isMissText)
	{
		m_fadeOut--;
		SetDrawBright(m_fadeOut, m_fadeOut, m_fadeOut);
		DrawString(100, 100, "焦るな！まだだ…", GetColor(255, 255, 255));
		SetDrawBright(255, 255, 255);
	}

	if (m_isPushScreen)
	{
		//円を表示
		DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, m_sphereSize, GetColor(GetRand(255), GetRand(255), GetRand(255)), false);
		DrawString(Game::kScreenWidth / 2 - 40, Game::kScreenHeight / 2, "今だ押せ！", GetColor(255, 255, 255));
	}

	//テキスト表示中
	DrawString(0, 0, "メイン画面表示中", GetColor(255, 255, 255));
}