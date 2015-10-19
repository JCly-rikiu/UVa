#include <iostream>
#include <string>
#include <sstream>

#include <set>

using namespace std;

char change(char ch) {
  if (ch >= 'A' && ch <= 'Z')
    return (char)((int)ch + 32);
  if (ch >= 'a' && ch <= 'z')
    return ch;
  return ' ';
}

int main() {
  set<string> s;
  
  string line;
  while (getline(cin, line)) {
    for (int i = 0; i != line.length(); i++)
      line[i] = change(line[i]);
    
    stringstream ss(line);
    string str;
    while (ss >> str)
      s.insert(str);
  }

  set<string>::iterator it;
  for (it = s.begin(); it != s.end(); it++)
    cout << *it << endl;

  return 0;
}
