#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include "args.h"
#include "animations.h"

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


int main(int argc, char *argv[])
{
        int speed;
        string (*get_string_func)(string, int, int, int, int);
        //do argument things
        try{
                Args args(argc, argv);
                speed = args.speed;
                get_string_func = args.get_string_func;
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
