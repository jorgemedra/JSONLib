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

```C++
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

##Identify JSONValue type

Use method JSONValueType getType() to identify the JSONValue Type, as sample shows:

```C++
void TEST::print(int level, JSONValue* val, int index)
{

	cout.width(level*2);
	cout << " ";
	if(val->getType() == T_NULL)
		cout << "(JSON NULL) \t" << "[" << val->name() << "]" << endl;
	else if(val->getType() == T_BOOL)
	{
		JSONBool* json = (JSONBool*)val;
		cout << "(JSON Bool) \t" << "[" << val->name() << "] = [" << json->value() << "]" << endl;
	}
	else if(val->getType() == T_NUMBER)
	{
		JSONNumber* json = (JSONNumber*)val;
		if(json->isInteger())
			cout << "(JSON Number) \t" << "[" << val->name() << "] = [" << json->intValue() << "]" << endl;
		else
			cout << "(JSON Number) \t" << "[" << val->name() << "] = [" << json->dlbValue() << "]" << endl;
	}
	else if(val->getType() == T_STRING)
	{
		JSONString* json = (JSONString*)val;
		cout << "(JSON String) \t" << "[" << val->name() << "] = [" << json->value() << "]" << endl;
	}
	else if(val->getType() == T_ARRAY)
	{
		JSONArray* json = (JSONArray*)val;
		cout << "(JSON Array) \t" << "[" << val->name() << "]:" << endl;
		for(int i=0; i<json->getCount(); i++)
		{
			JSONValue* v = (JSONValue*)json->operator[](i);
			this->print(level+1, v,i);
		}
	}
	else if(val->getType() == T_OBJECT)
	{
		JSONObject* json = (JSONObject*)val;
		if(index < 0)
			cout << "(JSON Object) \t" << "[" << val->name() << "]:" << endl;
		else
			cout << "(JSON Object) \t" << "[" << index << "]:" << endl;
		for(int i=0; i < json->getCount(); i++)
		{
			JSONValue* v = json->operator [](i);
			this->print(level+1, v,-1);
		}
	}
}
```


