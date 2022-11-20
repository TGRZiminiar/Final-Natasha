int add(int x, int y);
int sub(int x, int y);

#ifndef POINTOPERATIONS_H_
#define POINTOPERATIONS_H_

typedef struct {
  char userName[50];
  char email[50];
  char password[50];
  char phone[50];
  char role[10];
} User;

void Register();
void Login();
void PrintUserData();
int GetNumberOfUser();
void UpdateUserInDb();
User makeUser(char *userName, char *email, char *password, char *phone, char *role);

#endif /* POINTOPERATIONS_H_ */