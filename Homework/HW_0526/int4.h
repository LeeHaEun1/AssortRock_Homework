#pragma once

const int XLine = 20;
const int YLine = 10;

// �̳༮�� ĸ��ȭ�� Ŭ������� ���ٴ� �⺻�ڷ���
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
};