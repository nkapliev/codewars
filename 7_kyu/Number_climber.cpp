#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> climb(int n)
{
    vector<int> res = vector<int>({1});

    if (n > 1) {
        int highest_bit = (int) log2(n);
        int pow_of_2 = (int) pow(2, highest_bit);
        int current = 1;

        while (current != n) {
            current <<= 1;
            pow_of_2 >>= 1;
            current += (n & pow_of_2) ? 1 : 0;
            res.push_back(current);
        }
    }

    return res;
}

int main() {
    int n = 0;
    vector<int> result;

    cout << "n: ";
    cin >> n;

    result = climb(n);

    for (auto item : result) {
        cout << item << " ";
    }

    cout << endl;

    return 0;
}
