﻿// HomeWork0520.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수

// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// fasdhjkfasdhjfkasd--------
// Monster-------------------
// 위와같이 UI의 끝부분이 맞게 만들어라.

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
// 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
// 그냥 무식하게 생각해라.

// 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.


// 상태와 개념을 하나로 묶어서 내가 인간적인 생각을 문법으로 표현한다.
// 이걸 객체지향의 특성이 추상화라고 합니다.
class Player
{

};

// 몬스터와 플레이어가 서로 한대씩 때리면서
// 한명이 죽으면 끝납니다.
// 지금 그걸 그래픽으로 표현할 방법이 없으니까.
// 글자로 표현하겠습니다.

// 문자열의 글자수 세는 함수(숙제1 해결 위한 함수)
int StrLength(const char* const _String) 
{
    if (_String == nullptr)
    {
        return -1;
    }

    int count = 0;
    while (_String[count])
    {
        count++;
    }
    return count;
}

// 상태 UI 그리는 함수
void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // [숙제1]
    // 40개로 맞춰오세요.
    int maxDigit = 40;
    int _NameLength = StrLength(_Name);

    // 첫째 줄 (이름줄)
    printf_s("%s", _Name);
    for (int i = 0; i < maxDigit - _NameLength; i++)
    {
        printf_s("-");
    }
    printf_s("\n");

    // 줄바꿈이 안되고 있습니다.
    //printf_s("%s--------------------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);
    //printf_s("--------------------------\n");

    // 넷째 줄
    for (int i = 0; i < maxDigit; i++)
    {
        printf_s("-");
    }
    printf_s("\n");
}

// 공격 및 데미지 상황 설명하는 함수
void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

// Hp에서 Att(공격력)만큼 실제로 제하는 함수
void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;
}

// 내일꼭 break continue

int main()
{
    // 절차지향 코딩이라고 부르고 
    // 함수와 변수를 개념에 묶지 않고 데이터로만 보고 처리하는 방식입니다.

    // 컴퓨터 입장에서 본다면
    // 플레이어의 hp => 인간적인 머릿속에 그린 개념이다.
    // 컴퓨터적인 측면에서 void Damage(int& _Hp, int _Att)
    // 플레이어가 몬스터를 때린다.
    // => 컴퓨터가 보면 그냥 int나 2개 내놔.


    // 숙제1 Test
    //{
    //    char testStr[40] = "ewd fwe111";
    //    std::cout << StrLength(testStr) << std::endl;
    //}

    int PlayerHp = 100;
    int PlayerAtt = 10;
    char PlayerName[40] = "Player";

    int MonsterHp = 100;
    int MonsterAtt = 50;
    char MonsterName[40] = "Monster";

    while (true)
    {
        // [숙제2] (1, 2, 3)
        // 1--------------------------------------------------
        // 콘솔창을 모조리 지우는 함수
        system("cls");

        // 한번에 함수로 만든것이고
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        // 아무키나 입력할때까지 기다리는 함수
        _getch();

        // 2--------------------------------------------------
        system("cls");

        Damage(MonsterHp, PlayerAtt);

        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);

        // [숙제3]
        if (PlayerHp <= 0 || MonsterHp <= 0)
        {
            break;
        }

        _getch();

        // 3--------------------------------------------------
        system("cls");

        Damage(PlayerHp, MonsterAtt);

        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);

        // [숙제3]
        if (PlayerHp <= 0 || MonsterHp <= 0)
        {
            break;
        }

        _getch();
    }
}
