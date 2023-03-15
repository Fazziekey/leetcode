#include <cassert>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <array>


// This is the class you need to implement! Feel free to add members, private methods etc, but don't change the public
// method signatures.
class RiskLimitProcessor
{
    public:
        void AddLimit(const std::string& instrument, double maxValue, int maxVolume10Seconds, double maxValue1Second)
        {
            std::cout << "LIMIT" << " " << instrument << " " << maxValue << " " << maxVolume10Seconds << " " << maxValue1Second << std::endl;
        }

        void ProcessOrder(const std::string& instrument, uint64_t timestamp, int volume, double price)
        {
            std::cout << "ORDER" << " " << instrument << " " << timestamp << " " << volume << " " << price << std::endl;
        }
};

int main()
{
    RiskLimitProcessor riskLimitProcessor;
    while(!std::cin.eof())
    {
        std::string action, instrument;
        std::cin >> action >> instrument;
        if (action.empty())
            break; // handle whitespace at end of input
        if (action == "LIMIT")
        {
            double maxValue;
            int maxVolume10Seconds;
            double maxValue1Second;
            std::cin >> maxValue >> maxVolume10Seconds >> maxValue1Second;
            riskLimitProcessor.AddLimit(instrument, maxValue, maxVolume10Seconds, maxValue1Second);
        }
        else if (action == "ORDER")
        {
            uint64_t timestamp;
            int volume;
            double price;
            std::cin >> timestamp >> volume >> price;
            riskLimitProcessor.ProcessOrder(instrument, timestamp, volume, price);
        }
        else
        {
            std::cerr << "Malformed input!\n";
            return -1;
        }
    }
    return 0;
}