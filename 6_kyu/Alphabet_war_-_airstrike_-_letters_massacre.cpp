#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

char BOMB = '*';
string LEFT = "Left side wins!";
string RIGHT = "Right side wins!";
string NO_ONE = "Let's fight again!";

unordered_map<char,short> fighters ( {{'w',4},
                                      {'p',3},
                                      {'b',2},
                                      {'s',1},
                                      {'m',-4},
                                      {'q',-3},
                                      {'d',-2},
                                      {'z',-1}} );

inline void update_counter(char & c, long * counter) {
    *counter += fighters.count(c) ? fighters.at(c) : 0;
}

string alphabetWar(string fight)
{
    string *result = &NO_ONE;

    long counter = 0;
    const u_long len = fight.length();

    if (len == 0) {
        update_counter(fight[0], &counter);
    } else {
        u_long i = 0;
        while (i < len - 1) {
            if (fight[i] == BOMB or fight[i + 1] == BOMB) {
                while (fight[++i] == BOMB) {}
            } else {
                update_counter(fight[i], &counter);
            }
            i++;

            cout << i << fight[i] << counter << endl;
        }

        if (fight[len - 2] != BOMB) {
            update_counter(fight.back(), &counter);
        }
    }

    if (counter > 0)
        result = &LEFT;
    else if (counter < 0)
        result = &RIGHT;

    return *result;
}

int main () {
    string in;

    cin >> in;
    cout << alphabetWar(in) << endl;

    return 0;
}
