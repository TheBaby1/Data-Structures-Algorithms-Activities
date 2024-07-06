#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BinaryTrees.h"

void addNode(NodePtr *list, Product item){
	
	NodePtr newNode = malloc(sizeof(NodeType));
	
	newNode->item = item;
	newNode->left = NULL;
	newNode->right = NULL;
	
	if (*list == NULL){
		*list = newNode;
		return;
	}
	
	NodePtr current = *list;
	
	while (current != NULL){
		if (strcmp(item.prodName, current->item.prodName) < 0){
			if (current->left == NULL){
				current->left = newNode;
				break;
			} else {
				current = current->left;
			}
		}
		
		if (strcmp(item.prodName, current->item.prodName) > 0){
			if (current->right == NULL){
				current->right = newNode;
				break;
			} else {
				current = current->right;
			}
		}
	}
}

void deleteNode(NodePtr *list, Product item) {
    NodePtr *current = list;
    NodePtr temp = NULL;

    while (*current != NULL && strcmp((*current)->item.prodName, item.prodName) != 0) {
        if (strcmp(item.prodName, (*current)->item.prodName) < 0) {
            current = &(*current)->left;
        } else {
            current = &(*current)->right;
        }
    }

    if (*current != NULL) {
        temp = *current;

        if ((*current)->left == NULL) {
            *current = (*current)->right;
        } else if ((*current)->right == NULL) {
            *current = (*current)->left;
        }
 
        else {
            NodePtr successorParent = *current;
            NodePtr successor = (*current)->right;

            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }

            successor->left = (*current)->left;
            if (successorParent != *current) {
                successorParent->left = successor->right;
                successor->right = (*current)->right;
            }
            *current = successor;
        }

        free(temp);
    }
}

void inorderBST(NodePtr list){
	
	if (!isEmpty(list)){
		inorderBST(list->left);
		displayProduct(list->item);
		inorderBST(list->right);
	}
}

void preorderBST(NodePtr list){
	
	if (!isEmpty(list)){
		displayProduct(list->item);
		preorderBST(list->left);
		preorderBST(list->right);
	}
}

void postorderBST(NodePtr list){
	
	if (!isEmpty(list)){
		postorderBST(list->left);
		postorderBST(list->right);
		displayProduct(list->item);
	}
}

void breadthFirstSearch(NodePtr root){
	
	Queue Q;
	initializeQueue(&Q);
	
	enQueue(&Q, root);
	
	while (!isQueueEmpty(&Q)){
		NodePtr current = deQueue(&Q);
		displayProduct(current->item);
		
		if (current->left != NULL){
			enQueue(&Q, current->left);
		}
		
		if (current->right != NULL){
			enQueue(&Q, current->right);
		}
	}
}

bool isEmpty(NodePtr list){
	
	return (list == NULL);
}

void initializeTree(NodePtr *list){
	
	*list = NULL;
}

Date createDate(int day, int month, int year){
	
	Date D;
	
	D.day = day;
	D.month = month;
	D.year = year;
	
	return D;
}

Product createProduct(char *prodName, float prodPrice, int prodQty, Date expDate){
	
	Product P;
	
	strcpy(P.prodName, prodName);
	P.prodPrice = prodPrice;
	P.prodQty = prodQty;
	P.expDate = expDate;
	
	return P;
}

void displayProduct(Product item){
	
	printf("%-25s %10.2f %10d %8s %02d/%02d/%4d\n", item.prodName, item.prodPrice, item.prodQty, " ", item.expDate.month, item.expDate.day, item.expDate.year);

}

void initializeQueue(Queue *Q){
	
	Q->front = Q->rear = NULL;
}

bool isQueueEmpty(Queue *Q){
	
	return (Q->front == NULL);
}

void enQueue(Queue *Q, NodePtr treeNode){
	
	QueueNode *newNode = malloc(sizeof(QueueNode));
	
	newNode->treeNode = treeNode;
	newNode->next = NULL;
	
	if (Q->rear != NULL){
		Q->rear->next = newNode;
	}
	Q->rear = newNode;
	
	if (Q->front == NULL){
		Q->front = newNode;
	}
}

NodePtr deQueue(Queue *Q){
	
	QueueNode *temp = Q->front;
	NodePtr treeNode = temp->treeNode;
	
	Q->front = Q->front->next;
	
	if (Q->front == NULL){
		Q->rear = NULL;
	}
	
	free(temp);
	return treeNode;
}



