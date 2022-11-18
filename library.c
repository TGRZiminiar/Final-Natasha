#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

User makeUser(char *userName, char *email, char *password, char *phone, char *role){
  User user;
  
  strcpy(user.userName,userName);
  strcpy(user.email,email);
  strcpy(user.password,password);
  strcpy(user.phone,phone);
  strcpy(user.role,role);
  return user;

}


struct User {
  char userName[50];
  char email[50];
  char password[50];
  char phone[50];
  char role[10];
};



void Register(){
    User user;
    int checkRole;
    FILE *fp;

    system("clear");
    printf("\n============Reigster Page============");
    
    printf("\nPlease enter your userName:\t");
    fgets(user.userName,50,stdin);
    user.userName[strlen(user.userName)-1] = 0;
      
    printf("\nPlease enter your password:\t");
    fgets(user.password,50,stdin);
    user.password[strlen(user.password)-1] = 0;
    
    printf("\nPlease enter your email:\t");
    fgets(user.email,50,stdin);
    user.email[strlen(user.email)-1] = 0;

    printf("\nPlease enter your phone:\t");
    fgets(user.phone,50,stdin);
    user.phone[strlen(user.phone)-1] = 0;

    printf("\nPlease enter your role:\t");
    scanf("%d",&checkRole);

    if(checkRole == 1){
      strcpy(user.role,"admin");
    }
    else if (checkRole == 0){
      strcpy(user.role,"user");
    }
    // role[strlen(role)-1] = 0;


    printf("USER NAME => %s\n",user.userName);
    printf("Passwod => %s\n",user.password);
    printf("EMail => %s\n",user.email);
    printf("Phone => %s\n",user.phone);
    printf("Role => %s\n",user.role);
    printf("\nDo you want to save the invoice [y/n]:\t");
    char saveBill;
    scanf("%s",&saveBill);

    if(saveBill == 'y'){
      fp = fopen("User.dat","a+");
      fwrite(&user, sizeof(struct User),1 ,fp);
      if(fwrite != 0)
      printf("\nSuccessfully saved");
      else 
      printf("\nError saving");
      fclose(fp);
    }

}

int add(int x, int y)
{
  printf("add function\n");
  return x + y;
}

int sub(int x, int y)
{
  return x - y;
}