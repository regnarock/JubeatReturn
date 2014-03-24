#include "GraphicsController.h"
#include "SettingsIO.h"
#include "GUIPanelID.h"

GraphicsController::GraphicsController()
	: m_window(NULL), m_gui(this)
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
		graphicSettings.GetString("Window", "Title"),
		sf::Style::None);
	m_window->setPosition(sf::Vector2i(0, 0));

	m_gui.Show(PANEL_SPLASH);
}

void GraphicsController::RenderWindow()
{
	if (!m_window)
		return ;
	m_window->clear(sf::Color(255, 255, 255, 255));
	m_gui.Render();
	m_window->display();
}

sf::RenderWindow *GraphicsController::GetWindow() const { return (m_window); }
GUIController *GraphicsController::GetGUI() { return (&m_gui); }
