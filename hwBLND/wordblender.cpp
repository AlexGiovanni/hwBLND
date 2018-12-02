//Alexis Santiago December 2 2018
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include "wordblender.h"
#include <unordered_map>


using namespace std;


// Constructs a Wordblender that creates blend words 
// from those provided in the file. The file is promised
// to have the following format:
// 
// word1
// word2
// ...
// wordN
//
// where word1 < word2 < ... < wordN
//
// Must run in O(nk) time, where:
		// n is the number of words in the file
		// k equals max_word_count 
WordBlender::WordBlender(string filename, int max_word_count) {
	unordered_multimap<string, string>words;//key is first two letters
	unordered_multimap<string, string>chains;
	unordered_multimap<string, string>chains2;
	unordered_multimap<string, string>chains3;
	unordered_multimap<string, string>chains4;
	unordered_multimap<string, string>chains5;
	unordered_multimap<string, string>chains6;
	unordered_multimap<string, string>chains7;
	unordered_multimap<string, string>chains8;

	//store words in words unordered_map
	ifstream f(filename);
	string line;
	while (getline(f, line)) {
		string firstTwo = string() + line[0] + line[1];
		words.insert({firstTwo, line});
	}
	f.close();
 
	//create table max_word_count X 456976
	table = new string*[max_word_count];
	for (int i = 0; i < 10; i++) {
		table[i] = new string[456976];
	}
 
	//fill the table with words
	for (int row = 0; row < max_word_count; row++) {
		 
		 if (row == 0) {//find a word that starts and ends with the desired sequence 
			 //loop trough all words
			 for (pair<string, string> el : words){
				 string key = string() + el.second[0] + el.second[1] +
					 el.second[el.second.size() - 2] + el.second[el.second.size()-1];
				 table[row][get_index(key)] = el.second;
				 
			 }
			 
		 }
		 if (row == 1) {//find two words that start and end with the string
			 for (pair<string, string> el : words) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains.insert({ string()+el.second[0]+el.second[1]
						 ,table[row][get_index(key)] });
					 
				 }
			 
			 }


		 }//end of row 1
		 if (row == 2 && row < max_word_count ) {
			 for (pair<string, string> el : chains) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains2.insert({ string() + el.second[0] + el.second[1]
						 ,table[row][get_index(key)] });
					 
				 }
			 }
							 
		 }//end row 2
		 if (row == 3 && row < max_word_count) {
			 for (pair<string, string> el : chains2) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains3.insert({ string() + el.second[0] + el.second[1]
						 ,table[row][get_index(key)] });
					 
				 }
			 }
		 }//end row 3
		 if (row == 4 && row < max_word_count) {
			 for (pair<string, string> el : chains3) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains4.insert({ string() + el.second[0] + el.second[1]
						 ,table[row][get_index(key)] });
					 
				 }
			 }
		 }//end row 4
		 if (row == 5 && row < max_word_count) {
			 for (pair<string, string> el : chains4) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains5.insert({ string() + el.second[0] + el.second[1]
						 ,table[row][get_index(key)] });
					 
				 }
			 }
		 }//end row 5
		 if (row == 6 && row < max_word_count) {
			 for (pair<string, string> el : chains5) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains6.insert({ string() + el.second[0] + el.second[1]
						 ,table[row][get_index(key)] });
					 
				 }
			 }
		 }//end row 6
		 if (row == 7 && row < max_word_count) {
			 for (pair<string, string> el : chains6) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains7.insert({ string() + el.second[0] + el.second[1]
						 ,table[row][get_index(key)] });
				 
				 }
			 }
		 }//end row 7
		 if (row == 8 && row < max_word_count) {
			 for (pair<string, string> el : chains7) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 chains8.insert({ string() + el.second[0] + el.second[1]
						 ,table[row][get_index(key)] });
					 
				 }
			 }
		 }//end row 8
		 if (row == 9 && row < max_word_count) {
			 for (pair<string, string> el : chains8) {
				 string lt = string() + el.second[el.second.size() - 2] +
					 el.second[el.second.size() - 1];
				 auto its = words.equal_range(lt);
				 for (auto it = its.first; it != its.second; ++it) {
					 string key = string() + el.second[0] + el.second[1] +
						 it->second[it->second.size() - 2] + it->second[it->second.size() - 1];
					 table[row][get_index(key)] = chain_words(el.second, it->second);
					 
				 }
			 }
		 }//end row 9
 		 
		 
	}

	 
	words.clear(); chains.clear(); chains2.clear();chains3.clear(); chains4.clear();
	chains5.clear(); chains6.clear(); chains7.clear(); chains8.clear();
}//end constructor



	// Returns a blend word that:
	// -Starts and ends with the given words
	// -Otherwise consists entirely of words found in filename
	// -Consists of word_count total words.
	//
	// If no such blend word exists, returns "". 
	// 
	// Must run in O(1) time. 
string WordBlender::blend(string first, string last, int word_count) {
	//cout << "testing " << first << " " << last << endl;
	string chain = "";
	if (word_count == 2) {

		if (overlap(first, last)) {
			chain = chain_words(first, last);
		}

	}
	if (word_count > 2) {//3 or greater

		string ft = string() + first[first.size() - 2] + first[first.size() - 1];
		string la = string() + last[0] + last[1];
		string c = table[word_count - 3][get_index(string() + ft + la)];
		//cout <<"found chain word: "<< c << endl
		if (c != "")
			chain = chain_words(chain_words(first, c), last);

	}
	//cout << "chain: " << chain << endl;
	 
	return chain;
}


//returns the index of a given string or -1 if not found
int  WordBlender::get_index(string key) {
	int index = -1;
	//get the index of the letter
	index =
		(key[0] - 'a') *(26 * 26 * 26) +
		(key[1] - 'a') *(26 * 26) +
		(key[2] - 'a') *(26) +
		(key[3] - 'a');
	return index;
}


//takes two words and returns
//the chain of those words
string WordBlender::chain_words(string a, string b) {
	a.pop_back(); a.pop_back();
	return string() + a + b;
}
 
//check if two words overlap
//lasttwo of w1 same as firsttwo of w2
bool WordBlender::overlap(string w1, string w2) {

	string ltwo = string() + w1[w1.size() - 2] + w1[w1.size() - 1];
	string ftwo = string() + w2[0] + w2[1];
	//cout << "comparing " << ltwo << " " << ftwo << endl;
	if (ltwo == ftwo) {
		return true;
	}
	return false;
}
 
 


 