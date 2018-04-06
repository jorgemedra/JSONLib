#include "TEST.h"

using namespace json::utf8;
using namespace json::common;

TEST::TEST()
{
    cout << "TEST: " << json::common::VERSION << endl;
}

TEST::~TEST()
{
}

bool TEST::json_parse_1()
{
	string json_txt;

	cout << "--------------------------------" << endl;
	cout << "----- JSON PARSE MESSAJE 1 -----" << endl;
	cout << "--------------------------------" << endl;
	cout <<  endl;


	std::ostringstream outStr1;
	outStr1 << "{\"Null Value\":null,\"Boolean Value\" : true ,\"Integer Number\": 12  " << endl;
	outStr1 << ",\"Double Number\":231.45 ,\"Double Number Exp\":-27865400000.45E-12,\"String Value\":\"My String\" }" << endl;
	json_txt = outStr1.str();
	cout << "JSON INPUT:" << endl << "(" << json_txt <<")." << endl << endl;

	JSONObject obj;
    
    pair<int,string> res = obj.loadJSON(json_txt);
    
	if(res.first == ERR_C_OK)
	{
        print(1,obj,-1);
        cout << endl << endl;
        
		cout << "\tDouble Number Exp  = [" << obj["Double Number Exp"].toString(false) << "]" << endl;
		cout << "\tDouble Number      = [" << obj["Double Number"].toString(false) << "]" << endl;
		cout << "\tInteger Number     = [" << obj["Integer Number"].toString(false) << "]" << endl;
		cout << "\tNull Value         = [" << obj["Null Value"].toString(false) << "]" << endl;
		cout << "\tString Value       = [" << obj["String Value"].toString(false) << "]" << endl;

        cout << "\tSUM                = [" << obj["Double Number Exp"].numValue() + obj["Double Number"].numValue() << "]" << endl;
        
        obj["Integer Number"] = 666;
        cout << "\tNew Integer Number = [" << obj["Integer Number"].toString(false) << "]" << endl;
		cout << endl << endl;
		cout << "JSON OUTPUT:" << endl << "("<< obj.toString() << ")." << endl;
	}
	else
	{
		cout << "JSON ERROR: Code ("<< res.first << "): [" << res.second << "]" << endl;
		return false;
	}

	cout << endl << endl;
	return true;
}


bool TEST::json_parse_2()
{
	string json_txt;

	cout << "--------------------------------" << endl;
	cout << "----- JSON PARSE MESSAJE 2 -----" << endl;
	cout << "--------------------------------" << endl;
	cout <<  endl;

	json_txt = "{\"glossary\": {\"title\": \"example glossary\",\"GlossDiv\": {\"title\": \"S\",\"GlossList\": {\"GlossEntry\": {\"ID\": \"SGML\",\"SortAs\": \"SGML\",\"GlossTerm\": \"Standard Generalized Markup Language\",\"Acronym\": \"SGML\",\"Abbrev\": \"ISO 8879:1986\",\"GlossDef\": {\"para\": \"A meta-markup language, used to create markup languages such as DocBook.\",\"GlossSeeAlso\": [\"GML\", \"XML\"]},\"GlossSee\": \"markup\"}}}}}";
	cout << "JSON MSJ: ("<< json_txt <<")." << endl << endl;
    
    
    JSONObject obj;
    pair<int,string> res = obj.loadJSON(json_txt);
    
	if(res.first == ERR_C_OK)
	{
        print(1,obj,-1);
        cout << endl << endl;
        JSONObject innerObj = obj["glossary"]["GlossDiv"]["GlossList"]["GlossEntry"]["GlossDef"];
        cout << "GlossSeeAlso Para:" << innerObj["para"].toString() << endl;
        cout << "GlossSeeAlso Ittem 1:" << innerObj["GlossSeeAlso"][0].toString() << endl;
        cout << "GlossSeeAlso Ittem 2:" << innerObj["GlossSeeAlso"][1].toString() << endl;
        
        JSONObject nItem;
        nItem = string("My New Item");
        innerObj["GlossSeeAlso"]+= nItem;
        cout << "GlossSeeAlso Ittem 3:" << innerObj["GlossSeeAlso"][2].toString() << endl;
        
		cout << endl << endl;
		cout << "JSON : ("<< obj.toString() << ")." << endl;
	}
	else
	{
		cout << "JSON ERROR: Code ("<< res.first << "): [" << res.second << "]" << endl;
		return false;
	}

	cout << endl << endl;
	return true;
}


bool TEST::json_parse_3()
{
	string json_txt;

	cout << "--------------------------------" << endl;
	cout << "----- JSON PARSE MESSAJE 3 -----" << endl;
	cout << "--------------------------------" << endl;

	json_txt ="{\"menu\": {    \"header\": \"SVG Viewer\",    \"items\": [        {\"id\": \"Open\"},        {\"id\": \"OpenNew\", \"label\": \"Open New\"},        null,        {\"id\": \"ZoomIn\", \"label\": \"Zoom In\"},        {\"id\": \"ZoomOut\", \"label\": \"Zoom Out\"},        {\"id\": \"OriginalView\", \"label\": \"Original View\"},        null,        {\"id\": \"Quality\"},        {\"id\": \"Pause\"},        {\"id\": \"Mute\"},        null,        {\"id\": \"Find\", \"label\": \"Find...\"},        {\"id\": \"FindAgain\", \"label\": \"Find Again\"},        {\"id\": \"Copy\"},        {\"id\": \"CopyAgain\", \"label\": \"Copy Again\"},        {\"id\": \"CopySVG\", \"label\": \"Copy SVG\"},        {\"id\": \"ViewSVG\", \"label\": \"View SVG\"},        {\"id\": \"ViewSource\", \"label\": \"View Source\"},        {\"id\": \"SaveAs\", \"label\": \"Save As\"},        null,        {\"id\": \"Help\"},        {\"id\": \"About\", \"label\": \"About Adobe CVG Viewer...\"}    ]}}";
	cout << "JSON MSJ BEGIN["<< json_txt <<"]END." << endl << endl;


    JSONObject obj;
    pair<int,string> res = obj.loadJSON(json_txt);
    
	if(res.first == ERR_C_OK)
	{
        print(1,obj,-1);
        cout << endl << endl;
        cout << "JSON : ("<< obj.toString() << ")." << endl;
	}
	else
	{
		cout << "JSON ERROR: Code ("<< res.first << "): [" << res.second << "]" << endl;
		return false;
	}

	cout << endl << endl;

	return true;
}


bool TEST::json_parse_4()
{
	string json_txt;

	cout << "--------------------------------" << endl;
	cout << "----- JSON PARSE MESSAJE 4 -----" << endl;
	cout << "--------------------------------" << endl;


	json_txt ="{\"web-app\": {  \"servlet\": [       {      \"servlet-name\": \"cofaxCDS\",      \"servlet-class\": \"org.cofax.cds.CDSServlet\",      \"init-param\": {        \"configGlossary:installationAt\": \"Philadelphia, PA\",        \"configGlossary:adminEmail\": \"ksm@pobox.com\",        \"configGlossary:poweredBy\": \"Cofax\",        \"configGlossary:poweredByIcon\": \"/images/cofax.gif\",        \"configGlossary:staticPath\": \"/content/static\",        \"templateProcessorClass\": \"org.cofax.WysiwygTemplate\",        \"templateLoaderClass\": \"org.cofax.FilesTemplateLoader\",        \"templatePath\": \"templates\",        \"templateOverridePath\": \"\",        \"defaultListTemplate\": \"listTemplate.htm\",        \"defaultFileTemplate\": \"articleTemplate.htm\",        \"useJSP\": false,        \"jspListTemplate\": \"listTemplate.jsp\",        \"jspFileTemplate\": \"articleTemplate.jsp\",        \"cachePackageTagsTrack\": 200,        \"cachePackageTagsStore\": 200,        \"cachePackageTagsRefresh\": 60,        \"cacheTemplatesTrack\": 100,        \"cacheTemplatesStore\": 50,        \"cacheTemplatesRefresh\": 15,        \"cachePagesTrack\": 200,        \"cachePagesStore\": 100,        \"cachePagesRefresh\": 10,        \"cachePagesDirtyRead\": 10,        \"searchEngineListTemplate\": \"forSearchEnginesList.htm\",        \"searchEngineFileTemplate\": \"forSearchEngines.htm\",        \"searchEngineRobotsDb\": \"WEB-INF/robots.db\",        \"useDataStore\": true,        \"dataStoreClass\": \"org.cofax.SqlDataStore\",        \"redirectionClass\": \"org.cofax.SqlRedirection\",        \"dataStoreName\": \"cofax\",        \"dataStoreDriver\": \"com.microsoft.jdbc.sqlserver.SQLServerDriver\",        \"dataStoreUrl\": \"jdbc:microsoft:sqlserver://LOCALHOST:1433;DatabaseName=goon\",        \"dataStoreUser\": \"sa\",        \"dataStorePassword\": \"dataStoreTestQuery\",        \"dataStoreTestQuery\": \"SET NOCOUNT ON;select test='test';\",        \"dataStoreLogFile\": \"/usr/local/tomcat/logs/datastore.log\",        \"dataStoreInitConns\": 10,        \"dataStoreMaxConns\": 100,        \"dataStoreConnUsageLimit\": 100,        \"dataStoreLogLevel\": \"debug\",        \"maxUrlLength\": 500}},    {      \"servlet-name\": \"cofaxEmail\",      \"servlet-class\": \"org.cofax.cds.EmailServlet\",      \"init-param\": {      \"mailHost\": \"mail1\",      \"mailHostOverride\": \"mail2\"}},    {      \"servlet-name\": \"cofaxAdmin\",      \"servlet-class\": \"org.cofax.cds.AdminServlet\"},     {      \"servlet-name\": \"fileServlet\",      \"servlet-class\": \"org.cofax.cds.FileServlet\"},    {      \"servlet-name\": \"cofaxTools\",      \"servlet-class\": \"org.cofax.cms.CofaxToolsServlet\",      \"init-param\": {        \"templatePath\": \"toolstemplates/\",        \"log\": 1,        \"logLocation\": \"/usr/local/tomcat/logs/CofaxTools.log\",        \"logMaxSize\": \"\",        \"dataLog\": 1,        \"dataLogLocation\": \"/usr/local/tomcat/logs/dataLog.log\",        \"dataLogMaxSize\": \"\",        \"removePageCache\": \"/content/admin/remove?cache=pages&id=\",        \"removeTemplateCache\": \"/content/admin/remove?cache=templates&id=\",        \"fileTransferFolder\": \"/usr/local/tomcat/webapps/content/fileTransferFolder\",        \"lookInContext\": 1,        \"adminGroupID\": 4,        \"betaServer\": true}}],  \"servlet-mapping\": {    \"cofaxCDS\": \"/\",    \"cofaxEmail\": \"/cofaxutil/aemail/*\",    \"cofaxAdmin\": \"/admin/*\",    \"fileServlet\": \"/static/*\",    \"cofaxTools\": \"/tools/*\"},   \"taglib\": {    \"taglib-uri\": \"cofax.tld\",    \"taglib-location\": \"/WEB-INF/tlds/cofax.tld\"}}}";
	cout << "JSON MSJ BEGIN["<< json_txt <<"]END." << endl << endl;

    JSONObject obj;
    pair<int,string> res = obj.loadJSON(json_txt);

	if(res.first == ERR_C_OK)
	{
		print(1,obj,-1);
		cout << endl << endl;
		cout << "JSON : ("<< obj.toString() << ")." << endl;
	}
	else
	{
        cout << "JSON ERROR: Code ("<< res.first << "): [" << res.second << "]" << endl;
        return false;
	}

	cout << endl << endl;

	return true;
}
 

bool TEST::json_parse_5()
{
    string json_txt;
    
    cout << "--------------------------------" << endl;
    cout << "----- JSON PARSE MESSAJE 5 -----" << endl;
    cout << "--------------------------------" << endl;
    cout <<  endl;
    
    string jsonFile = "/Users/jorgeomarmedratorres/Desktop/Json/JSONLib/Build/Products/Debug/utf-8.json";
    cout << "Reading file: " << jsonFile << endl;
    
    JSONObject obj;
    
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
}

void TEST::print(int level, JSONObject& val, int index)
{

	cout.width(level*2);
	cout << " ";
    if(val.type() == JSONType::EMPTY)
		cout << "(JSON NULL) \t" << "[" << val.keyVal() << "]" << endl;
	else if(val.type() == JSONType::Boolean)
		cout << "(JSON Bool) \t" << "[" << val.keyVal() << "] = [" << val.boolValue() << "]" << endl;
	else if(val.type() == JSONType::Number)
        cout << "(JSON Number) \t" << "[" << val.keyVal() << "] = [" << val.numValue() << "]" << endl;
    else if(val.type() == JSONType::String)
		cout << "(JSON String) \t" << "[" << val.keyVal() << "] = [" << val.strValue() << "]" << endl;
	else if(val.type() == JSONType::Array)
	{
		cout << "(JSON Array) \t" << "[" << val.keyVal() << "]:" << endl;
		for(int i=0; i<val.size(); i++)
            this->print(level+1, val[i], i);
	}
	else if(val.type() == JSONType::Object)
	{
		if(index < 0)
			cout << "(JSON Object) \t" << "[" << val.keyVal() << "]:" << endl;
		else
			cout << "(JSON Object) \t" << "[" << index << "]:" << endl;
        
		for(int i=0; i < val.size(); i++)
			this->print(level+1, val[i],-1);
	}
}






