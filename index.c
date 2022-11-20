
#include <stdio.h>
#include <string.h>
#include "library.h"
#include "product.h"
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

  User user;
  FILE *fp;
  int exist;
  int loginOrNot = 0;
  // 0 = NotLogin 1 = UserLogin 2 = AdminLogin
  char keepGoingOrNot = 'y';
  while(keepGoingOrNot == 'y'){
    printf("THIS IS LOGINORNOT %d\n",loginOrNot);
    if(loginOrNot == 0){
      int choice;
      system("cls");
      printf("\t============WELCOME TO SLEEP SHOP============");
      printf("\n\nPlease select your prefered operation");
      printf("\n(1) Login");
      printf("\n(2) Register");
      printf("\n(3) Exist");
      printf("\n(4) PrintDb User");
      printf("\n\nYour choice\t:\t");
      scanf("%d",&choice);
      fgetc(stdin);

      switch (choice){
        case 1:
          loginOrNot = Login();
          break;
        
        case 2:
          loginOrNot = Register();
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
    }

    //User Section
    else if(loginOrNot == 1){
      printf("User Login Sucess");
    }

    //Admin Section
    else if(loginOrNot == 2){
      int choiceForAdmin;
      system("clear");
      printf("\t============Admin Section============");
      printf("\n\nPlease select your prefered operation");
      printf("\n(1) Add Product To Stock");
      printf("\n(2) Edit Product");
      printf("\n(3) Remove Product");
      printf("\n(4) Check Stock");
      printf("\n(5) Check Income");
      printf("\n(6) Check Payment");
      printf("\n(7) Print All User");
      printf("\n(8) Get Number Of User In DB");
      printf("\n(9) Update User In DB");
      printf("\n(10) Delete User In DB");
      printf("\n(11) Logout");
      printf("\n\nYour choice\t:\t");
      scanf("%d",&choiceForAdmin);
      fgetc(stdin);

      switch (choiceForAdmin){
        case 1:
          AddProduct();
          break;
        
        case 2:
          EditProductInDB();
          break;
        
        case 3:
          RemoveProduct();
          break;

        case 4:
          PrintProduct();
          break;

        case 5:

          break;

        case 6:

          break;

        case 7:
          PrintUserData();
          break;

        case 8:
          printf("\n\tNumber Of User In Db\t:\t%d\n",GetNumberOfUser());
          break;

        case 9:
          UpdateUserInDb();
          break;

        case 10:
          DeleteUserInDb();
          break;

        case 11:

          break;

        default:
          printf("Your input is invalid, please try again");
          break;
      }
      
    }

    printf("\nDo you want to perform another operation?[y/n]:\t");
    scanf("%s",&keepGoingOrNot);
  }
  return 0;
}