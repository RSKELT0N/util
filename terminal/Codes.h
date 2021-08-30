#ifndef CODES_H
#define CODES_H

#include "config.h"

//ansii escape codes
#if CODES 
     //Standard codes
    #define PREFIX                  "\x1b["
    #define SUFFIX                  "m"
     //colour codes   
    #define  RED                    "31"
    #define  GREEN                  "32"
    #define  YELLOW                 "33"
    #define  BLUE                   "34"
    #define  MAGENTA                "35"
    #define  CYAN                   "36"
    #define  WHITE                  "37"
     //graphic codes -> '\x1b[[gr  aphic]1;[colour]33;m[text]
    #define  RESET                  "0"
    #define  BOLD                   "1"
    #define  FAINT                  "2"
    #define  ITALIC                 "3"
    #define  UNDER_LINE             "4"
    #define  BLINK                  "5"
    #define  INVERSE                "7"
    #define  INVISIBLE              "8"
    #define  STRIKE_THROUGH         "9"
     //cursor control codes   
    #define  CURSOR_HOME            "H"
    #define  CURSOR_UP              "#A"
    #define  CURSOR_DOWN            "#B"
    #define  CURSOR_RIGHT           "#C"
    #define  CURSOR_LEFT            "#D"
    #define  CURSOR_DOWN_N          "#E"
    #define  CURSOR_UP_N            "#F"
    #define  CURSOR_COLUMN          "#G"
    #define  CURSOR_REQST           "6n"
    #define  CURSOR_SAVE_DEC        "7"
    #define  CURSOR_RESTORE_DCO     "8"
    #define  CURSOR_SAVE_SCO        "s"
    #define  CURSOR_RESTORE_SCO     "u"
    #define  CURSOR_VISIBLE         "?25l"
    #define  CURSOR_INVISIBLE       "?25h"
     //erase codes   
    #define  CLEAR_SCR              "J"
    #define  CLEAR_UNDER            "0J"
    #define  CLEAR_UPPER            "1J"
    #define  CLEAR_ENTIRE           "2J"
    #define  CLEAR_LINE             "K"
    #define  CLEAR_CURSOR_END       "0K"
    #define  CLEAR_CURSOR_START     "1K"
    #define  CLEAR_ENTIRE_LINE      "2K"
     //screen escape codes   
    #define  MODE_TYPE              "=#h"
    #define  MODE_40_25_MONO        "=0h"
    #define  MODE_40_25_COLR        "=1h"
    #define  MODE_80_25_MONO        "=2h"
    #define  MODE_80_25_COLR        "=3h"
    #define  MODE_320_200_4_COLR    "=4h"
    #define  MODE_320_200_MONO      "=5h"
    #define  MODE_640_200_MONO      "=6h"
    #define  MODE_LINE_WRAP         "=7h"
    #define  MODE_320_200_COLR      "=13h"
    #define  MODE_640_200_COLR      "=14h"
    #define  MODE_640_350_COLR      "=15h"
    #define  MODE_320_350_COLR      "=16h"
    #define  MODE_640_480_MONO      "=17h"
    #define  MODE_640_480_COLR      "=18h"
    #define  MODE_320_200_256_COLR  "=19h"
    #define  MODE_RESET             "=#l"
     //private modes
    #define  SCREEN_RESTORE         "?47l"
    #define  SCREEN_SAVE            "?47h"
    #define  SCREEN_ENABLE_BUFF     "?1049l"
    #define  SCREEN_SAVE_BUFF       "?1049h"
    
#endif

#endif // CODES_H
