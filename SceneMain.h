#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
		m_isEnd = false;
	}
	virtual ~SceneMain() {}


	virtual void init();
	virtual void end() {}

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

	float m_fadeIn;

	float m_fadeOut;

	float m_justTime;

	float m_sphereSize;

	float m_time;

	float m_feintTime;

	float m_buttonClick;
};