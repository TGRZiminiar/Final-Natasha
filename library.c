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


// struct User {
//   char userName[50];
//   char email[50];
//   char password[50];
//   char phone[50];
//   char role[10];
// };



int Register(){
    User user;
    int checkRole;
    FILE *fp;

    system("cls");
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
    else{
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
      fwrite(&user, sizeof(User),1 ,fp);
      if(fwrite != 0){
        printf("\nSuccessfully saved");
      }
      else{
        printf("\nError saving");
      } 
      fclose(fp);
      if(checkRole == 1){
        return 2;
      }
      else {
        return 1;
      }
    }
    else return 0;
}

int Login(){
    User user;
    User updateUserData;
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
    int loginSucces = 0;
    fp = fopen("User.dat","r");
    while (fread(&user, sizeof(User), 1, fp)){
      if(strcmp(userName, user.userName) == 0 && strcmp(password, user.password) == 0){
        printf("\nLogin Success\n");

        if(strcmp(user.role, "admin") == 0){
          loginSucces = 2;
        }
        else if(strcmp(user.role, "user") == 0){
          loginSucces = 2;
        }
        break;
      } else continue;
      // printf("\tUserName  :\t%s\n",user.userName);
      // printf("\tPassword  :\t%s\n",user.password);
    }

    return loginSucces;
}

void PrintUserData(){
    User user;
    FILE *fp;

    // system("clear");
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

int GetNumberOfUser(){
    User user;
    FILE *fp;

    fp = fopen("User.dat","r");
    fseek(fp, 0, SEEK_END);
    int numberOfUser = ftell(fp) / sizeof(User);
    fclose(fp);
    return numberOfUser;
}

void UpdateUserInDb(){
    User user;
    User updateUser;
    FILE *fp;
    FILE *fp1;
    int checkRole;
    char targetUser[50] = "mix";

    PrintUserData();
    printf("Enter userName that you want to update\t:\t");
    fgets(targetUser, 50, stdin);
    targetUser[strlen(targetUser)-1] = 0;
  
    fp = fopen("User.dat","a+");
    fp1 = fopen("temp.dat","w");
    int found = 0;
    while (fread(&user, sizeof(User), 1, fp)){
        if(strcmp(targetUser,user.userName) == 0){
            // fflush(stdin);
            found = 1;
            printf("\nPlease enter your userName:\t");
            fgets(updateUser.userName,50,stdin);
            updateUser.userName[strlen(updateUser.userName)-1] = 0;
              

            printf("\nPlease enter your password:\t");
            fgets(updateUser.password,50,stdin);
            updateUser.password[strlen(updateUser.password)-1] = 0;
            
            
            printf("\nPlease enter your email:\t");
            fgets(updateUser.email,50,stdin);
            updateUser.email[strlen(updateUser.email)-1] = 0;

            
            printf("\nPlease enter your phone:\t");
            fgets(updateUser.phone,50,stdin);
            updateUser.phone[strlen(updateUser.phone)-1] = 0;

            
            printf("\nPlease enter your role:\t");
            scanf("%d",&checkRole);

            
            if(checkRole == 1){
              strcpy(updateUser.role,"admin");
            }
            else if (checkRole == 0){
              strcpy(updateUser.role,"user");
            }

            user = updateUser;

            printf("Update User Success\n");

        }
        fwrite(&updateUser, sizeof(User),1 ,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found == 1){
      fp1 = fopen("temp.dat","r");
      fp = fopen("User.dat","w");

      while (fread(&updateUser, sizeof(User), 1, fp1)){
        fwrite(&updateUser, sizeof(User),1,fp);
      }
      

      fclose(fp);
      fclose(fp1);

    }
    else {
      printf("\nData Not Found\n");
    }

} 

void DeleteUserInDb(){
  User user;
  FILE *fp, *fp1;

  char targetUser[50];

  fp = fopen("User.dat","a+");
  fp1 = fopen("temp.dat","w");

  PrintUserData();
  printf("Enter userName that you want to delete\t:\t");
  fgets(targetUser, 50, stdin);
  targetUser[strlen(targetUser)-1] = 0;
  int found = 0;

  while (fread(&user, sizeof(User), 1, fp)){
    if(strcmp(targetUser,user.userName) == 0){
      found = 1;
    }
    else {
      fwrite(&user, sizeof(User), 1, fp1);
    }
  }
  
  fclose(fp);
  fclose(fp1);

  if(found == 1){
    fp1 = fopen("temp.dat","r");
    fp = fopen("User.dat","w");
    while (fread(&user, sizeof(User), 1 ,fp1)){
      fwrite(&user, sizeof(User), 1, fp);
    }
    
    fclose(fp);
    fclose(fp1);
    
  }

}