#include <stdio.h>

int main(){
int arr[20];
int limit;
printf("Enter the n terms:");
scanf("%d",&limit);
printf("Enter the numbers");
for (int i=0;i<limit;i++)
{
    scanf("%d",&arr[i]);
}
int temp;
for(int i=0;i<limit;i++)
{
   for(int j=i+1;j<limit;j++){
   if(arr[j]<arr[i]){
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   }
   }
}

for(int i=0;i<limit;i++)
{
printf("%d ",arr[i]);
}

return 0;
}
