#include <stdio.h>
#include "SceneTitle.h"
#include "SceneIceSpin.h"
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
	constexpr float kAcc = 1.0f;

	//�v���C���[�̓����蔻��
	constexpr float kPlayerSize = 35.0f;

	//�~�̃T�C�Y
	constexpr float kSphereSize = 300.0f;

	//���F�̉~���L����X�s�[�h
	constexpr float kSphereSpeed = 1.0f;

	//�~�̑傫��Max
	constexpr float kSphereSizeMax = 650.0f;

	//�G�̃X�s�[�h
	constexpr float kEnemySpeed = 15.0f;
	constexpr float kEnemyBirdSpeed = 22.0f;

	//�G�̈ʒu�ύX
	constexpr float kEnemyPosition = 70;

}

void SceneIceSpin::init()
{
	//�O���t�B�b�N�̃��[�h
	m_hPlayerGraphic    = LoadGraph("data/pengin.png");
	m_hEnemyGraphic     = LoadGraph("data/azarasi.png");
	m_hMapGraphic       = LoadGraph("data/umi.jpg");
	m_hEnemyBirdGraphic = LoadGraph("data/kkamome.png");
}
void SceneIceSpin::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hEnemyGraphic);
	DeleteGraph(m_hMapGraphic);
	DeleteGraph(m_hEnemyBirdGraphic);
}

SceneBase* SceneIceSpin::update()
{
	//�~�̍L����X�s�[�h
	m_SphereSizeUp += kSphereSpeed;
	m_SphereSizeUpTime++;

	if (m_SphereSizeUpTime == 60)
	{
		m_count--;
		m_SphereSizeUpTime = 0;
	}

	//�ړ��L�[
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
	
	m_playerPos.x += m_pos.x;
	m_playerPos.y += m_pos.y;

	//�v���C���[�̈ʒu���擾
	m_PlayerSizeX = m_pos.x;
	m_PlayerSizeY = m_pos.y;
	
	//�G��\��
	ScreenEnemy();
	//��ʊO�ɏo��Ɖ摜������
	ScreenOut();
	
	//���s����
	if (m_SphereSizeUp == kSphereSizeMax)//Win
	{
		return(new SceneGameClearResult);
	}
#if true
	if (!CheckHit())					//Lose
	{
		return(new SceneGameOverResult);
	}
	if (!CheckHitEnemy())				//Lose
	{
		return(new SceneGameOverResult);
	}
	if (!CheckHitEnemyBird())
	{
		return(new SceneGameOverResult);//Loss
	}
#endif
	//���j���[�ɖ߂�{�^��
	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneIceSpin::draw()
{
	//���̉摜��\��
	DrawGraph(0, 0, m_hMapGraphic, true);
	//�����̔w�i�i���ׂ��h�j
	DrawBox(0, 0, 300,100, GetColor(1, 1, 1), true);
	DrawBox(Game::kScreenWidth - 250, 0, Game::kScreenWidth - 40, 20, GetColor(1, 1, 1), true);
	//�e�L�X�g�\����
	DrawString(0 , 0, "�� S c e n e I c e S p e i n ��", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth - 250, 0, "���j���[��ʂɖ߂�ɂ́� X ��", GetColor(kColorWhite, kColorWhite, kColorWhite));

	//�~��\��
	DrawCircle(m_SphereSizeX, m_SphereSizeY, static_cast<int>(kSphereSize), GetColor(100, kColorWhite, kColorWhite), true);
	DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, static_cast<int>(m_SphereSizeUp), GetColor(GetRand(kColorWhite), GetRand(kColorWhite), GetRand(kColorWhite)), false);

	//�v���C���[��\��&�~
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hPlayerGraphic, true);
#if false
	DrawCircle(static_cast<int>(m_pos.x + 40) , static_cast<int>(m_pos.y + 40), static_cast<int>(kPlayerSize), GetColor(kColorWhite, kColorWhite, kColorWhite), false);
#endif
	//�G��\��
	if (m_isDelete)
	{
		DrawRotaGraph(static_cast<int>(m_enemyPos.x), static_cast<int>(m_enemyPos.y), 1.0f, 0.0f, m_hEnemyGraphic, true, false);
#if false
		DrawCircle(m_enemyPos.x, m_enemyPos.y, kPlayerSize, GetColor(kColorWhite, kColorWhite, kColorWhite), false);
#endif
	}
	if (m_isBirdDelete)
	{
		DrawRotaGraph(static_cast<int>(m_enemyBirdPos.x), static_cast<int>(m_enemyBirdPos.y), 1.0f, 0.0f, m_hEnemyBirdGraphic, true, false);
#if false
		DrawCircle(m_enemyBirdPos.x, m_enemyBirdPos.y, kPlayerSize, GetColor(kColorWhite, kColorWhite, kColorWhite), false);
#endif
	}
	SetFontSize(64);
	DrawFormatString(0,30, GetColor(kColorWhite, kColorWhite, 0), "�c�莞�� %d ",m_count);
	SetFontSize(16);
}

void SceneIceSpin::ScreenEnemy()
{

	//Enemy���E�����烉���_���ɏo��
	if (!m_isDelete)
	{
		m_PositionSide = GetRand(Game::kScreenHeight);
		m_enemyPos.x = Game::kScreenWidth;
		m_enemyPos.y = static_cast<float>(m_PositionSide -= 7);
		m_isDelete = true;
	}
	if (m_isDelete)
	{
		m_enemyPos.y = static_cast<float>(m_PositionSide);
		m_enemyPos.x -= kEnemySpeed;
	}
	//Enemy���㑤���烉���_���ɏo��
	if (!m_isBirdDelete)
	{
		m_PositionUpSide = GetRand(Game::kScreenWidth);
		m_enemyBirdPos.x = static_cast<float>(m_PositionUpSide);
		m_enemyBirdPos.y = 0.0f;

		m_isBirdDelete = true;
	}
	if (m_isBirdDelete)
	{
		m_enemyBirdPos.x = static_cast<float>(m_PositionUpSide);
		m_enemyBirdPos.y += kEnemyBirdSpeed;
	}
}

void SceneIceSpin::ScreenOut()
{
	//��ʊO�ɏo��Ɖ摜������
	if (m_enemyPos.x >= Game::kScreenWidth)
	{
		m_isDelete = false;
		m_isBirdDelete = false;
	}
	else if (m_enemyPos.x <= 0.0f)
	{
		m_isDelete = false;
		m_isBirdDelete = false;
	}
	if (m_enemyPos.y >= Game::kScreenHeight)
	{
		m_isDelete = false;
		m_isBirdDelete = false;
	}
	else if (m_enemyPos.y <= 0.0f)
	{
		m_isDelete = false;
		m_isBirdDelete = false;
	}

}

bool SceneIceSpin::CheckHit()
{
	//�����蔻��
	m_GetHitX = m_pos.x + 40.0f - m_SphereSizeX;
	m_GetHitY = m_pos.y + 40.0f - m_SphereSizeY;
	m_GetHit   = m_GetHitX * m_GetHitX + m_GetHitY * m_GetHitY;

	m_CenterSize = kPlayerSize + kSphereSize;
	m_CenterMatch = m_CenterSize * m_CenterSize;

	if (m_GetHit < m_CenterMatch)
	{
		return true;
	}

	return false;
}
bool SceneIceSpin::CheckHitEnemy()
{
	//�����蔻��
	m_GetEnemyHitX = m_enemyPos.x - m_PlayerSizeX;
	m_GetEnemyHitY = m_enemyPos.y - m_PlayerSizeY;
	m_GetEnemyHit = m_GetEnemyHitX * m_GetEnemyHitX + m_GetEnemyHitY * m_GetEnemyHitY;

	m_CenterEnemySize = kPlayerSize + kPlayerSize;
	m_CenterEnemyMatch = m_CenterEnemySize * m_CenterEnemySize;

	if (m_GetEnemyHit > m_CenterEnemyMatch)
	{
		return true;
	}

	return false;
}
bool SceneIceSpin::CheckHitEnemyBird()
{
	//�����蔻��
	m_GetEnemyBirdHitX = m_enemyBirdPos.x - m_PlayerSizeX;
	m_GetEnemyBirdHitY = m_enemyBirdPos.y - m_PlayerSizeY;
	m_GetEnemyBirdHit = m_GetEnemyBirdHitX * m_GetEnemyBirdHitX + m_GetEnemyBirdHitY * m_GetEnemyBirdHitY;

	m_CenterEnemyBirdSize = kPlayerSize + kPlayerSize;
	m_CenterEnemyBirdMatch = m_CenterEnemyBirdSize * m_CenterEnemyBirdSize;

	if (m_GetEnemyBirdHit > m_CenterEnemyBirdMatch)
	{
		return true;
	}

	return false;
}