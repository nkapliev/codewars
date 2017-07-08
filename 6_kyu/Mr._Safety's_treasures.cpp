#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char,char> nokia_keys ({
                                             {'a','2'},{'b','2'},{'c','2'},
                                             {'d','3'},{'e','3'},{'f','3'},
                                             {'g','4'},{'h','4'},{'i','4'},
                                             {'j','5'},{'k','5'},{'l','5'},
                                             {'m','6'},{'n','6'},{'o','6'},
                                             {'p','7'},{'q','7'},{'r','7'},{'s','7'},
                                             {'t','8'},{'u','8'},{'v','8'},
                                             {'w','9'},{'x','9'},{'y','9'},{'z','9'}
                                     });


string unlock (string str)
{
    string code;
    for (char c : str) {
        code.push_back(nokia_keys.at((const char &) tolower(c)));
    }
    return code;
}

int main () {
    string msg;

    cin >> msg;
    cout << unlock(msg) << endl;

    return 0;
}
