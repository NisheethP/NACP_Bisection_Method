#pragma once
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Functions.h"

enum ButtonEvent
{
	Event_Plus,
	Event_Minus,
	Event_Multiply,
	Event_Power,
	Event_Divide,
	Event_X,
	Event_0,
	Event_1,
	Event_2,
	Event_3,
	Event_4,
	Event_5,
	Event_6,
	Event_7,
	Event_8,
	Event_9,
	Event_Solve,
	Event_Backspace,
	Event_Left,
	Event_Right,
	Event_Up,
	Event_Down
};

class Button
{
	Coord buttonCoord;
	Coord size;
	ButtonEvent eventType;
	char symbol;

public:
	Button(Coord p_ButtonCoord = Coord(0,0), Coord p_Size = Coord(1,1), char p_Symbol = '~');

	ButtonEvent onClick();
	Coord rButtonCoord();
	Coord rSize();
	char rSymbol();

	~Button();
};

#endif