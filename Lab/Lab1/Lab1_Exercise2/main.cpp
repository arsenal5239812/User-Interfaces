#include <iostream>
using namespace std;

int main() {

    double x, y, z;

    cout << "Enter x length (m)> " << endl;
    cout << "Enter y length (m)> " << endl;
    cout << "Enter z length (m)> " << endl;
    cin >> x >> y >> z;

    cout << "The volume of the cuboid is "<< x*y*z << "!" << endl;
    return 0;
}
