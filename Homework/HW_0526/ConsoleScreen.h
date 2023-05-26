#pragma once
#include "int4.h"

class ConsoleScreen : public int4
{
public:
    ConsoleScreen()
    {

    }

    // BaseCh �ʱ�ȭ �Լ�
    void Init(char _BaseCh);

    // Ư�� ��ġ�� Ư�� ���� ����
    void SetPixel(const int4& _Pos, char _Ch);

    // BaseCh�� 2���� �迭 �ʱ�ȭ
    void Clear();
    

    // ���� ȭ�� ���
    void Print();
    

protected:


private:
    char BaseCh = ' ';
    // Q. ���� 0 �־�����ؼ� +1�ΰǰ�??
    char ArrScreen[YLine][XLine + 1] = {};
};