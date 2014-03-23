#pragma once

#include "GUIWidget.h"
#include "GUIPanelID.h"

class GUIPanel : public GUIWidget
{
private:
	GUIPANELID m_uid;
	std::vector<GUIWidget *> m_elements;

public:
	GUIPanel(GUIPANELID id);
	virtual ~GUIPanel();

	GUIPANELID GetID() const;

	void BroadcastEvent(GUIEVENT ev, void *param);
	void ButtonPressed(int keyid);
	void ButtonReleased(int keyid);

	void AddElement(GUIWidget *);
	void RemoveElement(GUIWidget *);
	std::vector<GUIWidget *>::iterator *FindElement(GUIWidget *);
};