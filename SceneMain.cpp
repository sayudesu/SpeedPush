#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneGameClearResult.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�������킹�ő吔
	constexpr int kTimeRand = 1000;
	//�������킹����
	constexpr int kTimeStop = 500;
	//�{�^���������܂ł̗P�\
	constexpr int kTimeHelp = 15;
}

void SceneMain::init()
{
	m_isEnd = false;
	m_isWait = true;
	m_isPushScreen = false;
	m_isKeyPush = false;
	m_isMissText = false;

	m_fadeIn = 0;	//�F��ύX
	m_fadeOut = 0;
	m_justTime = 0;	//��������
	m_sphereSize = 100;	//���̂̃T�C�Y��ύX
	m_time = 0;	//�������Ԃ��J�E���g
	m_buttonClick = 0;	//�N���b�N�񐔂��J�E���g
}

SceneBase* SceneMain::update()
{
	//�����̖��邳�ύX�t�F�[�h�C��
	if (m_fadeIn >= 0)
	{
		m_fadeIn++;

	}
	if (m_fadeIn >= 255)
	{
		m_fadeIn = 40;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isMissText = true;
		m_fadeOut = 255;
	}

	//�ő吔���烉���_���ɐ�������
	m_justTime = GetRand(kTimeRand);
	//�����_���ɑ�����ꂽ�����ƏƂ炵���킹��
	if (m_justTime == kTimeStop)
	{
		m_isPushScreen = true;
		m_isWait = false;
		m_isMissText = false;

	}
	//�{�^������������
	if (m_isPushScreen)
	{
		//�������Ԃ�ݒ�
		m_time++;

		//�������ꍇ
		if (padState & PAD_INPUT_2)//////////////��������{�^���������ă��U���g��ʂƕb���\��
		{
			return(new SceneGameClearResult);
		}
		//�����Ȃ������ꍇ
		if (m_time >= kTimeHelp)
		{
			return(new SceneGameOverResult);
		}
	}

	return this;
}

void SceneMain::draw()
{
	DrawFormatString(0, 200, GetColor(255, 255, 255), "NowRand%d", m_justTime);
	DrawFormatString(0, 250, GetColor(255, 255, 255), "NowTime%d", m_time);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "�ł��ă{�^�������Ă����%d", m_buttonClick);

	//���邳�ύX
	SetDrawBright(m_fadeIn, m_fadeIn, m_fadeIn);

	if (m_isWait)
	{
		//�e�L�X�g�\��
		DrawString(Game::kScreenWidth / 2 - 50, Game::kScreenHeight / 2, "�܂������ȁI", GetColor(255, 255, 255));
	}

	//���邳�ύX
	SetDrawBright(255, 255, 255);

	if (m_isMissText)
	{
		m_fadeOut--;
		SetDrawBright(m_fadeOut, m_fadeOut, m_fadeOut);
		DrawString(100, 100, "�ł�ȁI�܂����c", GetColor(255, 255, 255));
		SetDrawBright(255, 255, 255);
	}

	if (m_isPushScreen)
	{
		//�~��\��
		DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, m_sphereSize, GetColor(GetRand(255), GetRand(255), GetRand(255)), false);
		DrawString(Game::kScreenWidth / 2 - 40, Game::kScreenHeight / 2, "���������I", GetColor(255, 255, 255));
	}

	//�e�L�X�g�\����
	DrawString(0, 0, "���C����ʕ\����", GetColor(255, 255, 255));
}