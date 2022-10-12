#include "SceneManager.h"
#include <cassert>

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneGameClearResult.h"
#include "SceneGameOverResult.h"
#include "SceneRuleTable.h"

SceneManager::SceneManager()
{
	m_kind = kSceneKindTitle;
	m_pScene = nullptr;
}
SceneManager::~SceneManager()
{

}

void SceneManager::init(SceneKind kind)
{
	m_kind = kind;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_pScene = new SceneTitle;
		break;
	case SceneManager::kSceneKindMain:
		m_pScene = new SceneMain;
		break;
	case SceneManager::kSceneKindGameClearResult:
		m_pScene = new SceneGameClearResult;
		break;
	case SceneManager::kSceneKindGameOverResult:
		m_pScene = new SceneGameOverResult;
		break;
	case SceneManager::kSceneKindRuleTable:
		m_pScene = new SceneRuleTable;
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
}

void SceneManager::end()
{
	assert(m_pScene);
	if (!m_pScene) return;

	m_pScene->end();
	delete m_pScene;
}

void SceneManager::update()
{
	assert(m_pScene);
	if (!m_pScene) return;
	SceneBase* pSceme = m_pScene->update();

	if (pSceme != m_pScene)
	{
		// 前のシーンの終了処理
		m_pScene->end();
		delete m_pScene;

		m_pScene = pSceme;
		m_pScene->init();
	}
}

void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene) return;

	m_pScene->draw();
}