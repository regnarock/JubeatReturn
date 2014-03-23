#include "GraphicsController.h"
#include "SettingsIO.h"

GraphicsController::GraphicsController()
	: m_window(NULL)
{

}

GraphicsController::~GraphicsController()
{

}

void GraphicsController::Init()
{
	SettingsIO graphicSettings("Settings/render.ini");

	m_window = new sf::RenderWindow(sf::VideoMode(
		graphicSettings.GetInt("Window", "Width"), 
		graphicSettings.GetInt("Window", "Height")), 
		graphicSettings.GetString("Window", "Title"));
}

void GraphicsController::RenderWindow()
{
	if (!m_window)
		return ;
	m_window->display();
}

sf::RenderWindow *GraphicsController::GetWindow() const
{
	return (m_window);
}
