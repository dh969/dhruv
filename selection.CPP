#include<iostream.h>
#include<conio.h>
int arr[10],size;
void ins()
{int temp;
for(int i=1;i<size;i++)
{temp=arr[i];
for(int j=i-1;j>=0&&temp<arr[j];j--)
arr[j+1]=arr[j];
arr[j+1]=temp;
}
}
void print()
{for(int g=0;g<size;g++)
cout<<" "<<arr[g];
}
void main()
{clrscr();
cout<<"\n\t\tEnter the size of the array : ";
cin>>size;
cout<<"\n\t\tEnter the elements : ";
for(int k=0;k<size;k++)
{cout<<"\n\t\tElements : "<<k+1<<": ";
cin>>arr[k];

}
ins();
print();
getch();
}