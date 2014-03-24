#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "IInterfacable.h"

class GraphicsController;

class InputController
{
private:
	sf::Event m_activeEvent;
	void (IInterfacable::*m_btnPressedCallback)(int);
	void (IInterfacable::*m_btnReleasedCallback)(int);

public:
	InputController();
	~InputController();

	void SetBtnPressedCallback(void (IInterfacable::*clb)(int));
	void SetBtnReleasedCallback(void (IInterfacable::*clb)(int));

	// Returns the ammount of unhandled events
	int PollEvents(GraphicsController *wnd, IInterfacable *target);
};