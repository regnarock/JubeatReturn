#pragma once

#include <vector>
#include "GUIPanelID.h"

class GUIPanel;

class GUIController
{
private:
	std::vector<GUIPanel *> m_panels;
	std::vector<GUIPanel *> m_activePanels;

public:
	GUIController();
	~GUIController();

	void Render();
	void Update();
	void Show(GUIPANELID id);
	void Hide(GUIPANELID id);
	GUIPanel *Find(GUIPANELID id);
};