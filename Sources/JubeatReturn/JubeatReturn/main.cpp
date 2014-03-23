#include <iostream>
#include "GraphicsController.h"

int main(int ac, char **av)
{
	GraphicsController gc;

	gc.Init();
	while (gc.GetWindow()->isOpen()) {
		gc.RenderWindow();
	}
	return (0);
}