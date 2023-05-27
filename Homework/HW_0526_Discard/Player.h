#pragma once
#include "int4.h"

class ConsoleScreen;
class Wall;
class Player : public int4
{
public:
    int4 GetPos()
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }

    int4 AddPosResult(const int4& _Pos)
    {
        Pos += _Pos;
        return Pos;
    }

    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    Player() : Pos()
    {

    }

    Player(const Player&) = delete;

    bool IsNextToWall(Wall* _Wall);

    void Input(ConsoleScreen* _Screen, Wall* _Wall);
    

protected:


private:
    int4 Pos;
};