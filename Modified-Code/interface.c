#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>


int ch;
void MainMenue()
{
system("cls");    /* ************Main menu ***********************  */
printf("\n\t **** Welcome to a0 contact Manager ****");
printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new   Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit  a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
printf("Enter the choice:");
scanf("%d",&ch); 
choice(ch);    
     }


void choice(int choice)
{
  switch(ch)
{
case 0:
printf("\n\n\t\tAre you sure u want to exit?");
break;
/* *********************add new contacts************  */
case 1:
NewContact(); 
break;
 
/* *********************list of contacts*************************  */
case 2:
 ListContacts();
 
break;
 
/* *******************search contacts**********************  */
case 3:
SearchContacts();
break;
 
 
/* *********************edit contacts************************/
case 4:
EditContacts();
break;
 
 
/* ********************delete contacts**********************/
case 5:
 DeleteContacts();
break;
break;
 
default:
printf("Invalid choice");
     
}   
     
     
     }


void Exit()
{
  int choice;   
     

}
