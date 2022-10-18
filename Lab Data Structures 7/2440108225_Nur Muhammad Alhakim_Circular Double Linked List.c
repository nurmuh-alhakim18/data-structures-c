#include <stdio.h>
#include <stdlib.h>

struct train{
    int gerbong;
    int penumpang[10];
    struct train *next;
    struct train *prev;
}*head=NULL, *tail=NULL, *curr=NULL;

int i;
int penumpang[10];

int main(){
	srand(time(0));
	int input;
	int tampung =rand()%10;
	for(i=0;i<10;i++){
		push(i);
	}
    display(tampung);
	while(1){
		printf(">> ");
		scanf("%d",&input);
		puts("");
		if(input==1){
            tampung--;
            display(tampung);
        }
		else if(input==2){
            tampung++;
            display(tampung);
            puts("");
        }
		else if(input==3){
			exit:
			break;
		}
	}
	return 0;
}

void menu(){
	printf("\nChoose your need :\n");
	printf("1. Move to Left\n");
	printf("2. Move to Right\n");
	printf("3. Exit\n");
}

void push(int gerbong){
    curr=(struct train*)malloc(sizeof(struct train));
    curr->penumpang[0]=rand()%2;
    curr->penumpang[1]=rand()%2;
    curr->penumpang[2]=rand()%2;
    curr->penumpang[3]=rand()%2;
    curr->penumpang[4]=rand()%2;
    curr->penumpang[5]=rand()%2;
    curr->penumpang[6]=rand()%2;
    curr->penumpang[7]=rand()%2;
    curr->penumpang[8]=rand()%2;
    curr->penumpang[9]=rand()%2;
    curr->gerbong=gerbong;
    curr->next=NULL;
    curr->prev=NULL;
    if(head==NULL){
        head=tail=curr;
    }
	else{
        tail->next=curr;
        curr->prev=tail;
        tail=curr;
    }
    tail->next=head;
    head->prev=tail;
}

void display(int indeks){
	curr=head;
	int var=0;
    while(var<10){
        if(indeks==var){
            printf("  [You're here]   <=> ");
        }
        else{
            printf("[Gerbong ke %d] <==> ",var);
        }
    var++;
    curr=curr->next;
    }
    printf(" Head\n");
    printf("\nPenumpang Dengan Tiket: ");
	for(i=0;i<10;i++){
		curr->gerbong=indeks;
		if(curr->penumpang[i]==1){
			int rumus=10*curr->gerbong + i;
			if(rumus<0 || rumus>99){
				printf(" Tidak Ada Gerbong Yang Bisa Di Cek\n");
				break;
			}
			else{
				printf("%d  ",rumus);
			}
        }

    }
	printf("\n");
	printf("Penumpang Tanpa  Tiket:");
	for(i=0;i<10;i++){
		curr->gerbong=indeks;
		if(curr->penumpang[i]==0){
			int rumus=10*curr->gerbong + i;
			if(rumus<0 || rumus>99){
				printf("  Tidak Ada Gerbong Yang Bisa Di Cek\n");
				break;
			}
			else{
				printf(" %d ",rumus);
			}
	   }

   }
printf("\n");
menu();
}


