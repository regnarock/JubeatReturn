#pragma once

#include <vector>
#include "GUIPanelID.h"

class GraphicsController;
class GUIPanel;

class GUIController
{
private:
	std::vector<GUIPanel *> m_panels;
	std::vector<GUIPanel *> m_activePanels;
	GraphicsController *m_gcPtr;

public:
	GUIController(GraphicsController *gc);
	~GUIController();

	void Render();
	void Update();
	void Show(GUIPANELID id);
	void Hide(GUIPANELID id);
	GUIPanel *Find(GUIPANELID id);
	GUIPanel *FindActive(GUIPANELID id);
};