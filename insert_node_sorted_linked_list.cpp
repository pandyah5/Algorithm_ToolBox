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

void insert_node(linkedList* head, int num){
	if (head == NULL){
		return;
	}
	else if (head->value > num){
		int temp = head->value;
		linkedList* temp1 = head->next;
		head->value = num;
		head->next = create_node(temp);
		head->next->next = temp1;
		return;
	}
	if (head->next != NULL){
		if ((head->value == num) || (head->value < num && head->next->value > num)){
			linkedList* temp = head->next;
			head->next = create_node(num);
			head->next->next = temp;
			return;
		}
		else{
			insert_node(head->next, num);
		}
	}
	else{
		head->next = create_node(num);
		head->next->next = NULL;
		return;
	}
}

int main(){
	linkedList llist;
	llist.value = 2;
	llist.next = create_node(4);
	llist.next->next = create_node(5);
	llist.next->next->next = create_node(7);
	llist.next->next->next->next = NULL;
	print_linked_list(&llist);
	insert_node(&llist, 6);
	print_linked_list(&llist);
	insert_node(&llist, 9);
	print_linked_list(&llist);
	insert_node(&llist, 1);
	print_linked_list(&llist);
	insert_node(&llist, 2);
	print_linked_list(&llist);
	insert_node(&llist, -2);
	print_linked_list(&llist);
	insert_node(&llist, 12);
	print_linked_list(&llist);
	return 0;
}
