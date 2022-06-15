// Unordered map is used to store key value pairs
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    m["ide"] = 20;
    m["sahil"] = 10;
    m["person"] = 40;
    m.insert({"gfg", 30});
    if (m.find("ide") != m.end())
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";
    if (m.count("ide") > 0)
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";
    for (auto it = m.begin(); it != m.end(); it++)
        cout << (it->first) << " " << (it->second) << endl;
    auto it = m.find("ide");
    cout << (it->first) << endl;
    cout << m.size() << endl;
    m.erase("ide");
    cout << m.size() << endl;
    m.erase(m.begin());
    cout << m.size() << endl;
    m.erase(m.begin(), m.end());
    cout << m.size() << endl;
    return 0;
}