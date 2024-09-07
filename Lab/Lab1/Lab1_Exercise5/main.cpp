/*#include <iostream>
 *#include <algorithm>
 *#include <vector>
 *
 *using namespace std;
 *
 *bool is_negative(int value) { return value < 0; }
 *int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(2);

    // replace all 0s with 1s
    replace(v.begin(), v.end(), 0, 1);

    // count negative values
    int n = count_if(v.begin(), v.end(), is_negative);

    // replace negative values with 0
    replace_if(v.begin(), v.end(), is_negative, 0);
}*/

/*#include <iostream>
 *#include <algorithm>
 *#include <vector>
 *
 *using namespace std;
 *
 * int main()
{
    const int SIZE = 5;
    vector<double> numbers(SIZE);

    cout << "Enter 5 numbers:" << endl;

    for (int i = 0; i < SIZE; ++i){
        cout << "> ";
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    cout << "Sorted numbers:" << endl;
    for (double i : numbers){
        cout << i << endl;
    }

    return 0;

}*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    const int SIZE = 5;
    vector<double> numbers(SIZE);

    cout << "Enter 5 numbers:" << endl;

    for (int i = 0; i < SIZE; ++i){
        cout << "> ";
        cin >> numbers[i];
        numbers[i] *= 2;
    }

    reverse(numbers.begin(), numbers.end());

    cout << "Reverse numbers (after multiplying by 2):" << endl;
    for (double i: numbers){
        cout << i << endl;
    }

    return 0;
}
