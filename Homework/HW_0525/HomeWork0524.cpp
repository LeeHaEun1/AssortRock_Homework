// HomeWork0524.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <conio.h>

const int LineCount = 40;

int StringCount(const char* _Arr)
{
	// ���� �����ڵ带 �����ϼ���
	int ChCount = 0;
	while (_Arr[ChCount])
	{
		++ChCount;
	}

	return ChCount;
}

class Player
{
public:
	void StatusRender()
	{
		int Count = 0;

		Count = StringCount(Name);

		// 40���� ���������.

		// �ٹٲ��� �ȵǰ� �ֽ��ϴ�.
		printf_s("%s", Name);

		for (size_t i = 0; i < LineCount - Count; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

		printf_s("���ݷ� : %d\n", Att);
		printf_s("ü  �� : %d\n", Hp);
		for (size_t i = 0; i < LineCount; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

	}

	void DamagePrint(const char* const _AttName, int _Att)
	{
		printf_s("%s�� %s�� �����߽��ϴ�.\n", _AttName, Name);
		printf_s("%s�� %d�� �������� �Ծ����ϴ�.\n", Name, _Att);
	}

	void Damage(int _Att)
	{
		Hp -= _Att;
	}

	// 
	const char* GetName()
	{
		return Name;
	}

	int GetAtt()
	{
		return Att;
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}


private:
	// ĸ��ȭ
	char Name[40] = "Player";
	int Att = 10;
	int Hp = 100;
};

class Monster
{
	// c++������ �Լ����� �װ� ���� ���α׷����� �ǵ��� �ο��Ҽ��� �ֽ��ϴ�.

public:
	//void LvUp() 
	//{
	//	Att += 10;
	//}

	void StatusRender()
	{
		int Count = 0;

		Count = StringCount(Name);

		// 40���� ���������.

		// �ٹٲ��� �ȵǰ� �ֽ��ϴ�.
		printf_s("%s", Name);

		for (size_t i = 0; i < LineCount - Count; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

		printf_s("���ݷ� : %d\n", Att);
		printf_s("ü  �� : %d\n", Hp);
		for (size_t i = 0; i < LineCount; i++)
		{
			printf_s("-");
		}

		printf_s("\n");

	}

	void DamagePrint(const char* const _AttName, int _Att)
	{
		printf_s("%s�� %s�� �����߽��ϴ�.\n", _AttName, Name);
		printf_s("%s�� %d�� �������� �Ծ����ϴ�.\n", Name, _Att);
	}

	void Damage(int _Att)
	{
		Hp -= _Att;
	}

	const char* GetName()
	{
		return Name;
	}

	int GetAtt()
	{
		return Att;
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}

private:
	// ĸ��ȭ
	char Name[40] = "Monster";
	int Att = 10;
	int Hp = 100;
};

class FightZone
{
public:
	void Fight(Player& NewPlayer, Monster& NewMonster)
	{
		while (true)
		{
			system("cls");

			// �ѹ��� �Լ��� ������̰�
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			_getch();

			system("cls");
			NewMonster.Damage(NewPlayer.GetAtt());
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			NewMonster.DamagePrint(NewPlayer.GetName(), NewPlayer.GetAtt());
			_getch();

			if (true == NewMonster.IsDeath())
			{
				printf_s("%s�� �׾����ϴ�.\n", NewMonster.GetName());
				printf_s("%s�� �¸��Դϴ�.\n", NewPlayer.GetName());
				_getch();
				return;
			}

			system("cls");
			NewPlayer.Damage(NewMonster.GetAtt());
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			NewMonster.DamagePrint(NewPlayer.GetName(), NewPlayer.GetAtt());
			NewPlayer.DamagePrint(NewMonster.GetName(), NewMonster.GetAtt());
			_getch();

			if (true == NewPlayer.IsDeath())
			{
				printf_s("%s�� �׾����ϴ�.\n", NewPlayer.GetName());
				printf_s("%s�� �¸��Դϴ�.\n", NewMonster.GetName());
				_getch();
				return;
			}
		}
	}
};

// ������ �� �����ߴ�? �ΰ��� �ڵ带 ��ġ�� ���ؼ� �����߽��ϴ�.
int main()
{
	// ��ü�����̶�� �Ѵ�.
	Player NewPlayer;
	Monster NewMonster;

	FightZone FZone;
	FZone.Fight(NewPlayer, NewMonster);

}
