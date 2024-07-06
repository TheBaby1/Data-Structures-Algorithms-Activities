#include <stdio.h>
#include <stdlib.h>

#include "BinaryTrees.h"

int main(){
	
	NodePtr tree;
	initializeTree(&tree);
	
	Date D1 = createDate(12, 15, 2024);
	Date D2 = createDate(8, 30, 2024);
	Date D3 = createDate(3, 16, 2025);
	Date D4 = createDate(11, 21, 2026);
	Date D5 = createDate(9, 2, 2027);
	Date D6 = createDate(5, 6, 2024);
	
	Product P1 = createProduct("Tender Juicy Hotdog", 75.43, 3, D1);
	Product P2 = createProduct("Argentina Corned Beef", 30.32, 15, D2);
	Product P3 = createProduct("Pancit Canton", 20.15, 20, D3);
	Product P4 = createProduct("Mountain Dew", 25.00, 5, D4);
	Product P5 = createProduct("Toblerone Chocolate", 150.35, 10, D5);
	Product P6 = createProduct("Pringles Sour Cream", 86.93, 20, D6);
	
	addNode(&tree, P1);
	addNode(&tree, P2);
	addNode(&tree, P3);
	addNode(&tree, P4);
	addNode(&tree, P5);
	addNode(&tree, P6);
	
	printf("INORDER DFS TRAVERSAL: ---------------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	inorderBST(tree);
	
	printf("\nPREORDER DFS TRAVERSAL: --------------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	preorderBST(tree);
	
	printf("\nPOSTORDER DFS TRAVERSAL: -------------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	postorderBST(tree);
	
	printf("\nBREADTH FIRST SEARCH TRAVERSAL: ------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	breadthFirstSearch(tree);
	
	printf("\n\n\n-----------------------AFTER DELETING PANCIT CANTON: ---------------------------------\n\n\n");
	deleteNode(&tree, P3);
	
	
	printf("INORDER DFS TRAVERSAL: ---------------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	inorderBST(tree);
	
	printf("\nPREORDER DFS TRAVERSAL: --------------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	preorderBST(tree);
	
	printf("\nPOSTORDER DFS TRAVERSAL: -------------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	postorderBST(tree);
	
	printf("\nBREADTH FIRST SEARCH TRAVERSAL: ------------------------------------------------------\n");
	printf("%-25s %10s %13s %5s %02s\n\n", "PRODUCT NAME", "PRICE", "QUANTITY", " ", "EXPIRY DATE");
	breadthFirstSearch(tree);
	
	return 0;
}
