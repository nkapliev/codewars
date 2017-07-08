#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define BLACK "□"
#define WHITE "■"

string print_2d_vector(vector<vector<bool>> arr) {
    stringstream ss;

    for (int row = 0, len = arr.size(); row < len; row++) {
        for (int col = 0, len = arr[row].size(); col < len; col++) {
            ss << (arr[row][col] ? WHITE : BLACK);
        }
        if (row < len - 1) ss << "\n";
    }

    return ss.str();
}

string zoom(int n) {
    u_int deep = (u_int) n;
    vector<vector<bool>> cube(deep, vector<bool>(deep, true));
    u_int layers_number = (deep - 1) / 2;

    for (u_int layer = 1, size = 3; layer <= layers_number; layer += 2, size += 4) {
        for (u_int row = layers_number - layer, col = row; col < row + size; col++) cube[row][col] = false;
        for (u_int col = layers_number - layer, row = col; row < col + size; row++) cube[row][col] = false;

        for (u_int row = layers_number + layer, col = row; col > row - size + 1; col--) cube[row][col] = false;
        for (u_int col = layers_number + layer, row = col; row > col - size + 1; row--) cube[row][col] = false;
    }

    return print_2d_vector(cube);
}

int main () {
    int n;

    cin >> n;
    cout << zoom(n) << endl;

    return 0;
}
