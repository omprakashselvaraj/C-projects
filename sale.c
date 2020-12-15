#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
float max,min,esum,sr,srd,fvar,ey,eey;
struct apple
{
	int year;
	float sale;
}a[13];
FILE *fp;
void input(void);
void analysis(void);
int stat(void);
int prediction(void);
void predict(void);
void mean(void);
void median(void);
void mode(void);
void sd(void);
void range(void);
int main()
{
int m;
printf("\n\t\t\t\t *********************************************************");
printf("\n\t\t\t\t *iPHONE SALE DATA ANALYSIS USING BASIC STATISTICS METHOD*");
printf("\n\t\t\t\t *********************************************************");
printf("\n\t\t\t\t PRESS ENTER TO PROCEED");
if(getch()==13)
{
	goto X;
}
X:
printf(" \n\t\t\t\t SELECT YOUR OPTION\n\t\t\t\t 1.INPUT DATA\n\t\t\t\t 2.SIMPLE ANALYSIS \n\t\t\t\t 3.STATISTICS CALCULATION \n\t\t\t\t 4.STATISTICAL PREDICTION  \n\t\t\t\t 5.EXIT");
printf("\n\t\t\t\t ENTER YOUR OPTION TO PROCEED");
scanf("%d",&m);
switch(m)
{
case 1:
input();
goto X;
break;
case 2: 
analysis();
goto X;
break;
case 3:
stat();
goto X;
break;
case 4:
prediction();
goto X;
case 5:
return 0;
break;
default: printf("\n\n\t\t\t\tNO MATCH FOUND");
printf("\n\n\t\t\t\tPress Enter to re-Enter the choice");
if(getch()==13)
{
goto X;
}

}
}
void input()
{
	FILE *fp;
	int i;
	fp=fopen("phone.txt","w+");
	if(fp==NULL)
	{
		printf("\n\t\t\t\t error!!! FILE CANNOT FOUND");
	}
	for(i=0;i<13;i++)
	{
		struct apple a[i];		
		printf("\n\t\t\t\t ENTER YEAR:");
		scanf("%d",&a[i].year);
		printf("\n\t\t\t\t ENTER NO OF UNIT SOLD IN MILLIONS:");
		scanf("%f",&a[i].sale);
		fprintf(fp, "\n%d \t%f",a[i].year,a[i].sale); 
    }
	fclose(fp);
}
int stat()
{
	int o;
   A:
   printf("\n\t\t\t\t SELECT YOUR OPTION:\n\t\t\t\t 1.MEAN\n\t\t\t\t 2.MEDIAN\n\t\t\t\t 3.MODE\n\t\t\t\t 4.STANDARD DEVIATION AND VARIANCE\n\t\t\t\t 5.RANGE\n\t\t\t\t 6.EXIT");
   printf("\n\t\t\t\t ENTER YOUR OPTION");
   scanf("%d",&o);
   switch(o)
   {
      case 1:
	  mean();
	  goto A;
	  break;
	  case 2:
	  median();
	  goto A;
	  break;
	  case 3:
	  mode();
	  goto A;
	  break;
	  case 4:
	  sd();
	  goto A;
	  break;
	  case 5:
	  range();
	  goto A;
	  break;
	  case 6:
	  return 0;
	  break;
	  default: printf("\n\n\t\t\t\t NO MATCH FOUND");
printf("\n\n\t\t\t\tPress Enter to re-Enter the choice");
if(getch()==13)
{
goto A;
}
}	
}
void mean()
{
	int k;
	float sum=0,avg;
	FILE *fp;
	fp=fopen("phone.txt","rb");
	for(k=0;k<13;k++)
	{
		fscanf(fp, "\n%d \t%f",&a[k].year,&a[k].sale);
		sum=sum+a[k].sale;
	}
	avg=sum/13;
	printf("\n\t\t\t\t THE MEAN OF THE DATA: %f",avg);
	fclose(fp);
}
void median()
{
	int l,g;
	struct apple tem;
	FILE *fp;
  	fp=fopen("phone.txt","rb");
	for(l=0;l<13;l++)
	{
		fscanf(fp, "\n%d \t%f",&a[l].year,&a[l].sale);
	}
	for (l=0;l<12;l++)
    {
        for (g=0;g<12-l;g++)
        {
            if (a[g].sale<a[g + 1].sale)
            {
                tem=a[g];
                a[g]=a[g+1];
                a[g+1]=tem;
            } 
        }
    }
    printf("\n\t\t\t\t THE MEDIAN OF DATA IS %f",a[6].sale);
	fclose(fp);
}
void mode()
{
	int p,q,f;
	float mo[5];
	struct apple temp;
	FILE *fp;
	fp=fopen("phone.txt","rb");
	for(p=0;p<13;p++)
	{
		fscanf(fp, "\n%d \t%f",&a[p].year,&a[p].sale);
	}
	for (p=0;p<12;p++)
    {
        for (q=0;q<12-p;q++)
        {
            if (a[q].sale<a[q + 1].sale)
            {
                temp=a[q];
                a[q]=a[q+1];
                a[q+1] = temp;
            } 
        }
    }
    f=0;
    for (p=0;p<13;p++)
    {
    if(a[p].sale==a[p+1].sale)
    {
    	a[p].sale=mo[f];
    	f++;
	}
}
   if(f==0)
   printf("\n\t\t\t\t NO MODE");
   fclose(fp);
}
void range()
{
	FILE *fp;
	fp=fopen("phone.txt","rb");
	int t;
	for(t=0;t<13;t++)
	{
		fscanf(fp, "\n%d \t%f",&a[t].year,&a[t].sale);
	}
	max=a[0].sale;
	min=a[0].sale;
	for(t=1;t<13;t++)
	{
		if(a[t].sale>max)
        {
            max=a[t].sale;
        }

        if(a[t].sale<min)
        {
            min=a[t].sale;
        }
	}
    printf("\n\t\t\t\t MAXIMUM UNIT SALED= %f", max);
    printf("\n\t\t\t\t MINIMUM UNIT SALED= %f", min);
    printf("\n\t\t\t\t THE iPHONE SALE IS THE RANGE FROM %f TO %f",min,max);
   fclose(fp);
}
void sd(void)
{
	FILE *fp;
  	fp=fopen("phone.txt","rb");
	int e;
	ey=0;
	esum=0;
	for(e=0;e<13;e++)
	{
		fscanf(fp, "\n%d \t%f",&a[e].year,&a[e].sale);
	}
	for(e=0;e<13;e++)
	{
		ey=ey+a[e].sale;
	}
	eey=(ey/13);
	for(e=0;e<13;e++)
	{
		esum=esum+((a[e].sale-eey)*(a[e].sale-eey));
	}
	sr=(esum/12);
	srd=sqrt(sr);
	fvar=(srd*srd);
	printf("\n\t\t\t\t THE STANDARD DEVIATION OF THE DATA IS %f",srd);
	printf("\n\t\t\t\t THE VARIANCE OF THE DATA IS %f",fvar);
}
int prediction()
{
	int d;
	O:
	printf("\n\t\t\t\t SELECT YOUR OPTION TO PROCEED");
	printf("\n\t\t\t\t 1.SIMPLE LINEAR REGRESSION\n\t\t\t\t 2.EXIT");
	scanf("%d",&d);
	switch(d)
	{
	
	case 1:
	predict();
	goto O;
	break;
	case 2:
	return 0;
	break;
	default: printf("\n\n\t\t\t\tNO MATCH FOUND");
printf("\n\n\t\t\t\tPress Enter to re-Enter the choice");
if(getch()==13)
{
goto O;
}
}  
}
void predict()
{
  	FILE *fp;
	fp=fopen("phone.txt","rb");
	int r,sumX=0,sumX2=0,x;
	float sumY=0.0,sumXY=0.0,y,b,a1;
	for(r=0;r<13;r++)
	{
		fscanf(fp, "\n%d \t%f",&a[r].year,&a[r].sale);
	}
for(r=0;r<13;r++)
 {
  sumX=sumX+a[r].year;
  sumX2=sumX2+a[r].year*a[r].year;
  sumY=sumY+a[r].sale;
  sumXY=sumXY+a[r].year*a[r].sale;
 }
 b=(13*sumXY-sumX*sumY)/(13*sumX2-sumX*sumX);
 a1=(sumY-b*sumX)/13;
 printf("\n\t\t\t\t ENTER THE UPCOMING YEAR TO PREDICT:");
 scanf("%d",&x);
 y=a1+b*x;
 printf("\n\t\t\t\t THE PREDICTED SALE UNITS IN YEAR %d = %f",x,y);
 fclose(fp);
}
void analysis()
{
	int u,v;
	struct apple t;
	FILE *fp;
	fp=fopen("phone.txt","rb");
	for(u=0;u<13;u++)
	{
		fscanf(fp, "\n%d \t%f",&a[u].year,&a[u].sale);
	}
	for(u=0;u<12;u++)
    {
        for(v=0;v<12-u;v++)
        {
            if (a[v].sale<a[v+1].sale)
            {
                t=a[v];
                a[v]=a[v+1];
                a[v+1]=t;
            } 
        }
    }
    printf("\n\t\t\t\t YEAR\t NO OF UNITS SALE IN MILLION");
    for(u=0;u<13;u++)
    {
    	printf("\n\t\t\t\t %d\t%f",a[u].year,a[u].sale);
	}
}




