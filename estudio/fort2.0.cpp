#include <iostream>

using namespace std;


void checkNum(int n) {
  if (n == 1 || n == 2 || n == 3) {
    cout << "Yes" << endl;
    return;
  }
  if (n % 4 == 0 || n % 6 == 0) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl;
  return;
  
}


int main() {

  int n;
  int nums[200];
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  
  for (int i = 0; i < n; i++) {
    checkNum(nums[i]);
  }
    
  return 0;
}