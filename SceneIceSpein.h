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

	//�v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	//�G�l�~�[�̃O���t�B�b�N�n���h��
	int m_hEnemyGraphic;
	int m_hEnemyBirdGraphic;
	//�}�b�v�̃O���t�B�b�N�n���h��
	int m_hMapGraphic;
	//�����_��
	int m_count;
	//�G�̓�����ݒ�
	int m_EnemyMoveCount;
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
	//�����蔻��p�@�v���C���[�ƃG�l�~�[
	float m_GetEnemyBirdHitX;
	float m_GetEnemyBirdHitY;
	float m_GetEnemyBirdHit;
	float m_CenterEnemyBirdSize;
	float m_CenterEnemyBirdMatch;

	float m_PositionSide;
	float m_PositionUpSide;

	float m_TestNum_X;
	float m_TestNum_Y;

	Vec2 m_pos;
	Vec2 m_vec;

	Vec2 m_enemyPos;
	Vec2 m_enemyBirdPos;
};