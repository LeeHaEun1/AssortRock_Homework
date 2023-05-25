#pragma once

const int LineCount = 40;

int StringCount(const char* _Arr);

// 헤더파일에서는 선언만 해주고 구현은 .cpp에서!
// 여기서 구현까지 하면 LNK2005 오류 떠서 빌드 실패
// => Monster와 Player에서 중복으로 이 함수가 사용되는데 구현이 중복으로 되면서 발생하는 오류로 추정..