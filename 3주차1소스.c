#include <stdio.h>

int main() {
    int scores[10];
    int sum = 0;
    float average;
    int i;

    printf("10���� ���� :\n");
    for (i = 0; i < 10; i++) {
        printf("�л� %d: ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }
    average = sum / 10.0;
    printf("10�� �л��� ��� ���� : %.2f\n", average);
    return 0;
}