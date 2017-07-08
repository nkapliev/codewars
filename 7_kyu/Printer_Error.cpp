#include <string>
#include <iostream>

class Printer
{
private:
    static const char limit = 'm';
public:
    static std::string printerError(const std::string &s) {
        int counter = 0;
        for (auto c : s) {
            counter += c > Printer::limit;
        }

        return std::to_string(counter) + "/" + std::to_string(s.length());
    }
};

int main () {
    std::string s;

    std::cout << "s: ";
    std::cin >> s;

    std::cout << Printer::printerError(s) << std::endl;

    return 0;
}
