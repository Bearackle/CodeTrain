#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
        vector<int> citations = {3,0,6,1,5};
        sort(citations.begin(), citations.end());
        int h_index = 0;
        int size = citations.size();
        for(int i = 0 ; i < size ; i++){
             if(citations[i] >= (size - i)){
                h_index = size - i;
                break;
             }
        }
        cout<<h_index;
}