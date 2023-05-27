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
#include "Wall.h"

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ 10, 5 });

    int Count = 0;

    Wall ArrWall[20];
    //Wall* PtrWall = ArrWall;

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');

        for (int i = 0; i < 10; i++)
        {
            // int4 WallPos = PtrWall.GetPos();
            // int4 WallPos = ArrWall[i].GetPos();
            // 
            //int4 WallPos = { 5 + Count, i };

            ArrWall[i].SetPos({ i*2, 1 });
            Screen.SetPixel(ArrWall[i].GetPos(), 'O');
            //MainPlayer.IsNextToWall(ArrWall[i]);
        }
        //++Count;

        Screen.Print();

        /*if (0 != _kbhit())
        {
            for (int i = 0; i < 10; i++)
            {
                if (MainPlayer.IsNextToWall(ArrWall[i].GetPos()) == false)
                {
                    MainPlayer.Input();
                }
            }
        }*/
        //MainPlayer.Input(&Screen, &ArrWall[20]);


        for (int i = 0; i < 10; i++)
        {
            MainPlayer.Input(&Screen, &ArrWall[i]);
        }
        
        //if (0 != _kbhit())
        //{
        //    //MainPlayer.Input(&Screen); // 강사님 풀이가 아니라 내 숙제 기반으로 작업해서 발생한 차이..
        //    //MainPlayer.Input();
        //}
        //// 1000이면 1초입니다.
        //// 1초 동안 정지합니다.
        //Sleep(200);
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
