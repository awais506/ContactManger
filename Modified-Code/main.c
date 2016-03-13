    #include<stdio.h>
    #include<conio.h>
    #include<string.h>
    #include<process.h>
    #include<stdlib.h>
    #include<dos.h>
    #include"Functions.h"
    #include"interface.h"
    
    
     
        int main()
        {
        int ch;
         main:
        MainMenue();
         printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        main;
        case 0:
        break;
        default:
        printf("Invalid choice");
        break;
        } 
        return 0;
        }
