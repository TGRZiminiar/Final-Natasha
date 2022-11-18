
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




int main(){

  int choice;
  User user;
  FILE *fp;
  int exist;
  
  system("clear");
  printf("\t============WELCOME TO SLEEP SHOP============");
  printf("\n\nPlease select your prefered operation");
  printf("\n\n1.Login");
  printf("\n2.Register");
  printf("\n\nYour choice:\t");
  scanf("%d",&choice);

  fgetc(stdin);
  switch (choice){
  case 1:
    printf("HELLO\n");
    break;
  case 2:
    Register();
    break;

  case 3:
    system("clear");
    fp = fopen("User.dat","r");
    printf("\n ****User Information****\n");
    while (fread(&user, sizeof(User), 1, fp)){
      printf("USER NAME => %s\n",user.userName);
      printf("Passwod => %s\n",user.password);
      printf("EMail => %s\n",user.email);
      printf("Phone => %s\n",user.phone);
      printf("Role => %s\n",user.role);
    }
    fclose(fp);    
    break;
  default:
    break;
  }

  return 0;
}