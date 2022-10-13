#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"

class SceneManager
{
public:
	// シーンの種類定義
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,
		kSceneKindGameClearResult,
		kSceneKindGameOverResult,
		kSceneKindRuleTable,
		kSceneKindPlayer,

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
