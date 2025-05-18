#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    char phone[20];
    struct Node* next;
} Node;

Node* addContact(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = head;
    printf("전화번호 %s[%s] 추가 완료\n", name, phone);
    return newNode;
}

void searchContact(Node* head, const char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("전화번호 %s[%s] 검색 완료\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("전화번호 %s 검색 실패\n", name);
}

Node* deletaContact(Node* head, const char* name) {
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            printf("%s의 전화번호 %s 삭제 완료\n", current->name, current->phone);
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
    printf("%s의 전화번호 삭제 실패\n", name);
    return head;
}

void displayContacts(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }
    printf("전화번호부:\n");
    while (current != NULL) {
        printf("%s의 전화번호 - %s \n", current->name, current->phone);
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("전화번호부 메모리 해제 완료\n");
}

int main() {
    Node* head = NULL;
    int choice;
    char name[20];
    char phone[20];

    while (1) {
        printf("전화번호부 관리 : \n");
        printf("1. 전화번호 추가\n");
        printf("2. 전화번호 삭제\n");
        printf("3. 전화번호 검색\n");
        printf("4. 전화번호 전체 출력\n");
        printf("5. 종료\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("이름을 입력하세요: ");
            scanf("%s", name);
            printf("전화번호를 입력하세요: ");
            scanf("%s", phone);
            head = addContact(head, name, phone);
            break;
        case 2:
            printf("삭제할 이름을 입력하세요: ");
            scanf("%s", name);
            head = deletaContact(head, name);
            break;
        case 3:
            printf("검색할 이름을 입력하세요: ");
            scanf("%s", name);
            searchContact(head, name);
            break;
        case 4:
            displayContacts(head);
            break;
        case 5:
            freeList(head);
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
            break;
        }
    }
}

