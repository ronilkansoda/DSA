#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // char str[10];

    // cout << "Enter char array : ";
    // // cin.getline(str, 100, '$');
    // cin.getline(str, 10);

    // for (char c : str)
    // {
    //     cout << c << " ";
    // }
    // cout << endl;

    string str = "ronil Kansoda"; // dynamic => runtime resize

    str = "omil kansoda";

    getline(cin, str);

    cout << "Output : " << str << endl;

    reverse(str.begin(), str.end()); // iterators 
    cout << "reverse : " << str << endl;

    return 0;
}