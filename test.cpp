// Last Update:2018-11-22 17:42:13
/**
 * @file test.cpp
 * @brief 
 * @author tczengming@163.com www.benewtech.cn
 * @version 0.1.00
 * @date 2018-11-22
 */

#include <assert.h>
#include <iostream>
#include "wrapidjson.h"

    int
main( int argc, char **argv )
{
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
    printf( "%s\n", svalue.c_str() );

    return 0;
}
