#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"

class SceneManager
{
public:
	// �V�[���̎�ޒ�`
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,
		kSceneKindGameClearResult,
		kSceneKindGameOverResult,
		kSceneKindRuleTable,

		kSceneKindNum
	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager();

	void init(SceneKind kind = kSceneKindTitle);
	void end();

	void update();
	void draw();

private:

	SceneKind	m_kind;

	SceneBase* m_pScene;
};
