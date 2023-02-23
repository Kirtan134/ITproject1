#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int pass=123,qntrem;
float tempcost;
char del[100];
FILE *f;
struct product
{
    char name[100];
    int quantity;
    float cost;
};
struct product p;
void rem()
{
    f=fopen("stock.txt","a+");
    while(!feof(f))
    {
        fscanf(f,"%s %d %f",p.name,&p.quantity,&p.cost);
        if(stricmp(del,p.name)==0)
        {
            p.quantity-=qntrem;
            tempcost=p.cost;
            break;
        }
    }
    fclose(f);
}
void add()
{
    system("cls");
    f=fopen("stock.txt","a");
    char tempstr[100];
    int temp;
    float tempf;
    printf("Enter the Name, Quantity and Cost of the product respectively: ");
    scanf("%s %d %f",tempstr,&temp,&tempf);
    fprintf(f,"%s %d %f",tempstr,temp,tempf);
    fclose(f);
    printf("Press any key to continue to the main menu\n");
    getch();
}
void sys()
{
    system("cls");
    printf("\t\t\t\t\t\tSuccessfully logged in\n\n");
    printf("\t\t\t\t\t\tAction to do\n\t\t\t\t\t\t[1]Inventory Management\n\t\t\t\t\t\t[2]Finance Management\n\t\t\t\t\t\t[0]Exit to Main Menu\n");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        add();
    }
}
void buy()
{
    system("cls");
    int j;
    printf("\t\t\t\t\t\tEnter the number of distinct products you want to buy: ");
    scanf("%d",&j);
    while(j--)
    {
        printf("\t\t\t\t\t\tEnter the name of the product and the quantity respectively: ");
        scanf("%s %d",del,&qntrem);
        rem();
        printf("\t\t\t\t\t\tPay the amount of %f: ",qntrem*tempcost);
        int r;
        scanf("%d",&r);
    }
    printf("\t\t\t\t\t\tPress any key to continue to the main menu\n");
    getch();
}
void view()
{
    int i=1,j=1;
    system("cls");
    f=fopen("stock.txt","r");
    while(fread(&p,sizeof(struct product),1,f)==0)
    {
        printf("%s %d %f",p.name,p.quantity,p.cost);
        i++;
        j++;
    }
    fclose(f);
}
int main()
{
    printf("\t\t\t\t\t\tWelcome\n\n\n");
    int x;
    do
    {
        printf("\t\t\t\t\t\tLogin to the System as:\n");
        printf("\t\t\t\t\t\t[1]A Customer\n\t\t\t\t\t\t[2]An Owner\n\t\t\t\t\t\t[0]Exit from the System\n\t\t\t\t\t\t");
        scanf("%d",&x);
        if(x==1)
        {
            view();
            buy();
        }else if(x==2)
        {
            system("cls");
            printf("\t\t\t\t\t\tLogin to the Management System\n\t\t\t\t\t\tEnter the Password to Login: ");
            int y=pass;
            do
            {
                if(y!=pass)
                {
                    printf("\t\t\t\t\t\tWrong Password. Try Again: ");
                }
                scanf("%d",&y);
            } while (y!=pass);
            if(y==pass)
            {
                sys();
            }
        }
    }while(x==1 || x==2);
}
