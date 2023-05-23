// HomeWork0523.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [HW_0523] BytePadding 관련 변수들이 실제로 어떤 주소에 저장되는지 확인하기
// [][][][][][][][] [][][][][][][][] [][][][][][][][]

#include <iostream>
using namespace std;

// Size: (예상) 24 (실제) 24
// 메모리 배치:
// (예상) AAAA____ BBBBBBBB CDEEFFFF 또는 AAAABBBB BBBBCDEE FFFF____
// (실제) AAAA____ BBBBBBBB CDEEFFFF
class Test1
{
public:
    int A;
    __int64 B;
    char C;
    char D;
    short E; // 2바이트 정수입니다.
    int F;
};
// 1 2 4 8 : 기본자료형의 크기 TYPE (크기 6짜리는 없다)


// Size: (예상) 8 (실제) 8
// 메모리 배치: (예상) HHHH AAAA (실제) HHHH AAAA
class Player
{
public:
    int HP;
    int ATT;
};

                   // HHHH AAAA TTTT
void TestFunction1(Player _Newplayer, int _Test)
{
    // 이것도 확인해보세요.
    __int64 Address11 = (__int64)&_Newplayer.HP;
    __int64 Address12 = (__int64)&_Newplayer.ATT;
    __int64 Address13 = (__int64)&_Test;

    cout << Address11 << endl; // 7337552
    cout << Address12 << endl; // 7337556 (+4)
    cout << Address13 << endl; // 7337560 (+4)
    // 상기 수치는 빌드할 때마다 줄 92, 112에 대해서 같은 결과가 나온다.
}

int main()
{
    // [Test1]
    size_t Size1 = sizeof(Test1);

    Test1 NewTest1;

    __int64 Address0 = (__int64)&NewTest1.A;
    __int64 Address1 = (__int64)&NewTest1.B;
    __int64 Address2 = (__int64)&NewTest1.C;
    __int64 Address3 = (__int64)&NewTest1.D;
    __int64 Address4 = (__int64)&NewTest1.E;
    __int64 Address5 = (__int64)&NewTest1.F;

    cout << Size1 << endl; // 24
    cout << Address0 << endl; // 17823584 
    cout << Address1 << endl; // 17823592 (+8)
    cout << Address2 << endl; // 17823600 (+8)
    cout << Address3 << endl; // 17823601 (+1)
    cout << Address4 << endl; // 17823602 (+1)
    cout << Address5 << endl; // 17823604 (+2)
    printf_s("------------------------------------\n");


    // [Player]
    size_t Size2 = sizeof(Player);

    Player NewPlayer1;

    __int64 Address6 = (__int64)&NewPlayer1.HP;
    __int64 Address7 = (__int64)&NewPlayer1.ATT;

    cout << Size2 << endl; // 8
    cout << Address6 << endl; // 3799604
    cout << Address7 << endl; // 3799608 (+4)
    printf_s("------------------------------------\n");


    // [TestFunction1]
    Player NewPlayer2;
    NewPlayer2.HP = 100;
    NewPlayer2.ATT = 10;
    TestFunction1(NewPlayer2, 20); // 클래스 초기화 안 해주면 여기서 오류나는 것 같아서 82,83줄에서 초기화해줌..

    //size_t Size2 = sizeof(TestFunction1); // sizeof의 피연산자는 함수일 수 없다.
    
    __int64 Address8 = (__int64)&TestFunction1;
    __int64 Address9 = (__int64)&NewPlayer2.HP;
    __int64 Address10 = (__int64)&NewPlayer2.ATT;
    __int64 Address11 = (__int64)&NewPlayer2;

    cout << Address8 << endl; // 2757608
    cout << Address9 << endl; // 20183292
    cout << Address10 << endl; // 20183296
    cout << Address11 << endl; // 20183292
    printf_s("------------------------------------\n");


    // [TestFunction1_Parameter]
    Player NewPlayer3;
    NewPlayer3.HP = 100;
    NewPlayer3.ATT = 10;
    TestFunction1(NewPlayer3, 20);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
