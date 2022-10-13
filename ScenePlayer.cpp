#include "SceneTitle.h"
#include "ScenePlayer.h"
#include "SceneTitle.h"

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

	//���F�̉~���L����X�s�[�h
	constexpr float kSphereSpeed = 1.0f;

}

void ScenePlayer::init()
{
	m_hPlayerGraphic = -1;
	m_hEnemyGraphic = -1;
	//�O���t�B�b�N�̃��[�h
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hEnemyGraphic = LoadGraph("");

	m_pos.x = Game::kScreenWidth / 2 - 30;
	m_pos.y = Game::kScreenHeight / 2 - 30;

	m_vec.x = 0;
	m_vec.y = 0;

	big = 100;

	m_PlayerSizeX = 0;
	m_PlayerSizeY = 0;
}

SceneBase* ScenePlayer::update()
{
	//�v���[���[����//////////////
	//���j���[�ɖ߂�{�^��
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}

	//�~�̍L����X�s�[�h
	big += kSphereSpeed;

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




	return this;
}

void ScenePlayer::draw()
{
	//�e�L�X�g�\����
	DrawString(0 , 0, "�� P l a y e r ��", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth - 250, 0, "���j���[��ʂɖ߂�ɂ́� X ��", GetColor(kColorWhite, kColorWhite, kColorWhite));

	//�~��\��
	DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, big, GetColor(GetRand(255), GetRand(255), GetRand(255)), false);
	DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, 300, GetColor(100,255,255), true);


	//�v���C���[��\��&�~
	DrawGraph(m_pos.x ,m_pos.y, m_hPlayerGraphic, true);
	DrawCircle(m_PlayerSizeX + 30, m_PlayerSizeY + 40, kPlayerSize, GetColor(255, 255, 255), false);
}

int ScenePlayer::ChecHit()
{

	
}