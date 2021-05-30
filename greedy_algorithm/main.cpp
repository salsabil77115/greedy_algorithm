#include <bits/stdc++.h>
using namespace std;

class items{

public:

int value;
int weight;

   items(int value, int weight)
    {
       this->value=value;
       this->weight=weight;
    }
};
  bool sorting(items a,items b){
    double x=(double)a.value/(double)a.weight;
    double y=(double)b.value/(double)b.weight;

    return x>y;
    }
double calc(int capacity, items arr[], int n)
{
    double totalValue=0.0;
   int  totalWeight=0;

    sort(arr, arr + n, sorting);

    for(int i=0;i<n;i++){

        if(arr[i].weight+totalWeight<=capacity){
            totalValue+=arr[i].value;
            totalWeight+=arr[i].weight;

        }else{
        double diff=capacity-totalWeight;
        totalValue+=arr[i].value*((double)diff/ (double)arr[i].weight);
        }

    }


    return totalValue;
    }
int main()
{
   int capacity= 50;
    items arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value we can obtain = "
         << calc(capacity, arr, n);



    return 0;
}
