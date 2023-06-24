#include<stdio.h>


struct  stock {
    float open[7] ; 
    float close[7] ; 
    float high[7];
    float low[7] ; 
    float volume[7];
    char name[10];
    
};

 
void q1(struct stock arr[], int days , int i, int n) {
    float percent = 1.0*(arr[i].close[days-1] - arr[i].close[0])/arr[0].close[0];
    if(percent >= 0)
    {
        printf("The increment in %s is %f\n",arr[i].name,percent*100);
    }
    else
    {
        printf("The decrement in %s %f",arr[i].name,percent*100*(-1));
    }
}
void q2(struct stock arr[] ,int k , int n)
{
    int min_ind;
    int a[n];
    for(int i =0 ; i<n ; i++)
    {
        a[i] = arr[i].volume[k];
    }
     for (int i = 0; i < n-1 ; i++)
    {
       
       
        min_ind = i;
        for (int j = i+1; j <n ; j++)
        if (arr[j].volume[k] < arr[min_ind].volume[k]){
            min_ind = j;
        }
        for(int x =0 ; x<n ; x++)
        {
            if(a[min_ind] == arr[x].volume[k])
            {
                printf("%s -> %f\n",arr[x].name, arr[x].volume[k]);
                break;
            }
        }float temp = a[min_ind];
        a[min_ind] = a[i];
        a[i] = temp;
      
    }
    int maximum =0 ;
    for(int x =0 ; x<n ; x++){
     if(a[x] > a[maximum])
     {
         maximum = x; 
     }
    }
   printf(" %s-> %f\n",arr[maximum].name, arr[n-1].volume[k]);
    
}

void q3(struct stock arr[], int dayp , int dayb, int n,int i) {
    float ans = 1.0*(arr[i].high[dayb-1] -  arr[i].low[dayp-1])/arr[i].low[dayp-1];
    if( ans > 0) {
        printf(" The profit is %.2f of stock %s\n", ans*100,arr[i].name);
    }
    else {
        printf(" The loss is %.2f of stock is %s\n", ans*100 , arr[i].name);
    }
    
}
void q4(struct stock arr[] , int n , int days)
{
    float max = 0;
    float min = 100000.0;
    float maxi[n];
    
    int index =0 ;
    for(int j = 0; j<n ; j++){
        max= 0 ;
        min = 100000;
    for(int i = 0;  i<days ; i++)
    {
        if(arr[j].high[i] > max)
        {
            max = arr[j].high[i];
        }
        if(arr[j].low[i] < min)
        {
            min = arr[i].low[i];
        }
    }
    maxi[j]=(max - min)*(1.0)/min;
    }
    max =0 ;
    for( int i = 0 ; i<n ; i++)
    {
        if(max < maxi[i])
        {
            max = maxi[i];
            index=i;
        } 
      
    }
    printf("The higest performing task is %s whose profit is %f",arr[index].name , max*100);
}
void q5(struct stock arr[] , int n , int days)
{
    float max = 0;
    float min = 100000.0;

    float mini[n];
    int index =0 ;
    for(int j = 0; j<n ; j++){
        max= 0 ;
        min = 100000;
    for(int i = 0;  i<days ; i++)
    {
        if(arr[j].high[i] < min)
        {
            min = arr[j].high[i];
        }
        if(arr[j].low[i] > max)
        {
            max = arr[j].low[i];
        }
    }
    mini[j]=(min - max)*(1.0)/max;
    }
    min =100000 ;
    for( int i = 0 ; i<n ; i++)
    {
        if(min > mini[i])
        {
            min = mini[i];
            index=i;
        }
    }
    printf("The leastt performing task is %s whose profit is %f",arr[index].name , min*100);
}
void q6(struct stock arr[] , int start , int end , int n)
{
    float perform[n];
    float delta =0 ;
     int a[n];
     
       for(int i =0 ; i<n;  i++)
       {
           a[i] = perform[i];
       }
    for(int i =0 ; i<n ; i++)
    {   delta =0 ;
        for(int j = start-1 ; j< end-1 ; j++ )
        {
            delta = (1.0)*(arr[i].close[j+1] - arr[i].close[j]);
        }
        perform[i] = delta;
    }

        int i, j, min_ind;
        for ( i = 0; i < n-1 ; i++)
    {
        min_ind = i;
        for (j = i+1; j <n ; j++){
        if (perform[j] < perform[min_ind]){
            min_ind = j;
        }
        }
      
        for(int x =0 ; x<n ; x++)
        {
            if(a[x] == perform[min_ind])
            {
                printf("%s -> %f\n",arr[x].name , perform[min_ind]);
                break;
            }
        }float temp = perform[min_ind];
        perform[min_ind] = perform[i];
        perform[i] = temp;
      
    }
    int maximum =0 ;
    for(int x =0 ; x<n ; x++){
     if(a[x] > a[maximum])
     {
         maximum = x; 
     }
    }
   printf(" %s-> %f\n",arr[maximum].name, perform[n-1]);
    
}



void q7(struct stock arr[], int day, int n) {
    float num = 0, den=0;
    int i;
      for(i=0; i<n; i++) {
      num = (num + arr[i].close[day-1]*arr[i].volume[day-1])*1.0;
      
  }
  for(i=0; i < n; i++) {
      den = (den + arr[i].volume[day-1])*1.0;
  }
  float avg = num/den*1.0;
  printf("the average value is %f\n", avg);
    
}


int main() {
    int n;
    printf(" Enter the number of stocks");
    scanf("%d", &n);
    int days;
    printf(" Enter the number of days");
    scanf("%d", &days);
    int i;
    int j =0 ;
 
     struct stock arr[n] ;
        for(int i =0 ; i<n ; i++)
    {   printf("enter the name of stock\n");
        scanf("%s",arr[i].name);
        }
        for( i = 0; i < n; i++) {
        printf(" Enter the details of  %d stock\n", i+1);
      for(j =0 ; j<days ; j++){
            printf(" Enter the opening price of %d day\n", j+1);
            scanf("%f", &arr[i].open[j]);
              printf(" Enter the closing price of %d day\n", j+1);
            scanf("%f", &arr[i].close[j]);
              printf(" Enter the high price of %d day\n", j+1);
            scanf("%f", &arr[i].high[j]);
              printf(" Enter the low price of %d day\n", j+1);
            scanf("%f", &arr[i].low[j]);
              printf(" Enter the volume of %d day\n", j+1);
            scanf("%f", &arr[i].volume[j]);
      }
    }
     printf("Enter the NUmber\n");
    printf("1) Increment and Decrement of stock\n");
    printf("2) Sorting the Stock on the basis of Volume\n");
    printf("3) find the profit and Loss of Two or more stock\n");
    printf("4) find highest Performing stock for a specific Duration\n");
    printf("5) find lowest Performing stock for a specific Duration\n");
    printf("6) Overall Performance of Stock\n");
    printf("7) find the average value of stock\n");
    int num;
    scanf("%d",&num);
    switch(num){
  //q1

     case 1 :
    for(i = 0 ; i<n ; i++)
    {
        q1(arr, days , i , n);
           
    }printf("\n");
    break;
    //q2

    case 2:
    int k =0 ;
    printf("enter the day ");
    scanf("%d",&k);
    q2(arr, k-1 , n);
    break;

     case 3:
     int dayp, dayb;
    printf(" ENter the day of stock purchase and sold");
        scanf("%d", &dayp);
    scanf(" %d", &dayb);
 // q3
    for( i = 0; i < n; i++) {
        q3(arr,dayp,dayb,n,i);
        printf("\n");
    }
    break;
 //  q4

 case 4:
  q4(arr , n , days);
  break;
  // q5
   case 5:
  q5(arr, n, days);
  break;
//  q6
  case 6:
  printf("enter the starting date and closing date\n");
 int start , end;
 scanf("%d",&start);
 scanf("%d",&end);
  q6(arr, start , end , n);
  break;

  case 7:
 int day;
    printf(" Enter the day");
    scanf(" %d", &day);
 q7(arr,day,n);
 break;
  return 0;
    }
}
