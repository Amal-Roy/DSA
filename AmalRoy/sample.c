#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Define tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Define stack for tree nodes
struct StackNode {
    struct Node* treeNode;
    struct StackNode* next;
};

// Define stack for characters (operators)
struct CharNode {
    char data;
    struct CharNode* next;
};

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    // Input infix expression
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    // Operator stack
    struct CharNode* opTop = NULL;

    // Infix to Postfix
    while (infix[i] != '\0') {
        char c = infix[i];
        if (isspace(c)) {
            i++;
            continue;
        }

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            struct CharNode* newOp = (struct CharNode*)malloc(sizeof(struct CharNode));
            newOp->data = c;
            newOp->next = opTop;
            opTop = newOp;
        } else if (c == ')') {
            while (opTop != NULL && opTop->data != '(') {
                postfix[j++] = opTop->data;
                struct CharNode* temp = opTop;
                opTop = opTop->next;
                free(temp);
            }
            if (opTop != NULL && opTop->data == '(') {
                struct CharNode* temp = opTop;
                opTop = opTop->next;
                free(temp);
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            int prec;
            if (c == '+' || c == '-') prec = 1;
            else if (c == '*' || c == '/') prec = 2;
            else prec = 3;

            while (opTop != NULL) {
                int topPrec;
                if (opTop->data == '+' || opTop->data == '-') topPrec = 1;
                else if (opTop->data == '*' || opTop->data == '/') topPrec = 2;
                else if (opTop->data == '^') topPrec = 3;
                else topPrec = 0;

                if (topPrec >= prec) {
                    postfix[j++] = opTop->data;
                    struct CharNode* temp = opTop;
                    opTop = opTop->next;
                    free(temp);
                } else {
                    break;
                }
            }

            struct CharNode* newOp = (struct CharNode*)malloc(sizeof(struct CharNode));
            newOp->data = c;
            newOp->next = opTop;
            opTop = newOp;
        }

        i++;
    }

    while (opTop != NULL) {
        postfix[j++] = opTop->data;
        struct CharNode* temp = opTop;
        opTop = opTop->next;
        free(temp);
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    // Build Expression Tree
    struct StackNode* treeStack = NULL;
    i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = c;
        newNode->left = newNode->right = NULL;

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            struct StackNode* rightNode = treeStack;
            treeStack = treeStack->next;
            struct StackNode* leftNode = treeStack;
            treeStack = treeStack->next;

            newNode->right = rightNode->treeNode;
            newNode->left = leftNode->treeNode;

            free(rightNode);
            free(leftNode);
        }

        struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
        newStackNode->treeNode = newNode;
        newStackNode->next = treeStack;
        treeStack = newStackNode;

        i++;
    }

    struct Node* root = NULL;
    if (treeStack != NULL) {
        root = treeStack->treeNode;
        free(treeStack);
    }

    // Traversals without functions
    // Inorder (with brackets)
    printf("Inorder (infix): ");
    struct Node* stack[MAX];
    int top = -1;
    struct Node* curr = root;
    int done = 0;

    while (!done) {
        if (curr != NULL) {
            if (curr->left != NULL || curr->right != NULL)
                printf("(");
            stack[++top] = curr;
            curr = curr->left;
        } else {
            if (top >= 0) {
                curr = stack[top--];
                printf("%c", curr->data);
                if (curr->left != NULL || curr->right != NULL)
                    printf(")");
                curr = curr->right;
            } else {
                done = 1;
            }
        }
    }
    printf("\n");

    // Preorder (prefix)
    printf("Preorder (prefix): ");
    top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* node = stack[top--];
        if (node != NULL) {
            printf("%c ", node->data);
            if (node->right) stack[++top] = node->right;
            if (node->left) stack[++top] = node->left;
        }
    }
    printf("\n");

    // Postorder (postfix) using 2 stacks
    printf("Postorder (postfix): ");
    struct Node* s1[MAX];
    struct Node* s2[MAX];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;
    while (top1 >= 0) {
        struct Node* node = s1[top1--];
        s2[++top2] = node;
        if (node->left) s1[++top1] = node->left;
        if (node->right) s1[++top1] = node->right;
    }

    while (top2 >= 0) {
        printf("%c ", s2[top2--]->data);
    }

    printf("\n");

    return 0;
}

