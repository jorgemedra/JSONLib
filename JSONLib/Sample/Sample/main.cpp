/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jorgemedra
 *
 * Created on July 31, 2016, 5:23 PM
 */
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>


#include "TEST.h"
#include "TESTW.h"


int main(int argc, char **argv) {
    TEST t;
    
	t.json_parse_1();
	t.json_parse_2();
	t.json_parse_3();
	t.json_parse_4();
    t.json_parse_5();
    
    TESTW tw;
    
    tw.json_parse_1();
    tw.json_parse_2();
    tw.json_parse_3();
    tw.json_parse_4();
    tw.json_parse_5();

	return 0;
}


