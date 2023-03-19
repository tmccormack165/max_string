#include <iostream>
#include <string>
#include <vector>
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

bool quit_application(string std_input, char quit_char){
    bool exit_app = false;
    int nchar = std_input.length();
    if(nchar <= 1){
        if(nchar == 0){
            exit_app = true;
        }
        else if(std_input[0] == quit_char){
            exit_app = true;
        }
    }

    return exit_app;
}
/* Count the number of instances of the delimeter in the standard input
Parameters:
    - std_input (string): the response from the user
    - delim (string): the string that partitions entries from the user
Return:
    - (int): how many entries the user has sent
*/
int count_entries(string std_input, string delim){
    int n_entries = 0; // how many entries the user has sent
    int start_pos = 0; // initialize delimeter position to zero
    int n_delim = 0; // init count to zero
    int src_length = std_input.length(); // source is the string from standard input
    int delim_length = delim.length(); // delimeter is a string that separates entries
    assert(src_length > delim_length); // ensure that the standard input is longer than delim
    int diff = src_length - delim_length; // record diff 

    while(1){
        // find() will return the starting position of delim in std_input, or string::npos if no instances occur
        start_pos = std_input.find(delim, start_pos);
        // if a delimeter exists and the delimeter does not make up the final set of characters in the string, then increment count
        if(start_pos != string::npos && start_pos <= diff){
            n_delim++;
            start_pos += delim_length; // offset the new starting position so that repeat elements are not counted
        }
        else{
            break; // if either the end of the search string is reached, or no more instances are found, then exit.
        }
    }
    n_entries = n_delim + 1; // add one to n_delim to account for the final entry
    return n_entries;
}

int main(){
    string std_input, delim = ", ", longest_string = "", current_string = "";
    char char_delim = ',', quit_char = 'q';
    int n_entries;
    bool is_final;
    vector <string> phrases;

    // collect user input into one string
    cout << "Enter comma-separated strings (type " << quit_char << " to quit): ";
    getline(cin, std_input);

    // check if the user entered the quit character
    if(quit_application(std_input, quit_char)){
        return 0;
    }

    int occurences = 0;
    for(int i = 0; i < std_input.length(); i++){
        if(std_input[i] == char_delim){
            while(1){
                if(std_input[i] != ' ' && std_input[i] != char_delim){
                    phrases.push_back(current_string);
                    current_string = "";
                    current_string += std_input[i];
                    break;
                }
                else{
                    i++;
                }
            }
        }
        else{
            current_string += std_input[i];
        }
    }
    phrases.push_back(current_string);
    for(auto item:phrases){
        cout << item << endl;
    }

    return 0;

    



    /*
    int max_length = 0, current_len = 0;
    int input_length,

    s = new string[nwords];
    iarr = new int[nwords];

    input_length = std_input.length();

    
    For each character from standard input:
        - if the char is a delim or the char is the final char
            - if the current length is greater than the max length
                - update the max length
                - update the longest string
            - reset the current string and current length
    
    int hmr = 0;
    for(int i = 0; i < input_length; i++){
       
        
        is_final = check_final(i, input_length);
        if(std_input[i] == delim[0] || is_final){
            if(is_final){
                current_len += 1;
                current_string += std_input[i];
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
            current_string += std_input[i];
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
    
    return 0;
    
    */
}