#include<iostream.h>
#include<conio.h>
int adj(int ,int ,int );
void quick(int ,int ,int);
void swap(int,int);
void swap(int *fir,int *sec)
{int temp;
temp=*fir;
*fir=*sec;
*sec=temp;
}
int adj(int arr[],int low,int high)
{int j=0,i=low-1;;
int pivot=arr[high];
for(j=low;j<high;j++)
{if(pivot>arr[j])
{i++;
swap(&arr[j],&arr[i]);
}
}
swap(&arr[i+1],&arr[high]);
return (i+1);
}
void quick(int arr[],int low,int high)
{if(low<high)
{int pi=adj(arr,low,high);
quick(arr,pi+1,high);
quick(arr,low,pi-1);
}
}
void print(int arr[],int size)
{
int k;
cout<<"\n\t\tSorted array  : ";
for(k=0;k<size;k++)
{cout<<" "<<arr[k];
}

}
void  main()
{clrscr();
cout<<"\n\t\t------------------------------------";
cout<<"\n\t\t|           QUICK SORT             |";
cout<<"\n\t\t------------------------------------";
int arr[10],size,low,high,i;
cout<<"\n\t\tEnter the size of the array : ";
cin>>size;
cout<<"\n\t\tEnter the elements : ";
for(i=0;i<size;i++)
{cout<<"\n\t\tElement  "<<i+1<<": ";
cin>>arr[i];
}   clrscr();
cout<<"\n\t\tEntered array : ";
for(i=0;i<size;i++)
cout<<" "<<arr[i];
low=0;
high=size;
quick(arr,low,high);
print(arr,size);
getch();
}