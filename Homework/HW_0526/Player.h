#pragma once
#include "int4.h"

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

    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    Player() : Pos()
    {

    }

    Player(const Player&) = delete;

    void Input();
    

protected:


private:
    int4 Pos;
};