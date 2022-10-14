#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneIceSpein : public SceneBase
{
public:
	SceneIceSpein()
	{
		m_isEnd = false;
	}
	virtual ~SceneIceSpein(){}


	virtual void init();
	virtual void end() {}

	virtual SceneBase* update() override;
	virtual void draw();

	virtual void ScreenOut();

	virtual bool CheckHit();
	virtual bool CheckHitEnemy();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	bool m_isDelete;
	//プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	//エネミーのグラフィックハンドル
	int m_hEnemyGraphic;
	//マップのグラフィックハンドル
	int m_hMapGraphic;
	//ランダム
	int m_Position;
	int m_count;
	//円のサイズ
	float m_SphereSizeX;
	float m_SphereSizeY;
	//円のサイズを大きくする
	float SphereSizeUp;
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

	Vec2 m_pos;
	Vec2 m_vec;

	Vec2 m_enemyPos;
};