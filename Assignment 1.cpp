#include <bits/stdc++.h>
using namespace std;
#include <time.h>
#define billion  1000000000.0
long long int arr_memo[101];

//for only recursion
long long int recursion (long long int x){

    if (x==0) return 1;
    else {
      return x*recursion(x-1);
    }
}



//for only loop
void loop (long long int x){

    long long int k=1;
    while (x!=0){
        k*=x;
        x=x-1;
    }
}




//for recursion and memoization
 long long int recursion_memoization (long long int x){

    if (x==0) return 1;
    else if (arr_memo[x]!=-1) return arr_memo[x];
    else {
      arr_memo[x]= x*recursion_memoization(x-1);
      return arr_memo[x];
    }
}


// for loop memoization
void loop_memoization (long long int x){

  long long int k=1;
  for(int i=x;i>0;i--){
    if (arr_memo[i]!=-1) {
        k*=arr_memo[i];
        break;
    }
    else{
      k*=i;
  }
}
  arr_memo[x]=k;
}







int main(){

    struct timespec start,end;
    ios_base::sync_with_stdio(false);

    int n=0;
    long long flag=0;
    double t;
    cout<<"1. Recursion"<<endl<<"2. Loop"<<endl<<"3. Recusrsion and Memoization"<<endl<<"4. Loop and Memoization"<<endl;
    cout<<"Enter the number accordingly to check time for execution ";
    cin>>n;


    //for only recursion


    if(n==1){
        clock_gettime(CLOCK_REALTIME, &start);
        for(int i=1;i<=100;i++){
            flag=recursion(i);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        t= (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/billion ;
        cout<<"Time: "<<t<<endl;
    }



   //for only loop




    else if(n==2){
        clock_gettime(CLOCK_REALTIME, &start);
        for(int i=1;i<=100;i++){
            loop(i);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        t= (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/billion ;
        cout<<"Time: "<<t<<endl;

    }



  //for recursion and memoization




    else if(n==3){
        for(int i=0;i<=100;i++) arr_memo[i]=-1;
        clock_gettime(CLOCK_REALTIME, &start);
        for(int i=0;i<=100;i++){
            flag=recursion_memoization(i);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        t= (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/billion ;
        cout<<"Time: "<<t<<endl;
    }




  //for loop and memoization




    else if(n==4){
        for(int i=0;i<=100;i++) arr_memo[i]=-1;
        clock_gettime(CLOCK_REALTIME, &start);
        for(int i=1;i<=100;i++){
            loop_memoization(i);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        t= (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/billion ;
        cout<<"Time: "<<t<<endl;}



    return 0;


}

