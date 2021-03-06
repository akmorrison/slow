#include"args.h"
#include"animations.h"
#include<iostream>
#include<string>
#include<stdlib.h>

void setOption(int& field, char* value){
        field = atoi(value);
        if(field <= 0)
                throw "Invalid speed parameter";
}

void setStyle(string (**get_string_func)(string, int, int, int, int), string func_name){
        if(func_name == "topleft")
                *get_string_func = string_to_print_tl;
        else if(func_name == "centercircle")
                *get_string_func = string_to_print_cc;
        else
                throw "Invalid style parameter";
}

Args::Args(int argc, char* argv[]){
        //default values
        speed = 100 * 1000;
        get_string_func = string_to_print_tl;
        print_help = false;

        bool skip_flag = false;
        for(int i = 1; i < argc; i++){
                if(skip_flag){
                        skip_flag = false;
                        goto endfor;
                }
                //if the argument starts with a -
                if(*argv[i] == '-'){
                        while(*(++argv[i])){
                                if(*argv[i] == 'u'){
                                        if(i == argc -1)
                                                throw "Missing parameter";
                                        setOption(speed, argv[i+1]);
                                        skip_flag = true;
                                        goto endfor;
                                }
                                else if(*argv[i] == 's') {
                                        if(i == argc -1)
                                                throw "Missing parameter";
                                        setStyle(&get_string_func, string(argv[i+1]));
                                        skip_flag = true;
                                        goto endfor;
                                }
                                else if(*argv[i] == 'h') {
                                        print_help = true;
                                }
                                else{
                                        throw "Unrecognized Option!";
                                }
                        }
                }
                endfor:
                continue;
        }
}
