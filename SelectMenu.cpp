#include "SelectMenu.h"

//===================================================================
//SelectMenu::Item                                                  
//===================================================================
SelectMenu::Item::Item()
{
	//ポインターはnullptrで初期化することが多い
	m_text = nullptr;
}

SelectMenu::Item::~Item()
{

}

void SelectMenu::Item::setText(const char* text)
{
	m_text = text;
}

//===================================================================
//SelectMenu
//===================================================================
SelectMenu::SelectMenu()
{

}

SelectMenu::~SelectMenu()
{

}

void SelectMenu::init()
{

}

void SelectMenu::end()
{

}

void SelectMenu::update()
{

}

void SelectMenu::draw()
{

}