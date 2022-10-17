#include <stdio.h>
#include "SceneTitle.h"
#include "SceneIceSpein.h"
#include "SceneTitle.h"
#include "SceneGameClearResult.h"
#include "SceneGameOverResult.h"

#include "DxLib.h"
#include "game.h"

namespace
{
	//色指定
	constexpr int kColorWhite = 255;

	// X方向、Y方向の最大速度
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;

	//プレイヤーの当たり判定
	constexpr float kPlayerSize = 35.0f;

	//円のサイズ
	constexpr float kSphereSize = 300.0f;

	//虹色の円が広がるスピード
	constexpr float kSphereSpeed = 1.0f;

	//円の大きさMax
	constexpr float kSphereSizeMax = 650.0f;

	//敵のサイズ
	constexpr float kEnemySpeed = 10.0f;

}

void SceneIceSpein::init()
{
	m_isDelete = true;

	m_isUpSide = false;

	m_isDownSide = false;

	m_isRightSide = false;

	m_isLeftSide = false;

	m_hPlayerGraphic = -1;
	m_hEnemyGraphic = -1;
	m_hMapGraphic = -1;
	//グラフィックのロード
	m_hPlayerGraphic = LoadGraph("data/pengin.png");
	m_hEnemyGraphic = LoadGraph("data/azarasi.png");
	m_hMapGraphic = LoadGraph("data/umi.jpg");

	m_Position = 0;
	m_count = 70;
	m_EnemyMoveCount = 0;

	m_SphereSizeX = Game::kScreenWidth / 2.0f;
	m_SphereSizeY = Game::kScreenHeight / 2.0f;

	SphereSizeUp = 100.0f;


	m_GetHitX = 0.0f;
	m_GetHitY = 0.0f;
	m_GetHit = 0.0f;

	m_CenterSize = 0.0f;
	m_CenterMatch = 0.0f;

	m_GetEnemyHitX = 0.0f;
	m_GetEnemyHitY = 0.0f;
	m_GetEnemyHit = 0.0f;

	m_CenterEnemySize = 0.0f;
	m_CenterEnemyMatch = 0.0f;

	m_pos.x = Game::kScreenWidth / 2.0f - 30.0f;
	m_pos.y = Game::kScreenHeight / 2.0f - 30.0f;

	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_enemyPos.x = 0.0f;
	m_enemyPos.y = 0.0f;

	/*
	m_enemyPos.x = 0.0f;
	m_enemyPos.y = Game::kScreenHeight / 2;
	*/
	m_PlayerSizeX = m_pos.x;
	m_PlayerSizeY = m_pos.y;
	/*
	m_enemyPos.x = Game::kScreenWidth - 10;
	m_enemyPos.y = Game::kScreenHeight / 2;
	*/
	m_TestNum_X = 0.0f;
	m_TestNum_Y = 0.0f;
}

SceneBase* SceneIceSpein::update()
{
	m_TestNum_X = m_vec.x;
	m_TestNum_Y = m_vec.y;
	
	m_count++;

	if (m_count >= 70)
	{
		m_Position = GetRand(1);
		m_count = 0;
	}

	if (m_isDelete)
	{
		m_EnemyMoveCount++;
		//右から
		if (m_Position == 0)
		{
			m_enemyPos.x = Game::kScreenWidth - 10;
			m_enemyPos.y = Game::kScreenHeight / 2;

			if (m_vec.x >= m_TestNum_X)
			{
				m_enemyPos.x += m_TestNum_X;
				m_enemyPos.x -= 5.0f;

				if (m_pos.x >= m_enemyPos.x)
				{
					m_enemyPos.x -= 10.0f;
				}

			}
			if (m_vec.y >= m_TestNum_Y)
			{
				if (m_EnemyMoveCount >= 3)
				{
					m_enemyPos.y += m_TestNum_Y;
					m_EnemyMoveCount = 0;
				}
			}
		}
		//左から
		if (m_Position == 1)
		{
			m_enemyPos.x = 0.0f;
			m_enemyPos.y = Game::kScreenHeight / 2;

			if (m_vec.x >= m_TestNum_X)
			{
				m_enemyPos.x -= m_TestNum_X;
				m_enemyPos.x += 5.0f;
				/*
				if (m_pos.x >= m_enemyPos.x)
				{
					m_enemyPos.x += 10.0f;
				}
				*/
			}
			if (m_vec.y >= m_TestNum_Y)
			{
				if (m_EnemyMoveCount >= 3)
				{
					m_enemyPos.y += m_TestNum_Y;
					m_EnemyMoveCount = 0;
				}
			}
		}
	}
	
	//円の広がるスピード
	SphereSizeUp += kSphereSpeed;
	
	//プレイヤーの位置を取得
	m_PlayerSizeX = m_pos.x;
	m_PlayerSizeY = m_pos.y;
	
	//移動キー
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_vec.y -= kAcc;
		if (m_vec.y < -kSpeedMax)
		{
			m_vec.y = -kSpeedMax;
		}
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_vec.y += kAcc;
		if (m_vec.y > kSpeedMax)
		{
			m_vec.y = kSpeedMax;
		}
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)
		{
			m_vec.x = -kSpeedMax;
		}
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)
		{
			m_vec.x = kSpeedMax;
		}
	}
	m_pos += m_vec;
	
	//画面外に出ると画像を消す
	ScreenOut();

	//勝敗判定
	if (SphereSizeUp == kSphereSizeMax)//Win
	{
		return(new SceneGameClearResult);
	}
	if (!CheckHit())					//Lose
	{
		return(new SceneGameOverResult);
	}
	if (!CheckHitEnemy())				//Lose
	{
		return(new SceneGameOverResult);
	}

	//メニューに戻るボタン
	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneIceSpein::draw()
{
	//仮の画像を表示
	DrawGraph(0, 0, m_hMapGraphic, true);
	//テキスト表示中
	DrawString(0 , 0, "＜ S c e n e I c e S p e i n ＞", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth - 250, 0, "メニュー画面に戻るには＜ X ＞", GetColor(kColorWhite, kColorWhite, kColorWhite));

	//円を表示
	DrawCircle(m_SphereSizeX, m_SphereSizeY, kSphereSize, GetColor(100,255,255), true);
	DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, SphereSizeUp, GetColor(GetRand(kColorWhite), GetRand(kColorWhite), GetRand(kColorWhite)), false);

	//プレイヤーを表示&円
	DrawGraph(m_pos.x,m_pos.y, m_hPlayerGraphic, true);
	DrawCircle(m_PlayerSizeX + 40.0f, m_PlayerSizeY + 40.0f, kPlayerSize, GetColor(kColorWhite, kColorWhite, kColorWhite), false);

	if (m_isDelete)
	{
		DrawRotaGraph(m_enemyPos.x, m_enemyPos.y, 1.0f, 0.0f, m_hEnemyGraphic, true, false);
	//	DrawCircle(m_enemyPos.x, m_enemyPos.y, m_hEnemyGraphic, GetColor(kColorWhite, kColorWhite, kColorWhite), false);
	}
}

void SceneIceSpein::ScreenOut()
{
	//画面外に出ると画像を消す
	if (m_enemyPos.x >= Game::kScreenWidth)
	{
		m_isDelete = false;
	}
	else if (m_enemyPos.x <= 0.0f)
	{
		m_isDelete = false;
	}
	if (m_enemyPos.y >= Game::kScreenHeight)
	{
		m_isDelete = false;
	}
	else if (m_enemyPos.y <= 0.0f)
	{
		m_isDelete = false;
	}

}

bool SceneIceSpein::CheckHit()
{
	//当たり判定
	m_GetHitX = m_PlayerSizeX - m_SphereSizeX;
	m_GetHitY = m_PlayerSizeY - m_SphereSizeY;
	m_GetHit   = m_GetHitX * m_GetHitX + m_GetHitY * m_GetHitY;

	m_CenterSize = kPlayerSize + kSphereSize;
	m_CenterMatch = m_CenterSize * m_CenterSize;

	if (m_GetHit < m_CenterMatch)
	{
		return true;
	}

	return false;
}
bool SceneIceSpein::CheckHitEnemy()
{
	//当たり判定
	m_GetEnemyHitX =  m_enemyPos.x - m_PlayerSizeX;
	m_GetEnemyHitY =  m_enemyPos.y - m_PlayerSizeY;
	m_GetEnemyHit = m_GetEnemyHitX * m_GetEnemyHitX + m_GetEnemyHitY * m_GetEnemyHitY;

	m_CenterEnemySize = kPlayerSize + kPlayerSize;
	m_CenterEnemyMatch = m_CenterEnemySize * m_CenterEnemySize;

	if (m_GetEnemyHit > m_CenterEnemyMatch)
	{
		return true;
	}

	return false;
}