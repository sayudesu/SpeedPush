#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class ScenePlayer : public SceneBase
{
public:
	ScenePlayer()
	{
		m_isEnd = false;
	}
	virtual ~ScenePlayer(){}


	virtual void init();
	virtual void end() {}

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	//プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	//エネミーのグラフィックハンドル
	int m_hEnemyGraphic;

	int big;
	//プレイヤー当たり判定サイズ
	int m_PlayerSizeX;
	int m_PlayerSizeY;

	Vec2 m_pos;
	Vec2 m_vec;
};