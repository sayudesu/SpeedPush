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

	//�v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	//�G�l�~�[�̃O���t�B�b�N�n���h��
	int m_hEnemyGraphic;

	int big;
	//�v���C���[�����蔻��T�C�Y
	int m_PlayerSizeX;
	int m_PlayerSizeY;

	Vec2 m_pos;
	Vec2 m_vec;
};