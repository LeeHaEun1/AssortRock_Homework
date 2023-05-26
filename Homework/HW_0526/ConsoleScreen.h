#pragma once
#include "int4.h"

class ConsoleScreen : public int4
{
public:
    ConsoleScreen()
    {

    }

    // BaseCh 초기화 함수
    void Init(char _BaseCh);

    // 특정 위치에 특정 문자 삽입
    void SetPixel(const int4& _Pos, char _Ch);

    // BaseCh로 2차원 배열 초기화
    void Clear();
    

    // 실제 화면 출력
    void Print();
    

protected:


private:
    char BaseCh = ' ';
    // Q. 끝에 0 넣어줘야해서 +1인건가??
    char ArrScreen[YLine][XLine + 1] = {};
};