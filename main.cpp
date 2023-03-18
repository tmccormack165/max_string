#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool check_final(int i, int input_length){
    bool is_final = false;
    if(i == (input_length - 1)){
        is_final = true;
    }
    return is_final;
}

int count_delims(string std_input, char delim){
    int count = 0;
    for(int i = 0; i < std_input.length(); i++){
        if(std_input[i] == delim){
            count++;
        }
    }
    return count;
}

int main(){
    string std_input, longest_string = "", current_string = "";
    string* s;
    int *iarr;

    char delim = ' ';
    int max_length = 0, current_len = 0;
    int input_length, nwords;
    bool is_final;
    cout << "Enter space-separated words (type q to quit): ";
    getline(cin, std_input);
    nwords = count_delims(std_input, delim) + 1;
    s = new string[nwords];
    iarr = new int[nwords];

    input_length = std_input.length();

    /*
    For each character from standard input:
        - if the char is a delim or the char is the final char
            - if the current length is greater than the max length
                - update the max length
                - update the longest string
            - reset the current string and current length
    */
    int hmr = 0;
    for(int i = 0; i < input_length; i++){
        current_string += std_input[i];
        is_final = check_final(i, input_length);
        if(std_input[i] == delim || is_final){
            if(is_final){
                current_len += 1;
            }
            s[hmr] = current_string;
            iarr[hmr] = current_len;
            if(current_len >= max_length){
                max_length = current_len;
                longest_string = current_string;
            }
            
            current_string = "";
            current_len = 0;
            hmr++;
        }
        else{
            current_len += 1;
        }
        
        
    }
    

    cout << "Longest Words: " << endl;
    for(int i = 0; i < nwords; i++){
        if(iarr[i] == max_length){
            cout << s[i] << endl;
        }
    }
    delete[] s;
    delete[] iarr;

    /*
    while(cin >> word1){
        cout << "Word: " << word1 << endl;
        w1_len = word1.length();
        for(int i = 0; i < w1_len; i++){
            cout << word1[i] << endl;
            if(word1[i] == '\0'){
                cout << "Found newline" << endl;
            }
        }
    }
    */

    return 0;
}