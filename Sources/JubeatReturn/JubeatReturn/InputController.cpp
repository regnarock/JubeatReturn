#include "InputController.h"
#include "GraphicsController.h"

InputController::InputController()
{
	m_btnPressedCallback = NULL;
	m_btnReleasedCallback = NULL;
}

InputController::~InputController()
{

}

void InputController::SetBtnPressedCallback(void (IInterfacable::*clb)(int)) {
	m_btnPressedCallback = clb;
}

void InputController::SetBtnReleasedCallback(void (IInterfacable::*clb)(int)) {
	m_btnReleasedCallback = clb;
}

int InputController::PollEvents(GraphicsController *gc, IInterfacable *target)
{
	int cnt = 0;
	sf::RenderWindow *wnd = gc->GetWindow();

	while (wnd->pollEvent(m_activeEvent))
	{
		switch (m_activeEvent.type)
		{
		case sf::Event::KeyPressed:
			if (m_btnPressedCallback) {
				(target->*m_btnPressedCallback)(m_activeEvent.key.code);
			} else {
				cnt++;
			}
			break;
		case sf::Event::KeyReleased:
			if (m_btnPressedCallback) {
				(target->*m_btnReleasedCallback)(m_activeEvent.key.code);
			} else {
				cnt++;
			}
			break;
		default:
			cnt++;
		}
	}
	return (cnt);
}