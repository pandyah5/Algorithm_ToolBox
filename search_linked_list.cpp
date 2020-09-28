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


int find_elem(linkedList* head, int target){
	int count = 0;
	linkedList* search = head;
	while(search != NULL){
		if (search->value == target){
			return count;
		}
		else{
			count++;
			search = search->next;
		}
	}
	return -1;
}

int main(){
	linkedList llist;
	llist.value = 2;
	llist.next = create_node(4);
	llist.next->next = create_node(5);
	llist.next->next->next = create_node(7);
	llist.next->next->next->next = create_node(17);
	llist.next->next->next->next->next = NULL;
	std::cout << "Index: " << find_elem(&llist, 2) << '\n';
	std::cout << "Index: " << find_elem(&llist, 5) << '\n';
	std::cout << "Index: " << find_elem(&llist, 9) << '\n';
	std::cout << "Index: " << find_elem(&llist, 17) << '\n';
	return 0;
}
