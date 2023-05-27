#pragma once
#include "int4.h"
#include "ConsoleScreen.h"

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

class ConsoleScreen;
class Player
{
public:
	int4 GetPos() const
	{
		return Pos;
	}

	void AddPos(const int4& _Pos)
	{
		Pos += _Pos;
	}

	void SetPos(const int4& _Pos)
	{
		Pos = _Pos;
	}

	Player() : Pos()
	{

	}

	Player(const Player&) = delete;

	void Input(ConsoleScreen* _Sreen);


protected:


private:
	int4 Pos;
};