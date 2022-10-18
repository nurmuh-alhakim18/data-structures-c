#include <stdio.h>
#include<stdlib.h>

#define MAX 11

struct hotel{
    int room;
    char name[55];
    int dd;
    int mm;
    int yy;
};

struct record{
    struct hotel data;
    struct record *link;
};

int hashFunction(int key);
void insert(struct hotel hotelRecord, struct record *hashTable[]);
int search(int key, struct record *hashTable[]);
void show(struct record *hashTable[]);
void del(int key, struct record *hasTable[]);

int hashFunction(int key){
      return (key % MAX);
}

void insert(struct hotel hotelRecord, struct record *hashTable[]){
    int key, h;
    struct record *temp;
    key = hotelRecord.room;
    if(search(key, hashTable) != -1){
        printf("\n\t--- Room Already Booked ---\n\n");
        return;
    }
    printf("\n\t--- Add Data Success ---\n\n");
    h = hashFunction(key);
    temp = malloc(sizeof(struct record));
    temp->data = hotelRecord;
    temp->link = hashTable[h];
    hashTable[h] = temp;
}

int search(int key, struct record *hashTable[]){
    int h;
    struct record *ptr;
    h = hashFunction(key);
    ptr = hashTable[h];
    while(ptr != NULL){
        if(ptr->data.room == key){
            return h;
        }
        ptr = ptr->link;
    }
    return -1;
}

void show(struct record *hashTable[]){
    int rep;
    struct record *ptr;
    for(rep = 1; rep < MAX; rep++){
        printf("\n%d.", rep);
        if(hashTable[rep] != NULL){
            ptr = hashTable[rep];
            while(ptr != NULL){
                printf("\tRoom Number : %d\n", ptr->data.room);
                printf("\tName        : %s\n", ptr->data.name);
                printf("\tDate        : %d/%d/%d\n\n", ptr->data.dd, ptr->data.mm, ptr->data.yy);
                ptr=ptr->link;
            }
        }
        else{
            printf("\t--- Room Not Booked Yet ---\n\n");
        }
    }
}

void del(int key, struct record *hashTable[]){
    int h;
    struct record *temp, *ptr;
    h = hashFunction(key);
    if(hashTable[h] == NULL){
        printf("\n\t--- Room %d Not Booked Yet ---\n\n", key);
        return;
    }
    if(hashTable[h]->data.room == key){
        temp = hashTable[h];
        hashTable[h] = hashTable[h]->link;
        free(temp);
        return;
    }
    ptr = hashTable[h];
    while(ptr->link != NULL){
        if(ptr->link->data.room == key){
            temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
            return;
        }
        ptr = ptr->link;
    }
    printf("\n\t--- Room %d Not Booked Yet ---\n\n", key);
}

int main(){
    struct record *hashTable[MAX];
    struct hotel hotelRecord;
    int rep, key, option;
    for(rep = 1; rep < MAX; rep++){
        hashTable[rep] = NULL;
    }
    while(1){
        printf("Hotel Reservation Data\n");
        printf("======================\n\n");
        printf("1. Add Data\n");
        printf("2. Search Data\n");
        printf("3. Display Data\n");
        printf("4. Delete Data\n");
        printf("5. Exit\n");
        printf(">> Input your choice : ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\n\tRoom Number [1-10] : ");
                    scanf("%d", &hotelRecord.room);
                    if(hotelRecord.room < 1 || hotelRecord.room > 10){
                        printf("\n\t--- Room Number [1-10] ---\n\n");
                    }
                    else{
                        getchar();
                        printf("\tName [3-25] : ");
                        scanf("%[^\n]", hotelRecord.name);
                        if(strlen(hotelRecord.name) < 3 || strlen(hotelRecord.name) > 25){
                            printf("/n/t--- Name [3-25] ---\n\n");
                        }
                        else{
                            printf("\tDay [1-31] : ");
                            scanf("%d", &hotelRecord.dd);
                            if(hotelRecord.dd < 1 || hotelRecord.dd > 31){
                                printf("\n\t--- Wrong Day ---\n\n");
                            }
                            else{
                                printf("\tMonth [1-12] : ");
                                scanf("%d", &hotelRecord.mm);
                                if(hotelRecord.mm < 1 || hotelRecord.mm > 12){
                                    printf("\n\t--- Wrong Month ---\n\n");
                                }
                                else{
                                    printf("\tYear [2021-2023] : ");
                                    scanf("%d",&hotelRecord.yy);
                                    if(hotelRecord.yy < 2021 || hotelRecord.yy > 2023){
                                        printf("\n\t--- Wrong Month ---\n\n");
                                    }
                                    else{
                                        insert(hotelRecord, hashTable);
                                    }
                                }
                            }
                        }
                    }
                break;
            case 2:
                printf("\n\tRoom Number [1-10] : ");
                scanf("%d", &key);
                if(key < 1 || key > 10){
                    printf("\n\t--- Room Number [1-10] ---\n\n");
                }
                else{
                    rep = search(key, hashTable);
                    if(rep == -1){
                        printf("\n\t--- Room Not Booked Yet ---\n\n");
                    }
                    else{
                        printf("\n\t--- Room %d Already Booked ---\n\n", rep);
                    }
                }
                break;
            case 3:
                show(hashTable);
                break;
            case 4:
                printf("\n\tDelete Room Data [1-10] : ");
                scanf("%d", &key);
                if(key < 1 || key > 10){
                    printf("\n\t--- Room Number [1-10] ---\n\n");
                }
                del(key, hashTable);
                printf("\n\t--- Delete Room Data Success ---\n\n");
                break;
            case 5:
                exit(1);
        }
    }
    return 0;
}
