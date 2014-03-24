#include <iostream>
#include "CoreController.h"

CoreController::CoreController()
	: m_graphics()
{
	#if _DEBUG
		std::cout << "CoreController Init Debug Mode" << std::endl;
	#endif
	m_inputs.SetBtnPressedCallback(&IInterfacable::OnKeyPressed);
	m_inputs.SetBtnReleasedCallback(&IInterfacable::OnKeyReleased);
}

CoreController::~CoreController()
{

}

void CoreController::Run()
{
	#if _DEBUG
		std::cout << "[  ] CoreController: Graphics Init" << std::endl;
	#endif
	m_graphics.Init();
	#if _DEBUG
		std::cout << "[OK] CoreController: Graphics Init Complete" << std::endl;
	#endif

	#if _DEBUG
		std::cout << "[  ] CoreController: Running" << std::endl;
	#endif
	while (m_graphics.GetWindow()->isOpen())
	{
		m_inputs.PollEvents(&m_graphics, this);
		m_graphics.GetGUI()->Update();

		/* Rendering process */
		m_graphics.RenderWindow();
	}
}

void CoreController::OnKeyPressed(int key)
{
	#if _DEBUG
		std::cout << "[  ] CoreController: Key in received " << key << std::endl;
	#endif	
}
void CoreController::OnKeyReleased(int key)
{
	#if _DEBUG
		std::cout << "[  ] CoreController: Key off received " << key << std::endl;
	#endif	
}

