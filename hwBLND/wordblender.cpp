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
	//store words in words unordered_map
	ifstream f(filename);
	string line;
	while (getline(f, line)) {
		string firstTwo = string()+line[0] + line[1];
		words.insert({firstTwo, line});
	}
	f.close();
	
	//display words table
	display_table(words);
	//display whats in key ot
	display_same_key(words, "ot");
	

}

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
	//display whats in key ot
	cout << "display whats in key: "<<key << endl;
	auto its = words.equal_range(key);
	for (auto it = its.first; it != its.second; ++it) {
		cout << it->first << '\t' << it->second << endl;
	}
}