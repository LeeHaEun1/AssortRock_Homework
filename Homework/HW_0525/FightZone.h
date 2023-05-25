#pragma once
#include <iostream>
#include <conio.h>

class Player;
class Monster;
class FightZone
{
public:
	void Fight(Player& NewPlayer, Monster& NewMonster);
};