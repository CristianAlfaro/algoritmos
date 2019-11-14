#include <iostream>
#include <string>
using namespace std;

struct activity
{
    int start;
    int finish;
};

activity jobs[11]={{0,6},{1,4},{2,13},{3,5},{3,8},{5,7},{5,9},{6,10},{8,11},{8,12},{12,14}};

int main(){
    int L[] = {0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 11; i++){
        for(int j = 0; j < i; j++){
            if (jobs[j].finish < jobs[i].start && L[i] < L[j]){
                L[i] = L[j];
            }
        }
        L[i]++;
    }
}