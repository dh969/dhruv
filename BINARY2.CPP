#include<iostream.h>
#include<conio.h>
int binary(int first,int mid,int end,int arr[],int item)
{if(first<end)
{if(item<arr[mid])
{end=mid-1;
mid=(first+end)/2;
return binary(first,mid,end,arr,item);
}
else if(item==arr[mid])
{cout<<"\n\t\tElement found at position "<<mid+1<<". ";
}
else
{first=mid+1;
mid=(first+end)/2;
return binary(first,mid,end,arr,item);
}
}
else
return 1;
}
void main()
{
clrscr();
int end,mid,first,arr[10],size;
char ans;
cout<<"\n\t\tEnter the size of the array : ";
cin>>size;
cout<<"\n\t\tEnter the elements in the array : ";
for(int i=0;i<size;i++)
{cout<<"\n\t\tElement "<<i+1<<": ";
cin>>arr[i];
}
clrscr();
int temp;
cout<<"\n\t\tSorted array : ";
for(int p=0;p<size;p++)
{for(int k=p+1;k<size;k++)
{if(arr[p]>arr[k])
{temp=arr[p];
arr[p]=arr[k];
arr[k]=temp;
}
}
cout<<arr[p]<<" ";
}
first=0;
end=size-1;
mid=(end+first)/2;
int item;

cout<<"\n\t\tEnter the element you want to search for : ";
cin>>item;
binary(first,mid,end,arr,item);
getch();
}