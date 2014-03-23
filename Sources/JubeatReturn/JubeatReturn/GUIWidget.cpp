#include "GUIWidget.h"
#include "GUIPanel.h"
#include "GraphicsController.h"

GUIWidget::GUIWidget()
	: m_linkedKey(0), m_parent(NULL), m_clicked(false), m_pressed(false)
{

}

GUIWidget::~GUIWidget()
{

}

void GUIWidget::SetPosition(float x, float y) { m_position.x = x; m_position.y = y; }
void GUIWidget::SetSize(float x, float y) { m_size.x = x; m_size.y = y; }
void GUIWidget::SetPosition(sf::Vector2f pos) { m_position = pos; }
void GUIWidget::SetSize(sf::Vector2f sz) { m_size = sz; }
sf::Vector2f GUIWidget::GetPosition() const { return (m_position); }
sf::Vector2f GUIWidget::GetSize() const { return (m_size); }

void GUIWidget::SetParent(GUIPanel *res) { m_parent = res; }
GUIPanel *GUIWidget::GetParent() const { return (m_parent); }
void GUIWidget::SetLinkedKey(int key) { m_linkedKey = key; }
int GUIWidget::GetLinkedKey() const { return (m_linkedKey); }

void GUIWidget::Draw(GraphicsController *target)
{
	sf::RectangleShape rectangle(m_size);

	if (m_parent)
		rectangle.setPosition(m_position + m_parent->GetPosition());
	else
		rectangle.setPosition(m_position);

	rectangle.setFillColor(sf::Color(100, 250, 50));
	if (m_pressed)
		rectangle.setFillColor(sf::Color(50, 50, 250));

	target->GetWindow()->draw(rectangle);
}

void GUIWidget::Update()
{
}

void GUIWidget::ReceiveEvent(GUIEVENT ev, void *param)
{
	switch (ev)
	{
	case DRAW:
		Draw((GraphicsController *)param);
		break;
	case UPDATE:
		Update();
		break;
	case CLICK:
		OnClick();
		break;
	case PRESSED:
		OnPressed();
		break;
	case RELEASED:
		OnReleased();
		break;
	default:
		break;
	}
}

void GUIWidget::OnClick()
{
	m_clicked = true;
}

void GUIWidget::OnPressed()
{
	m_pressed = true;
}

void GUIWidget::OnReleased()
{
	m_pressed = false;
	m_clicked = false;
}
