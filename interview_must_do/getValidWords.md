// This is a hackerrank problem solving question asked in interviews and for problem solving evaluation tests.
In this task, a basic prototype service for detecting the word typed by a user by swiping the finger from key to key on the keyboard, more popularly known as glide typing, is to be implemented. A user usually intends to type a subsequence of the characters they swiped over.
Given an input string, s, and an array of n strings, dictionary, find the lexicographically smallest word in the dictionary that is a subsequence of the given string s. If there is no such string, return the string "-1" as the answer.
Note: A string x is considered lexicographically smaller than another string y if the string x will occur before y in dictionary order.

## Example
Suppose s = "hgferyjkllkop", and dictionary = ["coffee", "coding", "happy", "hello", "hop"]
The only possible valid words that are a subsequence of the given string are "hello" and "hop". Since
"hello" is lexicographically smaller, report "hello" as the answer.
Function Description
Complete the function getValidWord in the editor below.
getvalidWord takes the following arguments: string s: the string given by the user
string dictionary[n]: the list of valid words
Returns
string: the lexicographically smallest word that is a subsequence of the user-given string

```js
function getValidWord(s, dictionary) {
  let smallestWord = "-1";

  for (const word of dictionary) {
    let i = 0, j = 0;
    while (i < word.length && j < s.length) {
      if (word[i] === s[j]) {
        i++;
      }
      j++;
    }

    if (i === word.length && (smallestWord === "-1" || word < smallestWord)) {
      smallestWord = word;
    }
  }
  return smallestWord;
}
```
