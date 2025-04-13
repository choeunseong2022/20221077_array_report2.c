#include <stdio.h>

int main() {
    int scores[10];
    int sum = 0;
    float average;
    int i;

    printf("10명의 성적 :\n");
    for (i = 0; i < 10; i++) {
        printf("학생 %d: ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }
    average = sum / 10.0;
    printf("10명 학생의 평균 성적 : %.2f\n", average);
    return 0;
}