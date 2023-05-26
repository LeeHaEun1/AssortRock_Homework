#include <iostream>
#include <conio.h>
#include "Player.h"

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

void Player::Input()
{
    char Select = (char)_getch();

    switch (Select)
    {
    case 'a':
        if (Pos.X != 0)
        {
            AddPos(Left);
        }
        break;

    case 'd':
        if (Pos.X != XLine - 1)
        {
            AddPos(Right);
        }
        break;

    case 'w':
        if (Pos.Y != 0)
        {
            AddPos(Up);
        }
        break;

    case 's':
        if (Pos.Y != YLine - 1)
        {
            AddPos(Down);
        }
        break;

    default:
        break;
    }
}