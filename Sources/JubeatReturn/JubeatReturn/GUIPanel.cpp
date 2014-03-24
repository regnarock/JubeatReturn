#include <iostream>
#include "GUIPanel.h"

GUIPanel::GUIPanel(GUIPANELID id)
	: m_uid(id)
{
	#if _DEBUG
		std::cout << "Generated panel " << id << std::endl;
	#endif
}

GUIPanel::~GUIPanel()
{

}

GUIPANELID GUIPanel::GetID() const { return (m_uid); }

void GUIPanel::BroadcastEvent(GUIEVENT ev, void *param)
{

}

void GUIPanel::ButtonPressed(int keyid)
{

}

void GUIPanel::ButtonReleased(int keyid)
{

}

void GUIPanel::AddElement(GUIWidget *elem)
{

}

void GUIPanel::RemoveElement(GUIWidget *elem)
{

}

std::vector<GUIWidget *>::iterator *GUIPanel::FindElement(GUIWidget *elem)
{
	return (NULL);
}