#include <stdio.h>
struct std
  {
    char name[180];
    int mark[200];
    int total;
  }p[100];
void main()
{
  int i,j,m,n;
  printf("enter number of students  and number of subjects\n");
  scanf("%d %d",&m,&n);
   for(i=0;i<m;i++)
  {
     p[i].total=0;
     printf("enter name and marks of %d subjects of student %d\n",n,i+1);


     scanf("%s",p[i].name);


     for(j=0;j<n;j++)


     {


       scanf("%d",&(p[i].mark[j]));


      p[i].total=p[i].total+p[i].mark[j];



     }


    }


   for(i=0;i<m;i++)


  {


     printf("details of student %d\n",i+1);


     puts(p[i].name);


     printf("%d\n\n",p[i].total);


   }


}
