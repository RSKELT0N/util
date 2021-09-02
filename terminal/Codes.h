#ifndef CODES_H
#define CODES_H

#include "config.h"

//ansii escape codes
#if CODES 
    namespace util {
        namespace graphics {
            //Standard codes
            constexpr const char* PREFIX                  = "\x1b[";
            constexpr const char* SUFFIX                  = "m";
            //colour codes
            namespace colour {
                constexpr const char*  RED                = "31";
                constexpr const char*  GREEN              = "32";
                constexpr const char*  YELLOW             = "33";
                constexpr const char*  BLUE               = "34";
                constexpr const char*  MAGENTA            = "35";
                constexpr const char*  CYAN               = "36";
                constexpr const char*  WHITE              = "37";
            };
        //graphic codes -> '\x1b[[gr  aphic]1;[colour]33;m[text]
            constexpr const char*  RESET                  = "0";
            constexpr const char*  BOLD                   = "1";
            constexpr const char*  FAINT                  = "2";
            constexpr const char*  ITALIC                 = "3";
            constexpr const char*  UNDER_LINE             = "4";
            constexpr const char*  BLINK                  = "5";
            constexpr const char*  INVERSE                = "7";
            constexpr const char*  INVISIBLE              = "8";
            constexpr const char*  STRIKE_THROUGH         = "9";
        ;}
        namespace control {
            //cursor control codes   
            constexpr const char*  CURSOR_HOME            = "H";
            constexpr const char*  CURSOR_UP              = "#A";
            constexpr const char*  CURSOR_DOWN            = "#B";
            constexpr const char*  CURSOR_RIGHT           = "#C";
            constexpr const char*  CURSOR_LEFT            = "#D";
            constexpr const char*  CURSOR_DOWN_N          = "#E";
            constexpr const char*  CURSOR_UP_N            = "#F";
            constexpr const char*  CURSOR_COLUMN          = "#G";
            constexpr const char*  CURSOR_REQST           = "6n";
            constexpr const char*  CURSOR_SAVE_DEC        = "7";
            constexpr const char*  CURSOR_RESTORE_DCO     = "8";
            constexpr const char*  CURSOR_SAVE_SCO        = "s";
            constexpr const char*  CURSOR_RESTORE_SCO     = "u";
            constexpr const char*  CURSOR_VISIBLE         = "?25l";
            constexpr const char*  CURSOR_INVISIBLE       = "?25h";
            //erase codes   
            constexpr const char*  CLEAR_SCR              = "J";
            constexpr const char*  CLEAR_UNDER            = "0J";
            constexpr const char*  CLEAR_UPPER            = "1J";
            constexpr const char*  CLEAR_ENTIRE           = "2J";
            constexpr const char*  CLEAR_LINE             = "K";
            constexpr const char*  CLEAR_CURSOR_END       = "0K";
            constexpr const char*  CLEAR_CURSOR_START     = "1K";
            constexpr const char*  CLEAR_ENTIRE_LINE      = "2K";
            //screen escape codes   
            constexpr const char*  MODE_TYPE              = "=#h";
            constexpr const char*  MODE_40_25_MONO        = "=0h";
            constexpr const char*  MODE_40_25_COLR        = "=1h";
            constexpr const char*  MODE_80_25_MONO        = "=2h";
            constexpr const char*  MODE_80_25_COLR        = "=3h";
            constexpr const char*  MODE_320_200_4_COLR    = "=4h";
            constexpr const char*  MODE_320_200_MONO      = "=5h";
            constexpr const char*  MODE_640_200_MONO      = "=6h";
            constexpr const char*  MODE_LINE_WRAP         = "=7h";
            constexpr const char*  MODE_320_200_COLR      = "=13h";
            constexpr const char*  MODE_640_200_COLR      = "=14h";
            constexpr const char*  MODE_640_350_COLR      = "=15h";
            constexpr const char*  MODE_320_350_COLR      = "=16h";
            constexpr const char*  MODE_640_480_MONO      = "=17h";
            constexpr const char*  MODE_640_480_COLR      = "=18h";
            constexpr const char*  MODE_320_200_256_COLR  = "=19h";
            constexpr const char*  MODE_RESET             = "=#l";
            //private modes
            constexpr const char*  SCREEN_RESTORE         = "?47l";
            constexpr const char*  SCREEN_SAVE            = "?47h";
            constexpr const char*  SCREEN_ENABLE_BUFF     = "?1049l";
            constexpr const char*  SCREEN_SAVE_BUFF       = "?1049h";
        };
    };
#endif

#endif // CODES_H
