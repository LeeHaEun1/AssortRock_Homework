// 081_Random.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 특정 범위의 난수 생성하기

#include <iostream>
#include <conio.h>
#include <Windows.h>

int Seed = 0;

void SetSeed(int _Seed)
{
	Seed = _Seed;
}

int Random()
{
	// 특정 공식을 통해서 랜덤을 뽑아내는 겁니다.
	return ++Seed;
}

int main()
{
	LARGE_INTEGER Int;
	QueryPerformanceCounter(&Int);

	// 항상 다른 숫자를 넣어줘야 된다.
	srand(time(0));

	while (true)
	{
		std::cout << rand()%10+10 << std::endl;
		_getch();
	}
}