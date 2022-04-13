#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node* link;
} listNode;

typedef struct Head{
    struct Node* first;
}headNode;

headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main(){

    char command;
    int key;
    headNode* headnode = NULL;

    do
    {   
        printf("------------[2018068040]-------[Park Taehyun]-------------------\n");
        printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanff(" %c", &command);

        switch(command){
        case 'z': case 'Z':
                headnode = initialize(headnode);
                break;

        case 'p': case 'P':
                printList(headnode);
                break;

        case 'i': case 'I':
                printf("Your Key = ");
                scanf("%d", &key);
                insertNode(headnode, key);
                break;
        
        case 'd': case 'D':
                printf("Your Key = ");
                scanf("%d", &key);
                deleteNode(headnode, key);
                break;
        case 'n': case'N' :
                printf("Your Key = ");
                scanf("%d", &key);
                insertast(headnode, key);
                break;
        case 'e': case 'E':
                deleteLast(headnode);
                break;
        case 'f': case'F':
                printf("Your Key = ");
                scanf("%d", &key);
                insertFirst(headnode, key);
                break;
        case 't': case'T':
                deleteFirst(headnode);
                break;
        case 'r': case'R':
                invertList(headnode);
                break;
        case 'q': case'Q':
                freeList(headnode);
                break;
        default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;

        }
        

    } while (command != 'q' && command !='Q');
    


}

headNode* initialize(headNode* h){
        if(h != NULL){
                freeList(h);
        }

        headNode* temp = (headNode*)malloc(sizeof(headNode));
        temp->first = NULL;
        return temp;

}

int freeList(headNode* h){
        listNode* p = h->first; // p가 첫 노드를 가리키게 함

        listNode* prev = NULL; // 빈 노드포인터(링크) 생성
        while (p != NULL)
        {
                prev = p; // prev가 p와 같은 노드를 가리키게 함
                p = p->link; // p는 다음 노드를 가리키게함
                free(prev); // prev가 가리키는 노드를 할당해제
        }

        free(h);
        return 0;
}

int insertFirst(headNode* h, int key){
        listNode* node = (listNode*)malloc(sizeof(listNode));
        node->key = key;

        node->link = h->first; //삽입될 node가 first이므로, 삽입될 node의 링크는 기존의 first node를 포인팅한다.
        h->first = node; // 헤드가 삽입될 노드를 포인팅한다(new first node)

        return 0;
}

int insertNode(headNode* h, int key){
        listNode *p = h->first; // 리스트를 움직이며 key값을 비교할 node포인터
        listNode *trail = h->first; // p 한칸 뒤에서 따라가는 포인터(삽입용)
        
        listNode *node = (listNode*)malloc(sizeof(listNode));
        node->key = key;
        
        if(node->key < p->key){ // first앞에 삽입되는 경우
                node->link = h->first; // 삽입될 node의 link는 기존의 first노드를 가리킨다.
                h->first = node; // first는 삽입될 link이다.
        }
        else{   
                while(node->key < p->key){
                        p = p->link; // p는 다음 node를 가리킴
                        

                }

        }


        return 0;
}

int insertLast(headNode* h, int key){
        
        listNode* node = (listNode*)malloc(sizeof(listNode)); // node 1개 추가
        node->key = key; // 삽입될 node의 key값을 채워준다.

        listNode* p = h->first; // p가 첫 node를 가리킨다.
        while (p != NULL) // p가 NULL일때까지(마지막 node)
        {
                p = p->link; // p를 계속 다음 node를 가리키게 함
        }
        
        p->link = node; // 기존의 마지막 node의 링크가 삽입될 node와 연결된다.

        return 0;
}

int deleteFirst(headNode* h){

        return 0;
}

int deleteLast(headNode* h) {

	return 0; 
}

int invertList(headNode* h) {

	return 0;
}

void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}
