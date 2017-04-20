#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <cmath>
#include "args.h"

using namespace std;

vector<string> getlines()
{
        vector<string> lines;
        while(cin){ string newline;
                getline(cin, newline);
                lines.push_back(newline);
        }
        if(lines.back() == "")
                //remove trailing whitespace
                lines.pop_back();
        return lines;
}

string string_to_print_tl(string full_string, int line, int iter, int num_lines, int max_line_length)
{
        if(full_string.length() < iter)
                return full_string;
        int length = (int) sqrt(max(iter*iter - 8*line*line, 0));
        return full_string.substr(0,length);        
}

string string_to_print_cc(string full_string, int line, int iter, int num_lines, int max_line_length)
{
        int center_x = max_line_length / 2;
        int center_y = num_lines / 2;
        int characters_to_print = sqrt(max(iter*iter - (line-center_y)*(line-center_y), 0));
        int preceeding_spaces = center_x - characters_to_print;

        if(preceeding_spaces <= 0)
                return full_string;
        string return_str;
        for(int i = 0; i < full_string.length(); i++){
                if(i < preceeding_spaces)
                        return_str += " ";
                else if(i - preceeding_spaces < characters_to_print * 2)
                        return_str += full_string[i];
        }
        return return_str;

        /*
        ............c_to_print....
        ..y.......|----...........
        .......dl.|../............
        ..........|./..iter.......
        ..cy......c...............
        ..........................
        ..iter^2 = ctp^2 + dl^2...
        ..ctp = sqrt(iter^2-dl^2).
        ..........................
        */
}

string (*get_string_func)(string, int, int, int, int) = string_to_print_cc;

int main(int argc, char *argv[])
{
        int speed;
        //do argument things
        try{
                Args args(argc, argv);
                speed = args.speed;
        }
        catch(const char* msg){
                cerr << "Exception: " << msg << endl;
                return 1;
        }
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
                        string j = get_string_func(lines[i], i, iter, 
                                                   lines.size(), maxlen);
                        if(j != lines[i])
                                finished = false;
                        cout << j << endl;
                }
                iter++;
                usleep(speed);
        }
}
