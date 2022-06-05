#include<string>
using namespace std;
#include <iostream>
#include <vector>
class StudentName {
    string name;
public:
    StudentName(string Name);
    vector<string> getThe_name();
    void print();
    bool replace(int i, int j);
    int getsize();

};
StudentName::StudentName(string Name) {
    name = Name;
    auto The_name = StudentName::getThe_name();
    auto i = The_name.size();
    for (; i < 3; i++)
    {
        name = name + " " + The_name[The_name.size() - 1];
    }
}
int StudentName::getsize()
{
    vector<string> _name = StudentName::getThe_name();
    return _name.size();

}
vector<string> StudentName::getThe_name() {
    {
        vector<string> TheName;
        int pos = 0;
        string::size_type i = 0;
        for (i = 0; i < name.size(); i++) {
            if (name[i] == ' ') {
                TheName.push_back(name.substr(pos, i - pos));
                pos = (1 + i);
            }
        }
        TheName.push_back(name.substr(pos, i - pos));
        return TheName;
    }
};
bool StudentName::replace(int i, int j) {
    i--;
    j--;

    auto _name = StudentName::getThe_name();
    auto size = _name.size();
    if (i > j || i < j)
        swap(i, j);
    if (i < 0 || j < 0)
        return false;
    if (size - 1 < i)
        return false;
    if (size - 1 < j)
        return false;
    if (i == j)
        return true;
    swap(_name[j], _name[i]);
    name = _name[0];
    vector<string>::size_type c = 1;
    for (; c < _name.size(); c++) {
        name = name + " " + _name[c];
    }
    return true;
};
void StudentName::print() {
    int count = 1;
    vector<string>_thename = StudentName::getThe_name();
    vector<string>::iterator it = _thename.begin();
    for (; it != _thename.end(); it++) {
        cout << "(" << count << ") " << *it << endl;
        count++;
    }
}
void test(string name, int i, int j) {
    StudentName n1(name);
    cout << "Input:" << endl;
    cout << name << endl;
    cout << i << endl;
    cout << j << endl << endl;
    if (n1.replace(i, j) && j <= n1.getsize() - 1 && i > 0 && j > 0) {
        cout << "Output:" << endl;
        cout << "True" << endl;
        n1.print();
        cout << endl;
    }
    else
    {
        cout << "Output:" << endl;
        cout << "False" << endl;
        n1.print();
        cout << endl;
    }
    cout << endl;
}
int main() {
    test("Osama ahmed Modaser Qnas Hossam anchiloty", 1, 7);
    test("Osama ahmed Modaser Qnas Hossam anchiloty", 6, 4);
    test("zien", 2, 1);
    test("Modaser Qnas", 2, 1);
    test("Hossam anchiloty gendy", 3, 2);
    test("Ashaf jokey", 6, 2);
    test("ahmed Mohamed", 5, -1);
}

