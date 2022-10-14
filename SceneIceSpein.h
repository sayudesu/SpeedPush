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
	//�v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	//�G�l�~�[�̃O���t�B�b�N�n���h��
	int m_hEnemyGraphic;
	//�}�b�v�̃O���t�B�b�N�n���h��
	int m_hMapGraphic;
	//�����_��
	int m_Position;
	int m_count;
	//�~�̃T�C�Y
	float m_SphereSizeX;
	float m_SphereSizeY;
	//�~�̃T�C�Y��傫������
	float SphereSizeUp;
	//�v���C���[�����蔻��T�C�Y
	float m_PlayerSizeX;
	float m_PlayerSizeY;
	//�����蔻��p�@�v���C���[�Ɖ~
	float m_GetHitX;
	float m_GetHitY;
	float m_GetHit;
	float m_CenterSize;
	float m_CenterMatch;
	//�����蔻��p�@�v���C���[�ƃG�l�~�[
	float m_GetEnemyHitX;
	float m_GetEnemyHitY;
	float m_GetEnemyHit;
	float m_CenterEnemySize;
	float m_CenterEnemyMatch;

	Vec2 m_pos;
	Vec2 m_vec;

	Vec2 m_enemyPos;
};