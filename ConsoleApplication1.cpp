#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>

using namespace std;

void calculate_net_profit(int* gains, int* prices, int* net_profits, int length)
{
    for (int i = 0; i < length; i++)
    {
        net_profits[i] = gains[i] - prices[i];
        cout << "Net profit from " << i + 1 << " laptop: " << net_profits[i] << endl;
    }
    cout << "\n";
}

void print_array(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
        cout << "\n";
    }
    cout << endl;
}

int main()
{
    // Entering data    
    int start_capital_C;
    cout << "Enter initial capital C: ";
    cin >> start_capital_C;

    int max_number_N;
    cout << "Enter the maximum number of laptops N: ";
    cin >> max_number_N;

    int will_profit;
    cout << "Enter the number of laptops in the list: ";
    cin >> will_profit;

    int* gains = new int[will_profit];
    int* prices = new int[will_profit];
    int* net_profits = new int[will_profit];

    for (int i = 0; i < will_profit; i++)
    {
        cout << "Enter the expected profit after selling " << i + 1 << " laptop: ";
        cin >> gains[i];
    }
    cout << "\n";

    for (int i = 0; i < will_profit; i++)
    {
        cout << "Enter price " << i + 1 << " laptop: ";
        cin >> prices[i];
    }
    cout << "\n";

    calculate_net_profit(gains, prices, net_profits, will_profit);

    //Sorting net profit
    sort(net_profits, net_profits + will_profit, greater<int>());

    cout << "Net profit after sorting: ";
    print_array(net_profits, will_profit);

    int now_capital = start_capital_C;
    int laptops_bought = 0;

    for (int i = 0; i < will_profit && laptops_bought < max_number_N; i++)
    {
        if (prices[i] < now_capital)
        {
            now_capital += net_profits[i];
            laptops_bought++;
        }
    }

    cout << "Final capital after summer: " << now_capital << endl;

    delete[] gains;
    delete[] prices;
    delete[] net_profits;

    return 0;
}