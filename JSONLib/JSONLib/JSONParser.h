//
//  JSONParser.h
//  JSONLib
//
//  Created by Jorge Omar Medra Torres on 25/02/18.
//  Copyright © 2018 Jorge Omar Medra Torres. All rights reserved.
//

#ifndef JSONParser_h
#define JSONParser_h

/*
 #include<cstdlib>
 #include<iostream>
 #include<cstring>
 #include<iostream>
 #include<sstream>
 #include<iomanip>
 #include<utility>
 
 
 #include<string>
 #include<cstdio>
 #include<vector>
 #include<map>
 */

#include<cstdlib>
#include<iostream>


#include "JSONLib.h"

//using namespace std;
//using namespace json::common;

namespace json
{
    
    namespace utf8
    {
        class JSONParser
        {
            streambuf* _stream;
            int _offset;
            
            char getCurrentChar();
            void moveNextChar();
            void movePrevChar();
            void moveOffsetTo(int pos);
            //void findBeginToken();
            void skipEmptyChars();
            string readToken();
            void resetStreamOffset(int offset=0);
            std::tuple<JSONType, int, string> detectType();
            
            std::tuple<string, int, string> parseKey();
            std::tuple<JSONObject, int, string> parseValue();
            
            std::pair<int, string> parseObject(JSONObject& json);
            std::pair<int, string> parseArray(JSONObject& json);
            
            std::tuple<string, int, string> parseNull();
            std::tuple<bool, int, string>  parseBoolean();
            std::tuple<double, int, string> parseNumber();
            std::tuple<string, int, string> parseString();
            
        public:
            
            JSONParser():_offset{0}{}
            
            std::pair<int, string> parse(streambuf* stream, JSONObject&);
        };
    }
    
    namespace wide
    {
        class JSONParser
        {
            wstreambuf* _stream;
            int _offset;
            
            wchar_t getCurrentChar();
            void moveNextChar();
            void movePrevChar();
            void moveOffsetTo(int pos);
            //void findBeginToken();
            void skipEmptyChars();
            wstring readToken();
            void resetStreamOffset(int offset=0);
            std::tuple<JSONType, int, wstring> detectType();
            
            std::tuple<wstring, int, wstring> parseKey();
            std::tuple<JSONObject, int, wstring> parseValue();
            
            std::pair<int, wstring> parseObject(JSONObject& json);
            std::pair<int, wstring> parseArray(JSONObject& json);
            
            std::tuple<wstring, int, wstring> parseNull();
            std::tuple<bool, int, wstring>  parseBoolean();
            std::tuple<double, int, wstring> parseNumber();
            std::tuple<wstring, int, wstring> parseString();
            
        public:
            
            JSONParser():_offset{0}{}
            
            std::pair<int, wstring> parse(wstreambuf* stream, JSONObject&);
            std::wstring wconvert(std::string);
        };
    }
}


#endif /* JSONParser_h */
