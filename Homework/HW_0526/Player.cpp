#include <iostream>
#include <conio.h>
#include "Player.h"

void Player::Input(ConsoleScreen* _Sreen)
{
	char Select = (char)_getch();

	int4 MovePos = { 0, 0 };

	switch (Select)
	{
	case 'a':

		MovePos = Left;

		// ȭ�� �ٱ����� ������ �ʾҴٸ� <= �ൿ true
		// ���� �̵��Ѵ�.
		// 4 5 + -1 0
		// 3 5 
		// int4 NextPos = GetPos() + Left;
		//if (false == _Sreen->IsScreenOut(GetPos() + Left))
		//{
		//    AddPos(Left);
		//}

		// ������ ���ƿ´�.
		//AddPos(Left);
		//if (true == _Sreen->IsScreenOut(GetPos()))
		//{
		//    AddPos(Right);
		//}
		break;
	case 'd':
		MovePos = Right;

		//if (false == _Sreen->IsScreenOut(GetPos() + Right))
		//{
		//    AddPos(Right);
		//}

		break;
	case 'w':
		MovePos = Up;

		//if (false == _Sreen->IsScreenOut(GetPos() + Up))
		//{
		//    AddPos(Up);
		//}
		break;
	case 's':
		MovePos = Down;
		break;
	default:
		break;
	}

	if (false == _Sreen->IsScreenOut(GetPos() + MovePos))
	{
		AddPos(MovePos);
	}
}