#include<conio.h>
#include<stdio.h>
#include<math.h>
int VAL(int L[][50],int R[][5],int base,int m)
{
	int i,val,val1,z;
	for(i=0;i<50;i++)
	{
		z=base-L[m][i];
		if(z<0)
		{
			val=0;
			break;
		}
		else
		val=1;
	}
	for(i=0;i<5;i++)
	{
		z=base-R[m][i];
		if(z<0)
		{
			val1=0;
			break;
		}
		else
		val1=1;
	}
	z=val*val1;
	if(z==0)
	{
		for(i=0;i<50;i++)
		L[m][i]=0;
		for(i=0;i<5;i++)
		R[m][i]=0;
	}
	return z;
}
int SEC_INP(int L[][50],int R[][5],int *neg2)
{
	int Ldec[50],Rdec[5],i,n1,j;
	char a;
	printf("\nEnter the Second Input:\n");
	fflush(stdin);
	for(i=0;a!='.';i++)
	{
		scanf("%c",&a);
		if(a=='-')
		*neg2=1;
		else if(a=='\n')
		break;
		else if(a>='0'&&a<='9')
		Ldec[i]=a-48;
		else if(a>='A'&& a<='Z')
		Ldec[i]=a-55;
		else if(a>='a'&&a<='z')
		Ldec[i]=a-61;
	}
	if(a=='\n')
	{
		n1=(i-1);
		for(i=0;i<5;i++)
		Rdec[i]=0;
	}
	else
	{
		n1=(i-2);
		for(i=0;i<5;i++)
		{
			scanf("%c",&a);
			if(a=='\n')
			break;
			else if(a>='0'&&a<='9')
			Rdec[i]=a-48;
			else if(a>='A'&& a<='Z')
			Rdec[i]=a-55;
			else if(a>='a'&&a<='z')
			Rdec[i]=a-61;
		 }
		 for(;i<5;i++)
		 Rdec[i]=0;
	}
	 for(i=n1;i>=0;i--)
	{
		L[1][49-(n1-i)]=Ldec[i];
	}
	for(i=0;i<(49-n1);i++)
	{
			L[1][i]=0;
	}
	for(i=0;i<5;i++)
	{
		R[1][i]=Rdec[i];
	}
	return n1;
}
int DIV(int L[][50],int R[][5],int n,unsigned int div)
{
	int i,j,k,d=1,pro=0;
	for(i=(49-n);i<50;i++)
	{
		d=(pro*10)+L[0][i];
		pro=d%div;
		L[2][i-(49-n)]=d/div;
	}
	printf("Ans:\n");
	for(i=0;i<=n;i++)
	{
		printf("%d",L[2][i]);
	}
	for(i=0;i<5;i++)
	{
		d=(pro*10)+R[0][i];
		pro=d%div;
		R[2][i]=d/div;
	}
	printf(".");
	for(i=0;i<5;i++)
	{
		printf("%d",R[2][i]);
	}
	return 0;

}
int MUL(int L[][50],int R[][5],int n,int n1,int base2)
{
	int m[52][50],m1[52][50],l,i,j,sum=0,k=0,pro=0,len_n,len_b1;
	unsigned long b1,e;
	len_n=(n+1);
	printf("\n");
	for(i=0;i<5;i++)
	{
		m[0][45+i]=R[0][i];
	}
	for(j=0;j<len_n;j++)
	{
		m[0][45-len_n+j]=L[0][50-len_n+j];
	}
	for(j=0;j<(45-len_n);j++)
	{
		m[0][j]=0;
	}
	printf("\n");
	len_b1=n1+1;
	for(i=0;i<5;i++)
	{
		m[1][45+i]=R[1][i];
	}
	for(j=0;j<len_b1;j++)
	{
		m[1][45-len_b1+j]=L[1][50-len_b1+j];
	}
	for(j=0;j<(45-len_b1);j++)
	{
		m[1][j]=0;
	}
	printf("\n");
	k=0;
	for(j=49;j>=0;j--)
	{
		l=0;
		while(l<k)
		{
			m[(49-j)+2][49-l]=0;
			l++;
		}
		for(i=49;i>=0;i--)
		{
			pro=pro+(m[0][i]*m[1][j]);
			m[(49-j)+2][i-l]=pro%base2;
			pro=pro/base2;
		}
		for(i=0;i<50;i++)
		{
			m1[(49-j)+2][i]=m[(49-j)+2][i];
		}

		k++;
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<50;j++)
		{
			m1[i][j]=m[i][j];
		}
	}
	for(j=49;j>=0;j--)
	{
		for(i=50;i>=2;i--)
		{
			sum=sum+m1[i][j];
		}
		m1[51][j]=sum%base2;
		sum=sum/base2;
	}
	for(i=0;i<50;i++)
	{
		if(m1[51][i]>=0 && m1[51][i]<=9)
		L[2][i]=m1[51][i]+48;
		else if(m1[51][i]>=10 && m1[51][i]<=35)
		L[2][i]=m1[51][i]+55;
		else
		L[2][i]=m1[51][i]+61;
	}
	return 0;
}
int SUB(int L[][50],int R[][5],int n,int n1,int base1)
{
	int count=0,i,j,k,flag,temp[5],d=1,div=0,A3=0;
	if(n1>n)
	{
		for(i=0;i<50;i++)
		{
			flag=L[0][i];
			L[0][i]=L[1][i];
			L[1][i]=flag;
		}
		count=1;
		for(i=0;i<5;i++)
		{
			flag=R[0][i];
			R[0][i]=R[1][i];
			R[1][i]=flag;
		}
	}
	else if(n==n1)
	{
		for(i=0;i<50;i++)
		{
			div=L[0][i]-L[1][i];
			if(div<0)
			break;
		}
		if(i<50)
		{
			for(i=0;i<50;i++)
			{
				flag=L[0][i];
				L[0][i]=L[1][i];
				L[1][i]=flag;
			}
			count=1;
			for(i=0;i<5;i++)
			{
				flag=R[0][i];
				R[0][i]=R[1][i];
				R[1][i]=flag;
			}
			A3=1;
		}
	}
	for(i=4;i>=0;i--)
	{
		if(R[0][i]>=R[1][i])
		{
			div=R[0][i]-R[1][i];
		}
		else
		{
			j=i-1;
			if(j>=0)
			{
				R[0][i]=base1+R[0][i];
				R[0][j]=R[0][j]-1;
			}
			else
			{
				R[0][i]=base1+R[0][i];
				L[0][49]=L[0][49]-1;
			}
			div=R[0][i]-R[1][i];
		}
		if(div<10)
		R[2][i]=div+48;
		else if(div>10&&div<=35)
		R[2][i]=div+55;
		else
		R[2][i]=div+61;
	}
	for(i=49;i>=0;i--)
	{
		if(L[0][i]>=L[1][i])
		{
			div=L[0][i]-L[1][i];
		}
		else
		{
			j=i-1;
			L[0][i]=base1+L[0][i];
			L[0][j]=L[0][j]-1;
			div=L[0][i]-L[1][i];
		}
		if(div<10)
		L[2][i]=div+48;
		else if(div>=10&&div<=35)
		L[2][i]=div+55;
		else
		L[2][i]=div+61;
	}
	return count;
}
int TEN_BASE(int L[][50],int R[][5],int n,int Lrem[],int Rrem[],int base1)
{
	int A1,d=1,sum,pro=0,i,j,k,div[50],temp[5];
	for(j=0;sum!=0;j++)
	{
		pro=0;
		sum=0;
		for(i=(49-n);i<50;i++)
		{
			d=(pro*10)+L[0][i];
			pro=d%base1;
			div[i-(49-n)]=d/base1;
		}
		if(pro<10)
		Lrem[j]=pro+48;
		else if(pro>=10&&pro<=35)
		Lrem[j]=pro+55;
		else
		Lrem[j]=pro+61;
		for(i=0;i<=n;i++)
		{
			L[0][49-n+i]=div[i];
		}
		for(i=0;i<(49-n);i++)
		{
			L[0][i]=0;
		}
		for(i=0;i<=n;i++)
		{
			sum=sum+div[i];
		}
	}
	k=j-1;
	A1=k;
	for(i=0;i<5;i++)
	{
		temp[i]=R[0][4-i];
	}
	for(i=0;i<=4;i++)
	{
		sum=0;
		d=1;
		for(j=0;j<5;j++)
		{
			sum=sum+(temp[j]*d);
			d=d*10;
		}
		sum=sum*base1;
		k=sum;
		for(j=0;j<5;j++)
		{
			temp[j]=k%10;
			k=k/10;
		}
		sum=sum/1000;

		if(sum<10)
		Rrem[i]=sum+48;
		else if(sum>=10&&sum<=35)
		Rrem[i]=sum+55;
		else
		Rrem[i]=sum+61;
	}
	return A1;
}
int BASE_10(int L[][50],int R1[][5],int n,int base1)
{
	int A1=0,sum=0,i,j,b[30][50],dec[5][5];
	long int d=1,c;
	double f=1.0;
	float e;
	for(i=n;i>=0;i--)
	{
		c=L[0][49-(n-i)]*d;
		d=d*base1;
		for(j=49;c!=0;j--)
		{
			b[i][j]=c%10;
			c=c/10;
		}
		for( ;j>=0;j--)
		{
			b[i][j]=0;
		}
	}
	for(j=49;j>=0;j--)
	{
		for(i=n;i>=0;i--)
		{
			sum=sum+b[i][j];
		}
		L[2][j]=sum%10;
		sum=sum/10;
	}
	for(i=0;i<50;i++)
	{
		if(L[2][i]==0)
		A1++;
		else
		break;
	}
	for(i=0;i<5;i++)
	{
		f=f/base1;
		e=(float)R1[0][i]*f;
		e=e*100000.00;
		for(j=4;j>=0;j--)
		{
			dec[i][j]=(int)e%10;
			e=e/10;
		}

	 }
	 printf("\n");
	 for(j=4;j>=0;j--)
	 {
		for(i=0;i<5;i++)
		{
			sum=sum+dec[i][j];
		}
		R1[2][j]=sum%10;
		sum=sum/10;
	 }
	return A1;
}
int ADD(int L[][50],int R[][5],int n,int n1,int base1)
{
	int i,j,k,s=0,d=1,sum=0;
	sum=0;
	for(i=4;i>=0;i--)
	{
		for(j=0;j<2;j++)
		{
			sum=sum+R[j][i];
		}
		s=sum%base1;
		if(s<10)
		R[2][i]=s+48;
		else if(s>=10&&s<=35)
		R[2][i]=s+55;
		else
		R[2][i]=s+61;
		sum=sum/base1;
	}
	for(i=49;i>=0;i--)
	{
		for(j=0;j<2;j++)
		{
			sum=sum+L[j][i];
		}
		s=sum%base1;
		if(s<10)
		L[2][i]=s+48;
		else if(s>=10&&s<=35)
		L[2][i]=s+55;
		else
		L[2][i]=s+61;
		sum=sum/base1;
	}
	return 0;
}
int main()
{
	int i,n,n1,j,z,valid,m,l,d,k,k1,sum=0,pro=0,base1,base2,badd1,oper,A1,A2,A3,key,Ldec[2][50],Rdec[2][5],L[4][50],R[4][5],Lrem[50],Rrem[5],b[3][50],div1[50],neg1=0,neg2=0;
	unsigned long div;
	char a;
	//clrscr();
	do
	{
		do
		{
			fflush(stdin);
			printf("Input the number:\n");
			for(i=0;a!='.';i++)
			{
				scanf("%c",&a);
				printf("-%c",a );
				if(a=='-')
				neg1=1;
				else if(a=='\n')
				break;
				else if(a>='0'&&a<='9')
				Ldec[0][i]=a-48;
				else if(a>='A'&& a<='Z')
				Ldec[0][i]=a-55;
				else if(a>='a'&&a<='z')
				Ldec[0][i]=a-61;
			}
			if(a=='\n')
			{
				n=(i-1);
				for(i=0;i<5;i++)
				Rdec[0][i]=0;
			}
			else
			{
				n=(i-2);
				for(i=0;i<5;i++)
				{
					scanf("%c",&a);
					if(a>='0'&&a<='9')
					Rdec[0][i]=a-48;
					else if(a>='A'&& a<='Z')
					Rdec[0][i]=a-55;
					else if(a>='a'&&a<='z')
					Rdec[0][i]=a-61;
					else if(a=='\n')
					break;
				}
				for(;i<5;i++)
				Rdec[0][i]=0;
			}
			//printf("\n%d\n",n);
			for(i=n;i>=0;i--)
			{
				L[0][49-(n-i)]=Ldec[0][i];
			}
			for(i=0;i<(49-n);i++)
			{
				L[0][i]=0;
			}
			for(i=0;i<5;i++)
			{
				R[0][i]=Rdec[0][i];
			}
			printf("in base:  ");
			scanf("%d",&base1);
			valid=VAL(L,R,base1,0);
			if(valid==0)
			printf("INVALID INPUT\n");
		}while(valid==0);
	printf("\nOperation to be done:\n");
	printf("1.Base Conversion to 10\n2.Addition\n3.Subtraction\n");
	printf("4.Multiplication\n5.Division\n6.OR\n7.AND\n");
	printf("8.NOT\n9.10 to other base\n10.From any base to any base\n\n\n Enter the Option: ");
	scanf("%d",&oper);
	if(oper==1)
	{
		A1=BASE_10(L,R,n,base1);
		printf("\nIn base 10 is:\n");
		for(j=A1;j<50;j++)
		{
			printf("%d",L[2][j]);
		}
		printf(".");
		for(j=0;j<5;j++)
		{
			printf("%d",R[2][j]);
		}
		printf("\tin base: %d",10);
	}
	else if(oper==2)
	{
		do
		{
			n1=SEC_INP(L,R,&neg2);
			printf("in Base:\t");
			scanf("%d",&base2);
			valid=VAL(L,R,base2,1);
			if(valid==0)
			printf("INVALID INPUT\n");
		}while(valid==0);
		if(base1==base2)
		{
			if(n>=n1)
			z=n;
			else
			z=n1;
			if((neg1*neg2)==1)
			{
				A1=ADD(L,R,n,n1,base1);
				printf("Sum is:\n-");
			}
			else if((neg1+neg2)==1)
			{
				A1=SUB(L,R,n,n1,base1);
				if((neg1==0&&A1==0)||(neg2==0&&A1==1))
				printf("Sum is:\n");
				else
				printf("Sum is:\n-");
			}
			else
			A1=ADD(L,R,n,n1,base1);
			for(i=(49-z);i<50;i++)
			{
				printf("%c",L[2][i]);
			}
			printf(".");
			for(i=0;i<5;i++)
			{
				printf("%c",R[2][i]);
			}
			printf("\tin base: %d",base2);
		}
		if(base1!=base2)
		{
			A1=BASE_10(L,R,n,base1);
			for(j=0;j<50;j++)
			{
				L[0][j]=L[2][j];
			}
			for(j=0;j<5;j++)
			{
				R[0][j]=R[2][j];
			}
			A2=TEN_BASE(L,R,A1,Lrem,Rrem,base2);
			for(i=A2;i>=0;i--)
			{
				if(Lrem[i]>='0'&&Lrem[i]<='9')
				L[0][49-i]=Lrem[i]-48;
				else if(Lrem[i]>='A'&&Lrem[i]<='Z')
				L[0][49-i]=Lrem[i]-55;
				else
				L[0][49-i]=Lrem[i]-61;
			}
			for(j=0;j<5;j++)
			{
				if(Rrem[j]>='0'&&Rrem[j]<='9')
				R[0][j]=Rrem[j]-48;
				else if(Rrem[j]>='A'&&Rrem[j]<='Z')
				R[0][j]=Rrem[j]-55;
				else
				R[0][j]=Rrem[j]-61;
			}
			for(i=0;i<49-A2;i++)
			L[0][i]=0;
			if(n>=n1)
			z=n;
			else
			z=n1;
			if((neg1*neg2)==1)
			{
				A1=ADD(L,R,n,n1,base1);
				printf("Sum is:\n-");
			}
			else if((neg1+neg2)==1)
			{
				A1=SUB(L,R,n,n1,base1);
				if((neg1==0&&A1==0)||(neg2==0&&A1==1))
				printf("Sum is:\n");
				else
				printf("Sum is:\n-");
			}
			else
			A1=ADD(L,R,n,n1,base1);
			for(i=(49-z);i<50;i++)
			{
				printf("%c",L[2][i]);
			}
			printf(".");
			for(i=0;i<5;i++)
			{
				printf("%c",R[2][i]);
			}
			printf("\tin base: %d",base2);
		}
	}
	else if(oper==3)
	{
		do
		{
			n1=SEC_INP(L,R,&neg2);
			printf("in Base:\t");
			scanf("%d",&base2);
			valid=VAL(L,R,base2,1);
			if(valid==0)
			printf("INVALID INPUT\n");
		}while(valid==0);
		if(base1==base2)
		{
			if(n>=n1)
			z=n;
			else
			z=n1;
			printf("\n\n\nDifference is:\n");
			if((neg1+neg2)==0)
			{
				A1=SUB(L,R,n,n1,base1);
				if(A1==1)
				printf("\n-");
			}
			else if((neg1*neg2)==1)
			{
				A1=SUB(L,R,n,n1,base1);
				if(A1==0)
				printf("-");
			}
			else
			{
				if(neg1==1)
				{
					A1=SUB(L,R,n,n1,base1);
					printf("-");
				}
				else
				A1=ADD(L,R,n,n1,base1);
			}
			for(i=(49-z);i<50;i++)
			{
				printf("%c",L[2][i]);
			}
			printf(".");
			for(i=0;i<5;i++)
			{
				printf("%c",R[2][i]);
			}
			printf("\tin base: %d",base2);
		}
		if(base1!=base2)
		{
			A1=BASE_10(L,R,n,base1);
			for(j=0;j<50;j++)
			{
				L[0][j]=L[2][j];
			}
			for(j=0;j<5;j++)
			{
				R[0][j]=R[2][j];
			}
			A2=TEN_BASE(L,R,A1,Lrem,Rrem,base2);
			for(i=A2;i>=0;i--)
			{
				if(Lrem[i]>='0'&&Lrem[i]<='9')
				L[0][49-i]=Lrem[i]-48;
				else if(Lrem[i]>='A'&&Lrem[i]<='Z')
				L[0][49-i]=Lrem[i]-55;
				else
				L[0][49-i]=Lrem[i]-61;
			}
			for(j=0;j<5;j++)
			{
				if(Rrem[j]>='0'&&Rrem[j]<='9')
				R[0][j]=Rrem[j]-48;
				else if(Rrem[j]>='A'&&Rrem[j]<='Z')
				R[0][j]=Rrem[j]-55;
				else
				R[0][j]=Rrem[j]-61;
			}
			for(i=0;i<49-A2;i++)
			L[0][i]=0;
			if(n>=n1)
			z=n;
			else
			z=n1;
			printf("\n\n\nDifference is:\n");
			if((neg1+neg2)==0)
			{
				A1=SUB(L,R,n,n1,base1);
				if(A1==1)
				printf("\n-");
			}
			else if((neg1*neg2)==1)
			{
				A1=SUB(L,R,n,n1,base1);
				if(A1==0)
				printf("-");
			}
			else
			{
				if(neg1==1)
				{
					A1=SUB(L,R,n,n1,base1);
					printf("-");
				}
				else
				A1=ADD(L,R,n,n1,base1);
			}
			for(i=(49-z);i<50;i++)
			{
				printf("%c",L[2][i]);
			}
			printf(".");
			for(i=0;i<5;i++)
			{
				printf("%c",R[2][i]);
			}
			printf("\tin base: %d",base2);
		}
	}
	else if(oper==4)
	{
		do
		{
			n1=SEC_INP(L,R,&neg2);
			printf("in Base:\t");
			scanf("%d",&base2);
			valid=VAL(L,R,base2,1);
			if(valid==0)
			printf("INVALID INPUT\n");
		}while(valid==0);
		if(base1==base2)
		{
			A1=MUL(L,R,n,n1,base2);
			printf("ans is: \n");
			if((neg1+neg2)==0)
			printf("\n");
			else if((neg1*neg2)==0)
			printf("-");
			for(j=(50-(n+n1+12));j<45;j++)
			{
				if(j==40)
				printf(".");
				printf("%c",L[2][j]);
			}
			printf("\tin base: %d",base2);
		}
		if(base1!=base2)
		{
			A1=BASE_10(L,R,n,base1);
			for(j=0;j<50;j++)
			{
				L[0][j]=L[2][j];
			}
			for(j=0;j<5;j++)
			{
				R[0][j]=R[2][j];
			}
			A2=TEN_BASE(L,R,A1,Lrem,Rrem,base2);
			for(i=A2;i>=50;i--)
			{
				if(Lrem[i]>='0'&&Lrem[i]<='9')
				L[0][49-i]=Lrem[i]-48;
				else if(Lrem[i]>='A'&&Lrem[i]<='Z')
				L[0][49-i]=Lrem[i]-55;
				else
				L[0][49-i]=Lrem[i]-61;
			}
			for(j=0;j<5;j++)
			{
				if(Rrem[j]>='0'&&Rrem[j]<='9')
				R[0][j]=Rrem[j]-48;
				else if(Rrem[j]>='A'&&Rrem[j]<='Z')
				R[0][j]=Rrem[j]-55;
				else
				R[0][j]=Rrem[j]-61;
			}
			for(i=0;i<49-A2;i++)
			L[0][i]=0;
			A3=MUL(L,R,A2,n1,base2);
			printf("ans is: \n");
			if((neg1+neg2)==0)
			printf("\n");
			else if((neg1*neg2)==0)
			printf("-");
			for(j=(50-(n+n1+12));j<45;j++)
			{
				if(j==40)
				printf(".");
				printf("%c",L[2][j]);
			}
			printf("\tin base: %d",base2);
		}
	}
	else if(oper==5)
	{
		if(base1!=10)
		{
			A1=BASE_10(L,R,n,base1);
			n=A1;
			for(j=0;j<50;j++)
			{
				L[0][j]=L[2][j];
			}
			for(j=0;j<5;j++)
			{
				R[0][j]=R[2][j];
			}
		}
		printf("\nTo be divided by(in Base 10):\n");
		scanf("%lu",&div);
		if(neg1==1)
		printf("-");
		A2=DIV(L,R,n,div);
		printf("\tin base: 10");
	}
	else if(oper==6||oper==7)
	{
		do
		{
			n1=SEC_INP(L,R,&neg2);
			printf("in Base:\t");
			scanf("%d",&base2);
			valid=VAL(L,R,base2,1);
			if(valid==0)
			printf("INVALID INPUT\n");
		}while(valid==0);
		if(base1!=10)
		{
			A1=BASE_10(L,R,n,base1);
			n=A1;
			for(j=0;j<50;j++)
			{
				L[0][j]=L[2][j];
			}
			for(j=0;j<5;j++)
			{
				R[0][j]=R[2][j];
			}
		}
		if(base2!=10)
		{
			A1=BASE_10(L,R,n,base2);
			n=A1;
			for(j=0;j<50;j++)
			{
				L[0][j]=L[2][j];
			}
			for(j=0;j<5;j++)
			{
				R[0][j]=R[2][j];
			}
		}
		for(m=0;m<2;m++)
		{
			sum=1;
			for(j=0;sum!=0;j++)
			{
				pro=0;
				sum=0;
				if(m==0)
				l=n;
				else
				l=n1;
				for(i=(49-l);i<50;i++)
				{
					d=(pro*10)+L[m][i];
					pro=d%2;
					div1[i-(49-l)]=d/2;
				}
				b[m][j]=pro+48;
				for(i=0;i<=l;i++)
				{
					L[m][49-l+i]=div1[i];
				}
				for(i=0;i<(49-l);i++)
				{
					L[m][i]=0;
				}
				for(i=0;i<=l;i++)
				{
					sum=sum+div1[i];
				}
			}
			if(m==0)
			k=j-1;
			else
			k1=j-1;
		}
		for(m=0;m<2;m++)
		{
			if(m==0)
			l=k;
			else
			l=k1;
			for(j=l+1;j<50;j++)
			b[m][j]=48;
		}
		if(k1>=k)
		l=k1;
		else
		l=k;
		for(m=0;m<2;m++)
		{
			printf("Input %d in Base 2\n",m+1);
			for(i=l;i>=0;i--)
			{
				printf("%c",b[m][i]);
			}
			printf("\n");
		}
		if(oper==6)
		{
			for(i=l;i>=0;i--)
			{
				if(b[0][i]==48&&b[1][i]==48)
				b[2][i]=48;
				else
				b[2][i]=49;
			}
			printf("OR is:\n");
			for(i=l;i>=0;i--)
			{
				printf("%c",b[2][i]);
			}
		}
		else
		{
			for(i=l;i>=0;i--)
			{
				if(b[0][i]==48||b[1][i]==48)
				b[2][i]=48;
				else
				b[2][i]=49;
			}
			printf("AND is:\n");
			for(i=l;i>=0;i--)
			{
				printf("%c",b[2][i]);
			}
		}
	}
	else if(oper==8)
	{
		if(base1!=10)
		{
			A1=BASE_10(L,R,n,base1);
			for(j=0;j<50;j++)
			{
				L[0][j]=L[2][j];
			}
			for(j=0;j<5;j++)
			{
				R[0][j]=R[2][j];
			}
		}
		else
		A1=n;
		A2=TEN_BASE(L,R,A1,Lrem,Rrem,2);
		for(i=A2;i>=0;i--)
		{
			if(Lrem[i]==48)
			Lrem[i]=49;
			else
			Lrem[i]=48;
		}
		for(j=0;j<5;j++)
		{
			if(Rrem[j]==48)
			Rrem[j]=49;
			else
			Rrem[j]=48;
		}
		 printf("\n\nNOT of Input is:");
		 printf("\n");
		 for(j=A2;j>=0;j--)
		 {
			printf("%c",Lrem[j]);
		 }
	}
	else if(oper==9)
	{
		printf("\nWhich base you want to convert:\n");
		scanf("%d",&base1);
		A1=TEN_BASE(L,R,n,Lrem,Rrem,base1);
		for(i=A1;i>=0;i--)
		{
			printf("%c",Lrem[i]);
		}
		printf(".");
		for(j=0;j<5;j++)
		{
			printf("%c",Rrem[j]);
		}
	}
	else if(oper==10)
	{

		printf("\nWhich base you want to convert:\n");
		scanf("%d",&base1);
		A1=BASE_10(L,R,n,base1);
		for(j=0;j<50;j++)
		{
			L[0][j]=L[2][j];
		}
		for(j=0;j<5;j++)
		{
			R[0][j]=R[2][j];
		}
		A1=TEN_BASE(L,R,n,Lrem,Rrem,base1);
		for(i=A1;i>=0;i--)
		{
			printf("%c",Lrem[i]);
		}
		printf(".");
		for(j=0;j<5;j++)
		{
			printf("%c",Rrem[j]);
		}
		printf("\tin base: %d",base1);

	}
	fflush(stdin);
	printf("\n\n\n\n\nAny Other operation you want to carry out\n Press 1 for YES\n Press 0 for NO\n\n\n\n");
	scanf("%d",&key);
	}while(key==1);

	return 1;
	
	getch();
}
