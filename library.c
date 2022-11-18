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

    printf("\n------------- User Detail ---------------\n\n");
    printf("\tUserName  :\t%s\n",user.userName);
    printf("\tPassword  :\t%s\n",user.password);
    printf("\tEmail     :\t%s\n",user.email);
    printf("\tPhone     :\t%s\n",user.phone);
    printf("\tRole      :\t%s\n",user.role);
    printf("\n\n");
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

void Login(){
    User user;
    FILE *fp;
    char userName[50];
    char password[50];

    printf("\n------------- Please Fill UserName And Password ---------------\n\n");
    printf("\tUserName  :\t");
    fgets(userName, 50, stdin);
    userName[strlen(userName)-1] = 0;

    printf("\tPassword  :\t");
    fgets(password, 50, stdin);
    password[strlen(password)-1] = 0;

    // printf("THIS IS userName %s\n",userName);
    // printf("THIS IS PASSWORD %s\n",password);

    fp = fopen("User.dat","r");
    while (fread(&user, sizeof(User), 1, fp)){
      if(strcmp(userName, user.userName) == 0 && strcmp(password, user.password) == 0){
        printf("\nLogin Success\n");
        break;
      } else continue;
      // printf("\tUserName  :\t%s\n",user.userName);
      // printf("\tPassword  :\t%s\n",user.password);
    }


}

void PrintUserData(){
    User user;
    FILE *fp;

    system("clear");
    fp = fopen("User.dat","r");
    printf("\n ****User Information****\n");
    int i = 1;
    while (fread(&user, sizeof(User), 1, fp)){
      printf("----------- User Number : %d -------------\n\n",i);
      printf("\tUserName  :\t%s\n",user.userName);
      printf("\tPassword  :\t%s\n",user.password);
      printf("\tEmail     :\t%s\n",user.email);
      printf("\tPhone     :\t%s\n",user.phone);
      printf("\tRole      :\t%s\n",user.role);
      printf("\n\n");
      i++;
    }
    fclose(fp);    
}

