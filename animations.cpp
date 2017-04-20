#include <string>
#include <cmath>
#include "animations.h"

using namespace std;

string string_to_print_tl(string full_string, int line, int iter, int num_lines, int max_line_length)
{
        int length = (int) sqrt(max(iter*iter - line*line, 0));
        if(full_string.length() <= length)
                return full_string;
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
}

