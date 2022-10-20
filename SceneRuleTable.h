#pragma once
#include "SceneBase.h"

class SceneRuleTable : public SceneBase
{
public:
	SceneRuleTable()
	{
		m_isEnd = false;
		m_hGraphic = -1;
	}
	virtual ~SceneRuleTable();

	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

	int m_hGraphic;
};
