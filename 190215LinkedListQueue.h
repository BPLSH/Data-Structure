typedef struct tagLinkedQueue {
	struct tagNode* front;
	struct tagNode* rear;
	int size;
}LinkedQueue;

void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);
Node* LQ_CreateNode(char* data);
void LQ_DestroyNode(Node* Node);
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);
int LQ_IsEmpty(LinkedQueue* Queue);
#endif
