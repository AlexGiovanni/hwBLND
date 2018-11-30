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
add that word in the table

for the second row i must find two words that end and start with then appropriate letters
in the nested for loop i is the row j is the column
there is a at most 15 rows

maybe i need an outer for loop that loops from 1 to max-word-count+1
this will be the number of rows starting at 1
for each row find a chain of size row
l cannot be the column because l only loops 26 times before reseting

for the second row i need two words that start and end with the string and overlap
find a word that starts with the sequence 
find a word that ends with the sequence
if they dont overlap find another word that ends with the sequence
if there is no overlap find another first word and repete

in row two column 1 i am looking for a word that starts with aa and a word that ends with aa
i will create an unordered multimap that uses that last two letters as key(maybe not)

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
