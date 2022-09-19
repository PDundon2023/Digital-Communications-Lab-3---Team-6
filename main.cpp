#include<bits/stdc++.h>
using namespace std;
 
// This function generates the key in
// a cyclic manner until it's length is
// equal to the length of original text
string match_length(string str, string key)
{
  int x = str.size();
 
  for (int i = 0; ; i++)
  {
    if (x == i)
      i = 0;
    if (key.size() == str.size())
      break;
    key.push_back(key[i]);
  }
  return key;
}
 
// This function returns the encrypted text
// generated with the help of the key
string Encryption(string str, string key)
{
    string cipher_text;
 
    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        char x = (str[i] + key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
 
        cipher_text.push_back(x);
    }
    return cipher_text;
}
 
// This function decrypts the encrypted text
// and returns the original text
string Decryption(string cipher_text, string key)
{
    string orig_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        char x = (cipher_text[i] - key[i] + 26) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}
 
// Driver program to test the above function
int main()
{

    //make sure both are capatalized
    string str = "PATRICK";
    string key = "KEY";
 
    string keyword = match_length(str, key);

    string cipher_text = Encryption(str, keyword);
 
    cout << "Ciphertext : "
         << cipher_text << "\n";
 
    cout << "Original/Decrypted Text : "
         << Decryption(cipher_text, keyword);
    return 0;
}