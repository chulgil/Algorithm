#include <stdio.h>

int main(int argc, char *argv[] )
{
    // 정수로 second를 입력받아 '시:분:초' 형식으로 출력
    // 각 시간은 모두 정수로 표시되어야 하며 한자리 숫자인경우 0을 붙여 출
    // 입력 예 : 4000
    // 출력 예 : 4000초는 01시간 06분 40초 입니다.
    
    int microtime;

    scanf("%d", &microtime);

    int time, minute, second;
    second = microtime % 60;
    minute = microtime/60 % 60;
    time = microtime/60/60 %60;

    printf("%d초는 %02d시간 %02d분 %02d초 입니다. \n",microtime, time, minute, second);

    return 0;
}