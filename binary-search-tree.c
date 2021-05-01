/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if (*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}

void inorderTraversal(Node* ptr) //LVR식으로 출력
{
	if (ptr != NULL) //ptr이 NULL이 아니라면
	{
		inorderTraversal(ptr->left); //순환 호출을 통해서 ptr이 가장 왼쪽 자식을 가리키게 하고
		printf("   [%d]",ptr->key); //ptr의 key 프린트
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr) //VLR식으로 출력
{

}

void postorderTraversal(Node* ptr)
{

}

int insert(Node* head, int key)
{
	Node* node = (Node*)malloc(sizeof(Node));
	Node* temp;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	if (head->left == NULL) //비어있는 트리라면
	{
		head->left = node;
	}
	else //트리가 비어있지 않다면
	{
		temp = head->left; //temp는 트리의 첫 번째 원소 가리킴
		while (temp->left!=NULL || temp->right != NULL )
		{
			if (temp->key >= key) //temp가 가리키는 곳의 key가 key보다 크거나 같다면
			{
				if (temp->left == NULL)
					break;
				temp = temp->left;
			}
			else
			{
				if (temp->right == NULL)
					break;
				temp = temp->right;
			}
		}
		//반복문을 나왔다면 temp의 child로 node가 들어가면 된다.
		if (temp->key >= key) //temp의 key가 key보다 크거나 같다면 temp의 left가 node
		{
			temp->left = node;
			node->left = NULL;
			node->right = NULL;
		}
		else //아니라면 temp의 right가 node
		{
			temp->right = node;
		}
	}
	return 0;
}

int deleteLeafNode(Node* head, int key)
{
	return 0;
}

Node* searchRecursive(Node* ptr, int key)
{
	return NULL;
}

Node* searchIterative(Node* head, int key)
{
	return NULL;
}

int freeBST(Node* head)
{
	//free가 호출되는 경우 트리가 비지않았을 때 뿐이다
	Node* p = head->left; //p는 첫 번째 
	Node* next;
	return 0;
}





