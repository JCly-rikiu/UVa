#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

void count(std::string &str, std::array<int, 26> &ary) {
  ary.fill(0);

  for (char &ch : str)
    ary[ch - 'A']++;

  return ;
}

int main() {
  std::string be_str, af_str;
  std::array<int, 26> be_array, af_array;
  while (cin >> be_str) {
    count(be_str, be_array);
    cin >> af_str;
    count(af_str, af_array);

    std::sort(be_array.begin(), be_array.end());
    std::sort(af_array.begin(), af_array.end());

    if (be_array == af_array)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
  }

  return EXIT_SUCCESS;
}