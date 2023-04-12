//Elleson Tran
//Roberts
//Palindromator
//FINAL

#include <iostream>
#include <string>

using namespace std;

//gets the phrase (returns a string)
string getPhrase(string &userTemp){
    cout<<endl<<"Please enter text to check for palindrome:";
    getline(cin, userTemp);
    return userTemp;
}


//checks if letter is in the alphabet, not a puncutation or space (returns if the letter if its in the alphabet true or false)
bool inAbc(char letter){
  string abc = "abcdefghijkllmnopqrstuvwxyz";
  bool answer;
  for(int x = 0; x <  abc.length(); x++){
    if(abc.at(x) == letter){
      answer = true;
      return answer;
    }
  }
  answer = false;
  return false;
}

//breaksup the word into no spaces, no puncutation, and all lowercase (returns the new word)
string breakUp(string word){
  string newWord;
  for(int x = 0; x < word.length(); x++){
    char letter = tolower(word.at(x));
    if(inAbc(letter) == true){
      newWord = newWord + letter;
    }
  }
  return newWord;
}

//reverses the new broken up word (returns a new variable of the reversed word)
string reverse(string word){
  string reverse;
  for(int x = word.length() - 1; x >= 0; x--){
    reverse = reverse  + word.at(x);
  }
  return reverse;
}

//compares the reversed and brokenup word (returns if it is the same, true of false)
bool compare(string word, string wordReverse){
  bool answer;
  if(word == wordReverse){
    answer = true;
    return answer;
  }
  if(word != wordReverse){
    answer = false;
    return answer;
  }
  return answer;
}

//displays if is a palindrome or not
void display(string word, string wordReverse, string user){
    if(compare(word, wordReverse) == true){
      cout<<endl<<"Yes! "<<user<<" is a palindrome!";
    }
    if(compare(word, wordReverse) == false){
      cout<<endl<<"No, "<<user<<" is NOT a palindrome!";
    }
}


//asks the user if they want to play again (returns if they want to play again, true of false)
bool playAgain(){
  bool playAgain;

  string yesOrNo;
  cout<<endl<<"Checker another? yes/no ";
  cin>>yesOrNo;
  cin.ignore();

  if(yesOrNo == "yes"){
    playAgain = true;
    return playAgain;
  }
  if(yesOrNo == "no"){
    playAgain = false;
    return playAgain;
  }
  return playAgain;
}

int main() {
  do{
    string userTemp;
    string user = getPhrase(userTemp);

    string word = breakUp(user);

    string wordReverse;
    wordReverse = reverse(word);
    
    display(word, wordReverse, user);
  }while(playAgain() != false);
  
  
}