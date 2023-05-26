#include <iostream>
#include <conio.h>
#include "Player.h"

// #include "Wall.h"해서 Wall 10개의 위치를 이용하는 방식으로 해결..?!
// ADWS(이동)했을때 Wall의 위치가 된다면 이동하지 않는 조건 추가

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

void Player::Input()
{
    char Select = (char)_getch();

    int4 NextPos = { 0, 0 };

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