// Last Update:2018-11-22 16:22:49
/**
 * @file wrapidjson.h
 * @brief 
 * @author tczengming@163.com www.benewtech.cn
 * @version 0.1.00
 * @date 2018-11-22
 */

#ifndef __WRAPIDJSON_H__
#define __WRAPIDJSON_H__

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

class Wrapidjson
{
public:
    static bool HasString(const rapidjson::Value &value, const char *name);
    static bool HasInt(const rapidjson::Value &value, const char *name);
    static bool HasInt64(const rapidjson::Value &value, const char *name);
    static bool HasUint(const rapidjson::Value &value, const char *name);
    static bool HasUint64(const rapidjson::Value &value, const char *name);
    static bool HasDouble(const rapidjson::Value &value, const char *name);
    static bool HasBool(const rapidjson::Value &value, const char *name);
    static bool HasArray(const rapidjson::Value &value, const char *name);

    static bool GetString(rapidjson::Value &value, const char *name, std::string *out);
    static bool GetInt(rapidjson::Value &value, const char *name, int *out);
    static bool GetInt64(rapidjson::Value &value, const char *name, int64_t *out);
    static bool GetUint(rapidjson::Value &value, const char *name, uint32_t *out);
    static bool GetUint64(rapidjson::Value &value, const char *name, uint64_t *out);
    static bool GetDouble(rapidjson::Value &value, const char *name, double *out);
    static bool GetBool(rapidjson::Value &value, const char *name, bool *out);

private:
    static bool Has(const rapidjson::Value &value, const char *name);
};

#endif  /*WRAPIDJSON_H*/
