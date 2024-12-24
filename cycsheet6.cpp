#include <stdio.h>
#define SIZE 3
int queue[SIZE], front = -1, rear = -1;
void insert(int item);
int deletes();
void display();
int main() {
 int choice = 1, value;
 while (choice) {
 printf("\nQueue Operations:\n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Display\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the value to insert: ");
 scanf("%d", &value);
 insert(value);
 break;
 case 2:
 value = deletes();
 if (value != -1) {
 printf("Deleted value is %d\n", value);
 }
 break;
 case 3:
 display();
 break;
 default:
 printf("Invalid choice.\n");
 }
 printf("\nDo you want to continue? (1 for Yes / 0 for No): ");
 scanf("%d", &choice);
 }
 return 0;
}
void insert(int item) {
 if (rear >= SIZE - 1) {
 	printf("Queue is full you cannot insert item %d.\n", item);
 } else {
 if (front == -1) { 
 front = 0;
 }
 queue[++rear] = item; // Insert item at the rear
 printf("Inserted item %d in queue.\n", item);
 }
}
int deletes() {
 if (front == -1 || front > rear) { // Queue is empty
 printf("Queue is empty you cannot delete item.\n");
 return -1;
 } else {
 int item = queue[front];
 front++; 
 if (front > rear) { 
 front = rear = -1;
 }
 return item;
 }
}
void display() {
 if (front == -1 || front > rear) {
 }
 printf("Queue is empty\n");
 } 
 else {
 printf("Queue elements are: ");
 for (int i = front; i <= rear; i++) { r
 printf("%d ", queue[i]);
 }
 printf("\n")
}
}
