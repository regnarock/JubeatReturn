#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GUIController.h"

class GraphicsController
{
private:
	sf::RenderWindow *m_window;
	GUIController m_gui;

public:
	GraphicsController();
	~GraphicsController();

	void Init();
	void RenderWindow();
	sf::RenderWindow *GetWindow() const;
	GUIController *GetGUI();

};