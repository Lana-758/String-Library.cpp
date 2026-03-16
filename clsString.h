#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clsString
{
    string _Value;

public:

    clsString() {
        _Value = "";
    }
    clsString(string v) {
        _Value = v;
    }
    void SetValue(string v) {
        _Value = v;
    }
    string GetValue() {
        return _Value;
    }
    static  short GetLength(string s) {
        return (short)s.length();

    }
    short GetLength() {
        return GetLength(_Value);
    }
    __declspec(property(get = GetValue, put = SetValue))string value;

    //Split for cutting the string into words
   static vector<string> Split(string s, string sep) {    
        vector<string> vstring;
        int position = 0;           //position of delimiter
        string s1;

        while ((position = s.find(sep)) != std::string::npos) {
          s1=  s.substr(0, position);
            if (s1 != "") {
                vstring.push_back(s1);
            }
            s.erase(0, position + sep.length());
        }
        if (s != "") {
            vstring.push_back(s);
        }
        return vstring;
    }
   vector<string> Split(string delimiter) {
     return  Split(_Value,delimiter);
   }

  //To get a capital first letter in each word in the string
   static string UpperFirstLetterInEachWord(string s){   
       bool isFirstLetter = true;
       for (short i = 0; i < s.length(); i++) {
           if (s[i] != ' ' && isFirstLetter) {
               s[i] = toupper(s[i]);
           }
           isFirstLetter = (s[i] == ' ' ? true : false);
       }
       return s;
   }
   //To get small first letter in each word in the string
   static string LowerFirstLetterInEachWord(string s) {
       bool isFirstLetter = true;
       for (short i = 0; i < s.length(); i++) {
           if (s[i] != ' ' && isFirstLetter) {
               s[i] = tolower(s[i]);
           }
           isFirstLetter = (s[i] == ' ' ? true : false);
       }
       return s;
   }
   void UpperFirstLetterInEachWord() {
       _Value = UpperFirstLetterInEachWord(_Value);
   }
   void LowerFirstLetterInEachWord() {
       _Value = LowerFirstLetterInEachWord(_Value);
   }
   //To get capital letters in all string
   static string UpperAllString(string s) {
       for (short i = 0; i < s.length(); i++) {
           s[i] = toupper(s[i]);
       }
       return s;
  }
   //To get small letters in all string
   static string LowerAllString(string s) {
       for (short i = 0; i < s.length(); i++) {
           s[i] = tolower(s[i]);
       }
       return s;
   }
   void UpperAllString() {
       _Value = UpperAllString(_Value);
   }
   void LowerAllString() {
       _Value = LowerAllString(_Value);
   }
   //To convert the case of letter 
   static char InvertLetterCase(char c) {
       return(isupper(c) ? tolower(c) : toupper(c));
   }
   //convert the case of all letters in the string
   static string InvertAllLettersCase(string s) {
       for (short i = 0; i < s.length(); i++) {
           s[i] = InvertLetterCase(s[i]);
       }
       return s;
   }
   void InvertAllLettersCase() {
       _Value = InvertAllLettersCase(_Value);
   }

   enum enWhatToCount { smallLetters = 0, capitalLetters=1, all=2 };

   static short CountLetters(string s , enWhatToCount WhatToCount = enWhatToCount::all) {

       if (WhatToCount == enWhatToCount::all) {
           return(short) s.length();
      }
       short counter = 0;   //Counter to count letters
       for (short i = 0; i < s.length(); i++) {
           if (WhatToCount == enWhatToCount::capitalLetters && isupper(s[i]))
               counter++;
           if (WhatToCount == enWhatToCount::smallLetters && islower(s[i]))
               counter++;
       }
       return counter;
   }
   short CountCapitalLetters() {
       return CountLetters(_Value, enWhatToCount::capitalLetters);
   }
   short CountSmallLetters() {
       return CountLetters(_Value, enWhatToCount::smallLetters);
   }
   static bool IsVowel(char c) {
       return(c == 'a' || c == 'u' || c == 'i' || c == 'e' || c == 'o');
   }
   static short CountVowels(string s) {
       short counter = 0;    //counter of vowel letters
       for (short i = 0; i < s.length(); i++) {
             if(IsVowel(s[i]))
                 counter++;
       }
       return counter;
   }
   short CountVowels() {
       return CountVowels(_Value);
   }
   static short CountSpecificLetter(string s, char c, bool matchcase = 1) {
       short counter = 0;   //counter of special letter
       for (short i = 0; i < s.length(); i++) {
           if (matchcase) {
               if (s[i] == c) {
                   counter++;
               }
           }
               else {
                   if (toupper(s[i]) == toupper(c))
                       counter++;
               }
           }
       return counter;
       }
   short CountSpecificLetter(char c,bool matchcase=1) {
       return CountSpecificLetter(_Value, c, matchcase);
   }
   static short CountWords(string s) {
       string delim = " ";
       short c = 0;
       short pos = 0;
       string sWord;
       while ((pos = s.find(delim)) != std::string::npos) {
           sWord = sWord.substr(0, pos);
           if (sWord != " ") {
               c++;
           }
           s.erase(0, pos + delim.length());
       }
       if (s != " ") {
           c++;
       }
       return c;
   }
   short CountWords() {
       return CountWords(_Value);
   }
   static string RemovePunctuations(string s) {
       string s2 = "";
       for (short i = 0; i < s.length(); i++) {
           if (!ispunct(s[i]))
               s2 += s[i];
       }
       return s2;
   }
   void RemovePunctuations() {
       _Value = RemovePunctuations(_Value);
   }
   
  // To delete the left emptiness
   static string TrimLeft(string s) {
       for (short i = 0; i < s.length(); i++) {
           if (s[i] != ' ')
               return s.substr(i, s.length() -i);
       }
       return "";
   }
   //To delete the right emptiness
   static string TrimRigth(string s) {
       for (short i = s.length() - 1; i >= 0; i--) {
           if (s[i] != ' ')
               return s.substr(0, i + 1);
       }
       return "";
   }
   
   void TrimLeft() {
       _Value = TrimLeft(_Value);
   }
   void TrimRigth() {
       _Value = TrimRigth(_Value);
   }
   static string Trim(string s) {
       return(TrimLeft(TrimRigth(s)));
   }
   //To delete the right and left emptiness
   void Trim() {
       _Value = Trim(_Value);
   }
   // To conect the separate words into a string using vectors
   static string JoinString(vector<string> vstring, string delim) {
       string s = "";
       for (string& s1 : vstring) {
           s = s + s1 + delim;
       }
       return s.substr(0, s.length() - delim.length());
   }
   //To conect the separate words into a string using array
   static string JoinString(string arr[], short length, string delim) {
       string s = "";
       for (short i = 0; i < length; i++) {
           s += arr[i] + delim;
       }
       return s.substr(0,s. length() - delim.length());
   }
   //To Reverse the string
   static string ReverseWordsInString(string s) {
       vector<string> vstring;
       string s1 = "";
       vstring = Split(s," ");
       vector<string> ::iterator iter = vstring.end();
       while (iter != vstring.begin()) {

           --iter;
           s1 += *iter + " ";
       }
       s1 = s1.substr(0, s1.length() - 1);
       return s1;
   }
   void ReverseWordInString() {
       _Value = ReverseWordsInString(_Value);
   }
   static string  ReplaceWord(string s, string StringToReplace, string StringReplaceTo, bool MatchCase = true) {
       vector<string> vstring = Split(s, " ");
       for (string& s1 : vstring) {
           if (MatchCase) {
               if (s1 == StringToReplace) {
                   s1 = StringReplaceTo;
               }
           }
           else {
               if (LowerAllString(s1) == LowerAllString(StringToReplace)) {
                   s1 = StringReplaceTo;
               }
           }
       }
       return JoinString(vstring, " ");
   }
   string ReplaceWord(string StoRelace,string SreplaceTo) {
       return ReplaceWord(_Value,StoRelace,SreplaceTo);
   }
};

