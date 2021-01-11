//
// Public link - https://repl.it/@Meagher01/Quote-a-Quote#main.cpp
// Invite link - https://repl.it/join/bnrthchz-meagher01
//
#include <iostream>
using namespace std;

int main() {
  string quote;
  string author;

  cout << "What is the quote? ";
  getline(cin, quote);

  cout << "Who said it? ";
  getline(cin, author);

  cout << author << " says: \"" << quote << "\""; 
  
  return 0;
}
