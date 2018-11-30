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
	unordered_multimap<string, string>words;//key is first two letters
	unordered_multimap<string, string>wordsb;//key is last two letters
	
	//store words in words unordered_map
	ifstream f(filename);
	string line;
	while (getline(f, line)) {
		string firstTwo = string()+line[0] + line[1];
		words.insert({firstTwo, line});
	}
	f.close();

	////store words in wordsb unordered_map last letters are the key
	//ifstream f(filename);
	//while (getline(f, line)) {
	//	string lastTwo = string() + line[0] + line[1];
	//	wordsb.insert({ lastTwo, line });
	//}
	//f.close();
	
	
	 
	//create table max_word_count X 456976
	table = new string*[max_word_count];
	for (int i = 0; i < 10; i++) {
		table[i] = new string[456976];
	}
	char al[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	
	string test = "";
	cout << "test size: " << test.size() << endl;
	//system("Pause");
	//fill the table with words
	int column = 0;
	for (int row = 0; row < max_word_count ; row++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					for (int l = 0; l < 26; l++) {
						//cout << column<<": "<<string() + al[i] + al[j] + al[k] + al[l]<<endl;
						if (row == 0) {//find a word that starts and ends with the desired sequence
							table[row][column] = start_end(words, string() + al[i] + al[j], string() + al[k] + al[l]);
						}
						if (row == 1) {//find two words that start and end with the string
							//for example apple lefty
							//find word that starts with ap

							//system("Pause");
						}
						 
						column++;
					}
				}
			}
		}
	}

	
	/*cout << "ap le in table: " << table[0][get_index("aple")] << endl;
	cout << "ap ty row two: " << table[1][get_index("apty")] << endl;
*/
	vector<string>last = find_last_two("as", 0);
	for (int i = 0; i < last.size(); i++) {
		cout << "in last: " << last[i]<<endl;
	}

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

//display all words with same key in hash table
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
 
//returns the index of a given string or -1 if not found
int  WordBlender::get_index(string key) {
	int index = -1;
	//get the index of the letter
	index =
		(key[0] - 'a') *(26 * 26 * 26) +
		(key[1] - 'a') *(26 * 26 ) +
		(key[2] - 'a') *(26 ) +
		(key[3] - 'a') ;
	return index;
}

//takes a string containing last two letters
//and an int representing the row to look for
//and returns vector of strings containing words with last two letters
vector<string>  WordBlender::find_last_two(string lastTwo, int row) {
	vector<string>last;
	int start = get_index(string() + "aa" + lastTwo);
	while (start < 456976) {
		if (table[row][start] != "") 
			last.push_back(table[row][start]);
       start += 676;
	}
	return last;
}