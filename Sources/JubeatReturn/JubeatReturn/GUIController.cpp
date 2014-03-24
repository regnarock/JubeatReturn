#include <iostream>
#include "GUIController.h"
#include "GUIPanel.h"
#include "GraphicsController.h"

#include "SplashPanel.hpp"

GUIController::GUIController(GraphicsController *gc)
	: m_gcPtr(gc)
{
	SplashPanel *res = new SplashPanel();
	m_panels.push_back(res);
}

GUIController::~GUIController()
{
	while (!m_activePanels.empty())
		m_activePanels.pop_back();
	while (!m_panels.empty())
	{
		delete m_panels.back();
		m_panels.pop_back();
	}
}

void GUIController::Render()
{
	std::vector<GUIPanel *>::iterator it;

	it = m_activePanels.begin();
	while (it != m_activePanels.end())
	{
		(*it)->ReceiveEvent(DRAW, m_gcPtr);
		++it;
	}
}

void GUIController::Update()
{
	std::vector<GUIPanel *>::iterator it;

	it = m_activePanels.begin();
	while (it != m_activePanels.end())
	{
		(*it)->ReceiveEvent(UPDATE, NULL);
		++it;
	}
}

void GUIController::Show(GUIPANELID id)
{
	std::vector<GUIPanel *>::iterator it;

	#if _DEBUG
		std::cout << "[  ] GUIController: Show " << id << std::endl;
	#endif
	if (FindActive(id))
		return ;
	it = m_panels.begin();
	while (it != m_panels.end())
	{
		if ((*it)->GetID() == id) {
			#if DEBUG
				std::cout << "[OK] GUIController: Show " << id << " Found and added to actives" << std::endl;
			#endif
			m_activePanels.push_back((*it));
			return ;
		}
		++it;
	}
	#if _DEBUG
		std::cout << "[KO] GUIController: Show " << id << " Not Found!" << std::endl;
	#endif
}

void GUIController::Hide(GUIPANELID id)
{
	std::vector<GUIPanel *>::iterator it;

	it = m_activePanels.begin();
	while (it != m_activePanels.end())
	{
		if ((*it)->GetID() == id) {
			m_activePanels.erase(it);
			return ;
		}
		++it;
	}
}

GUIPanel *GUIController::Find(GUIPANELID id)
{
	std::vector<GUIPanel *>::iterator it;

	it = m_panels.begin();
	while (it != m_panels.end())
	{
		if ((*it)->GetID() == id) {
			return (*it);
		}
		++it;
	}
	return (NULL);
}

GUIPanel *GUIController::FindActive(GUIPANELID id)
{
	std::vector<GUIPanel *>::iterator it;

	it = m_activePanels.begin();
	while (it != m_activePanels.end())
	{
		if ((*it)->GetID() == id) {
			return (*it);
		}
		++it;
	}
	return (NULL);
}


