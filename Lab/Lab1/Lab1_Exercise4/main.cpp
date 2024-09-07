/*#include <iostream>
 *#include <vector>
 *
 *using namespace std;
 *
 * int main()
{
    const int SIZE = 5;
    double numbers[SIZE];
    double sum = 0;
    double average;

    cout << "Enter 5 numbers:" << endl;

    for(int i = 0; i < SIZE; i++){
        cout << "> ";
        cin >> numbers[i];
        sum += numbers[i];
    }

    average = sum / SIZE;

    cout << "The mean is: " << average <<endl;

    return 0;
}*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int SIZE = 5;
    vector<double> numbers(SIZE);
    double sum = 0;
    double average;

    cout << "Enter 5 numbers" << endl;

    for (int i = 0; i < SIZE; ++i){
        cout << "> ";
        cin >> numbers[i];
        sum += numbers[i];
    }

    average = sum / SIZE;

    cout << "The mean is: " << average << endl;

    return 0;
}
