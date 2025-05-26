#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(TreeNode* node) {
    if (node == NULL) return;
    printf("%d -> ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(TreeNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d -> ", node->data);
    inorder(node->right);
}

void postorder(TreeNode* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d -> ", node->data);
}

void freeTree(TreeNode* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int getHeight(TreeNode* node) {
    if (node == NULL) return 0;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) +1 ;
}

int countNodes(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(TreeNode* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

int getSum(TreeNode* node) {
    if (node == NULL) return 0;
    return node->data + getSum(node->left) + getSum(node->right);
}

int getMax(TreeNode* node) {
    if (node == NULL) return INT_MIN;
    int maxLeft = getMax(node->left);
    int maxRight = getMax(node->right);
    int maxChild = maxLeft > maxRight ? maxLeft : maxRight;
    return node->data > maxChild ? node->data : maxChild;
}

void searchRange(TreeNode* node, int min, int max) {
    if (node == NULL) return;
    if (node->data >= min && node->data <= max) {
        printf("%d -> ", node->data);
    }
    searchRange(node->left, min, max);
    searchRange(node->right, min, max);
}

int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    printf("���� ��ȸ : ");
    preorder(root);
    printf("\n");

    printf("���� ��ȸ : ");
    inorder(root);
    printf("\n");

    printf("���� ��ȸ : ");
    postorder(root);
    printf("\n");

    printf("Ʈ���� ���� : %d\n", getHeight(root));
    printf("����� ���� : %d\n", countNodes(root));
    printf("���� ����� ���� : %d\n", countLeaves(root));
    printf("����� �� : %d\n", getSum(root));
    printf("�ִ밪 : %d\n", getMax(root));

    printf("���� 6 �̻� 20 ������ ��� : ");
    searchRange(root, 6, 20);
    printf("\n");

    freeTree(root);
    return 0;
}
