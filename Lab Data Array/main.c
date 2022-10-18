#include <stdio.h>
#include <string.h>

struct airFresh {
 char *code;
 int available;
 int price;
};

int main (){
 int menu;
 printf("JOJO AIR FRESHENER SHOP CASHIER\n");
 printf("-------------------------------\n\n");
 printf("No. : Code   :  Air Freshener Name           :  Available  :  Price  \n");
 printf("-------------------------------------------------------------------------\n");
 printf("01  : AR004  :  Classic Rose                 :     20      :  Rp. 28000,-\n");
 printf("02  : AR005  :  Fresh Lemon                  :     40      :  Rp. 30000,-\n");
 printf("03  : AR007  :  Wild Lavender                :     25      :  Rp. 30000,-\n");
 printf("04  : AR011  :  Elegant Vanilla              :     20      :  Rp. 32000,-\n");
 printf("05  : AR016  :  Freesia & Jasmine            :     18      :  Rp. 33000,-\n");
 printf("06  : AR019  :  Exotic Flower                :     21      :  Rp. 34000,-\n");
 printf("07  : AR022  :  Ocean Scape                  :     30      :  Rp. 35000,-\n");
 printf("-------------------------------------------------------------------------\n\n");

 printf("Menu :\n");
 printf("1. Sell\n");
 printf("2. Add Stock\n");
 printf("3. Exit\n");
 printf("Input Choice : ");
 scanf("%d",&menu);
 puts("");
 if(menu == 1){
    sell();
 }
 else if(menu == 2){
    add();
 }
 else if(menu == 3){
    exit(0);
 }
 else{
    printf("\n\n---Option not found---\n");
    puts("");
 }
 return 0;
}

void sell (){
 struct airFresh data1,data2,data3,data4,data5,data6,data7;
 data1.code="AR004";
 data1.available=20;
 data1.price=28000;

 data2.code="AR005";
 data2.available=40;
 data2.price=30000;

 data3.code="AR007";
 data3.available=25;
 data3.price=30000;

 data4.code="AR011";
 data4.available=20;
 data4.price=32000;

 data5.code="AR016";
 data5.available=18;
 data5.price=33000;

 data6.code="AR019";
 data6.available=21;
 data6.price=34000;

 data7.code="AR022";
 data7.available=30;
 data7.price=35000;

 char code[5];
 int q,total;
 printf("Input Air Freshener Code [5 chars]: ");
 scanf("%s",&code);
 if(strcmp(data1.code,code)==0){
    printf("Input Quantity [0..20]: ");
    scanf("%d",&q);
    puts("");
    if(q > data1.available || q < 0){
        puts("");
        printf("...Air Freshener Is Not Enough...\n");
        puts("");
    }
    else{
        total = q * data1.price;
        printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-\n",data1.price,q,total);
        puts("");
        printf("--- Thank You ---\n");
    }
 }
 else if(strcmp(data2.code,code)==0){
    printf("Input Quantity [0..40]: ");
    scanf("%d",&q);
    puts("");
    if(q > data2.available || q < 0){
        puts("");
        printf("...Air Freshener Is Not Enough...\n");
        puts("");
    }
    else{
        total = q * data2.price;
        printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-\n",data2.price,q,total);
        puts("");
        printf("--- Thank You ---\n");
    }
 }
 else if(strcmp(data3.code,code)==0){
    printf("Input Quantity [0..25]: ");
    scanf("%d",&q);
    puts("");
    if(q > data3.available || q < 0){
        puts("");
        printf("...Air Freshener Is Not Enough...\n");
        puts("");
    }
    else{
        total = q * data3.price;
        printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-\n",data3.price,q,total);
        puts("");
        printf("--- Thank You ---\n");
    }
 }
 else if(strcmp(data4.code,code)==0){
    printf("Input Quantity [0..20]: ");
    scanf("%d",&q);
    puts("");
    if(q > data4.available || q < 0){
        puts("");
        printf("...Air Freshener Is Not Enough...\n");
        puts("");
    }
    else{
        total = q * data4.price;
        printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-\n",data4.price,q,total);
        puts("");
        printf("--- Thank You ---\n");
    }
 }
 else if(strcmp(data5.code,code)==0){
    printf("Input Quantity [0..18]: ");
    scanf("%d",&q);
    puts("");
    if(q > data5.available || q < 0){
        puts("");
        printf("...Air Freshener Is Not Enough...\n");
        puts("");
    }
    else{
        total = q * data5.price;
        printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-\n",data5.price,q,total);
        puts("");
        printf("--- Thank You ---\n");
    }
 }
 else if(strcmp(data6.code,code)==0){
    printf("Input Quantity [0..21]: ");
    scanf("%d",&q);
    puts("");
    if(q > data6.available || q < 0){
        puts("");
        printf("...Air Freshener Is Not Enough...\n");
        puts("");
    }
    else{
        total = q * data6.price;
        printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-\n",data6.price,q,total);
        puts("");
        printf("--- Thank You ---\n");
    }
 }
 else if(strcmp(data7.code,code)==0){
    printf("Input Quantity [0..30]: ");
    scanf("%d",&q);
    puts("");
    if(q > data7.available || q < 0){
        puts("");
        printf("...Air Freshener Is Not Enough...\n");
        puts("");
    }
    else{
        total = q * data7.price;
        printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-\n",data7.price,q,total);
        puts("");
        printf("--- Thank You ---\n");
    }
 }
 else{
    printf("\n\n...Air Freshener Not Found...\n");
 }
}

void add(){
 struct airFresh data1,data2,data3,data4,data5,data6,data7;
 data1.code="AR004";
 data1.available=20;
 data1.price=28000;

 data2.code="AR005";
 data2.available=40;
 data2.price=30000;

 data3.code="AR007";
 data3.available=25;
 data3.price=30000;

 data4.code="AR011";
 data4.available=20;
 data4.price=32000;

 data5.code="AR016";
 data5.available=18;
 data5.price=33000;

 data6.code="AR019";
 data6.available=21;
 data6.price=34000;

 data7.code="AR022";
 data7.available=30;
 data7.price=35000;

 char code[5];
 int q,total;
 printf("Input Air Freshener Code [5 chars]: ");
 scanf("%s",&code);
 if(strcmp(data1.code,code)==0){
    printf("Input Quantity [1..100]: ");
    scanf("%d",&q);
    printf("\n\n--- Adding Stock Success ---\n");
 }
 else if(strcmp(data2.code,code)==0){
    printf("Input Quantity [1..100]: ");
    scanf("%d",&q);
    printf("\n\n--- Adding Stock Success ---\n");
 }
 else if(strcmp(data3.code,code)==0){
    printf("Input Quantity [1..100]: ");
    scanf("%d",&q);
    printf("\n\n--- Adding Stock Success ---\n");
 }
 else if(strcmp(data4.code,code)==0){
    printf("Input Quantity [1..100]: ");
    scanf("%d",&q);
    printf("\n\n--- Adding Stock Success ---\n");
 }
 else if(strcmp(data5.code,code)==0){
    printf("Input Quantity [1..100]: ");
    scanf("%d",&q);
    printf("\n\n--- Adding Stock Success ---\n");
 }
 else if(strcmp(data6.code,code)==0){
    printf("Input Quantity [1..100]: ");
    scanf("%d",&q);
    printf("\n\n--- Adding Stock Success ---\n");
 }
 else if(strcmp(data7.code,code)==0){
    printf("Input Quantity [1..100]: ");
    scanf("%d",&q);
    printf("\n\n--- Adding Stock Success ---\n");
 }
 else{
    printf("\n\n...Air Freshener Not Found...\n");
 }
}




