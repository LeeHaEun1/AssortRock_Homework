#include <iostream>
#include <conio.h>
#include <Windows.h>

// [숙제]
// 1. 파일 정리

// 2. 10개의 장애물 배치 class Wall (완료)
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.

// 3. 장애물을 통과 못하게 하기.

// 4. 플레이어가 어떠한 키를 누르면 플레이어 위치에서
//    총알 1발이 발사되게 만드세요. (완료)

// 5. 그 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.



class int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

    int4 operator+(const int4& _Other) const
    {
        int4 Return;
        Return.X = X + _Other.X;
        Return.Y = Y + _Other.Y;
        Return.Z = Z + _Other.Z;
        Return.W = W + _Other.W;
        return Return;
    }

    bool operator==(const int4& _Other)
    {
        if (X == _Other.X && Y == _Other.Y && Z == _Other.Z && W == _Other.W)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

// Init('*')

// [*][*][0] \n
// [*][*][0] \n

const int XLine = 20;
const int YLine = 10;

class ConsoleScreen
{
public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh)
    {
        BaseCh = _BaseCh;
        Clear();
    }

    void SetPixel(const int4& _Pos, char _Ch)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

    void Clear()
    {
        system("cls");
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    }

    bool IsScreenOut(const int4& _Pos) const
    {
        if (0 > _Pos.X)
        {
            return true;
        }

        if (0 > _Pos.Y)
        {
            return true;
        }

        if (XLine <= _Pos.X)
        {
            return true;
        }

        if (YLine <= _Pos.Y)
        {
            return true;
        }

        return false;
    }


    void Print() const
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    }

protected:


private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};

class Player
{
public:
    // 레퍼런스는 기본적으로 8바이트 참조입니다.
    // int4를 그냥 16바이트입니다.
    // int4&를 그냥 8바이트입니다.
    // int4*를 그냥 8바이트입니다.

    // 내가 넣으려는 인자가 합쳐서 8바이트가 넘어갈때
    // 그걸 구조체나 클래스로 묶어서 참조형태로 넘기는게 대부분의 상황에서
    // 무조건 이득이다.

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

    void Input(ConsoleScreen* _Screen)
    {
        char Select = (char)_getch();

        int4 MovePos = { 0, 0 };

        switch (Select)
        {
        case 'a':

            MovePos = Left;

            // 화면 바깥으로 나가지 않았다면 <= 행동 true
            // 나는 이동한다.
            // 4 5 + -1 0
            // 3 5 
            // int4 NextPos = GetPos() + Left;
            //if (false == _Sreen->IsScreenOut(GetPos() + Left))
            //{
            //    AddPos(Left);
            //}

            // 가고나서 돌아온다.
            //AddPos(Left);
            //if (true == _Sreen->IsScreenOut(GetPos()))
            //{
            //    AddPos(Right);
            //}
            break;
        case 'd':
            MovePos = Right;
            break;
        case 'w':
            MovePos = Up;
            break;
        case 's':
            MovePos = Down;
            break;
        case ' ':

        default:
            break;
        }

        if (false == _Screen->IsScreenOut(GetPos() + MovePos))
        {
            AddPos(MovePos);
        }

    }

protected:


private:
    int4 Pos;
};


class Bullet
{
public:
    int4 GetPos() const
    {
        return Pos;
    }

    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    bool IsShooting = false;
    bool HitWall = false; 

private:
    int4 Pos;
};


class Wall
{
public:
    int4 GetPos() const
    {
        return Pos;
    }

    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

private:
    int4 Pos;
};


int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ 10, 5 });

    Wall Wall[10];

    Bullet Bullet;

    //int4 int0 = { 0, 1 };
    //int4 int1 = { 0, 1 };

    while (true)
    {
        // == 기호는 정상 작동
        //if (int0 == int1)
        //{
        //    printf_s("same");
        //}

        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');

        // 벽 설치
        for (int i = 0; i < 10; i++)
        {
            Wall[i].SetPos({ i * 2, 1});
            Screen.SetPixel(Wall[i].GetPos(), 'O');
        }

        // 총알이 벽에 맞았는지 확인 (for문)
        for (int i = 0; i < 10; i++)
        {
            if (Wall[i].GetPos() == Bullet.GetPos())
            {
                Bullet.HitWall = true;
                Screen.SetPixel(Wall[i].GetPos(), '*');
                Screen.SetPixel(Bullet.GetPos(), '*');
                std::cout << "hitwall" << std::endl;
            }
        }

        // 총알 발사
        if (Bullet.IsShooting == true && Screen.IsScreenOut(Bullet.GetPos()+Up) == false && Bullet.HitWall == false)
        {
            Bullet.SetPos(Bullet.GetPos() + Up);
            Screen.SetPixel(Bullet.GetPos(), 'B');
        }

        Screen.Print();

        if (0 != _kbhit())
        {
            MainPlayer.Input(&Screen);
            
            // Key 'B' 클릭 시 총알 발사
            if ((char)_getch() == 'b')
            {
                Bullet.IsShooting = true;
                Bullet.SetPos(MainPlayer.GetPos());
            }
        }

        // 1000이면 1초입니다.
        // 1초 동안 정지합니다.
        Sleep(200);
    }
}