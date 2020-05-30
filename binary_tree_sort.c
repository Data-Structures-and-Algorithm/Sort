#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

//BST Related

typedef struct Node {
	
	struct Node *lchild;
	int data;
	struct Node *rchild;

} Node_t;


typedef enum {
	QUEUE_STATUS_SUCCESS = 0,
	QUEUE_STATUS_FULL    = 1,
	QUEUE_STATUS_EMPTY   = 2,
} Queue_Status_t;



typedef enum {
	STACK_STATUS_SUCCESS = 0,
	STACK_STATUS_FULL    = 1,
	STACK_STATUS_EMPTY   = 2,
} Stack_Status_t;




Node_t *get_node(int x);
void display(void);
void preorder(Node_t *p);
void inorder(Node_t *p);
void postorder(Node_t *p);
void levelorder(Node_t *p);
int height(Node_t *p);
Node_t *insert(Node_t *root, int info);
Node_t *search(Node_t *p, int info);
Node_t *min(Node_t *p);
Node_t *max(Node_t *p);
Node_t *delete(Node_t *root, int info);



//Stack Related

#define MAX 128

Node_t *Stack[MAX];

int top;

void Stack_Init(void);
int isEmpty(void);
int isFull(void);
int size(void);
Node_t *peek(void);
void push(Node_t *node);
Node_t *pop(void);



//Queue related

Node_t *queue_nodes[MAX];

void Queue_Init(void);
bool Queue_IsEmpty(void);
bool Queue_IsFull(void);
uint32_t Queue_Size(void);
Queue_Status_t EnQueue(Node_t *node);
Queue_Status_t DeQueue(Node_t *node);


int front;
int rear;


int main(void)
{
	Node_t *root = NULL;
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);
	inorder(root);
	
	
	Node_t *temp = search(root, 6);
	
	printf("\n");
	
	temp == NULL ? printf("NULL...\n") : printf("Value = %d...\n", temp->data);

	
	return 0;
}


//BST Implementations


Node_t *get_node(int x)
{
	Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));

	if (new_node == NULL) {
		printf("Memory Allocation Failure...\n");
		return NULL;
	}

	new_node->lchild = NULL;
	new_node->data   = x;
	new_node->rchild = NULL;

	return new_node;
}


void preorder(Node_t *p)
{
	if (p != NULL) {
		printf("%d --> ", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(Node_t *p)
{
	if (p != NULL) {
		inorder(p->lchild);
		printf("%d --> ", p->data);
		inorder(p->rchild);
	}
}

void postorder(Node_t *p)
{
	if (p != NULL) {
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d --> ", p->data);
	}
}

void levelorder(Node_t *p)
{
	if (p == NULL) {
		printf("Empty Tree...\n");
		return;
	}


	Node_t *visiting_node;

	EnQueue(p);
	
	while (!Queue_IsEmpty()) {
		
		DeQueue(visiting_node);
		printf("%d -->", visiting_node->data);
		
		if (visiting_node->lchild != NULL) {
			EnQueue(visiting_node->lchild);
		}
		
		if (visiting_node->rchild != NULL) {
			EnQueue(visiting_node->rchild);
		}
	}

	printf("\n");


}

int height(Node_t *p)
{
	if (p == NULL) {
		return 0;
	}

	int l_height = height(p->lchild); 
	int r_height = height(p->rchild); 

	return 1 + (l_height > r_height) ? l_height : r_height;
}

Node_t *search(Node_t *p, int info)
{

	if (p == NULL) 
		return NULL;
	
	if (info > p->data)
		return search(p->rchild, info);
	if (info < p->data)
		return search(p->lchild, info);

	return p;
}

Node_t *delete(Node_t *root, int info)
{
}

Node_t *min(Node_t *p)
{
	if (p == NULL) {
		return NULL;
	}
	Node_t *temp = p;

	while (temp->lchild) {
		temp = temp->lchild;
	}

	return temp;
}

Node_t *max(Node_t *p)
{
	if (p == NULL) {
		return NULL;
	}
	Node_t *temp = p;

	while (temp->rchild) {
		temp = temp->rchild;
	}

	return temp;
}

Node_t *insert(Node_t *root, int info)
{
	Node_t *new_node =get_node(info);

	Node_t *temp = root;

	Node_t *parent = NULL;

	while (temp) {
		parent = temp;
		if (info < temp->data) {
			temp = temp->lchild;
		} else if (info > temp->data) {
			temp = temp->rchild;
		} else {
			printf("Duplicate Entry Error...\n");
		}
	}

	if (parent == NULL) {
		root = new_node;
		return root;
	}

	if (info < parent->data) {
		parent->lchild = new_node;
	} else {
		parent->rchild = new_node;
	}

	return root;
}





//Stack Implementations


void Stack_Init(void)
{
}


int isEmpty(void)
{
}


int isFull(void)
{
}


int size(void)
{
}


Node_t *peek(void)
{
}


void push(Node_t *node)
{
}


Node_t *pop(void)
{
}


void display(void)
{
}






//Queue Implementations


void Queue_Init(void)
{
	front = rear = 0;
}



bool Queue_IsEmpty(void)
{
	return front == rear;
}



bool Queue_IsFull(void)
{
	return (((rear + 1) % MAX) == front);
}



Queue_Status_t EnQueue(Node_t *node)
{
	if (Queue_IsFull) {
		printf("Queue Full Error...\n");
		return QUEUE_STATUS_FULL;
	}

	queue_nodes[rear] = node;
	
	rear = (rear + 1) % MAX;

	return QUEUE_STATUS_SUCCESS;
}



Queue_Status_t DeQueue(Node_t *node)
{
	if (Queue_IsEmpty) {
		printf("Queue Emty Error...\n");
		return QUEUE_STATUS_EMPTY;
	}
	
	node = queue_nodes[front];

	front = (front + 1) % MAX;

	return QUEUE_STATUS_SUCCESS;

}



uint32_t Queue_Size(void)
{
	return ((MAX + (rear - front)) % MAX);
}







