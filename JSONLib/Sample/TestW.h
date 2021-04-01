//
//  TestW.hpp
//  Sample
//
//  Created by Jorge Omar Medra Torres on 02/04/18.
//  Copyright © 2018 Jorge Omar Medra Torres. All rights reserved.
//


#ifndef TESTW_H
#define TESTW_H

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <JSONLib.h>


class TESTW
{
private:
    void print(int level, json::wide::JSONObject& val, int index);
    
public:
    TESTW();
    ~TESTW();
    
    bool json_parse_1();
    bool json_parse_2();
    bool json_parse_3();
    bool json_parse_4();
    bool json_parse_5();
    
    
};


#endif // TEST_H
