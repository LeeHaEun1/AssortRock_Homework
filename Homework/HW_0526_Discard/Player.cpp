#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Wall.h"
#include "ConsoleScreen.h"

// #include "Wall.h"해서 Wall 10개의 위치를 이용하는 방식으로 해결..?!
// ADWS(이동)했을때 Wall의 위치가 된다면 이동하지 않는 조건 추가

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
        // !Wall::IsNextToWall 사용시 하기와 같은 에러 발생
        // => 오류	C2171	'!' : 'bool (const int4 &)' 형식의 피연산자에는 맞지 않습니다.
        // ! 이런것까지 일일히 정의해줘야 사용 가능한건가..?

        // Wall::IsNextToWall => 왜 안되는데..
        // E0245 비정적 멤버 참조는 특정 개체에 상대적이어야 합니다.
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