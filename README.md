# wrapidjson
rapidjson c++ wrapper
封装了下rapidjson这个json解析库

Requirements
[rapidjson](https://github.com/Tencent/rapidjson)

## example
```c
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
```

## test
```c
const char *JSON = "{"
                   "\"double\":100.11,"
                   "\"int\":200,"
                   "\"str\":\"Hello World\","
                   "\"bool\":false"
                   "}";

rapidjson::Document d;

d.Parse(JSON);

if (d.HasParseError())
{
    printf( "parse error!\n" );
    return -1;
}

uint32_t uvalue;

assert(!Wrapidjson::GetUint(d, "uintvalue", &uvalue));

assert(Wrapidjson::HasDouble(d, "double"));

double dvalue;

assert(Wrapidjson::GetDouble(d, "double", &dvalue));

assert(dvalue == 100.11);

assert(!Wrapidjson::HasDouble(d, "int"));

int ivalue;

assert(Wrapidjson::GetInt(d, "int", &ivalue));

assert(ivalue == 200);

bool bvalue;

assert(Wrapidjson::GetBool(d, "bool", &bvalue));

assert(bvalue == false);

std::string svalue;

assert(Wrapidjson::GetString(d, "str", &svalue));

assert(svalue == std::string("Hello World"));
```

## compile
compile test

cd wrapidjson/

git clone https://github.com/Tencent/rapidjson

cd test

make
