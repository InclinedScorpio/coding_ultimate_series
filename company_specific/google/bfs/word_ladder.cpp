// https://leetcode.com/problems/word-ladder/

/**
 * LOGIC: Understanding this problem is a graph traversal problem.
 * We can think of each word as a node in a graph, and an edge exists between two nodes if they differ by exactly one letter.
 * We can use BFS to find the shortest path from the beginWord to the endWord.
 * The BFS will explore all possible transformations level by level, ensuring that we find the shortest path.
 * The key is to generate all possible transformations of the current word by changing one letter at a time and checking if the new word exists in the word list.
 * If it does, we add it to the queue for further exploration.
 * The process continues until we either find the endWord or exhaust all possibilities.
 */
class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> store;
            for(int i=0;i<wordList.size();i++) {
                store.insert(wordList[i]);
            }
            if(store.find(endWord)==store.end()) return 0; //edge-case
    
            // bfs
            queue<pair<string, int>> queueStore;
            queueStore.push({beginWord, 1});
            store.erase(beginWord);
            while(!queueStore.empty()) {
                pair<string, int> currWord = queueStore.front();
                queueStore.pop();
                for(int i=0;i<currWord.first.length();i++) {
                    for(int asciiChar=97;asciiChar<=122;asciiChar++) {
                        string checkChar = currWord.first;
                        checkChar[i] = (char)asciiChar;
                        if(checkChar==endWord) return currWord.second+1;
                        if(store.find(checkChar)!=store.end()) {
                            queueStore.push({checkChar, currWord.second+1});
                            store.erase(checkChar);
                        }
                    }
                }
            }
            return 0;
        }
    };
    