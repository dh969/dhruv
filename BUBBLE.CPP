#include<iostream.h>
#include<conio.h>
int arr[10],size;
void bubble()
{int temp;
for(int i=0;i<size;i++)
{for(int j=i+1;j<size;j++)
{ if(arr[i]>arr[j])
{temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
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
bubble();
print();
getch();
}