//Alexis Santiago
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
	unordered_multimap<string, string>words;
	unordered_map<string, int>index;//stores the indeses of aaaa aaab...
	//store words in words unordered_map
	ifstream f(filename);
	string line;
	while (getline(f, line)) {
		string firstTwo = string()+line[0] + line[1];
		words.insert({firstTwo, line});
	}
	f.close();
	
	 
	//create table max_word_count X 456976
	table = new string*[max_word_count];
	for (int i = 0; i < 10; i++) {
		table[i] = new string[456976];
	}
	char al[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	
	cout << "alphabet 4 letters" << endl;
	int column = 0;
	for (int row = 0; row < max_word_count ; row++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					for (int l = 0; l < 26; l++) {
						if (row == 0) {
							table[row][column] = start_end(words, string() + al[i] + al[j], string() + al[k] + al[l]);

						}
						index.insert({ string() + al[i] + al[j] + al[k] + al[l],column });
						column++;
					}
				}
			}
		}
	}

	//find index for table 
	auto it = index.find("tyol");
	if (it == index.end())
		cout << "not found" << endl;
	else
	cout << "ty ol in table: " << table[0][it->second] <<" index: "<<it->second<< endl;
	
	

}//end constructor



	// Returns a blend word that:
	// -Starts and ends with the given words
	// -Otherwise consists entirely of words found in filename
	// -Consists of word_count total words.
	//
	// If no such blend word exists, returns "". 
	// 
	// Must run in O(1) time. 
string WordBlender::blend(string first_word, string last_word, int word_count) {

	return "";
}
//display the words in hash table
void  WordBlender::display_table(unordered_multimap<string, string> w) {
	for (std::pair<std::string, string> element : w)
	{
		std::cout << element.first << " :: " << element.second << std::endl;
	}
}

//display words with same key in hash table
void  WordBlender::display_same_key(unordered_multimap<string, string>words, string key) {
	//display whats in key 
	cout << "display whats in key: "<<key << endl;
	auto its = words.equal_range(key);
	for (auto it = its.first; it != its.second; ++it) {
		cout << it->first << '\t' << it->second << endl;
	}
}

//find words that start and end with a given key
string  WordBlender::start_end(unordered_multimap<string, string>words, string key, string end) {
	 
	auto its = words.equal_range(key);
	for (auto it = its.first; it != its.second; ++it) {
		int size = it->second.size();
		string ltwo = string()+it->second[size-2] + it->second[size-1];
		if (ltwo == end ) {
			return it->second;
		}
	}
	return "";
}

//char al[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//int column = 0; int row = 0;
//cout << "alphabet 4 letters" << endl;
//for (int i = 0; i < 26; i++) {
//	for (int j = 0; j < 26; j++) {
//		for (int k = 0; k < 26; k++) {
//			for (int l = 0; l < 26; l++) {
//
//				//string found = start_end(words, string()+al[i]+al[j], string() + al[k] + al[l]);
//				//if (found != "") { cout <<"found: " <<found << endl; }
//				column++;
//			}
//		}
//	}
//	row++;
//}
