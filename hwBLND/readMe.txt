in the constructor create the table with chain words
read the words from the file into a unordered_multimap use first two letters as the key
all words that start with those same letters should be in the same bucket
the first section could be 
aaa[a-z] then
aab[a-z]
aac[a-z]
aa[a-z][a-z]

in the loop 
if there is a word that starts with the first two letters and ends with the last two letters
add that word in the table first row

for the second row i must find two words that end and start with then appropriate letters
there is a at most 15 rows

maybe i need an outer for loop that loops from 1 to max-word-count+1
this will be the number of rows starting at 1
for each row find a chain of size row +1

for the second row i need two words that start and end with the string and overlap
find a word that starts with the sequence 
find a word that ends with the sequence
if there is words with these properties check if they overlap

if they dont overlap find another word that ends with the sequence
if there is no overlap find another first word and repeat

in row two column 1 i am looking for a word that starts with aa and a word that ends with aa

create a function that will find the words that end with a pair
loop trough the first row of the table 
and find the appropriate word
for example apple lefty
find words that start with apaa-apzz there are 26a 26b 26c to 26z 26X26=676 10140 10815
just loop  676 times from the index of apaa and that will be all words that start with ap
its faster to loop trough the hashtable because words are guaranteed to exist

how can i find words that end with a string
ee is at index 3488
its next occurence is at 4164
and then at 4840 and then 5516
it increments by 676
if i create a loop that starts at the first occurence
aa+lastTwo and increments by 676 it will go through all words that end with lastTwo
some may be empty strings
the size of an empty string is 0

first occurence of le at 290

to find words that overlap 
i find the first word
and last word
for each first word i need to loop trough all the last words vector
if there is no match move to the second first word

for first to end
 for last to end
  check overlap

for the third row i have to look at the second row
if the column is rots then i am looking for a word in the second row
that either starts with ro or ends with ts
for every 2chain that starts with ro look for a word that ends in ts and overlaps
if there is none look for 
a chain that ends in ts and find a word that starts with ro and overlaps
basicly what im trying to do is add a word to the beggining or end of a
2 chain to form a 3 chain word

(insert at the end)
i have a list of chains that start with ij
and a list of words that end with kl
for each chain that starts with 
	for each kl
	 if overlap
	 set; break;

(insert at the begining)
if nothing was inserted
look for 2 chains tha end with kl
an look for words that start with ro
for each chain that ends with
	for each ij
	if overlap 
	set; 

create a function that loops trough a row in the table and returns all 
2chains that start with the firstTwo
aa** goes from 0 to 675 aazz
bb** goes from 18252 to 18927 bbzz
there is a diference of 675
so starting at firstTwo +"aa"
loop trough 675 to find 2 chain strings that start with firstTwo

repeat for all rows
but change it so that it looks for that chain in the previous row

for the second row the chain is in row 1
for the third row the chain is in row 2

if i am loking for a 3 chain 
then i find a 1 chain 
and add the to words to the beginning and end
i have to look two rows previous

find a chain that starts with fir[st] and starts with [la]st

test 3 i got to row 1, 2, 3, 4, 5

//checks and inserts chains in table
void insert_table(string ftwo, string ltwo int r, int c){
		vector<string>first = find_first_two(ftwo, r-2);//chain
		vector<string>last = find_last_two(ltwo, 0);//word
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
		 


}//end insettable





 

column 4 and 3 are inserting same chain
i think the problem is tha if the table is of size less than 10


this takes to long maybe as i insert in table also insert in unordered multimap 
to use with the next row. that would avoid looping 675 times to 
find chains in previous rows. then overwite the map
unordered_multimap<string, string >prevf first
unordered_multimap<string, string >prevl last
whenever a word gets inserted (starting in row 1)
add it to prevf with key ij
add it to prevl with key kl
this way i can find words that start with and end with a key faster

(insert at the end)
i have a list of chains that start with ij(prevf)
and a list of words that end with kl(wordsb)
for each chain that starts with 
	for each kl
	 if overlap
	 set; 


if(prevf(key) && wordsb(key) are not empty)
  for each prevf(key)
    for each wordsb(key)
      if overlap 
      	set

how to check if its the first time in that row

forget the multimap 
maybe instead of looping 675 to find the words to plug in the chain
i am looking for words that end in kl and checking if they overlap
another way to do that is
to find words that start with the last letters of chain 
and check if they end with kl

1) find chains that start with ij
2) store in a string the last letters of each chain 
	use start end loops troug multimap
	returns string with start endl letters
3) find words that start with that string and end with kl

1) find chains that start with ij
2) find words that end with kl
3) check if they overlap

i can speed up find last two function by looping trough 
the multimap instead of table
because it is only used in row == 1

is there any way to get the chains without looping trough the table

maybe a better way is to start at the end 
for all words that end with kl
  find a chain that starts  with ij and ends with firstlettersofword

1) loop trough wordsb
2) string ends = it->second[0]+[1]
3) 

 this approach requires me to find words in dictionary by last letters
 it actualy builds it prety fast
 why dosnt row 3 find anything

 if row == 1 i am looking for
 a word that startst with firsttwo
 a word that ends with lasttwo
 and that they overlap
  for all ij
    for all kl
    if overalp
    set

row 0:
loop trough the words 
for each word get its index plug it in table

row 1: 
for each word
  for each word that overlaps
  get index
  plug in table
  plug in chain list

row >= 2 && < max_word_count
for each chain 
  for each word that overlaps 
  get index
  plug in table 
  plug in chain list

when row increments clear the map
i got to line 80
 if (row >= 2 && row < max_word_count&&row<10)