#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneIceSpein : public SceneBase
{
public:
	SceneIceSpein()
	{
		m_isEnd        = false;
		m_isDelete     = false;
		m_isBirdDelete = false;
		m_isUpSide     = false;
		m_isDownSide   = false;
		m_isRightSide  = false;
		m_isLeftSide   = false;
		m_isTracking   = false;

		m_hPlayerGraphic    = 0;
		m_hEnemyGraphic     = 0;
		m_hEnemyBirdGraphic = 0;

	    m_hMapGraphic    = 0;
		m_count          = 0;
		m_EnemyMoveCount = 0;
		m_SphereSizeX    = 0;
		m_SphereSizeY    = 0;
		m_SphereSizeUp = 0.0f;
		m_PlayerSizeX  = 0.0f;
		m_PlayerSizeY  = 0.0f;

		m_GetEnemyHitX     = 0.0f;
		m_GetEnemyHitY     = 0.0f;
		m_GetEnemyHit      = 0.0f;
		m_CenterEnemySize  = 0.0f;
		m_CenterEnemyMatch = 0.0f;

		m_GetEnemyBirdHitX     = 0.0f;
		m_GetEnemyBirdHitY     = 0.0f;
		m_GetEnemyBirdHit      = 0.0f;
		m_CenterEnemyBirdSize  = 0.0f;
		m_CenterEnemyBirdMatch = 0.0f;

		m_GetHitX     = 0.0f;
		m_GetHitY     = 0.0f;
		m_GetHit      = 0.0f;
		m_CenterSize  = 0.0f;
		m_CenterMatch = 0.0f;

		m_PositionSide   = 0;
	    m_PositionUpSide = 0;

	}
	virtual ~SceneIceSpein(){}


	virtual void init();
	virtual void end() {}

	virtual SceneBase* update() override;
	virtual void draw();

	virtual void ScreenOut();
	virtual void ScreenEnemy();

	virtual bool CheckHit();
	virtual bool CheckHitEnemy();
	virtual bool CheckHitEnemyBird();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	bool m_isDelete;

	bool m_isBirdDelete;

	bool m_isUpSide;

	bool m_isDownSide;

	bool m_isRightSide;

	bool m_isLeftSide;

	bool m_isTracking;

	//プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	//エネミーのグラフィックハンドル
	int m_hEnemyGraphic;
	int m_hEnemyBirdGraphic;
	//マップのグラフィックハンドル
	int m_hMapGraphic;
	//ランダム
	int m_count;
	//敵の動きを設定
	int m_EnemyMoveCount;
	//円のサイズ
	int m_SphereSizeX;
	int m_SphereSizeY;
	//円のサイズを大きくする
	float m_SphereSizeUp;
	//プレイヤー当たり判定サイズ
	float m_PlayerSizeX;
	float m_PlayerSizeY;
	//当たり判定用　プレイヤーと円
	float m_GetHitX;
	float m_GetHitY;
	float m_GetHit;
	float m_CenterSize;
	float m_CenterMatch;
	//当たり判定用　プレイヤーとエネミー
	float m_GetEnemyHitX;
	float m_GetEnemyHitY;
	float m_GetEnemyHit;
	float m_CenterEnemySize;
	float m_CenterEnemyMatch;
	//当たり判定用　プレイヤーとエネミー
	float m_GetEnemyBirdHitX;
	float m_GetEnemyBirdHitY;
	float m_GetEnemyBirdHit;
	float m_CenterEnemyBirdSize;
	float m_CenterEnemyBirdMatch;

	int m_PositionSide;
	int m_PositionUpSide;

	Vec2 m_pos;
	Vec2 m_vec;

	Vec2 m_playerPos;

	Vec2 m_enemyPos;
	Vec2 m_enemyBirdPos;
};