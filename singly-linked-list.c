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
        scanf(" %c", &command);

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
                insertLast(headnode, key);
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
        listNode *p = h->first; // 리스트를 움직이며 key값을 비교할 node포인터, 초기값 => 첫 노드
        
        listNode *node = (listNode*)malloc(sizeof(listNode));
        node->key = key; // 추가될 node key값 삽입
        node->link = NULL; //추가될 node link 초기화
        
        if (h->first==NULL)// 공백 노드에 삽입되는 경우
        {
                node->link = NULL; 
                h->first = node; // 헤드노드는 삽입될 node를 포인팅
                return 0;
        }

        while (key>=(p->key)) // 삽입될 node의 key값이 더크면
        {       
             if (p->link == NULL)
             {        
                     break;
             }
                
             if (key>=(p->link->key))
                {
                        p = p->link;
                        
                }
                else{
                        break;
                }
        }


        if(p == h->first && key<=p->key){ //first위치에 삽입되는 경우
                node->link = p;
                h->first = node;
        }
        else if (p->link == NULL) // last위치에 삽입되는 경우
        {
                node->link = NULL;
                p->link = node;
        }
        else{ //중간에 삽입되는 경우
                node->link = p->link;
                p->link = node;
        }
       

        return 0;
}

int insertLast(headNode* h, int key){
        
        listNode* node = (listNode*)malloc(sizeof(listNode)); // node 1개 추가
        node->key = key; // 삽입될 node의 key값을 채워준다.
        node->link = NULL;

        listNode* p = h->first; // p가 첫 node를 가리킨다.
        while (p->link != NULL) // p가 NULL일때까지(마지막 node)
        {
                p = p->link; // p를 계속 다음 node를 가리키게 함
        }
        
        p->link = node; // 기존의 마지막 node의 링크가 삽입될 node와 연결된다.

        return 0;
}

int deleteNode(headNode* h, int key){
        
        listNode* p = h->first;
        listNode* trail = NULL;

        while(p->key != key){
                trail = p;
                p = p->link;
        }

        if(trail){ 
                trail->link = p->link; //이전 노드를 p의 다음 노드에 연결
        } // first가 아닌 노드를 삭제하는 경우

        else{
                h->first = p->link;
        } //first를 삭제하는 경우

        free(p); // 노드 삭제

        return 0;
}

int deleteFirst(headNode* h){
        listNode* prev = h->first; // 첫 노드를 가리키는 노드 포인터
        h->first = prev->link; // first를 다음 노드로 변경
        free(prev); //기존 first 할당 해제
        return 0;
}

int deleteLast(headNode* h) {
        listNode* p = h->first;
        listNode* trail = h->first;

        while(p->link != NULL){
                trail = p;
                p = p->link;
        }

        free(p); // last 노드 할당 해제(delete)

        if (trail == h->first) // 노드가 1개였던 경우
        {        
                h->first = NULL; // 빈 리스트이므로 헤드는 NULL
        }
        else{       
                trail->link = NULL; //해제된 노드의 이전 노드가 last가 되므로, 이전 노드의 link에 NULL대입
        }
        
        

	return 0; 
}

int invertList(headNode* h) {

        listNode* p = h->first;
        listNode* tail = NULL;
        listNode* front = p->link;

        if (p->link == NULL) //1개짜리 연결리스트
        {
                return 0;
        }

        while (p->link != NULL) //따라가는 노드 포인터가 0이 될때까지
        {
              p->link = tail;
              tail = p;
              p = front;
              front = front->link;
        }

        p->link = tail;
        h->first = p;

        
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
