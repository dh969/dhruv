#include<iostream.h>
#include<conio.h>
void print(int b,int i)
{if(i==4)
{cout<<"0"<<" "<<"1"<<" "<<"1"<<" "<<b;
}
else
cout<<" "<<b;
}
int fibo(int a,int b,int i)
{if(i!=0)
{--i;
int c=0;
c=a+b;
print(c,i);
return fibo(b,c,i);
}
else
return 1;

}
void main()
{clrscr();  int n;
cout<<"\n\t\tEnter the number of series you wanna see : ";
cin>>n;
fibo(1,1,n);

getch();

}