#include <stdio.h>

int main(int argc, char *argv[] ) 
{

    // 두 정수를 입력받아 평균을 계산해서 출력
    // 제약사항 : 변수는 두개만 사용하고 소수점 둘째자리까지만 표시
    // 입력 예 : 두정수를 입력하세요. : 10 20
    // 출력 예 : AVG : 15.00
    
    int x, y;

    scanf("%d %d", &x, &y);

    if(x == 0 || y == 0) {
        printf("0이상의 숫자를 입력해주세요. \n");
        return 0;
    }

    

    printf("result is %0.2f \n", float(x + y / 2) );

}
