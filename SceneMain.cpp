#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneGameClearResult.h"
#include "SceneGameOverResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�������킹�ő吔
	constexpr int kTimeRand = 1000;//1000
	//�������킹����
	constexpr int kTimeStop = 500;//500
	//�t�F�C���g�p�̐���
	constexpr int kFeintStop = 100;//100
	//�{�^���������܂ł̗P�\
	constexpr int kTimeHelp = 15;
	//�t�F�C���g�p
	constexpr int kFeintTimeHelp = 60;
	//�F�w��
	constexpr int kColorWhite = 255;
}

void SceneMain::init()
{
	m_isEnd = false;
	m_isWait = true;
	m_isPushScreen = false;
	m_isKeyPush = false;
	m_isMissText = false;
	m_isFeint = false;

	m_fadeIn = 0.0f;	//�F��ύX
	m_fadeOut = 0.0f;
	m_justTime = 0.0f;	//��������
	m_sphereSize = 100.0f;	//���̂̃T�C�Y��ύX
	m_time = 0.0f;	//�������Ԃ��J�E���g
	m_feintTime = 0.0f; //�t�F�C���g���Ԃ��J�E���g
	m_buttonClick = 0.0f;	//�N���b�N�񐔂��J�E���g
}

SceneBase* SceneMain::update()
{
	//�����̖��邳�ύX�t�F�[�h�C��
	if (m_fadeIn >= 0.0f)
	{
		m_fadeIn++;
	}
	if (m_fadeIn >= 255.0f)
	{
		m_fadeIn = 40.0f;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isMissText = true;
		m_fadeOut = 255.0f;
	}
	
	if (padState & PAD_INPUT_3)
	{
		return(new SceneTitle);
	}
	
	//�ő吔���烉���_���ɐ�������
	m_justTime = static_cast<float>(GetRand(kTimeRand));
	//�����_���ɑ�����ꂽ�����ƏƂ炵���킹��
	if (m_justTime == kTimeStop)
	{
		m_isPushScreen = true;
		m_isWait = false;
		m_isMissText = false;

	}

	if (m_justTime == kFeintStop)
	{
		m_isFeint = true;
	}
	//�{�^������������
	if (m_isPushScreen)
	{
		//�t�F�C���g���N�����Ȃ�
		m_isFeint = false;
		//�o�ߎ���
		m_time++;

		//�������ꍇ
		if (padState & PAD_INPUT_2)
		{
			return(new SceneGameClearResult);
		}
		//�����Ȃ������ꍇ
		if (m_time >= kTimeHelp)
		{
			return(new SceneGameOverResult);
		}
	}
	//�t�B���g�Ɋ|�������ꍇ
	if (m_isFeint)
	{
		//���Ԍo��
		m_feintTime++;

		if (padState & PAD_INPUT_2)
		{
			return(new SceneGameOverResult);
		}
		//����������Ȃ������ꍇ
		if (m_feintTime >= kFeintTimeHelp)
		{
			m_isFeint = false;
			m_isWait = true;
		}
	}

	return this;
}

void SceneMain::draw()
{
#if false
	//������\��
	DrawFormatString(0, 200, GetColor(kColorWhite, kColorWhite, kColorWhite), "NowRand%d", m_justTime);
#endif

	//�e�L�X�g�\����
	DrawString(0, 0, "�� S p e e d P u s h ��", GetColor(kColorWhite, kColorWhite, kColorWhite));

	DrawString(Game::kScreenWidth - 250,20, "�� B ���ő������I", GetColor(kColorWhite, kColorWhite, kColorWhite));
	DrawString(Game::kScreenWidth - 250, 0, "���j���[��ʂɖ߂�ɂ́� X ��", GetColor(kColorWhite, kColorWhite, kColorWhite));
	//���邳�ύX
	SetDrawBright(static_cast<int>(m_fadeIn), static_cast<int>(m_fadeIn), static_cast<int>(m_fadeIn));

	if (m_isWait)
	{
		//�e�L�X�g�\��
		DrawString(Game::kScreenWidth / 2 - 50, Game::kScreenHeight / 2, "�܂������ȁI", GetColor(kColorWhite, kColorWhite, kColorWhite));
	}

	if (m_isFeint)
	{
		DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, static_cast<int>(m_sphereSize), GetColor(kColorWhite, kColorWhite, kColorWhite), false);
		DrawString(Game::kScreenWidth / 2 - 60, Game::kScreenHeight / 2, "���́I�����ȁI", GetColor(kColorWhite, kColorWhite, kColorWhite));
		m_isWait = false;
	}

	//���邳�ύX
	SetDrawBright(kColorWhite, kColorWhite, kColorWhite);
	//�{�^���𑁂��ɉ����Ă��܂�����\��
	if (m_isMissText)
	{
		m_fadeOut--;
		SetDrawBright(static_cast<int>(m_fadeOut), static_cast<int>(m_fadeOut), static_cast<int>(m_fadeOut));
		DrawString(300, 300, "�ł�ȁI�܂����c", GetColor(kColorWhite, kColorWhite, kColorWhite));
		SetDrawBright(kColorWhite, kColorWhite, kColorWhite);
	}
	//�����^�C�~���O�ł킩��₷���J���t���Ɍ���~��\��
	if (m_isPushScreen)
	{
		//�~��\��
		DrawCircle(Game::kScreenWidth / 2, Game::kScreenHeight / 2, static_cast<int>(m_sphereSize), GetColor(GetRand(255), GetRand(255), GetRand(255)), false);
		DrawString(Game::kScreenWidth / 2 - 40, Game::kScreenHeight / 2, "���������I", GetColor(kColorWhite, kColorWhite, kColorWhite));
	}
}