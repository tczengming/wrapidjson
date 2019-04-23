// Last Update:2019-04-12 10:42:06
/**
 * @file wrapidjson.cpp
 * @brief 
 * @author tczengming@163.com www.benewtech.cn
 * @version 0.1.00
 * @date 2018-11-22
 */

#include "wrapidjson.h"

bool Wrapidjson::HasString(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsString();
}

bool Wrapidjson::HasInt(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsInt();
}

bool Wrapidjson::HasInt64(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsInt64();
}

bool Wrapidjson::HasUint(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsUint();
}

bool Wrapidjson::HasUint64(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsUint64();
}

bool Wrapidjson::HasDouble(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsDouble();
}

bool Wrapidjson::HasBool(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsBool();
}

bool Wrapidjson::HasArray(const rapidjson::Value &value, const char *name)
{
    return Has(value, name) && value[name].IsArray();
}

bool Wrapidjson::GetString(const rapidjson::Value &value, const char *name, std::string *out, const std::string &defaultVal)
{
    if (HasString(value, name))
    {
        *out = value[name].GetString();
        return true;
    }
    else
    {
        *out = defaultVal;
        return false;
    }
}

bool Wrapidjson::GetInt(const rapidjson::Value &value, const char *name, int *out, int defaultVal)
{
    if (HasInt(value, name))
    {
        *out = value[name].GetInt();
        return true;
    }
    else
    {
        *out = defaultVal;
        return false;
    }
}

bool Wrapidjson::GetInt64(const rapidjson::Value &value, const char *name, int64_t *out, int64_t defaultVal)
{
    if (HasInt64(value, name))
    {
        *out = value[name].GetInt64();
        return true;
    }
    else
    {
        *out = defaultVal;
        return false;
    }
}

bool Wrapidjson::GetUint(const rapidjson::Value &value, const char *name, uint32_t *out, uint32_t defaultVal)
{
    if (HasUint(value, name))
    {
        *out = value[name].GetUint();
        return true;
    }
    else
    {
        *out = defaultVal;
        return false;
    }
}

bool Wrapidjson::GetUint64(const rapidjson::Value &value, const char *name, uint64_t *out, uint64_t defaultVal)
{
    if (HasUint64(value, name))
    {
        *out = value[name].GetUint64();
        return true;
    }
    else
    {
        *out = defaultVal;
        return false;
    }
}

bool Wrapidjson::GetDouble(const rapidjson::Value &value, const char *name, double *out, double defaultVal)
{
    if (HasDouble(value, name))
    {
        *out = value[name].GetDouble();
        return true;
    }
    else
    {
        *out = defaultVal;
        return false;
    }
}

bool Wrapidjson::GetBool(const rapidjson::Value &value, const char *name, bool *out, bool defaultVal)
{
    if (HasBool(value, name))
    {
        *out = value[name].GetBool();
        return true;
    }
    else
    {
        *out = defaultVal;
        return false;
    }
}

bool Wrapidjson::Has(const rapidjson::Value &value, const char *name)
{
    return value.IsObject() && value.HasMember(name);
}
