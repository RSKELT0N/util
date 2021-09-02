#ifndef CONFIG_H
#define CONFIG_H

#define ENABLE_CODES 1

namespace util {

    #if ENABLE_CODES
        #define CODES 1
    #else
        #define CODES 0
    #endif
    
};

#endif // CONFIG_H