#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

// 맨 앞에 노드 삽입 
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// 맨 앞의 노드를 삭제
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* reverse(ListNode* head) {
	ListNode* p, *q, *r;

	p=head;
	q=NULL;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->link;
		q->link=r;
	}
	return q;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	/*
	// ArrayListType를 정적으로 생성하고 ArrayListType를 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;
	init(&list);
	//insert(&list, 0, 10); // 구현되지 않은 insert_first 형태로 사용중
	insert_first(&list, 10);
	print_list(&list);// 0번째 위치에 10 추가
	//insert(&list, 0, 20);
	insert_first(&list, 20);
	print_list(&list);// 0번째 위치에 20 추가
	//insert(&list, 0, 30);
	insert_first(&list, 30);
	print_list(&list);// 0번째 위치에 30 추가
	insert_last(&list, 40);
	print_list(&list);// 맨 끝에 40 추가
	remove(&list, 0);
	print_list(&list);// 0번째 항목 삭제
	*/

	ListNode* head1=NULL;
	ListNode* head2=NULL;
	for(int i=4; i>=1; i--){
		head1=insert_first(head1, i*10);
	}
	print_list(head1);
	head2=reverse(head1);
	print_list(head2);


	return 0;
}