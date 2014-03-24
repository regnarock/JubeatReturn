#pragma once

#include <SFML\Graphics.hpp>
#include "GUIPanel.h"
#include "GraphicsController.h"

class SplashPanel : public GUIPanel
{
private:
	GUIWidget m_startBtn;

public:
	SplashPanel() 
		: GUIPanel(PANEL_SPLASH)
	{
		m_startBtn.SetParent(this);
		m_startBtn.SetPosition(450, 600);
		m_startBtn.SetSize(150, 150);
	}

	virtual void Draw(GraphicsController *target)
	{
		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(0, 0), sf::Color(80, 80, 80, 255)),
			sf::Vertex(sf::Vector2f(100, 400), sf::Color(255, 255, 255, 255)),
		};
		target->GetWindow()->draw(line, 2, sf::Lines);
		m_startBtn.Draw(target);
	}

	virtual void Update()
	{
		m_startBtn.Update();
	}
};