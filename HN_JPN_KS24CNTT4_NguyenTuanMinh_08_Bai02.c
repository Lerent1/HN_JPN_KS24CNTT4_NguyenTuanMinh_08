#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int id;
    char name[100];
    int age;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree *createTree(int id, char name[], int age) {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->id = id;
    strcpy(tree->name, name);
    tree->age = age;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void addTree(Tree *tree, int id, int age) {
    if (tree == NULL) {
        
    }
}

void inorder(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    inorder(tree->left);
    printf("ID: %d | Ten: %s | Tuoi: %d\n", tree->id, tree->name, tree->age);
    inorder(tree->right);
}

int main(void) {
    int choice;
    Tree *root = NULL;

    do {
        printf("1. Them sinh vien\n");
        printf("2. Hien thi sinh vien\n");
        printf("3. Tim kiem sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Them sinh vien\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                break;
            }
            case 2: {
                printf("Danh sach sinh vien la: ");
                inorder(root);
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                printf("Thoat thanh cong\n");
                break;
            }
            default: {
                printf("Hay chon lai\n");
            }
        }
    } while (choice != 5);

    return 0;
}
