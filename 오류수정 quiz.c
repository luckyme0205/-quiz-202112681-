#include <stdio.h> 
#include <stdlib.h> 

int main() {
    double* p1;
    p1 = (double*)malloc(sizeof(double)); // 메모리 할당을 sizeof(double)로 수정
    if (p1 == NULL) { // 동적 메모리 할당이 실패했는지 확인
        printf("메모리 할당에 실패했습니다.\n");
        return 1; // 실패 시 종료
    }

    *p1 = 23.92; // 할당된 메모리에 값을 할당하기 위해 간접 참조 연산자를 사용

    free(p1); // 동적으로 할당된 메모리 해제
    return 0; 
}
