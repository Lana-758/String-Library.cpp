// String Library project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include "clsString.h"
using namespace std;
int main()
{
clsString s1;
clsString s2("Redmi Samsung");

	s1.value = "Hey there I'm using Whatsapp!";
	cout << "string1 :" << s1.value << endl;
	cout << "String2 :" << s2.value << endl;

	cout << "Number of words in string1: " << s1.CountWords() << endl;
	cout << "Number of words in this string \"Iris Iris \": " << s1.CountWords("Iris Iris") << endl;
	cout << "Number of words here:\"we were born to die\" " << clsString::CountWords("we were born to die") << endl;
	cout << "*******************************************\n";

	clsString s3("Hi, How are you?");
	cout << "String3 = " << s3.value << endl;
	cout << " Length of string3: " << s3.GetLength() << endl;
	s3.UpperFirstLetterInEachWord();
	cout <<" Upper first letter in each word in string3 : "<< s3.value << endl;
	cout << "*******************************************\n";

	s3.LowerFirstLetterInEachWord();
	cout <<" Lower first letter in each word in string3 : "<< s3.value << endl;
	cout << "*******************************************\n";
	cout << "After inverting a :" << clsString::InvertLetterCase('a') << endl;
	cout << "*******************************************\n";

	s3.value = "wiwiwi";
	cout << "New value of string3 is : " << s3.value << endl; 
	s3.InvertAllLettersCase();
	cout << " invert all letter case in string3 : " << s3.value << endl;
	cout << "*******************************************\n";
	cout << "Capital letters number :" << clsString::CountLetters("Lana iris", clsString::capitalLetters) << endl;
	cout << "*******************************************\n";

	s3.value = "Welcome in Syria";
	cout << "New value of string3 : " << s3.value << endl;
	cout << "Capital letters number : " << s3.CountCapitalLetters() << endl;
	cout << "Small letters number : " << s3.CountSmallLetters() << endl;
	cout << "Vowel letters number : " << s3.CountVowels() << endl;
	cout << "Letter E number : " << s3.CountSpecificLetter('E', false) << endl;
	cout << "Is letter u vowel ? " << clsString::IsVowel('u') << endl;
	cout << "Number of words in string3 : " << s3.CountWords() << endl;
	cout << "Replace the word \"Syria\" by \"Gremany\" :" << s3.ReplaceWord("Syria", "Germany") << endl;
	cout << "*******************************************\n";

	vector<string> vstring;
	vstring = s3.Split(" ");
	cout << "Tokens = " << vstring.size() << endl;
	for (string& s : vstring) {
		cout << s << endl; }
	cout << "*******************************************\n";

	s3.value = "    Lana lolo lili    ";
	cout << "New value of string3 : " << endl; 
	s3.TrimLeft();
	cout << "String3 with Trim Left : " << s3.value << endl;
	s3.TrimRigth();
	cout << "String3 with Trim Right : " << s3.value << endl;
	s3.Trim();
	cout << "String3 with Full Trim : " << s3.value << endl;

	s3.ReverseWordInString();
	cout << "Reverse String3 : " << s3.value << endl;
	cout << "*******************************************\n";

	vector<string> vsstring = { "lana","lanitta","wiwi","dodoo" };
	cout << "Join string from vector :\n";
	cout << clsString::JoinString(vsstring, " ") << endl;

	string arr[] = { "lele","lili","kk" };
	cout << "Join string from array :\n";
	cout << clsString::JoinString(arr, 3, " ") << endl;

	clsString s4(" lana ,lolo ,lili..");
	cout <<"String4 : "<< s4.value << endl;
	s4.RemovePunctuations(); 
	cout << "Remove all punctuations in string4:" << s4.value;


	system("pause>0");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
