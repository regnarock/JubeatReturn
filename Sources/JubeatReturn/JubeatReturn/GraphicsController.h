#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GraphicsController
{
private:
	sf::RenderWindow *m_window;

public:
	GraphicsController();
	~GraphicsController();

	void Init();
	void RenderWindow();
	sf::RenderWindow *GetWindow() const;

};