#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

int main(){
  int arr[size] = {0};
  int sim[size] = {0};
  int maxSimSize=0;
  int maxSimNum=0;
  int count=0;

  //random seed
  srand(time(NULL));

  //make random number array
  for(int i=0; i<size; i++){
    arr[i] = rand()%10+1;
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  //check similarity
  for(int i=0; i<size-1; i++){
    if(sim[i]!=0){continue;}
    for(int j=i+1; j<size; j++){
      if(arr[i]==arr[j]){
        sim[j]=arr[i];
        count++;
      }
    }
    if(maxSimSize<count+1){
      maxSimSize=count+1;
      maxSimNum=arr[i];
    }
    count=0;
  }

  //print similarity array
  printf("\n");
  for(int i=0; i<size; i++){
    printf("sim[%d] = %d\n", i, sim[i]);
  }

  //print result
  printf("\nmax similarity size = %d, that number = %d\n", maxSimSize, maxSimNum);
  
  return 0;
}