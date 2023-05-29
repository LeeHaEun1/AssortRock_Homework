#pragma once
#include "int4.h"

class Wall : public int4
{
public:
	int4 GetPos()
	{
		return Pos;
	}

	void SetPos(const int4& _Pos)
	{
		Pos = _Pos;
	}

	int4 AddPos(const int4& _Pos)
	{
		Pos += _Pos;
		return Pos;
	}

	/*bool IsNextToWall(const int4& _Pos);*/

	char wallChar = 'O';

private:
	int4 Pos;
};