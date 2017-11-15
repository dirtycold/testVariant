

#include <iostream>
#include <chrono>
#include "Value.h"

using namespace std;

int main()
{
    int count = 1;
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < count; ++i)
    {
    /*
    try
    {
    */
        Value v1, v2, v3, v4;
        v1 = std::string ("Hello World");
        cout << v1.type() << " " << v1.toString() << endl;

        v2 = 46;
        cout << v2.type() << " " << v2.toString() << endl;
        v2 = false;
        cout << v2.type() << " " << v2.toString() << " " << v2.toInteger() << endl;
        v2 = std::string ("So what???");
        cout << v2.type() << " " << v2.toString() << " " << v2.toInteger() << endl;
        v2 = "So bad...";
        cout << v2.type() << " " << v2.toString() << " " << v2.toInteger() << endl;

        v3 = 3.14159;
        cout << v3.type() << " " << v3.toReal() << " " << v3.toInteger() << endl;

        cout << v4.type() << " " << v4.toString() << endl;
        v4 = v1;
        cout << v4.type() << " " << v4.toString() << endl;

        Value v5 ("Wrong");
        cout << v5 << endl;

        Value v6;
        v6 = "Aloha"s;
        cout << v6 << endl;

        Value v7 (200);
        cout << v7 << endl;

        Value v8 (true);
        cout << v8 << endl;

        Value v9 (2.71828);
        cout << v9 << endl;

        Value v10 ("0"s);
        cout << v10 << " " << v10.toBoolean() << endl;
    /*
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    */

    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;

    cout << "test of " << count << " iterations in : " << diff.count() << " seconds." << endl;

    return 0;
}
