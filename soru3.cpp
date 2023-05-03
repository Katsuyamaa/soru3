#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node temp;
    struct Node* dummy = &temp;
    dummy->next = NULL;
    while (head1 && head2) {
        if (head1->data < head2->data) {
            dummy->next = head1;
            head1 = head1->next;
        }
        else {
            dummy->next = head2;
            head2 = head2->next;
        }
        dummy = dummy->next;
    }
    dummy->next = head1 ? head1 : head2;
    return temp.next;
}

int main() {
    struct Node n1 = { 1, NULL };
    struct Node n2 = { 3, NULL };
    struct Node n3 = { 5, NULL };
    n1.next = &n2;
    n2.next = &n3;

    struct Node m1 = { 2, NULL };
    struct Node m2 = { 4, NULL };
    struct Node m3 = { 6, NULL };
    m1.next = &m2;
    m2.next = &m3;

    struct Node* mergedList = mergeLists(&n1, &m1);
    while (mergedList) {
        printf("%d ", mergedList->data);
        mergedList = mergedList->next;
    }
}