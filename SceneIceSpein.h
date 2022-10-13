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

	virtual bool ChecHit();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	//�v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	//�G�l�~�[�̃O���t�B�b�N�n���h��
	int m_hEnemyGraphic;
	//�~�̃T�C�Y
	float SphereSizeX;
	float SphereSizeY;
	//�~�̃T�C�Y��傫������
	float SphereSizeUp;
	//�v���C���[�����蔻��T�C�Y
	float m_PlayerSizeX;
	float m_PlayerSizeY;

	float m_GetHitX;
	float m_GetHitY;
	float m_GetHit;

	float m_CenterSize;
	float m_CenterMatch;

	Vec2 m_pos;
	Vec2 m_vec;

	Vec2 m_enemyPos;
};