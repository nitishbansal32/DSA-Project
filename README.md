# DSA-Project
This directory contains our project for the submission which is due on 7th June.
IMPLEMENTATION OF TRIE 
Using trie to search patterns in a string
 
GROUP MEMBERS 
Nitish Kumar Bansal – 20BCE0999 
Bhoomi Abichandani – 20BDS0242 
Akshita Langer          – 20BCE2872 
 
HP | Data structure and algorithms | 21/05/21 
6 
INTRODUCTION TO TRIE – 
 
A trie is a tree-like data structure whose nodes store the letters of an alphabet. By structuring the nodes in a particular way, words and strings can be retrieved from the structure by traversing down a branch path of the tree. 

<p align = "center">
<img width = "600" hiegth = "600" src = "https://user-images.githubusercontent.com/72986912/119155134-79f2f080-ba70-11eb-834a-78bd679c876b.png">
</p>

Each trie has an empty root node, with links to other nodes —
one for each possible alphabetic value.
The shape and the structure of a trie is always a set of linked 
nodes, connecting back to an empty root node. The number 
of child nodes in a trie depends completely upon the total 
number of values possible.

<p align = "center">
<img width = "600" hiegth = "600" src = "https://user-images.githubusercontent.com/72986912/119156773-2ed9dd00-ba72-11eb-88da-bbed1e7cfe51.png">
</p>

In the above example, we have a trie that has an empty root node, which has links to child nodes. If we look at the crosssection of one of these child nodes, we’ll notice that a single node in a trie contains two things: 
1. A value that might be 	null	 
2. An array of references to child nodes, all of which 
also might be null. 
""
Each node in a trie, including the root node itself, has only these two aspects to it. When a trie representing the English language is created, it consists of a single root node, whose value is usually set to an empty string: . 
 
That root node will also have an array that contains 26 
references, all of which will point to 	null	 at first. As the trie 
grows, those pointers start to get filled up with references to 
other nodes. 
We know that each node contains an array of references/links to other nodes. We can use the array’s indexes to find specific references to nodes. For example, our root node will hold an array of indexes 0 through 25, since there are 26 possible slots for the 26 letters of the alphabet. 
Since the alphabet is in order, we know that the reference to the node that will contain the letter A will live at index 0. 
Trie traversal  
In the following trie, we’re representing a sentence which is “Peter Piper picked a peck of pickled peppers”.  
Looking at our trie, we can see that we have an empty root node, as is typical for a trie structure. We also have six different words that we’re representing in this trie: Peter, piper, picked, peck, pickled, and peppers. 
Notice how there are six different “branches” to this trie, one for each word that’s being represented. We can also see that some words are sharing parent nodes. For example, all of the branches for the words Peter, peck, and peppers share the nodes for p and for e. Similarly, the path to the 
word 	picked	 and 	pickled	 share the nodes 	p, i	, c	, and k	. 
 
 
So, if we want to add the word pecked to this list of words represented by this trie, we’d need to do two things  
 
1. First, we’d need to check that the word 	pecked	 doesn’t 
already exist in this trie. 
 
2. Next, if we’ve traversed down the branch where this word ought to live and the words doesn’t exist yet, we’d insert a value into the node’s reference where 
the word should go. In this case, we’d insert 	e and 	d at 
the correct references. 
 
<p align = "center">
<img width = "600" hiegth = "600" src = "https://user-images.githubusercontent.com/72986912/119157441-d0612e80-ba72-11eb-9fa5-3b2e077cb32c.png">
</p>

DELETING FROM A TRIE 
 
<p align = "center">
<img width = "600" hiegth = "600" src = "https://user-images.githubusercontent.com/72986912/119157566-f090ed80-ba72-11eb-861e-8fa805393e4d.png">
</p>

For deletion, we’d need to take two steps: 
1. First, we need to find the node that contains the 
value for that key, and set its value to 	null	. This means 
"pies"
12	 to 	null
traversing down and finding the last letter of the word 	, and then resetting the value of the last node from 	. 
2. Second, we need to check the node’s references and see if 
all of its pointers to other nodes are also 	null	. If all of them 
are empty, that means that there are no other 
words/branches below this one, and they can all be 
removed. However, if there are pointers for other nodes that do have values, we don’t want to delete the node that we’ve just set to null. 
 
 
There are some great benefits to using tries, however. For starters, the bulk of the work in creating a trie happens early on. This makes sense if we think about it, because when we’re first adding nodes, we have to do some heavy lifting of allocating memory for an array each time. But, as the trie grows in size, we have to do less work each time to add a value, since it’s likely that we’ve already initialized nodes and their values and references. Adding “intermediate nodes” becomes a lot easier since the branches of the trie have already been built up. 
Another fact in the “pro column” for tries is that each time we add a word’s letter, we know that we’ll only ever have to look at 26 possible indexes in a node’s array, since there are only 26 possible letters in the English alphabet. Even though 26 seems like a lot, for our computers, it’s really not that much space. However, the fact that we are sure that each array will only ever contain 26 references is a huge benefit, because this number will never change in the context of our trie. It is a constant value. 
ADVANTAGES OF TRIE: 
 
1.	It can be insert faster and search the string than hash tables and binary search trees. 
 
2.	It provides.an alphabetical filter of entries by the key of the node. 
 
DISADVANTAGES OF TRIE: 
1.	It requires more memory to store the strings. 
 
2.	It is slower than the hash table. 
 
 
BIG O TIME COMPLEXITY 
The amount of time it takes to create a trie is tied directly to how many words/keys the trie contains, and how long those keys could potentially be. The worst-case runtime for creating a trie is a combination of m, the length of the longest key in the trie, and n, the total number of keys in the trie. Thus, the worst case runtime of creating a trie is O(mn). 
 
 
The time complexity of searching, inserting, and deleting from a trie depends on the length of the word a that’s being searched for, inserted, or deleted, and the number of total words, n, making the runtime of these operations O(an). Of course, for the longest word in the trie, inserting, searching, and deleting will take more time and memory than for the shortest word in the trie. 
APPLICATIONS OF TRIE: 
Tries rarely used exclusively; usually, they’re used in combination with another structure, or in the context of an algorithm.  
Tries are also used for matching algorithms and implementing things like spellcheckers, and can also be used for implementing versions of radix sort, too. 
 
IMPLEMENTATION: Pattern Searching using a Trie of all Suffixes 
 
How to search a pattern in the built Trie? 
 
Following are steps to search a pattern in the built Trie: 
 
1)	Starting from the first character of the pattern and root of the Trie, do following for every character. 
a)	For the current character of pattern, if there is an edge from the current node, follow the edge. 
b)	If there is no edge, print “pattern doesn’t exist in text” and 
PAGE 
return. 
 
2)	If all characters of pattern have been processed, i.e., there is a path from root for characters of the given pattern, then print print all indexes where pattern is present. To store indexes, we use a list with every node that stores indexes of suffixes starting at the node. 




