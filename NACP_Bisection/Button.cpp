#include "Button.h"
#include "Functions.h"
#include <Windows.h>

Button::Button(Coord p_ButtonCoord, Coord p_Size, char p_Symbol) :
buttonCoord(p_ButtonCoord),
size(p_Size),
symbol(p_Symbol)
{
}

ButtonEvent Button::onClick()
{
	return eventType;
}

Coord Button::rButtonCoord()
{
	return buttonCoord;
}

Coord Button::rSize()
{
	return size;
}

char Button::rSymbol()
{
	return symbol;
}

Button::~Button()
{
}
