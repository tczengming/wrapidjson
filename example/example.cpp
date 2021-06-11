#include "wrapidjson.h"

int RapidjsonCode()
{
    const char *JSON = "{\"testStr\":\"Hello World\"}";

    // -----------------read-----------------
    rapidjson::Document d;
    d.Parse(JSON);
    if (d.HasParseError())
    {
        printf( "parse error!\n" );
        return -1;
    }

    if (d.IsObject() && d.HasMember("testStr") && d["testStr"].IsString())
    {
        printf("testStr:%s\n", d["testStr"].GetString());
        return 0;
    }
    else
    {
        return -1;
    }

    // -----------------add-----------------
    const char *valueName = "newObjectName";
    rapidjson::Value value;
    value.SetInt(10);
    rapidjson::Value::MemberIterator itr;
    if ((itr = d.FindMember(valueName)) == d.MemberEnd())
        d.AddMember(rapidjson::Value().SetString(valueName, strlen(valueName)), value, d.GetAllocator());
}

int WrapidjsonCode()
{
    const char *JSON = "{\"testStr\":\"Hello World\"}";

    // -----------------read-----------------
    Wrapidjson wd;
    std::string err;
    if (!wd.Parse(JSON, &err))
    {
        printf( "parse error!\n" );
        return -1;
    }

    std::string testStr;
    if (wd.GetString(wd.RootRef(), "testStr", &testStr, ""))
    {
        printf("testStr:%s\n", testStr.c_str());
    }

    // -----------------add-----------------
    wd.AddInt("newObjectName", 10);
}

    int
main( int argc, char **argv )
{
    RapidjsonCode();

    WrapidjsonCode();

    return 0;
}
