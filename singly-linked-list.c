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
        listNode* p = h->first; // p??? ??? ????????? ???????????? ???

        listNode* prev = NULL; // ??? ???????????????(??????) ??????
        while (p != NULL)
        {
                prev = p; // prev??? p??? ?????? ????????? ???????????? ???
                p = p->link; // p??? ?????? ????????? ???????????????
                free(prev); // prev??? ???????????? ????????? ????????????
        }

        free(h);
        return 0;
}

int insertFirst(headNode* h, int key){
        listNode* node = (listNode*)malloc(sizeof(listNode));
        node->key = key;

        node->link = h->first; //????????? node??? first?????????, ????????? node??? ????????? ????????? first node??? ???????????????.
        h->first = node; // ????????? ????????? ????????? ???????????????(new first node)

        return 0;
}

int insertNode(headNode* h, int key){
        listNode *p = h->first; // ???????????? ???????????? key?????? ????????? node?????????, ????????? => ??? ??????
        
        listNode *node = (listNode*)malloc(sizeof(listNode));
        node->key = key; // ????????? node key??? ??????
        node->link = NULL; //????????? node link ?????????
        
        if (h->first==NULL)// ?????? ????????? ???????????? ??????
        {
                node->link = NULL; 
                h->first = node; // ??????????????? ????????? node??? ?????????
                return 0;
        }

        while (key>=(p->key)) // ????????? node??? key?????? ?????????
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


        if(p == h->first && key<=p->key){ //first????????? ???????????? ??????
                node->link = p;
                h->first = node;
        }
        else if (p->link == NULL) // last????????? ???????????? ??????
        {
                node->link = NULL;
                p->link = node;
        }
        else{ //????????? ???????????? ??????
                node->link = p->link;
                p->link = node;
        }
       

        return 0;
}

int insertLast(headNode* h, int key){
        
        listNode* node = (listNode*)malloc(sizeof(listNode));
        listNode* p = h->first;

        node->key = key;
        node->link = NULL;

        if(p == NULL){ //?????? ?????????
                h->first = node;
        }

        else{
                 while (p->link != NULL)
                {
                        p = p->link;
                }
                p->link = node;
        }

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
                trail->link = p->link; //?????? ????????? p??? ?????? ????????? ??????
        } // first??? ?????? ????????? ???????????? ??????

        else{
                h->first = p->link;
        } //first??? ???????????? ??????

        free(p); // ?????? ??????

        return 0;
}

int deleteFirst(headNode* h){
        listNode* prev = h->first; // ??? ????????? ???????????? ?????? ?????????
        h->first = prev->link; // first??? ?????? ????????? ??????
        free(prev); //?????? first ?????? ??????
        return 0;
}

int deleteLast(headNode* h) {
        listNode* p = h->first;
        listNode* trail = h->first;

        while(p->link != NULL){
                trail = p;
                p = p->link;
        }

        free(p); // last ?????? ?????? ??????(delete)

        if (p == h->first) // ????????? 1????????? ??????
        {        
                h->first = NULL; // ??? ?????????????????? ????????? NULL
        }
        else{       
                trail->link = NULL; //????????? ????????? ?????? ????????? last??? ?????????, ?????? ????????? link??? NULL??????
        }
        
        

	return 0; 
}

int invertList(headNode* h) {

        listNode* p = h->first;
        listNode* tail = NULL;
        listNode* front = p->link;

        if (p->link == NULL) //1????????? ???????????????
        {
                return 0;
        }

        while (p->link != NULL) //???????????? ?????? ???????????? 0??? ????????????
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
