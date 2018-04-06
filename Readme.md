#JSONLib for C++ 2.0

JSONLib is a dynamic library for c++ which allows parse,read and build data with JSON format, using [ECMAC-404 standar for JSON](https://www.json.org/index.html), and can read file with *UTF-8* or *UTF-16* content.

The repository has 2 projects

+ **JSONLib** is the main project and it contains the source code and distribution file for JSONLib.
+ **Sample** project has a sample to use the JSONLib.
#Using JSONLib

##prerequisites

This code was developed with:

+ *XCode Version 8.0*
+ *C++11.*

> If you want use it library with another OS just recompile the library.

Include Header file **JSONLib.h** (*JSONLib/include/*) and link with the library file **libJSONLib.so** (*JSONLib/Build/Products/Release*).

#How to use

##Select *UTF-8* or *UTF-16*

To work with *UTF-8* you must use the namespace `json::utf8`:

```c++
using namespace json::utf8;
```

To work with *UTF-16* you must use the namespace `json::wide`:

```c++
using namespace json::wide;
```

> for this mode (*UTF-16*) the library use `wstring` and, for this reason, all the strings must be handled as UTF-16: `L"My Wide String"`.

No matter what kind of codec was choosed, there is a names pace that must be added to handled the `JSONObect`: `json::common`, wich has the definitions of `JSONType` that could has every `JSONObject` and error definitions (Codes and Descriptions).

```c++
using namespace json::common;
```


##Load and parse a JSON File or JSON String

**JSONLib** can read and parse a file with JSON content, in UTF-8 or UTF-16.

To load a file just the method `JSONObject::loadJSONByFile`, as this sample shows:

```c++
    JSONObject obj;

    string jsonFile = "../utf-8.json";
    pair<int,string> res = obj.loadJSONByFile(jsonFile);

    if(res.first == ERR_C_OK)
    {
        cout << "JSON OUTPUT:" << endl << "("<< obj.toString() << ")." << endl;


        print(1,obj,-1);
    }
    else
    {
        cout << "JSON ERROR: Code ("<< res.first << "): [" << res.second << "]" << endl;
        return false;
    }

    cout << endl << endl;
    return true;
```

`loadJSONByFile` load and parse the file and the content is stored into the `JSONObject` instance.

> When it use the **JSONLib** with *UTF-16* the method `loadJSONByFile` use a `std::string` to set the path file.

To load a JSON string and parse it, use the method `JSONObject::loadJSON`, as this sample shows:

```c++
    JSONObject obj;

    pair<int,string> res = obj.loadJSON(json_txt);
```


As `JSONObject::loadJSONByFile` does, it loads, parses and stores the JSON content into the the `JSONObject` instance.


If there is a problema with loading and parsing the JSON Content, both methods return a `pair<int,string>` which has the error code and error description of the problem:

```cpp
pair<int,string> res = obj.loadJSON(json_txt);

	if(res.first == ERR_C_OK)
	{
    //...
	}
	else
	{
		cout << "JSON ERROR: Code ("<< res.first << "): [" << res.second << "]" << endl;
		return false;
	}
```



## Reading and modify the JSONLib content

After loading and parse the content of a file or string, JSON content is stored into the instance of `JSONObject`. The `JSONObject` can store another `JSONObject` that can represent, according with *JSON Standar*:

+ NULL (Empty) value
+ Boolean value.
+ Number Value.
+ String value.
+ Object, which is a value and can store another objects, values or arrays.
+ Array, which has a collection of values

All the types are defined in the `enum` `json::common::JSONType`.

To read a value, which has a defined key, use the operator `[]` and the key of the value:


**JSON Content:**
```json
{
  "Null Value": null,
  "Boolean Value": true,
  "Integer Number": 12,
  "Double Number": 231.45,
  "Double Number Exp": -443.32,
  "String Value": "My String"
}
```

Reading the value with key *Integer Number*:

```cpp

JSONObject obj;

//Parse the JSON content

//Reading the value
cout << "\tInteger Number     = [" << obj["Integer Number"].toString(false) << "]" << endl;

```

To get the type of the JSONObject (Object, Array or Value), use the method `type()` which return a value of type `json::common::JSONType`:

```cpp
if(val.type() == JSONType::EMPTY)
//...
else if(val.type() == JSONType::Boolean)
//...
else if(val.type() == JSONType::Array)
```

To modify a value or add a new value into the JSONObject use the operator `=`, as it shows:

```c++
obj["Integer Number"] = 666;
```

> The JSONObject detect the type of value using its override operators:
```cpp
void operator=(int);
void operator=(long);
void operator=(float);
void operator=(double);
```

To access at inner *Object* use the operator `[]` to navigate across the inner objects and value:

**JSON Content** with array:

```json
{
  "glossary": {
    "title": "example glossary",
    "GlossDiv": {
      "title": "S",
      "GlossList": {
        "GlossEntry": {
          "ID": "SGML",
          "SortAs": "SGML",
          "GlossTerm": "Standard Generalized Markup Language",
          "Acronym": "SGML",
          "Abbrev": "ISO 8879:1986",
          "GlossDef": {
            "para": "A meta-markup language, used to create markup languages such as DocBook.",
            "GlossSeeAlso": [
              "GML",
              "XML"
            ]
          },
          "GlossSee": "markup"
        }
      }
    }
  }
}
```

```c++
//Getting an inner JSONObject.
JSONObject innerObj = obj["glossary"]["GlossDiv"]["GlossList"]["GlossEntry"]["GlossDef"];

//Use the inner JSONObject and navigate across its values.
cout << "GlossSeeAlso Para:" << innerObj["para"].toString() << endl;
```

To navigate across an array use the operator `[]` and set the index, which is base 0:

```cpp
cout << "GlossSeeAlso Ittem 1:" << innerObj["GlossSeeAlso"][0].toString() << endl;
cout << "GlossSeeAlso Ittem 2:" << innerObj["GlossSeeAlso"][1].toString() << endl;
```


To add a new `JSONObject` into the *Array* or *Object* use the operator `+=`:

```c++

JSONObect obj; //The main JSONObject

//load and parse...

JSONObject innerObj = obj["glossary"]["GlossDiv"]["GlossList"]["GlossEntry"]["GlossDef"];

JSONObject nItem;
nItem = string("My New Item");
innerObj["GlossSeeAlso"]+= nItem; //Adding a new Object to array.
cout << "GlossSeeAlso Ittem 3:" << innerObj["GlossSeeAlso"][2].toString() << endl;

```


## Use of memory

The **JSONLib** doesn't use dynamic memory. Instead of it, **JSONLib** use copyable object. So, avoid alloc dynamic memory for each instance of `JSONObject`.


**So, avoid create any instance of `JSONObject` as this:**

```cpp
JSONObect* obj = new JSONObect();
```

If you need send an instance of `JSONObject` as argument and manipulate it, send it by reference:

```cpp
void printJson(int level, JSONObject& val, int index)
{
  cout.width(level*2);
	cout << " ";
  if(val.type() == JSONType::EMPTY)
    //...
}

int main(int argc, char **argv) {
{
    string json_txt;

    cout << "Reading file: " << jsonFile << endl;

    JSONObject obj;

    pair<int,string> res = obj.loadJSONByFile(jsonFile);

    if(res.first == ERR_C_OK)
    {
        printJson(1,obj,-1); //Sending a reference of JSONObjet.
    }
}
```
