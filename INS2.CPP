#include<iostream.h>
#include<conio.h>
int a[10],size,i,temp,pos;

void min(int k)
{int small=a[k];
for(int c=k;c<size;c++)
{if(small>a[c])
{small=a[c];pos=c;}
}

}
void ins()
{for(int j=0;j<size-1;j++)
{
min(j);

temp=a[j];
a[j]=a[pos];
a[pos]=temp;
}
}
void print()
{for(i=0;i<size;i++)
cout<<" "<<a[i];
}
void main()
{clrscr();
cout<<"\n\t\tEnter the size of the array : ";
cin>>size;
cout<<"\n\t\tEnter the values in the array : ";
for(i=0;i<size;i++)
{cout<<"\n\t\tElement "<<i+1<<": ";
cin>>a[i];}
ins();
print();
getch();
}