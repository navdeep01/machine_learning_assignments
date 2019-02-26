/*
Find-S concept learning algorithm that finds the most specific hypothesis
 that is consistent with the given training data.
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int i,j=0,k=0,flag=0,count=0,n=0;
	char buf[18];
	char hypothesis[8];

	FILE *fp;
	fp=fopen(argv[1],"r");

// initialize hypothesis to most specific
	while(flag==0 && count!=21)
	{

		fgets(buf,20,fp);
		if(buf[16]=='1')        //put first row with positive output
		{
			flag=1;
			for(i=0;i<17;i=i+2)
			{
				hypothesis[j]=buf[i];
				j++;
			}


		}
		fseek( fp,k, SEEK_SET);
	        k=k+19;
		count++;
	}
//minimally generalize hypothesis in each positive data set
	while(count!=21)
	{
		n=0;
		j=0;
		fgets(buf,18,fp);

		if(buf[16]=='1')
		{
			for(i=0;i<17;i=i+2)
			{
				if(hypothesis[j]!=buf[i])
					hypothesis[j]='*';
				else
					n=n+1;
				j++;
			}
		}


		fseek( fp,k, SEEK_SET);
		k=k+19;
		count++;
	}
	printf("%d, ",n);    //print no. of features affecting output
	for(i=0;i<8;i++)
	{
		if(hypothesis[i]=='1')
			printf("%d, ",i+1);
		else if(hypothesis[i]=='0')
			printf("%d, ",-(i+1));
	}
	fclose(fp);
	return 0;
}


