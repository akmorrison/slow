#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> getlines()
{
        vector<string> lines;
        while(cin){
                string newline;
                getline(cin, newline);
                lines.push_back(newline);
        }
        if(lines.back() == "")
                //remove trailing whitespace
                lines.pop_back();
        return lines;
}

string string_to_print(string full_string, int line, int iter, int num_lines, int max_line_length)
{
        if(full_string.length() < iter)
                return full_string;
        int length = (int) sqrt(max(iter*iter - 8*line*line, 0));
        return full_string.substr(0,length);        
}

int main()
{
        //get all the lines
        vector<string> lines = getlines();
        if(lines.size() == 0)
                return 1;
        //find the maximum line length
        int maxlen = lines[0].length();
        for(const string& j : lines)
                if(j.length() > maxlen) maxlen = j.length();

        int iter = 0;
        bool finished = false;
        while(!finished){
                finished = true;
                if(iter != 0)
                        for(int j = 0; j < lines.size(); j++)
                                cout << "\e[A";
                for(int i = 0; i < lines.size(); i++){
                        string j = string_to_print(lines[i], i, iter, 
                                                   lines.size(), maxlen);
                        if(j != lines[i])
                                finished = false;
                        cout << j << endl;
                }
                iter++;
                usleep(300 * 1000);
        }
}
