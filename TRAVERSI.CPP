#include<iostream.h>
#include<conio.h>
void main()
{int arr[]={32,1,4,5,2,7},size,i ;
 size=sizeof (arr)/sizeof (arr[0]);
cout<<"\n\t\tElements in the array : ";
for(i=0;i<size;i++)
{cout<<" "<<arr[i];
}
getch();
}