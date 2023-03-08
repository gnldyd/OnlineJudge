#include <iostream>
#define MAX_B 500
#define MAX_WORD 50

using namespace std;

int KMPCount(string sentence, string word)
{
    int kmp_count = 0, sentence_length = sentence.length(), word_length = word.length();
    int word_prefix_suffix_common_length[MAX_WORD] = {0, };
    int common_length, sentence_index, word_index;

    // Calculate word's common length of prefix and suffix.
    common_length = 0;
    word_index = 1;
    while(word_index < word_length)
    {
        if(word[word_index] == word[common_length])
        {
            word_prefix_suffix_common_length[word_index++] = ++common_length;
        }
        else if(common_length > 0)
        {
            common_length = word_prefix_suffix_common_length[common_length - 1];
        }
        else
        {
            word_prefix_suffix_common_length[word_index++] = 0;
        }
    }

    // Calculate KMP count.
    sentence_index = word_index = 0;
    while((sentence_length - sentence_index) >= (word_length - word_index)) 
    {
        if(word[word_index] == sentence[sentence_index])
        {
            ++word_index;
            ++sentence_index;
        }
        if(word_index == word_length)
        {
            ++kmp_count;
            word_index = word_prefix_suffix_common_length[word_index - 1];
        }
        else if(sentence_index < sentence_length && word[word_index] != sentence[sentence_index])
        {
            if(word_index > 0)
            {
                word_index = word_prefix_suffix_common_length[word_index - 1];
            }
            else
            {
                ++sentence_index;
            }
        }
    }
    return kmp_count;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int B, N, number, total_low, total_high, C;
    string word, low[MAX_B], high[MAX_B];
    cin >> B;
    for(int i = 0; i < B; ++i)
    {
        cin >> low[i];
    }
    for(int i = 0; i < B; ++i)
    {
        cin >> high[i];
    }
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        total_low = total_high = 0;
        cin >> word;
        for(int j = 0; j < B; ++j)
        {
            total_low += KMPCount(word, low[j]);
            total_high += KMPCount(word, high[j]);
        }
        C = total_high - total_low;
        cout << (C > 0 ? "LOW " + to_string(C) : C < 0 ? "HIGH " + to_string(-C) : "GOOD") << endl;
    }
    return 0;
}