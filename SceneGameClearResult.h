#pragma once
#include "SceneBase.h"

class SceneGameClearResult : public SceneBase
{
public:
	SceneGameClearResult()
	{
		m_isEnd = false;
		m_isGraphicNum = false;
		m_hClearGraphic = -1;
		m_hClearGraphicNext = -1;
		m_isTimeNum = 0;
		m_randomScene = 0;
	}
	virtual ~SceneGameClearResult(){}

	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:


	bool m_isEnd;

	bool m_isGraphicNum;

	int m_hClearGraphic;

	int m_hClearGraphicNext;

	int m_isTimeNum;
	int m_randomScene;
};
