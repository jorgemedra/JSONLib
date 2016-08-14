#JSONLib for C++

JSONLib is a dynamic library for c++ wich allow parse, read and build data with JSON format. It uses the *Standar ECMAC-404 for [JSON](http://www.json.org/)*.

The repository has 2 package:
- JSONLib. Contain the source code and distribution file for JSONLib.
- Sample. Contain samples to use the JSONLib.

#Using JSONLib

##prerequisites
Include Header file *JSONLib.h*
Link the library file *libJSONLib.so*

##Parse a JSON Data
Use the class JSONFactory to parse a JSON Data, as sample shows:

```
int errCode;
string errDesc;
string json_txt;
JSONFactory factory;
JSONValue* out;
	
json_txt = ".. JSON DATA ..";
cout << "JSON MSJ: ("<< json_txt <<")." << endl << endl;

out = factory.parseJSON(json_txt, &errCode, &errDesc);

if(errCode == ERR_C_OK)
{
	JSONObject* obj = (JSONObject*) out;
}
```
It will return a JSONValue object which must be cast to its corret type. The available types are:
- JSONNull
- JSONBool
- JSONNumber
- JSONString
- JSONObject
- JSONArray



