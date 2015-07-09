#include <map>
#include <queue>
#include <string>
#include <set>
using namespace std;

// node that is used to build a graph of the word laddeer
typedef struct WordNodeStruct WordNode;
struct WordNodeStruct {
    // the word this node represents
    string word;
    // how many steps it is from the start
    int numSteps;
    // whether or not this word has been visited yet
    bool isVisited;

    // the path back to the original word
    WordNodeStruct* prevWordNode;
};

void printWordPath(WordNode* wordNode);
void findWordPath(string startWord, string endWord);
vector<string> getAdjacentWords(string word);
vector<string> getAdjacentWords(string word);
void addWordToWordNodeMap(string word);

set<string> wordDict = { "hot","dot","dog","lot","log", "hit", "cog" };
map<string, WordNode*> wordNodeMap;

int main() {
    string startWord = "hit";
    string endWord = "cog";

    printf("WORD LADDER: %s -> %s\n", startWord.c_str(), endWord.c_str());

    findWordPath(startWord, endWord);

    WordNode* endWordNode = wordNodeMap.find(endWord)->second;
    printf("Total Steps: %u\nPath: ", endWordNode->numSteps);
    printWordPath(endWordNode);
    printf("\n");

    return 0;
}

void printWordPath(WordNode* wordNode) {
    if(wordNode) {
        printWordPath(wordNode->prevWordNode);
        printf("%s ", wordNode->word.c_str());
    }
}

void findWordPath(string startWord, string endWord) {
    // we need a queue of word nodes because its a BFS
    queue<WordNode*> wordNodeQueue;

    // add the starting word node to the queue
    WordNode* startNode = new WordNode();
    startNode->word = startWord;
    startNode->numSteps = 0;
    startNode->isVisited = false;
    wordNodeQueue.push(startNode);

    // add the starting word node to the map
    wordNodeMap[startWord] = startNode;

    // continue until the word node queue is empty
    while(!wordNodeQueue.empty()) {

        // get the first word node off the queue
        //
        // this will be the starting word on first iteration
        WordNode* wordNode = wordNodeQueue.front();
        wordNodeQueue.pop();
        wordNode->isVisited = true;

        // if the word is the end word we are done because it is now visited
        // so that means it has the shortest path
        if(wordNode->word == endWord) {
            return;
        }

        // loop through all adjacent words
        vector<string> adjacentWords = getAdjacentWords(wordNode->word);
        for(uint32_t i = 0; i < adjacentWords.size(); i++) {
            // make sure the word is in the word node map

            WordNode* adjacentWordNode = wordNodeMap.find(adjacentWords[i])->second;

            // determine if this node has been visited before
            if(!adjacentWordNode->isVisited) {
                // if the current number of steps is less than the existing number of steps
                // then update the adjacent node
                int numSteps = wordNode->numSteps + 1;
                if(numSteps < adjacentWordNode->numSteps) {
                    adjacentWordNode->numSteps = numSteps;
                    adjacentWordNode->prevWordNode = wordNode;
                }

                // add the word node to the queue of nodes to process
                wordNodeQueue.push(adjacentWordNode);
            }
        }
    }
}

vector<string> getAdjacentWords(string word) {

    vector<string> adjacentWords;

    // loop through the word changing one letter at a time
    for(uint32_t i = 0; i < word.length(); i++) {
        for(char j = 'a'; j <= 'z'; j++) {
            // don't test if its not actually changing the letter
            if(word[i] != j) {
                // store temp so we can restore it
                char temp = word[i];
                word[i] = j;
                set<string>::iterator wordDictIterator = wordDict.find(word);
                if(wordDictIterator != wordDict.end()) {
                    adjacentWords.push_back(*wordDictIterator);
                    // make sure the word is in the node map
                    addWordToWordNodeMap(*wordDictIterator);
                }
                word[i] = temp;
            }
        }
    }

    return adjacentWords;
}

void addWordToWordNodeMap(string word) {
    map<string, WordNode*>::iterator wordNodeMapIterator = wordNodeMap.find(word);
    if(wordNodeMapIterator == wordNodeMap.end()) {
        WordNode* wordNode = new WordNode();
        wordNode->word = word;
        wordNode->isVisited = false;
        wordNode->numSteps = 9999;
        wordNodeMap[word] = wordNode;
    }
}
