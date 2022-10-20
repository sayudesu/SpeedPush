
#pragma once
#include "SceneBase.h"

class SceneGameOverResult : public SceneBase
{
public:
	SceneGameOverResult()
	{
		m_isEnd = false;
		m_isGraphicNum = false;
		m_hOverGraphic = -1;
		m_hOverGraphicNext = -1;
		m_randomScene = 0;
	}
	virtual ~SceneGameOverResult(){}

	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	bool m_isGraphicNum;

	int m_hOverGraphic;

	int m_hOverGraphicNext;

	int m_randomScene;
};