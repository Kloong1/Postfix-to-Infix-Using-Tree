#include <stdlib.h>
#include <stdio.h>
#define ElementType_T char

typedef struct _NODE{
	ElementType_T element;
	struct _NODE* left;
	struct _NODE* right;
} NODE;

NODE* makeNode(ElementType_T op){
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->element = op;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void printInorder(NODE* tree){
	if(tree->left != NULL)
		printInorder(tree->left);
	printf("%c ", tree->element);
	if(tree->right != NULL)
		printInorder(tree->right);
}

void printPostorder(NODE* tree){
	if(tree->left != NULL)
		printPostorder(tree->left);
	if(tree->right != NULL)
		printPostorder(tree->right);
	printf("%c ", tree->element);
}

void deleteTree(NODE* tree){
	if(tree->left != NULL){
		deleteTree(tree->left);
		free(tree->left);
	}
	if(tree->right != NULL){
		deleteTree(tree->right);
		free(tree->right);
	}

}
