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
void freeTree(Node* head);

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
		printf("[%d]   ",ptr->key); //ptr의 key 프린트
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr) //VLR식으로 출력
{
	if (ptr != NULL) //ptr이 NULL이 아니라면
	{
		printf("[%d]   ", ptr->key); //ptr의 key 프린트
		preorderTraversal(ptr->left); //순환 호출을 통해서 ptr이 왼쪽으로 가면서 왼쪽 자식들 프린트
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr) //LRV식으로 출력
{
	if (ptr != NULL) //ptr이 NULL이 아니라면
	{
		postorderTraversal(ptr->left); //순환 호출을 통해서 ptr이 가장 왼쪽 자식을 가리키게 하고
		postorderTraversal(ptr->right);
		printf("[%d]   ", ptr->key); //ptr의 key 프린트
	}
}

int insert(Node* head, int key)
{
	Node* node = (Node*)malloc(sizeof(Node));
	Node* temp;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	if (head->left == NULL) //비어있는 트리라면
		head->left = node;
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
	Node* temp,* pre;
	if (head->left == NULL) //트리가 이미 비어있다면 
		printf("tree is empty\n");
	else //아니라면
	{
		pre = head;
		temp = head->left; //temp는 트리의 첫 번째 노드를 가리킴
		while (temp!=NULL)
		{
			if (temp->key == key) //temp의 key가 찾는 key와 같고
			{
				if (temp->left == NULL && temp->right == NULL)//temp가 leaf 노드이고
				{
					if (pre->left == temp) // pre의 left child가 temp 라면 pre의 left를 NULL로 만듬
						pre->left = NULL; 
					else //pre의 right child 가 temp 라면 pre의 right를 NULL로 만듬
						pre->right = NULL;
						free(temp); //삭제
						return 0; //종료
				}
				else //leaf 노드가 아니라면
				{
					printf("the node [%d] is not a leaf\n", temp->key);
					return 0;
				}
			}
			else if (temp->key >= key) //temp의 key가 찾는 key보다 크거나 같다면 tmep는 왼쪽 자식을 가리키고 pre는 temp의 부모를 가리킴
			{
				pre = temp;
				temp = temp->left;
			}
			else//아니라면 temp는 오른쪽 자식을 가리키고 pre는 temp의 부모를 가리킴
			{
				pre = temp;
				temp = temp->right;
			}
		}
		//반복문을 나왔으므로 key는 트리에 없다
		printf("node [%d] is not in tree\n",key);
	}
	return 0;
}

Node* searchRecursive(Node* ptr, int key)
{
	if(ptr == NULL)
		return NULL;
	if (ptr->key == key)
		return ptr;
	else if (ptr->key > key)
		return searchRecursive(ptr->left, key);
	else
		return searchRecursive(ptr->right, key);
}

Node* searchIterative(Node* head, int key)
{
	Node* temp = head->left;
	while (temp != NULL)
	{
		if (temp->key == key)//temp의 key와 찾는 key가 같다면 temp가 가리키는 주소 리턴
			return temp;
		else if (temp->key > key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	//반복문을 나왔다는 것은 key가 트리에 없다는 것이다
	return NULL;
}

int freeBST(Node* head) //inorder처럼 recursive 하게 동작
{
	if(!head->left) freeTree(head->left); //트리에 원소가 있다면 freeTree 함수를 호출하여 free
	free(head); //head도 free해준다
	return 0;
}

void freeTree(Node* head) //트리를 free해주는 방식을 recursive하게 구현하기 위해 새로운 함수 사용
{
	if (head == NULL)
		return;
	freeBST(head->left);
	freeBST(head->right);
	free(head);
}
