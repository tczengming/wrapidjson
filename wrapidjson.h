// Last Update:2019-04-12 10:38:27
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

    static bool GetString(const rapidjson::Value &value, const char *name, std::string *out, const std::string &defaultVal = "");
    static bool GetInt(const rapidjson::Value &value, const char *name, int *out, int defaultVal = 0);
    static bool GetInt64(const rapidjson::Value &value, const char *name, int64_t *out, int64_t defaultVal = 0);
    static bool GetUint(const rapidjson::Value &value, const char *name, uint32_t *out, uint32_t defaultVal = 0);
    static bool GetUint64(const rapidjson::Value &value, const char *name, uint64_t *out, uint64_t defaultVal = 0);
    static bool GetDouble(const rapidjson::Value &value, const char *name, double *out, double defaultVal = 0.0);
    static bool GetBool(const rapidjson::Value &value, const char *name, bool *out, bool defaultVal = false);

private:
    static bool Has(const rapidjson::Value &value, const char *name);
};

#endif  /*WRAPIDJSON_H*/
