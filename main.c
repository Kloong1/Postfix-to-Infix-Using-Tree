#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isOperand(char);
void printInfix(NODE*);

int main(){
	
	FILE* fp = NULL;
	fp = fopen("postfix.txt", "r");

	STACK* s = (STACK*)malloc(sizeof(STACK));
	s->top = -1;

	char op = 0;
	NODE* parent = NULL;
	NODE* leftChild = NULL;
	NODE* rightChild = NULL;

	printf("Print postfix\n");
	while(1){
		fscanf(fp, "%c", &op);
		if(op == '#') break; // End of FILE

		printf("%c", op);
		/* when op is operand */

		if(isOperand(op)){
			Push(s, makeNode(op));
			continue;
		}

		/* when op is operator */

		rightChild = Top(s);
		Pop(s);
		leftChild = Top(s);
		Pop(s);

		parent = makeNode(op);
		parent->left = leftChild;
		parent->right = rightChild;

		Push(s, parent);
	}
	
	printf("\n");

	NODE* root = Top(s);
	Pop(s);

	if(!isEmpty(s)){
		printf("Error: Wrong postfix statement!");
	}

	printf("Print tree postorder\n");
	printPostorder(root);
	printf("\n");

	printf("Print tree inorder\n");
	printInorder(root);
	printf("\n");

	printf("Print infix\n");
	printInfix(root);
	printf("\n");

	deleteTree(root);
	free(root);

	free(s);
	fclose(fp);
	return 0;
}

int isOperand(char op){
	return (op >= '0' && op <= '9');
}

void printInfix(NODE* tree){
	if(tree->left != NULL){
		printf("( ");
		printInfix(tree->left);
	}
	printf("%c ", tree->element);
	if(tree->right != NULL){
		printInfix(tree->right);
		printf(") ");
	}
}
