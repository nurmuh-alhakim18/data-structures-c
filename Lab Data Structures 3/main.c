#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//Nama 	: Dary Ramadhan Fajar
//NIM	: 2440075220

//create linklist
struct list {
	int isi;
	int age;
	char name[20];
	char address[100];

	struct list *next;
};

struct list *head = NULL;
struct list *tail = NULL;
int num = 0;
int i;
char nama[20];
char alamat[100];
int umur;

void ascsortAge();
void ascsortRegis();
void dscsortAge();
void dscsortRegis();
void display();
void sorting();
void menuExit();
void displayMenu();
void add();

//bikin 3 linked list (main())
int main(){

	printf("\t\t   Governance Library\n");
	printf("\t\t--------------------------\n");
	displayMenu();

	return 0;
}


void displayMenu(menu){
	printf("\n----- Registration Menu -----\n");
	printf("1. Add the data\n");
	printf("2. Show the data\n");
	printf("3. Exit\n");
	printf("----------------\n");
	printf("Choose your actions : ");
	scanf("%d", &menu);

	if (menu == 1){
		add();
	} if (menu == 2) {
		sorting();
	} if (menu == 3) {
		menuExit();
	}
};

void sorting(){
	printf("1. Ascending\n");
	printf("2. Descending\n");
	int num;
		printf("\nInput number :"); scanf("%d", &num);
		if (num == 1){
			printf("1. Age\n");
			printf("2. Registration Number\n");
			int num_asc;
			printf("\nInput number :"); scanf("%d", &num_asc);
			if (num_asc == 1){
				printf("Ascending by Age\n");
				printf("----------------\n\n");
				printf("Original List :\n");
				display();
				//sorting function
				ascsortAge();
				printf("====================\n");
				printf("\n--- Sorted List ---\n");
				display();
				printf("====================\n");

				return displayMenu();
			}
			if (num_asc == 2){
				printf("Ascending by Registration Number\n");
				printf("--------------------------------\n\n");
				printf("Original List :\n");
				display();
				//sorting function
				ascsortRegis();
				printf("====================\n");
				printf("\n--- Sorted List ---\n");
				display();
				printf("====================\n");

				return displayMenu();
			}
		}
		if (num == 2){
			printf("1. Age\n");
			printf("2. Registration Number\n");
			int num_desc;
			printf("\nInput number :"); scanf("%d", &num_desc);
			if (num_desc == 1){
				printf("Descending by Age\n");
				printf("----------------\n\n");
				printf("Original List :\n");
				display();
				//sorting function
				dscsortAge();
				printf("====================\n");
				printf("\n--- Sorted List ---\n");
				display();
				printf("====================\n");

				return displayMenu();
			}
			if (num_desc == 2){
				printf("Descending by Registration Number\n");
				printf("--------------------------------\n\n");
				printf("Original List :\n");
				display();
				//sorting function
				dscsortRegis();
				printf("====================\n");
				printf("\n--- Sorted List ---\n");
				display();
				printf("====================\n");

				return displayMenu();
			}
		}
}

void add(int isi){
	num ++;

	struct list *newNode = (struct list*)malloc(sizeof(struct list));
	printf("\nTotal registration in this day : %d\n", num);
	printf("----------------------------------------------\n");
	printf("Input Name\t: "); scanf(" %[^\n]", nama); getchar();
	printf("Input Address\t: "); scanf(" %[^\n]", alamat); getchar();
	printf("Input Age\t: "); scanf(" %d", &umur); getchar();
	printf("----------------------------------------------\n");

	newNode->isi = num;
	newNode->age = umur;
	strcpy(newNode->name, nama);
	strcpy(newNode->address, alamat);

	if(head == NULL){
		head = newNode;
		tail = newNode;
		newNode->next = head;
	} else {
		tail->next = newNode;
		tail = newNode;
		tail->next = head;
	}

	return displayMenu();
}

void display(){
	printf("\nTotal Registration Number %d\n", num);
	printf("___________________________________\n");
    struct list *current = head;
    if(head == NULL){
        printf("List is empty");
    }
    else{
    do{
     //Prints each node by incrementing pointer.

    printf("\nName\t:%s\n", current->name);

    printf("Address\t:%s\n", current->address);
    printf("Age\t:%d\n",current->age);
    printf("Registration Number\t:%d\n", current->isi);
    printf("___________________________________\n");
    current = current->next;
    }
    while(current != head);
    printf("\n");
    }
}

void ascsortAge() {
//Current will point to head

    struct list *current = head, *index = NULL;
    int temp;
	char arr[100];

    if(head == NULL) {
            printf("List is empty");
            }
    else {
            do{
    //Index will point to node next to current
    index = current->next;
    while(index != head) {
//If current node is greater than index data, swaps the data
    if(current->age > index->age) {

            temp =current->age;
            current->age= index->age; // swap umur
            index->age = temp;

            temp = current->isi;
            current->isi=index->isi;
            index->isi = temp;

          	strcpy(arr,current->name);
          	strcpy(current->name, index->name);
          	strcpy(index->name,arr);

          	strcpy(arr, current->address);
          	strcpy(current->address, index->address);
          	strcpy(index->address,arr);

		   }
        index= index->next;
        }
        current =current->next;
        }
    while(current->next != head );
    }
}

void ascsortRegis() {
//Current will point to head
    struct list *current = head, *index = NULL;
    int temp;
    char arr[100];
    if(head == NULL) {
            printf("List is empty");
            }
    else {
            do{
    //Index will point to node next to current
    index = current->next;

    while(index != head) {
//If current node is greater than index data, swaps the data
    if(current->isi > index->isi) {
            temp =current->isi;
            current->isi= index->isi;
            index->isi = temp;

            temp= current->age;
            current->age= index->age;
            index->age= temp;

            strcpy(arr, current->name);
            strcpy(current->name,index->name);
            strcpy(index->name,arr);

            strcpy(arr, current->address);
            strcpy(current->address, index->address);
            strcpy(index->address,arr);

            }
        index= index->next;
        }
        current =current->next;
        }
    while(current->next != head);
    }
}

void dscsortAge() {
//Current will point to head

    struct list *current = head, *index = NULL;

    int temp;
	char arr[100];


    if(head == NULL) {
            printf("List is empty");
            }
    else {
            do{
    //Index will point to node next to current
    index = current->next;
//	cc[100]= current->next;
    while(index != head) {
//If current node is greater than index data, swaps the data
    if(current->age < index->age) {


            temp = index->age;
            index->age= current->age;
            current->age = temp;


		    temp = index->isi;
		    index->isi = current->isi;
		    current->isi = temp;

          	strcpy(arr, index->name);
          	strcpy(index->name,current->name);
          	strcpy(current->name,arr);

          	strcpy(arr, index->address);
          	strcpy(index->address, current->address);
          	strcpy(current->address,arr);


		   }
        index= index->next;
      //  cc[100]=cc[100]->next;
        }
        current =current->next;
       // current=current->next;
        }
    while(current->next != head );
    }
}

void dscsortRegis() {
//Current will point to head
    struct list *current = head, *index = NULL;
    int temp;
    char arr[100];
    if(head == NULL) {
            printf("List is empty");
            }
    else {
            do{
    //Index will point to node next to current
    index = current->next;

    while(index != head) {
//If current node is greater than index data, swaps the data
    if(current->isi < index->isi) {

    		temp=index->isi;
    		index->isi = current->isi;
    		current->isi = temp;

    		temp =  index->age;
    		index->age =  current->age;
    		current->age =  temp;

    		strcpy(arr,index->name);
    		strcpy(index->name,current->name);
    		strcpy(current->name,arr);

    		strcpy(arr, index->address);
    		strcpy(index->address, current->address);
    		strcpy(current->address,arr);

            }
        index= index->next;
        }
        current =current->next;
        }
    while(current->next != head);
    }
}

void menuExit(){
	printf("=====================\n");
	printf("Thanks for using Governance Library Program!\n");

}
