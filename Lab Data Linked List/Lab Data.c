#include <stdio.h>
#include <stdlib.h>

//create linked lst
struct list{
 int isi;
 struct list *next;
};

//contoh membuat 3 linked list
int main(){
 struct list *head = NULL;
 struct list *dua = NULL;
 struct list *tiga = NULL;

 head = (struct list*)malloc(sizeof(struct list));
 dua = (struct list*)malloc(sizeof(struct list));
 tiga = (struct list*)malloc(sizeof(struct list));

 head->isi = 10;
 head->next = dua;
 dua->isi = 20;
 dua->next = tiga;
 tiga->isi = 30;
 tiga->next = NULL;
 insertDepan (5, &head);
 insertCustom (100, dua);

 print(head);
}

void print(struct list *data){
    while(data != NULL){
        printf("%d ",data->isi);
        data = data->next;
    }
}

void insertDepan(int isiData, struct list **head){
 struct list *temp = (struct list*)malloc(sizeof(struct list));
 temp->isi = isiData;
 temp->next = *head;
 (*head) = temp;
}


void insertCustom(int isiData, struct list *linklist){
 struct list *temp = (struct list*)malloc(sizeof(struct list));
 temp->isi = isiData;
 temp->next = linklist->next;
 linklist->next = temp;
}


