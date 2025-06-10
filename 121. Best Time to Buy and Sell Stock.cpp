class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int minsofar = prices[0];
       int maxprofit = 0;
       for(int i = 0; i<n;i++)
         {
            if(prices[i] < minsofar)
                  minsofar = prices[i];
            else 
              {
                 if((prices[i]- minsofar)>maxprofit)
                    maxprofit = (prices[i]- minsofar);
              }
         } 
        return maxprofit;
    }
};