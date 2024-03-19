#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int main() {
    int N, M; // N = word len, M = text len
    cin >> N >> M;

    
    char word[N+1];
    char text[M+1];
    cin >> word;
    cin >> text;

    int number = 0;
    int wordCount[26*2]{0};

    for (int i = 0; i < N; ++i) {
        if (word[i] >= 'a' && word[i] <= 'z')
            wordCount[word[i] - 'a']++;
        else if (word[i] >= 'A' && word[i] <= 'Z')
            wordCount[word[i] - 'A' + 26]++;
    }

    int count[26*2]{0};

    queue<char> windowQueue;
    
    for (int i = 0; i < M; ++i) {

        if (text[i] >= 'a' && text[i] <= 'z'){
            count[text[i] - 'a']++;
            windowQueue.push(text[i]);
        } else if (text[i] >= 'A' && text[i] <= 'Z'){
            count[text[i] - 'A' + 26]++;
            windowQueue.push(text[i]);
        }

        if ((int)windowQueue.size() == N+1) { // si la window est plus grande que le mot, on enleve le premier caractere
            char oldestChar = windowQueue.front();
            windowQueue.pop();
            if ( oldestChar >= 'a' && oldestChar <= 'z')
                count[oldestChar - 'a']--;
            else if (oldestChar >= 'A' && oldestChar <= 'Z')
                count[oldestChar - 'A' + 26]--;
        }

        // Check if the window matches the word, 
        if ((int)windowQueue.size() == N) {
            bool match = true;
            for (int j = 0; j < 26*2; j++) {
                if (count[j] != wordCount[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ++number;
            }
        }
    }
    cout << number << endl;

    return 0;
}



