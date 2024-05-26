#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

// Linked List example.
/*
Linked list of students.
A) Adds a new student
B) Searches for the student and if that student exists, the program returns its index.
C) Sorts the list according to the student number
D) Prints the List
*/

struct student{
	long long int stdNo;
	char name[20];
	char surname[20];
	struct student* next;
};

typedef struct student Student;
Student* Head = NULL;

void Add() {
	long long int number;
	char Name[20], Surname[20];
	if (Head == NULL) {
		Head = (Student*)malloc(sizeof(Student));
		printf("Enter the student's number: "); scanf("%lld", &number);
		printf("\nEnter the student's name: "); scanf("%s", Name);
		printf("\nEnter the student's surname: "); scanf("%s", Surname);
		Head->stdNo = number;
		strcpy(Head->name, Name);
		strcpy(Head->surname, Surname);
		Head->next = NULL;
	} else {
		Student* temp = Head;
		while (temp->next != NULL)
			temp = temp->next;
		Student* newStudent = (Student*)malloc(sizeof(Student));
		printf("Enter the student's number: "); scanf("%lld", &number);
		printf("\nEnter the student's name: "); scanf("%s", Name);
		printf("\nEnter the student's surname: "); scanf("%s", Surname);
		newStudent->stdNo = number;
		strcpy(newStudent->name, Name);
		strcpy(newStudent->surname, Surname);
		newStudent->next = NULL;
		temp->next = newStudent;
	}
}

int Search(long long int x) {
	Student* temp = Head;
	int cnt = 0;
	while (temp != NULL) {
		if (temp->stdNo == x)
			return cnt;
		temp = temp->next;
		cnt++;
	}
	return -1; // Student not found
}

void Sort() {
	if (Head == NULL || Head->next == NULL) {
		return;
	}

	Student* sorted = NULL;
	Student* current = Head;

	while (current != NULL) {
		Student* next = current->next;

		if (sorted == NULL || sorted->stdNo >= current->stdNo) {
			current->next = sorted;
			sorted = current;
		} else {
			Student* temp = sorted;
			while (temp->next != NULL && temp->next->stdNo < current->stdNo) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = next;
	}

	Head = sorted;
}

void Print() {
	printf("\n\n");
	if (Head == NULL) {
		printf("Your list is empty. \n");
	} else {
		Student* temp = Head;
		while (temp != NULL) {
			printf("The student number: %lld ", temp->stdNo);
			printf("The student's name: %s ", temp->name);
			printf("The student's surname: %s \n", temp->surname);
			temp = temp->next;
		}
	}
}

int main() {
	int option;
	long long int No;

	while (1) {
		printf("1 -> Adds a new student to the list. \n");
		printf("2 -> Searches for the student; if the student exists, then the program returns the index. \n");
		printf("3 -> Sorts the list according to the student number. \n");
		printf("4 -> Prints the list. \n");
		printf("5 -> Cleans the screen for you. \n");
		printf("6 -> Exits the program. \n");
		printf("Enter your option: \n"); scanf("%d", &option);
		switch (option) {
			case 1:
				printf("You are now adding a new student to the list... \n");
				Add();
				break;
			case 2:
				printf("You are searching for the student by his/her stdNo... \n");
				printf("Enter the student number: \n"); scanf("%lld", &No);
				int index = Search(No);
				if (index != -1) {
					printf("Student found at index: %d\n", index);
				} else {
					printf("Student not found.\n");
				}
				break;
			case 3:
				printf("You are sorting the list according to the student number...\n");
				Sort();
				break;
			case 4:
				printf("You are printing the list...\n\n");
				Print();
				break;
			case 5:
				system("cls");
				break;
			case 6:
				printf("You are exiting the program. \n");
				exit(0);
				break;
			default:
				printf("There isn't an option such as that... \n");
		}
	}

	getch();
	return 0;
}

