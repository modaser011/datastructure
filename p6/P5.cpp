#include <iostream>
#include <set>
#include <string>
using namespace std;
void RecPermute(set<string>& perms, string soFar, string rest) {
    if (rest == "")
        perms.insert(soFar);
    else
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i];
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(perms, next, remaining);
        }
}

void ListPermutations(string s) {
    set<string> Permutations;
    RecPermute(Permutations, "", s);
    set<string>::iterator _iterator = Permutations.begin();
    for (; _iterator != Permutations.end(); _iterator++) {
        cout << *_iterator << " ";
    }
}
void test(string s) {
    cout << "Input:" << endl;
    cout << s << endl<<endl;
    cout << "Output:" << endl;
    ListPermutations(s);

    cout << "\n____________________________________________________________________________________________________________________\n";
}
int main() 
{
    test("ABCA");
   
    test("AbcD");
   
    test("Abcde");
    
    
}
