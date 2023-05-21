// HomeWork0519.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//int ChCount = 0;
//while (_string[ChCount])
//{
//    ++ChCount;
//}

// 문자열에 Ch와 같은 문자가 몇개들어있는지 세어서 리턴해주는 함수
int ChCount(const char* const _string, char Ch)
{
    if (nullptr == _string)
    {
        return -1;
    }

    int i = 0;
    int Count = 0;
    while (_string[i])
    {
        if (_string[i] == Ch) 
        {
            Count++;
        }

        i++;
    }

    return Count;
}

// 문자열의 공백을 없애주는 함수
// 개인 체감 난이도 상
void TrimDelete(char* _string)
{
    int i = 0;
    while (_string[i]) 
    {
        if (_string[i] == ' ')
        {
            //int j = i;
            //while (_string[j]) 
            //{
            //    _string[j] = _string[j + 1];
            //    j++;
            //}

            while (_string[i] == ' ') 
            {
                int j = i;
                while (_string[j]) 
                {
                    _string[j] = _string[j + 1];
                    j++;
                }
            }
        }
        i++;
    }

    return;
}

// 정수의 글자수를 반환하는 함수(ex. 12345 -> 5, 100 -> 3)
int DigitsCount(int _Number)
{
    int count = 1;
    int temp = _Number;
    while (temp >= 10)
    {
        temp = temp / 10;
        count++;
    }

    return count;
}

// _Right에 _Left의 문자열을 그대로 복사하는 함수
void StrCopy(const char* const _Left, char* _Right)
{
    int i = 0;
    while (_Left[i])
    {
        _Right[i] = _Left[i];
        i++;
    }

    return;
}

// 정수를 문자열로 반환하는 함수
// 가장 어려운 숙제
void NumberToString(int _Number, char* _Right)
{
    int digits = DigitsCount(_Number); //6
    int temp = _Number;

    for (int i = 0; i < digits; i++)
    {
        _Right[digits - i - 1] = temp % 10 + 48;
        temp = temp / 10;
    }

    return;
}


int main()
{
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        // 4가 리턴되어야 합니다. (두 번째 인자가 'a'인 경우)    
        int Result = ChCount("ab aaa ccc ddd eee", 'a');

        int Result2 = ChCount(nullptr, 'w');
    }

    {
        char Arr[256] = "aa  b  c dd ee";

        TrimDelete(Arr);

        // Arr "aabcddee"
        int a = 0;
    }

    {
        int Result = DigitsCount(12345);

        int a = 0;
    }

    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);

        int a = 0;
    }

    {
        char Result[256] = {};

        // Result = "312312";
        NumberToString(312312, Result);


        // Hint
        char Ch = '0'; // 48 '0'

        int Value = 7;

        char ChConvert = Value + 48; // 55 '7'

        int a = 0;
    }
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
