
#include <stdio.h>
#include<string.h>
#include "library.h"
#include <stdlib.h>

// typedef struct Product {
//   char product_name[50]; 
//   int product_quantity; 
//   double product_price; 
//   int product_minimum;
// } ;

// 1 = admin
// 2 = user


int main(){

  int choice;
  User user;
  FILE *fp;
  int exist;

  char keepGoingOrNot = 'y';
  while(keepGoingOrNot == 'y'){

    system("clear");
    printf("\t============WELCOME TO SLEEP SHOP============");
    printf("\n\nPlease select your prefered operation");
    printf("\n(1) Login");
    printf("\n(2) Register");
    printf("\n(3) PrintDb User");
    printf("\n(4) Exist");
    printf("\n\nYour choice\t:\t");
    scanf("%d",&choice);
    fgetc(stdin);

    switch (choice){
      case 1:
        printf("HELLO\n");
        Login();
        break;
      
      case 2:
        Register();
        break;

      case 3:
        PrintUserData();
        break;
      
      case 4:
        printf("\n\t\t Bye Bye :)\n\n");
        exit(0);
        break;
      
      default:
        printf("Your input is invalid, please try again");
        break;
    }
    printf("\nDo you want to perform another operation?[y/n]:\t");
    scanf("%s",&keepGoingOrNot);
  }
  return 0;
}