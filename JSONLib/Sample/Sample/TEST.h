#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <JSONLib.h>

class TEST
{
private:
    void print(int level, json::utf8::JSONObject& val, int index);

public:
    TEST();
    ~TEST();
    
    bool json_parse_1();
    bool json_parse_2();
    bool json_parse_3();
    bool json_parse_4();
    bool json_parse_5();

    
};


#endif // TEST_H
