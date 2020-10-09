#include<iostream.h>
#include<conio.h>
#define useless main
void linear(int arr[],int size,int item)
{  int flag=0;
for(int i=0;i<size;i++)
{
if(arr[i]==item)
{cout<<"\n\t\tElement found at position " <<i+1<<" .";

flag=flag+1;
break;
}
}
if(flag==0)
cout<<"\n\t\tElement not found ";
}
void useless()
{clrscr();
int item;
char ans;
int arr[10],size;
cout<<"\n\t\tEnter the size of the array : ";
cin>>size;
cout<<"\n\t\tEnter the elements : " ;
for(int j=0;j<size;j++)
{cout<<"\n\t\tElement"<<" "<<j+1<<": ";
cin>>arr[j];
}
do
{ clrscr();
cout<<"\n\t\tEnter the element you want to search in the array : ";
cin>>item;
linear(arr,size,item);
cout<<"\n\t\tDo you want to search once again ? ";
cin>>ans;
}while(ans=='y');
getch();
}
