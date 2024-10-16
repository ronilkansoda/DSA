#include <iostream>
#include <vector>
using namespace std;

int buySell(vector<int> prices)
{
    int n = prices.size();

    int bestBuy = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > bestBuy)
        {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }

    return maxProfit;
}

int main()
{
    vector<int> arr = {7,6,4,3,1};

    int result = buySell(arr);

    cout << "Max Profit : " << result << endl;
    return 0;
}