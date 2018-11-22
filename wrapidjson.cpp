// Last Update:2018-11-22 16:17:45
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

bool Wrapidjson::GetString(rapidjson::Value &value, const char *name, std::string *out)
{
    if (HasString(value, name))
    {
        *out = value[name].GetString();
        return true;
    }
    else
    {
        return false;
    }
}

bool Wrapidjson::GetInt(rapidjson::Value &value, const char *name, int *out)
{
    if (HasInt(value, name))
    {
        *out = value[name].GetInt();
        return true;
    }
    else
    {
        return false;
    }
}

bool Wrapidjson::GetInt64(rapidjson::Value &value, const char *name, int64_t *out)
{
    if (HasInt64(value, name))
    {
        *out = value[name].GetInt64();
        return true;
    }
    else
    {
        return false;
    }
}

bool Wrapidjson::GetUint(rapidjson::Value &value, const char *name, uint32_t *out)
{
    if (HasUint(value, name))
    {
        *out = value[name].GetUint();
        return true;
    }
    else
    {
        return false;
    }
}

bool Wrapidjson::GetUint64(rapidjson::Value &value, const char *name, uint64_t *out)
{
    if (HasUint64(value, name))
    {
        *out = value[name].GetUint64();
        return true;
    }
    else
    {
        return false;
    }
}

bool Wrapidjson::GetDouble(rapidjson::Value &value, const char *name, double *out)
{
    if (HasDouble(value, name))
    {
        *out = value[name].GetDouble();
        return true;
    }
    else
    {
        return false;
    }
}

bool Wrapidjson::GetBool(rapidjson::Value &value, const char *name, bool *out)
{
    if (HasBool(value, name))
    {
        *out = value[name].GetBool();
        return true;
    }
    else
    {
        return false;
    }
}
