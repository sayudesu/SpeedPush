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
	//�F�w��
	constexpr int kColorWhite = 255;

	// X�����AY�����̍ő呬�x
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;

	//�v���C���[�̓����蔻��
	constexpr float kPlayerSize = 35.0f;

	//�~�̃T�C�Y
	constexpr float kSphereSize = 300;

	//���F�̉~���L����X�s�[�h
	constexpr float kSphereSpeed = 1.0f;

	//�~�̑傫��Max
	constexpr float kSphereSizeMax = 650.0f;

}

void SceneIceSpein::init()
{
	m_hPlayerGraphic = -1;
	m_hEnemyGraphic = -1;
	//�O���t�B�b�N�̃��[�h
	m_hPlayerGraphic = LoadGraph("data/pengin.png");
	m_hEnemyGraphic = LoadGraph("data/azarasi.png");

	SphereSizeX = Game::kScreenWidth  / 2.0f;
	SphereSizeY = Game::kScreenHeight / 2.0f;

	SphereSizeUp = 100.0f;

	m_PlayerSizeX = m_pos.x;
	m_PlayerSizeY = m_pos.y;

	m_GetHitX = 0.0f;
	m_GetHitY = 0.0f;
	m_GetHit = 0.0f;

	m_CenterSize = 0.0f;
	m_CenterMatch = 0.0f;


	m_pos.x = Game::kScreenWidth / 2.0f - 30;
	m_pos.y = Game::kScreenHeight / 2.0f - 30;
	
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_enemyPos.x = 0.0f;
	m_enemyPos.y = 0.0f;
}

SceneBase* SceneIceSpein::update()
{
	//�v���[���[����//////////////
	//���j���[�ɖ߂�{�^��
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	//�~�̍L����X�s�[�h
	SphereSizeUp += kSphereSpeed;

	//�v���C���[�̈ʒu���擾
	m_PlayerSizeX = m_pos.x;
	m_PlayerSizeY = m_pos.y;

	//�ړ��L�[
	if (padState & PAD_INPUT_UP)
	{
		m_vec.y -= kAcc;
		if (m_vec.y < -kSpeedMax)	m_vec.y = -kSpeedMax;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		m_vec.y += kAcc;
		if (m_vec.y > kSpeedMax)	m_vec.y = kSpeedMax;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	m_pos += m_vec;
	//�G�l�~�[����//////////////



	//���s����
	if (SphereSizeUp == kSphereSizeMax)//Win
	{
		return(new SceneGameClearResult);
	}
	if (!ChecHit())					//Lose
	{
		return(new SceneGameOverResult);
	}
	return this;
}

void SceneIceSpein::draw()
{
	//�e�L�X�g�\����
	DrawString(0 , 0, "�� S c e n e I c e S p e i n ��", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth - 250, 0, "���j���[��ʂɖ߂�ɂ́� X ��", GetColor(kColorWhite, kColorWhite, kColorWhite));

	//�~��\��
	DrawCircle(SphereSizeX, SphereSizeY, kSphereSize, GetColor(100,255,255), true);
	DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, SphereSizeUp, GetColor(GetRand(kColorWhite), GetRand(kColorWhite), GetRand(kColorWhite)), false);

	//�v���C���[��\��&�~
	DrawGraph(m_pos.x,m_pos.y, m_hPlayerGraphic, true);
	DrawCircle(m_PlayerSizeX + 40, m_PlayerSizeY + 40, kPlayerSize, GetColor(kColorWhite, kColorWhite, kColorWhite), false);

	//�G�l�~�[�\��
	//DrawGraph(m_enemyPos.x, m_enemyPos.x, m_hEnemyGraphic, true);
	DrawRotaGraph(m_enemyPos.x + 100 , m_enemyPos.x + 100, 1.0f, 0.0f, m_hEnemyGraphic, true, false);
}

bool SceneIceSpein::ChecHit()
{
	//�����蔻��
	m_GetHitX = m_PlayerSizeX - SphereSizeX;
	m_GetHitY = m_PlayerSizeY - SphereSizeY;
	m_GetHit   = m_GetHitX * m_GetHitX + m_GetHitY * m_GetHitY;

	m_CenterSize = kPlayerSize + kSphereSize;
	m_CenterMatch = m_CenterSize * m_CenterSize;

	if (m_GetHit < m_CenterMatch)
	{
		return true;
	}
	
	return false;
}