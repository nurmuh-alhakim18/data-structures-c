#include <stdio.h>
#include <stdlib.h>

struct doubleList{
    char name[25];
    char destination[25];
    struct doubleList *next;
    struct doubleList *before;
}*head = NULL, *tail = NULL, *curr = NULL;

int ctr1 = 0, ctr2 = 0, ctr3 = 0;
char destination[25], name[25];

int main()
{
    table();
    display();
    return 0;
}

void display(menu){
    printf("1. Add a polling data\n");
    printf("2. Delete a polling data\n");
    printf("3. Show the polling result\n");
    printf("4. Exit\n\n");
    printf(">> Input your choice : ");
    scanf("%d",&menu);
    if(menu == 1){
        add();
    }
    else if(menu == 2){
        deleteData();
    }
    else if(menu == 3){
        show();
    }
    else if(menu == 4){
        exit(0);
    }
}

void add(){
    int choice, no;
    printf("\n     1- add before the first data\n");
    printf("     2- add after the last data\n");
    printf("   Input your choice [1...2]: ");
    scanf("%d",&choice);
    puts("");
    if(choice == 1){
        getchar();
        printf("   Input family members name: ");
        scanf("%[^\n]",&name);
        puts("");
        printf("     1- Singapore       2- South Korea       3- Australia\n");
        printf("   Select the tourism destination [1..3]: ");
        scanf("%d",&no);
        while(no == 1){
            strcpy(destination,"Singapore");
            PushHead(name,destination);
            printf("\n   --- successfully add: %s's Data ---\n\n",name);
            ctr1++;
            break;
        }
        while(no == 2){
            strcpy(destination,"South Korea");
            PushHead(name,destination);
            printf("\n   --- successfully add: %s's Data ---\n\n",name);
            ctr2++;
            break;
        }
        while(no == 3){
            strcpy(destination,"Australia");
            PushHead(name,destination);
            printf("\n   --- successfully add: %s's Data ---\n\n",name);
            ctr3++;
            break;
        }
        if(no < 1 || no > 3){
            printf("\n   --- Your Destination Not Found ---\n");
            return add();
        }
    }
    else if(choice == 2){
        getchar();
        printf("   Input family members name: ");
        scanf("%[^\n]",&name);
        puts("");
        printf("     1- Singapore       2- South Korea       3- Australia\n");
        printf("   Select the tourism destination [1..3]: ");
        scanf("%d",&no);
        while(no == 1){
            strcpy(destination,"Singapore");
            PushTail(name,destination);
            printf("\n   --- successfully add: %s's Data ---\n\n",name);
            ctr1++;
            break;
        }
        while(no == 2){
            strcpy(destination,"South Korea");
            PushTail(name,destination);
            printf("\n   --- successfully add: %s's Data ---\n\n",name);
            ctr2++;
            break;
        }
        while(no == 3){
            strcpy(destination,"Australia");
            PushTail(name,destination);
            printf("\n   --- successfully add: %s's Data ---\n\n",name);
            ctr3++;
            break;
        }
        if(no < 1 || no > 3){
            printf("\n   --- Your Destination Not Found ---\n");
            return add();
        }
    }
    else{
        printf("   --- Your Choice Not Found ---\n");
        return add();
    }
    return main();
}


void deleteData(){
    int choiceDel;
    printf("\n     1- Remove the first data\n");
    printf("     2- Remove the last data\n");
    printf("   Input your choice [1...2]: ");
    scanf("%d",&choiceDel);
    if(choiceDel < 1 || choiceDel > 2){
        printf("\n   --- Your Choice Not Found ---\n\n");
        return deleteData();
    }
    else{
        if (head == NULL){
            printf("   --- no data can be deleted ---\n\n");
        }
        else{
            if(choiceDel == 1){
                PopHead();
                printf("\n   --- Successfull Delete: %s's Data ---\n\n",name);
            }
            else if(choiceDel == 2){
                PopTail();
                printf("\n   --- Successfull Delete: %s's Data ---\n\n",name);
            }
        }
        return main();
    }
}

void show(){
    if(head == NULL){
        printf("\n   --- no data, no polling result ---\n\n");
    }
    else{
        printf("\n   The polling result so far are\n");
        printf("   Singapore = %d,  South Korea = %d,  Australia = %d\n\n",ctr1,ctr2,ctr3);
        printf("   Based on the polling\n");
        if(ctr1>ctr2 && ctr1>ctr3){
            strcpy(destination,"SINGAPORE");
            printf("   on the next holiday our family will go to %s\n\n",destination);
        }
        else if(ctr2>ctr1 && ctr2>ctr3){
            strcpy(destination,"SOUTH KOREA");
            printf("   on the next holiday our family will go to %s\n\n",destination);
        }
        else if(ctr3>ctr1 && ctr3>ctr2){
            strcpy(destination,"AUSTRALIA");
            printf("   on the next holiday our family will go to %s\n\n",destination);
        }
        else{
            printf("   insert or remove polling data.\n\n");
        }
    }
    return main();
}

void table(){
    curr = head;
    int ctr = 0;
    if(head == NULL){
        printf("\t\t--- Determining a tourist destination ---\n\n");
        printf("---------------------------------------------------------------\n");
        printf(": No. :  Family members name  :   Tourist destination         :\n");
        printf("---------------------------------------------------------------\n");
        printf(":                                                             :\n");
        printf(":                   --- no data here ---                      :\n");
        printf(":                                                             :\n");
        printf("---------------------------------------------------------------\n\n");
    }
    else{
        printf("\t\t--- Determining a tourist destination ---\n\n");
        printf("---------------------------------------------------------------\n");
        printf(": No. :  Family members name  :   Tourist destination         :\n");
        printf("---------------------------------------------------------------");
        while(curr != NULL){
            ctr++;
            printf("\n: %d.  :  %-21s:   %-28s:",ctr,curr->name,curr->destination);
            if(curr==head){
				printf(" <-- head ");
			}
			if(curr==tail){
				printf(" <-- tail\n");
			}
            curr = curr->next;
        }
        printf("---------------------------------------------------------------\n\n");
    }
}

void PushHead(const char* name,const char* destination){
	curr = (struct doubleList*)malloc(sizeof(struct doubleList));
	curr->next = NULL;
	curr->before = NULL;
	strcpy(curr->name,name);
	strcpy(curr->destination,destination);
	if(head == NULL){
		head = tail = curr;
	}
	else{
		curr->next = head;
		head->before = curr;
		head = curr;
	}
}

void PushTail(const char* name,const char* destination){
	curr = (struct doubleList*)malloc(sizeof(struct doubleList));
	curr->next = NULL;
	curr->before = NULL;
	strcpy(curr->name,name);
	strcpy(curr->destination,destination);
	if(head == NULL){
		head = tail = curr;
	}
	else{
		tail->next = curr;
		curr->before = tail;
		tail = curr;
	}
}

void PopHead(){
	curr = head;
	if(head != NULL){
		if(head == tail){
			free(curr);
			head = tail = curr = NULL;
		}
		else{
			head = head->next;
			free(curr);
			head->before = NULL;
		}
	}
}

void PopTail(){
	curr = tail;
	if(head != NULL){
		if(head == tail){
			free(curr);
			head = tail = curr = NULL;
		}
		else{
			tail = tail->before;
			free(curr);
			tail->next = NULL;
		}
	}
}


