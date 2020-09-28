#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct LinkedList{
	int value;
	struct LinkedList* next;
}linkedList;

linkedList* create_node(int value){
	linkedList* node = (linkedList*)malloc(sizeof (linkedList));
	if (node != NULL){
		node->value = value;
		node->next = NULL;
		return node;
	}
	else{
		return NULL;
	}
}

void add_at_end(linkedList* head, int num){
	if (head == NULL){
		return;
	}
	if (head->next == NULL){
		head->next = create_node(num);
		return;
	}
	else{
		add_at_end(head->next, num);
	}
}

void add_at_start(linkedList* head, int num){
	if (head == NULL){
		head = create_node(num);
		return;
	}
	else{
		linkedList* temp = head->next;
		int temp1 = head->value;
		head->value = num;
		head->next = create_node(temp1);
		head->next->next = temp;
		return;
	}
}

void print_linked_list(linkedList* head){
	if (head != NULL){
		std::cout << head->value << ' ';
		if (head->next != NULL){
			//std::cout << "Blah!Blah!Blah!" << '\n';
			print_linked_list(head->next);
		}
		else{
			std::cout << '\n';
			return;
		}
	}
}

int main(){
	linkedList llist;
	llist.value = 2;
	llist.next = create_node(4);
	llist.next->next = create_node(5);
	llist.next->next->next = create_node(7);
	llist.next->next->next->next = create_node(17);
	add_at_end(&llist, 21);
	add_at_end(&llist, 23);
	add_at_end(&llist, 14);
	add_at_start(&llist, 1);
	add_at_start(&llist, 0);
	print_linked_list(&llist);
	return 0;
}
