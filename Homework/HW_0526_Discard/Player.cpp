#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Wall.h"
#include "ConsoleScreen.h"

// #include "Wall.h"�ؼ� Wall 10���� ��ġ�� �̿��ϴ� ������� �ذ�..?!
// ADWS(�̵�)������ Wall�� ��ġ�� �ȴٸ� �̵����� �ʴ� ���� �߰�

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

bool Player::IsNextToWall(/*const int4& _Pos*/ Wall* _Wall)
{
    char Select = (char)_getch();

    switch (Select)
    {
    case 'a':
        if (AddPosResult(Left) == _Wall->GetPos())
        {
            return true;
        }
        break;
    case 'd':
        if (AddPosResult(Right) == _Wall->GetPos())
        {
            return true;
        }
        break;
    case 'w':
        if (AddPosResult(Up) == _Wall->GetPos())
        {
            return true;
        }
        break;
    case 's':
        if (AddPosResult(Down) == _Wall->GetPos())
        {
            return true;
        }
        break;
    default:
        return false;
        break;
    }
}

void Player::Input(ConsoleScreen* _Screen, Wall* _Wall)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        // !Wall::IsNextToWall ���� �ϱ�� ���� ���� �߻�
        // => ����	C2171	'!' : 'bool (const int4 &)' ������ �ǿ����ڿ��� ���� �ʽ��ϴ�.
        // ! �̷��ͱ��� ������ ��������� ��� �����Ѱǰ�..?

        // Wall::IsNextToWall => �� �ȵǴµ�..
        // E0245 ������ ��� ������ Ư�� ��ü�� ������̾�� �մϴ�.
        /*if (Pos.X != 0 && IsNextToWall(Pos) == false)
        {
            AddPos(Left);
        }*/
        MovePos = Left;
        break;

    case 'd':
        /*if (Pos.X != XLine - 1 && IsNextToWall == false)
        {
            AddPos(Right);
        }*/
        MovePos = Right;
        break;

    case 'w':
      /*  if (Pos.Y != 0 && IsNextToWall == false)
        {
            AddPos(Up);
        }*/
        MovePos = Up;
        break;

    case 's':
       /* if (Pos.Y != YLine - 1 && IsNextToWall == false)
        {
            AddPos(Down);
        }*/
        MovePos = Down;
        break;

    default:
        break;
    }

    if (false == _Screen->ConsoleScreen::IsScreenOut(Player::GetPos() + MovePos) && false == Player::IsNextToWall(_Wall))
    {
        AddPos(MovePos);
    }
    
   /* if (false == this->Player::IsNextToWall(_Wall))
    {
        AddPos(MovePos);
    }*/
}