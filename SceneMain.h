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

	int m_fadeIn;

	int m_fadeOut;

	int m_justTime;

	int m_sphereSize;

	int m_time;

	int m_feintTime;

	int m_buttonClick;
};