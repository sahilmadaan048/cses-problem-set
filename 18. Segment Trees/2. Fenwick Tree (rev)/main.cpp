#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> temp(n);
  for (int i = 0; i < n; i++)
    cin >> temp[i];
  for (auto ele : temp)
    cout << ele << " ";

  cout << endl;
}
