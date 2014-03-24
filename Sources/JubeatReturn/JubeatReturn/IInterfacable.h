#pragma once

class IInterfacable
{
public:
	virtual ~IInterfacable() { }

	virtual void OnKeyPressed(int key) = 0;
	virtual void OnKeyReleased(int key) = 0;
};
