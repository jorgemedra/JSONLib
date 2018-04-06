//
//  TESTWW.cpp
//  Sample
//
//  Created by Jorge Omar Medra Torres on 02/04/18.
//  Copyright © 2018 Jorge Omar Medra Torres. All rights reserved.
//

#include "TESTW.h"

using namespace std;
using namespace json::wide;
using namespace json::common;

TESTW::TESTW()
{
    cout << "TEST (Wide): " << json::common::VERSION << endl;
}

TESTW::~TESTW()
{
}

bool TESTW::json_parse_1()
{
    wstring json_txt;
    
    wcout << L"--------------------------------" << endl;
    wcout << L"----- JSONW PARSE MESSAJE 1 -----" << endl;
    wcout << L"--------------------------------" << endl;
    wcout <<  endl;
    
    
    std::wstringstream outStr1;
    outStr1 << L"{\"Null Value\":null,\"Boolean Value\" : true ,\"Integer Number\": 12  " << endl;
    outStr1 << L",\"Double Number\":231.45 ,\"Double Number Exp\":-27865400000.45E-12,\"wstring Value\":\"My wstringÑñó\" }" << endl;
    json_txt = outStr1.str();
    wcout << L"JSON INPUT:" << endl << L"(" << json_txt <<L")." << endl << endl;
    
    JSONObject obj;
    
    pair<int,wstring> res = obj.loadJSON(json_txt);
    
    if(res.first == ERR_C_OK)
    {
        print(1,obj,-1);
        wcout << endl << endl;
        
        wcout << L"\tDouble Number Exp  = [" << obj[L"Double Number Exp"].toString(false) << L"]" << endl;
        wcout << L"\tDouble Number      = [" << obj[L"Double Number"].toString(false) << L"]" << endl;
        wcout << L"\tInteger Number     = [" << obj[L"Integer Number"].toString(false) << L"]" << endl;
        wcout << L"\tNull Value         = [" << obj[L"Null Value"].toString(false) << L"]" << endl;
        wcout << L"\twstring Value       = [" << obj[L"wstring Value"].toString(false) << L"]" << endl;
        
        wcout << L"\tSUM                = [" << obj[L"Double Number Exp"].numValue() + obj[L"Double Number"].numValue() << L"]" << endl;
        
        obj[L"Integer Number"] = 666;
        wcout << L"\tNew Integer Number = [" << obj[L"Integer Number"].toString(false) << L"]" << endl;
        wcout << endl << endl;
        wcout << L"JSON OUTPUT:" << endl << L"("<< obj.toString() << L")." << endl;
        
    }
    else
    {
        wcout << L"JSON ERROR: Code ("<< res.first << L"): [" << res.second << L"]" << endl;
        return false;
    }
    
    wcout << endl << endl;
    return true;
}


bool TESTW::json_parse_2()
{
    wstring json_txt;
    
    wcout << L"--------------------------------" << endl;
    wcout << L"----- JSONW PARSE MESSAJE 2 -----" << endl;
    wcout << L"--------------------------------" << endl;
    wcout <<  endl;
    
    json_txt = L"{\"glossary\": {\"title\": \"example glossary\",\"GlossDiv\": {\"title\": \"S\",\"GlossList\": {\"GlossEntry\": {\"ID\": \"SGML\",\"SortAs\": \"SGML\",\"GlossTerm\": \"Standard Generalized Markup Language\",\"Acronym\": \"SGML\",\"Abbrev\": \"ISO 8879:1986\",\"GlossDef\": {\"para\": \"A meta-markup language, used to create markup languages such as DocBook.\",\"GlossSeeAlso\": [\"GML\", \"XML\"]},\"GlossSee\": \"markup\"}}}}}";
    wcout << L"JSON MSJ: ("<< json_txt << L")." << endl << endl;
    
    
    JSONObject obj;
    pair<int,wstring> res = obj.loadJSON(json_txt);
    
    if(res.first == ERR_C_OK)
    {
        print(1,obj,-1);
        wcout << endl << endl;
        JSONObject innerObj = obj[L"glossary"][L"GlossDiv"][L"GlossList"][L"GlossEntry"][L"GlossDef"];
        wcout << L"GlossSeeAlso Para:" << innerObj[L"para"].toString() << endl;
        wcout << L"GlossSeeAlso Ittem 1:" << innerObj[L"GlossSeeAlso"][0].toString() << endl;
        wcout << L"GlossSeeAlso Ittem 2:" << innerObj[L"GlossSeeAlso"][1].toString() << endl;
        
        JSONObject nItem;
        nItem = L"My New Item";
        innerObj[L"GlossSeeAlso"]+= nItem;
        wcout << L"GlossSeeAlso Ittem 3:" << innerObj[L"GlossSeeAlso"][2].toString() << endl;
        
        wcout << endl << endl;
        wcout << L"JSON : ("<< obj.toString() << L")." << endl;
        
    }
    else
    {
        wcout << L"JSON ERROR: Code ("<< res.first << L"): [" << res.second << L"]" << endl;
        return false;
    }
    
    wcout << endl << endl;
    return true;
}


bool TESTW::json_parse_3()
{
    wstring json_txt;
    
    wcout << L"--------------------------------" << endl;
    wcout << L"----- JSONW PARSE MESSAJE 3 -----" << endl;
    wcout << L"--------------------------------" << endl;
    
    json_txt = L"{\"menu\": {    \"header\": \"SVG Viewer\",    \"items\": [        {\"id\": \"Open\"},        {\"id\": \"OpenNew\", \"label\": \"Open New\"},        null,        {\"id\": \"ZoomIn\", \"label\": \"Zoom In\"},        {\"id\": \"ZoomOut\", \"label\": \"Zoom Out\"},        {\"id\": \"OriginalView\", \"label\": \"Original View\"},        null,        {\"id\": \"Quality\"},        {\"id\": \"Pause\"},        {\"id\": \"Mute\"},        null,        {\"id\": \"Find\", \"label\": \"Find...\"},        {\"id\": \"FindAgain\", \"label\": \"Find Again\"},        {\"id\": \"Copy\"},        {\"id\": \"CopyAgain\", \"label\": \"Copy Again\"},        {\"id\": \"CopySVG\", \"label\": \"Copy SVG\"},        {\"id\": \"ViewSVG\", \"label\": \"View SVG\"},        {\"id\": \"ViewSource\", \"label\": \"View Source\"},        {\"id\": \"SaveAs\", \"label\": \"Save As\"},        null,        {\"id\": \"Help\"},        {\"id\": \"About\", \"label\": \"About Adobe CVG Viewer...\"}    ]}}";
    wcout << L"JSON MSJ BEGIN["<< json_txt << L"]END." << endl << endl;
    
    
    JSONObject obj;
    pair<int,wstring> res = obj.loadJSON(json_txt);
    
    if(res.first == ERR_C_OK)
    {
        print(1,obj,-1);
        wcout << endl << endl;
        wcout << L"JSON : ("<< obj.toString() << L")." << endl;
    }
    else
    {
        wcout << L"JSON ERROR: Code ("<< res.first << L"): [" << res.second << L"]" << endl;
        return false;
    }
    
    wcout << endl << endl;
    
    return true;
}


bool TESTW::json_parse_4()
{
    wstring json_txt;
    
    wcout << L"--------------------------------" << endl;
    wcout << L"----- JSONW PARSE MESSAJE 4 -----" << endl;
    wcout << L"--------------------------------" << endl;
    
    
    json_txt = L"{\"web-app\": {  \"servlet\": [       {      \"servlet-name\": \"cofaxCDS\",      \"servlet-class\": \"org.cofax.cds.CDSServlet\",      \"init-param\": {        \"configGlossary:installationAt\": \"Philadelphia, PA\",        \"configGlossary:adminEmail\": \"ksm@pobox.com\",        \"configGlossary:poweredBy\": \"Cofax\",        \"configGlossary:poweredByIcon\": \"/images/cofax.gif\",        \"configGlossary:staticPath\": \"/content/static\",        \"templateProcessorClass\": \"org.cofax.WysiwygTemplate\",        \"templateLoaderClass\": \"org.cofax.FilesTemplateLoader\",        \"templatePath\": \"templates\",        \"templateOverridePath\": \"\",        \"defaultListTemplate\": \"listTemplate.htm\",        \"defaultFileTemplate\": \"articleTemplate.htm\",        \"useJSP\": false,        \"jspListTemplate\": \"listTemplate.jsp\",        \"jspFileTemplate\": \"articleTemplate.jsp\",        \"cachePackageTagsTrack\": 200,        \"cachePackageTagsStore\": 200,        \"cachePackageTagsRefresh\": 60,        \"cacheTemplaTESTWrack\": 100,        \"cacheTemplatesStore\": 50,        \"cacheTemplatesRefresh\": 15,        \"cachePagesTrack\": 200,        \"cachePagesStore\": 100,        \"cachePagesRefresh\": 10,        \"cachePagesDirtyRead\": 10,        \"searchEngineListTemplate\": \"forSearchEnginesList.htm\",        \"searchEngineFileTemplate\": \"forSearchEngines.htm\",        \"searchEngineRobotsDb\": \"WEB-INF/robots.db\",        \"useDataStore\": true,        \"dataStoreClass\": \"org.cofax.SqlDataStore\",        \"redirectionClass\": \"org.cofax.SqlRedirection\",        \"dataStoreName\": \"cofax\",        \"dataStoreDriver\": \"com.microsoft.jdbc.sqlserver.SQLServerDriver\",        \"dataStoreUrl\": \"jdbc:microsoft:sqlserver://LOCALHOST:1433;DatabaseName=goon\",        \"dataStoreUser\": \"sa\",        \"dataStorePassword\": \"dataStoreTESTWQuery\",        \"dataStoreTESTWQuery\": \"SET NOCOUNT ON;select TESTW='TESTW';\",        \"dataStoreLogFile\": \"/usr/local/tomcat/logs/datastore.log\",        \"dataStoreInitConns\": 10,        \"dataStoreMaxConns\": 100,        \"dataStoreConnUsageLimit\": 100,        \"dataStoreLogLevel\": \"debug\",        \"maxUrlLength\": 500}},    {      \"servlet-name\": \"cofaxEmail\",      \"servlet-class\": \"org.cofax.cds.EmailServlet\",      \"init-param\": {      \"mailHost\": \"mail1\",      \"mailHostOverride\": \"mail2\"}},    {      \"servlet-name\": \"cofaxAdmin\",      \"servlet-class\": \"org.cofax.cds.AdminServlet\"},     {      \"servlet-name\": \"fileServlet\",      \"servlet-class\": \"org.cofax.cds.FileServlet\"},    {      \"servlet-name\": \"cofaxTools\",      \"servlet-class\": \"org.cofax.cms.CofaxToolsServlet\",      \"init-param\": {        \"templatePath\": \"toolstemplates/\",        \"log\": 1,        \"logLocation\": \"/usr/local/tomcat/logs/CofaxTools.log\",        \"logMaxSize\": \"\",        \"dataLog\": 1,        \"dataLogLocation\": \"/usr/local/tomcat/logs/dataLog.log\",        \"dataLogMaxSize\": \"\",        \"removePageCache\": \"/content/admin/remove?cache=pages&id=\",        \"removeTemplateCache\": \"/content/admin/remove?cache=templates&id=\",        \"fileTransferFolder\": \"/usr/local/tomcat/webapps/content/fileTransferFolder\",        \"lookInContext\": 1,        \"adminGroupID\": 4,        \"betaServer\": true}}],  \"servlet-mapping\": {    \"cofaxCDS\": \"/\",    \"cofaxEmail\": \"/cofaxutil/aemail/*\",    \"cofaxAdmin\": \"/admin/*\",    \"fileServlet\": \"/static/*\",    \"cofaxTools\": \"/tools/*\"},   \"taglib\": {    \"taglib-uri\": \"cofax.tld\",    \"taglib-location\": \"/WEB-INF/tlds/cofax.tld\"}}}";
    wcout << L"JSON MSJ BEGIN["<< json_txt <<L"]END." << endl << endl;
    
    JSONObject obj;
    pair<int,wstring> res = obj.loadJSON(json_txt);
    
    if(res.first == ERR_C_OK)
    {
        print(1,obj,-1);
        wcout << endl << endl;
        wcout << L"JSON : ("<< obj.toString() << L")." << endl;
        
        
    }
    else
    {
        wcout << L"JSON ERROR: Code ("<< res.first << L"): [" << res.second << L"]" << endl;
        return false;
    }
    
    wcout << endl << endl;
    
    return true;
}

bool TESTW::json_parse_5()
{
    wstring json_txt;
    
    wcout << L"--------------------------------" << endl;
    wcout << L"----- JSONW PARSE MESSAJE 5 -----" << endl;
    wcout << L"--------------------------------" << endl;
    wcout <<  endl;
    
    string jsonFile = "/Users/jorgeomarmedratorres/Desktop/Json/JSONLib/Build/Products/Debug/utf-16.json";
    cout << "Reading file: " << jsonFile << endl;
   
    
    JSONObject obj;
    
    pair<int,wstring> res = obj.loadJSONByFile(jsonFile);
    
    if(res.first == ERR_C_OK)
    {
        wcout << L"JSON OUTPUT:" << endl << L"("<< obj.toString() << L")." << endl;
        
        print(1,obj,-1);
        wcout << endl << endl;
        
        wcout << L"ÑiKey  = [" << obj[L"ÑiKey"].toString(false) << L"]" << endl;
    }
    else
    {
        wcout << L"JSON ERROR: Code ("<< res.first << L"): [" << res.second << L"]" << endl;
        return false;
    }
    
    wcout << endl << endl;
    return true;
}

void TESTW::print(int level, JSONObject& val, int index)
{
    wcout.width(level*2);
    wcout << L" ";
    if(val.type() == JSONType::EMPTY)
        wcout << L"(JSON NULL) \t" << L"[" << val.keyVal() << L"]" << endl;
    else if(val.type() == JSONType::Boolean)
        wcout << L"(JSON Bool) \t" << L"[" << val.keyVal() << L"] = [" << val.boolValue() << L"]" << endl;
    else if(val.type() == JSONType::Number)
        wcout << L"(JSON Number) \t" << L"[" << val.keyVal() << L"] = [" << val.numValue() << L"]" << endl;
    else if(val.type() == JSONType::String)
        wcout << L"(JSON wstring) \t" << L"[" << val.keyVal() << L"] = [" << val.strValue() << L"]" << endl;
    else if(val.type() == JSONType::Array)
    {
        wcout << L"(JSON Array) \t" << L"[" << val.keyVal() << L"]:" << endl;
        for(int i=0; i<val.size(); i++)
            this->print(level+1, val[i], i);
    }
    else if(val.type() == JSONType::Object)
    {
        if(index < 0)
            wcout << L"(JSON Object) \t" << L"[" << val.keyVal() << L"]:" << endl;
        else
            wcout << L"(JSON Object) \t" << L"[" << index << L"]:" << endl;
        
        for(int i=0; i < val.size(); i++)
            this->print(level+1, val[i],-1);
    }
}
