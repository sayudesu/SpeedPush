#pragma once
#include "SceneBase.h"

class SceneGameClearResult : public SceneBase
{
public:
	SceneGameClearResult()
	{

		m_isEnd = false;
	}
	virtual ~SceneGameClearResult() {}


	virtual void init();
	virtual void end() {}

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:


	bool m_isEnd;
};
