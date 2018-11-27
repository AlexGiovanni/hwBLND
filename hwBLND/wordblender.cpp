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
	unordered_map<string, string>words;
	//store words in words unordered_map
	ifstream f(filename);
	string line;
	while (getline(f, line)) {
		string firstTwo = string()+line[0] + line[1];
		words[firstTwo] = line;
	}
	f.close();

	//display words table
	display_table(words);

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

void  WordBlender::display_table(unordered_map<string, string> w) {
	/*for (std::pair<std::string, string> element : w)
	{
		std::cout << element.first << " :: " << element.second << std::endl;
	}*/

	std::cout << "mymap contains:";
	for (auto it = w.begin(); it != w.end(); ++it)
		std::cout << " " << it->first << ":" << it->second<<endl;
	std::cout << std::endl;

	std::cout << "mymap's buckets contain:\n";
	for (unsigned i = 0; i < w.bucket_count(); ++i) {
		//std::cout << "bucket #" << i << " contains:";
		for (auto local_it = w.begin(i); local_it != w.end(i); ++local_it)
			std::cout << " " << local_it->first << ":" << local_it->second << endl;
		//std::cout << std::endl;
	}

}