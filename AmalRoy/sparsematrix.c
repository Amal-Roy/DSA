#include<stdio.h>
int main(){

    int a[10][10],b[10][10],c[10][10],A[10][10],B[10][10];
    int k=0,i,j,row1,col1,row2,col2;
      printf("Enter number of rows and columns of 1st matrix: ");
      scanf("%d%d", &row1, &col1);

    printf("Enter the matrix elements of 1st matrix:\n");
    for(i = 1;i<=row1; i++) {
        for(j = 1; j<=col1; j++) {
            scanf("%d",&a[i][j]);
            if(a[i][j] != 0) {
            k++;
                A[k][1] = i;
                A[k][2] = j;
                A[k][3] = a[i][j];
                
            }
        }
    }
    int tt=k;
      k=0;
     printf("Enter number of rows and columns of 2nd matrix: ");
     scanf("%d%d", &row2, &col2);
   
    printf("Enter the matrix elements of 2nd matrix:\n");
    for(i=1;i<=row2;i++) {
        for(j = 1;j<=col2; j++) {
            scanf("%d",&b[i][j]);
            if(b[i][j] != 0) {
                k++;
                B[k][1] = i;
                B[k][2] = j;
                B[k][3] =b[i][j];
                
             }   
            }
        }
      int pp=k;
      printf("The sparse matrix of 1st matrix:\n");
      printf("Row\t Column\t Value\t\n");
      int v=0;
      for(i=1;i<=tt;i++)
      {
         v++;
         printf("%d\t%d\t%d\t\n",A[v][1],A[v][2],A[v][3]);
      }
      
      printf("The sparse matrix of 2nd matrix:\n");
      printf("Row\t Column\t Value\t\n");
       v=0;
      for(i=1;i<=pp;i++)
      {
         v++;
         printf("%d\t%d\t%d\t\n",B[v][1],B[v][2],B[v][3]);
      }
      return 0;
     }
     
    
