#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool palindrome(string aString){
    aString.erase(remove_if(aString.begin(), aString.end(), [](char c){
        return isspace(c);}), aString.end());
    transform(aString.begin(), aString.end(), aString.begin(), ::tolower);

    int len = aString.length();

    for (int i = 0; i < len / 2; ++i){
        if (aString[i] != aString[len - 1 - i]){
            return false;
        }
    }
    return true;
}
int main()
{
    cout << boolalpha;

    cout << palindrome("wanne") << endl;
    cout << palindrome("anna") << endl;
    cout << palindrome("hello") << endl;
    cout << palindrome("are we not drawn onward to new era") << endl;

    return 0;
}
