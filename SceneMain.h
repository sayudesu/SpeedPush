#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
		m_isEnd        = false;
		m_isWait       = true;
		m_isPushScreen = false;
		m_isFeint      = false;
		m_isKeyPush    = false;
		m_isMissText   = false;

		m_hGraphic = -1;

		m_fadeIn      = 0.0f;
		m_fadeOut     = 0.0f;
		m_justTime    = 0.0f;
		m_sphereSize  = 100.0f;
		m_time        = 0.0f;
		m_feintTime   = 0.0f;
		m_buttonClick = 0.0f;
	}
	virtual ~SceneMain(){}


	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	bool m_isWait;

	bool m_isPushScreen;

	bool m_isFeint;

	bool m_isKeyPush;

	bool m_isMissText;

	int m_hGraphic;

	float m_fadeIn;    //色を変更

	float m_fadeOut;

	float m_justTime;  //乱数を代入

	float m_sphereSize;//球体のサイズを変更

	float m_time;      //制限時間をカウント

	float m_feintTime; //フェイント時間をカウント

	float m_buttonClick;//クリック回数をカウント
};