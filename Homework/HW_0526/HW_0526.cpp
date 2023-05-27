// HW_0526.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [숙제]
// 1. 파일 정리
// 
// 2. 10개의 장애물 배치 class Wall
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.
// 
// 3. 장애물을 통과 못하게 하기.
// 
// 4. 플레이어가 어떠한 키를 누르면 플레이어 위치에서
//    총알 1발이 발사되게 만드세요.
// 
// 5. 그 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "int4.h"
#include "ConsoleScreen.h"
#include "Player.h"

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ 10, 5 });

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');


        //for (size_t i = 0; i < 5; i++)
        //{

        //    // int4 WallPos = PtrWall.GetPos();
        //    // int4 WallPos = ArrWall[i].GetPos();
        //    int4 WallPos = { 5 + Count, i };
        //    Screen.SetPixel(WallPos, '0');
        //}
        //// ++Count;

        Screen.Print();
        MainPlayer.Input(&Screen);

        //if (0 != _kbhit())
        //{
        //}
        //// 1000이면 1초입니다.
        //// 1초 동안 정지합니다.
        //Sleep(200);
    }
}