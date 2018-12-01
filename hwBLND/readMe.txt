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

i have a list of chains that start with ij
and a list of words that end with kl
for each chain
	for each kl
	 if overlap
	 set; break;

if nothing was inserted
look for 2 chains tha end with kl
an look for words that start with ro
for each chain
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