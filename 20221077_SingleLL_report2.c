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
    printf("��ȭ��ȣ %s[%s] �߰� �Ϸ�\n", name, phone);
    return newNode;
}

void searchContact(Node* head, const char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("��ȭ��ȣ %s[%s] �˻� �Ϸ�\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("��ȭ��ȣ %s �˻� ����\n", name);
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
            printf("%s�� ��ȭ��ȣ %s ���� �Ϸ�\n", current->name, current->phone);
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
    printf("%s�� ��ȭ��ȣ ���� ����\n", name);
    return head;
}

void displayContacts(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("��ȭ��ȣ�ΰ� ��� �ֽ��ϴ�.\n");
        return;
    }
    printf("��ȭ��ȣ��:\n");
    while (current != NULL) {
        printf("%s�� ��ȭ��ȣ - %s \n", current->name, current->phone);
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
    printf("��ȭ��ȣ�� �޸� ���� �Ϸ�\n");
}

int main() {
    Node* head = NULL;
    int choice;
    char name[20];
    char phone[20];

    while (1) {
        printf("��ȭ��ȣ�� ���� : \n");
        printf("1. ��ȭ��ȣ �߰�\n");
        printf("2. ��ȭ��ȣ ����\n");
        printf("3. ��ȭ��ȣ �˻�\n");
        printf("4. ��ȭ��ȣ ��ü ���\n");
        printf("5. ����\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("�̸��� �Է��ϼ���: ");
            scanf("%s", name);
            printf("��ȭ��ȣ�� �Է��ϼ���: ");
            scanf("%s", phone);
            head = addContact(head, name, phone);
            break;
        case 2:
            printf("������ �̸��� �Է��ϼ���: ");
            scanf("%s", name);
            head = deletaContact(head, name);
            break;
        case 3:
            printf("�˻��� �̸��� �Է��ϼ���: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
            break;
        }
    }
}

