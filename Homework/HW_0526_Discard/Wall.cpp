#include "Wall.h"

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

//bool Wall::IsNextToWall(const int4& _Pos)
//{
//	//if (_Pos==AddPos(Left)) // �̰� ����;; ������ �߿��Ѱǰ�...? -> ���߿� ���� �ٲ� ���� �߰��ؼ� �׽�Ʈ �غ���
//	if (AddPos(Left)==_Pos || AddPos(Right) == _Pos || AddPos(Up) == _Pos || AddPos(Down) == _Pos)
//	{
//		return true;
//	}
//}