#pragma once

#include <SFML\Graphics.hpp>
#include "GUIEvents.h"

class GraphicsController;
class GUIPanel;

class GUIWidget
{
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_size;

	int m_linkedKey;
	GUIPanel *m_parent;
	bool m_clicked;
	bool m_pressed;

public:
	GUIWidget();
	virtual ~GUIWidget();

	// Position and size definition (non sfml related)
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f pos);
	sf::Vector2f GetPosition() const;	
	void SetSize(float x, float y);
	void SetSize(sf::Vector2f sz);
	sf::Vector2f GetSize() const;
	
	// Key that triggers the widget
	void SetLinkedKey(int key);
	void SetParent(GUIPanel *);
	GUIPanel *GetParent() const;
	int GetLinkedKey() const;

	virtual void Draw(GraphicsController *target);
	virtual void Update();
	virtual void ReceiveEvent(GUIEVENT ev, void *param);

	// On first press of the key before release
	virtual void OnClick(); // Alias of OnClickFinish

	// If the key is pressed but not released (constantly active)
	virtual void OnPressed(); 

	// If the key is released (active once)
	virtual void OnReleased(); 


};