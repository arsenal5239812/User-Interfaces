/*#include <string>
 *#include <iostream>
 *
 *using namespace std;
 *int main()
{
    string target = "World";
    string message = "Hello " + target + "!";
    cout << message << endl;
    cout << message.length() << endl;
    cout << message[6] << endl;
    cout << message.find("W") << endl;
    message.replace(0, 5, "Goodbye");
    cout << message << endl;

    return 0;
}*/

#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str = "hello world";

    for (int i = str.length(); i > 0; --i ){

        cout << str.substr(0, i) << endl;
    }

    return 0;
}
