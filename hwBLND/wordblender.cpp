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
	//unordered_multimap<string, string>wordsb;//key is last two letters
	
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
	
	//display_same_key(words , "ot");

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
							//find word that starts with sequence
							auto its = words.equal_range(string()+al[i]+al[j]);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (last.size()!=0 && its.first!=its.second ) {//if both words exist
								//cout << "if both words exist" << endl;
								for (auto it = its.first; it != its.second; ++it) {
									//cout << "first " << it->first << endl;
									for (int c = 0; c <= last.size() - 1; c++) {
										//cout <<"checking overlap "<< it->second <<" "<< last[c]<<endl;
										if (overlap(it->second, last[c])) {
											//cout << "---------overlap: " << it->second << ", " << last[c] << endl;
											table[row][column] = chain_words(it->second, last[c]); 
											//cout << "inserted in " << row << ", " << column << ": "<<table[row][column] << endl;
											break;
										}
									}

								}

							 
							}

							 
						}//end of row 1
						if (row == 2) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 1);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size()!=0 && last.size() != 0 ) {//if both words exist
								for (int a = 0; a <= first.size()-1 ; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 1);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();

						}//end row 2
						if (row == 3) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 2);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size() != 0 && last.size() != 0) {//if both words exist
								for (int a = 0; a <= first.size() - 1; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 2);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();
						}//end row 3
						if (row == 4) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 3);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size() != 0 && last.size() != 0) {//if both words exist
								for (int a = 0; a <= first.size() - 1; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 3);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();
						}//end row 4
						if (row == 5) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 4);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size() != 0 && last.size() != 0) {//if both words exist
								for (int a = 0; a <= first.size() - 1; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 4);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();
						}//end row 5
						if (row == 6) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 5);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size() != 0 && last.size() != 0) {//if both words exist
								for (int a = 0; a <= first.size() - 1; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 5);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();
						}//end row 6
						if (row == 7) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 6);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size() != 0 && last.size() != 0) {//if both words exist
								for (int a = 0; a <= first.size() - 1; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 6);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();
						}//end row 7
						if (row == 8) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 7);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size() != 0 && last.size() != 0) {//if both words exist
								for (int a = 0; a <= first.size() - 1; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 7);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();
						}//end row 8
						if (row == 9) {
							vector<string>first = find_first_two(string() + al[i] + al[j], 8);
							vector<string>last = find_last_two(string() + al[k] + al[l], 0);
							if (first.size() != 0 && last.size() != 0) {//if both words exist
								for (int a = 0; a <= first.size() - 1; a++) {
									for (int b = 0; b <= last.size() - 1; b++) {
										if (overlap(first[a], last[b])) {
											//cout << "overlap: " << first[a] << " " << last[b] << endl;
											table[row][column] = chain_words(first[a], last[b]);
											//cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
										}

									}

								}

							}
							if (table[row][column] == "") {//if nothing was inserted 
								vector<string>firstb = find_first_two(string() + al[i] + al[j], 0);//finds words
								vector<string>lastb = find_last_two(string() + al[k] + al[l], 8);//finds chains
								if (firstb.size() != 0 && lastb.size() != 0) {//if both words exist
									for (int a = 0; a <= lastb.size() - 1; a++) {
										for (int b = 0; b <= firstb.size() - 1; b++) {
											if (overlap(firstb[a], lastb[b])) {
												cout << "overlap: " << firstb[a] << " " << lastb[b] << endl;
												table[row][column] = chain_words(firstb[a], lastb[b]);
												cout << "inserted in " << row << ", " << column << ": " << table[row][column] << endl;
											}
										}
									}

								}
								firstb.clear(); lastb.clear();
							}
							first.clear(); last.clear();
						}//end row 9
						 
						 
						column++;
						if (column >= 456976)column = 0;
					}
				}
			}
		}
	}

	/*
	cout << "ap le in table: " << table[0][get_index("aple")] << endl;
	cout << "ot or row two: " << table[1][get_index("otor")] << endl;
	cout << "ve ot is at index " << get_index("veot") << endl;

	 */

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
//in the unordered_multimap
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

//returns chains that start with firstTwo letters
//takes a string containing first two letters
//and an int representing the row to look for
//and returns vector of strings containing words with first two letters
vector<string>  WordBlender::find_first_two(string ft, int row) {
	vector<string>first;
	int start = get_index(string() + ft + "aa");
	int end = start + 675;
	while ( start<end) {
		if (table[row][start] != "")
			first.push_back(table[row][start]);
		start++;
	}

	return first;
}

//check if two words overlap
bool WordBlender::overlap(string w1, string w2) {
	
		string ltwo = string() + w1[w1.size()-2] + w1[w1.size() - 1];
		string ftwo = string() + w2[0] + w2[1];
		//cout << "comparing " << ltwo << " " << ftwo << endl;
		if ( ltwo == ftwo) {
			return true;
		}
		return false;
}

//takes two words and returns
//the chain of those words
string WordBlender::chain_words(string a, string b) {
	a.pop_back(); a.pop_back();
	return string()+a+b;
}