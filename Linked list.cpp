#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a singly linked list node
struct Node {
    char data;
    struct Node* next;
};

// Function to push a character onto the linked list
void push(struct Node** head_ref, char data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%c -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to reverse a linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;
    struct Node* prev_slow_ptr = head;
    struct Node* mid_of_list = NULL;
    bool result = true;

    // Find the middle of the linked list
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    // Handle odd length lists
    if (fast_ptr != NULL) {
        mid_of_list = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    struct Node* second_half = slow_ptr;
    prev_slow_ptr->next = NULL;
    second_half = reverse(second_half);

    // Compare first and second halves of the linked list
    struct Node* first_half = head;
    while (first_half != NULL && second_half != NULL) {
        if (first_half->data != second_half->data) {
            result = false;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    // Restore the reversed second half
    second_half = reverse(second_half);

    // Restore the original linked list structure
    if (mid_of_list != NULL) {
        prev_slow_ptr->next = mid_of_list;
        mid_of_list->next = second_half;
    } else {
        prev_slow_ptr->next = second_half;
    }

    return result;
}

int main() {
    struct Node* head = NULL;
    char str[] = "racecar";

    for (int i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
    }

    printf("Linked List: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
