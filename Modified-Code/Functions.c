    /*
    Modifeid and Updated by : Muhammad Awais 12 EE 506
    UET Lahore
    */
    
    #include<stdio.h>
    #include<conio.h>
    #include<string.h>
    #include<process.h>
    #include<stdlib.h>
    #include<dos.h>
     #include "interface.h"
     
     //Strut is used to create data type including all the  details of contact
    struct contact
    {
    long ph;
    char name[20],add[20],email[30];
    }list;
     
    char query[20],name[20];
    FILE *fp, *ft;
    int i,n,l,ch,found;
    
    /* *********************add new contacts************  */
    void NewContact(){
         
       int choice;  
    system("cls");    
    fp=fopen("contact.dll","a");
    //for (;;)
    do
    { fflush(stdin);
    printf("To exit enter blank space in the name input\nName (Use identical):");
    scanf("%[^\n]",&list.name);
    if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
    break;
    fflush(stdin);
    printf("Phone:");
    scanf("%ld",&list.ph);
    fflush(stdin);
    printf("address:");
    scanf("%[^\n]",&list.add);
    fflush(stdin);
    printf("email address:");
    
    gets(list.email);
    
    
    printf("\n");
    fwrite(&list,sizeof(list),1,fp);
    printf("Return to main menue[0]  Continue [1]:");
    scanf("%i",&choice);
    }while(choice!=0);
    
    fclose(fp);
    MainMenue();
         
         }
    
    /* *********************list of contacts*************************  */
    
    void ListContacts()
    {
         system("cls");
    printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t==== ============================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=== ==============================================================\n\n");
     
    for(i=97;i<=122;i=i+1)
    {
     
    fp=fopen("contact.dll","r");
    fflush(stdin);
    found=0;
    while(fread(&list,sizeof(list),1,fp)==1)
    {
    if(list.name[0]==i || list.name[0]==i-32)
    {
    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name, 
    list.ph,list.add,list.email);
    found++;
    }
    }
    if(found!=0)
    {printf("=========================================================== [%c]- (%d)\n\n",i-32,found);
    getch();}
    fclose(fp);
     
    }
          
         }
         
         
      /* *******************search contacts**********************  */   
         void SearchContacts(){
              
              system("cls");
    do
    {
    found=0;
    printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of  contact to search: ");
    fflush(stdin);
    scanf("%[^\n]",&query);
    l=strlen(query);
    fp=fopen("contact.dll","r");
     
    system("cls");
    printf("\n\n..::Search result for '%s' \n====================================== =============\n",query);
    while(fread(&list,sizeof(list),1,fp)==1)
    {
    for(i=0;i<=l;i++)
    name[i]=list.name[i];
    name[l]='\0';
    if(stricmp(name,query)==0)
    {
    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t:  %s\n",list.name,list.ph,list.add,list.email);
    found++;
    if (found%4==0)
    {
    printf("..::Press any key to continue...");
    getch();
    }
    }
    }
     
    if(found==0)
    printf("\n..::No match found!");
    else
    printf("\n..::%d match(s) found!",found);
    fclose(fp);
    printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
    scanf("%d",&ch);
    }while(ch==1);
              
              
              }
              
    void EditContacts()
    {
    system("cls");
    fp=fopen("contact.dll","r");
    ft=fopen("temp.dat","w");
    fflush(stdin);
    printf("..::Edit contact\n===============================\n\n\t..::Enter the  name of contact to edit:");
    scanf("%[^\n]",name);
    while(fread(&list,sizeof(list),1,fp)==1)
    {
    if(stricmp(name,list.name)!=0)
    fwrite(&list,sizeof(list),1,ft);
    }
    fflush(stdin);
    printf("\n\n..::Editing '%s'\n\n",name);
    printf("..::Name(Use identical):");
    scanf("%[^\n]",&list.name);
    fflush(stdin);
    printf("..::Phone:");
    scanf("%ld",&list.ph);
    fflush(stdin);
    printf("..::address:");
    scanf("%[^\n]",&list.add);
    fflush(stdin);
    printf("..::email address:");
    gets(list.email);
    printf("\n");
    fwrite(&list,sizeof(list),1,ft);
    fclose(fp);
    fclose(ft);
    remove("contact.dll");
    rename("temp.dat","contact.dll");  
                   
                       
                   }
    
    
    void DeleteContacts(){
         
         system("cls");
    fflush(stdin);
    printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter  the name of contact to delete:");
    scanf("%[^\n]",&name);
    fp=fopen("contact.dll","r");
    ft=fopen("temp.dat","w");
    while(fread(&list,sizeof(list),1,fp)!=0)
    if (stricmp(name,list.name)!=0)
    fwrite(&list,sizeof(list),1,ft);
    fclose(fp);
    fclose(ft);
    remove("contact.dll");
    rename("temp.dat","contact.dll");
    
         
         }
