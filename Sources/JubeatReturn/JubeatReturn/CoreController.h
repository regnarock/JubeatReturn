#pragma once

#include "GraphicsController.h"
#include "InputController.h"
#include "IInterfacable.h"

class CoreController : public IInterfacable
{
private:
	GraphicsController m_graphics;
	InputController m_inputs;
	sf::Clock m_time;

	/*
		TODO

	// parses a beatmap file and provides a stream to generate a game
	Parser m_parser;

	// Active game
	Game *m_activeGame;

	// Active session (data kept over game but not after close)
	Session m_activeSession;
	*/

public:
	CoreController();
	~CoreController();

	void Run();

	virtual void OnKeyPressed(int key);
	virtual void OnKeyReleased(int key);
};