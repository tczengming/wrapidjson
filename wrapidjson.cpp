#include "wrapidjson.h"

Wrapidjson::Wrapidjson() : m_root(rapidjson::kObjectType)
{
}

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

bool Wrapidjson::HasObject(const rapidjson::Value &value, const char *name)
{
    return Has(value, name);
}

bool Wrapidjson::GetString(const rapidjson::Value &value, const char *name, std::string *out,
                           const std::string &defaultVal)
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

bool Wrapidjson::GetInt64(const rapidjson::Value &value, const char *name, int64_t *out,
                          int64_t defaultVal)
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

bool Wrapidjson::GetUint(const rapidjson::Value &value, const char *name, uint32_t *out,
                         uint32_t defaultVal)
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

bool Wrapidjson::GetUint64(const rapidjson::Value &value, const char *name, uint64_t *out,
                           uint64_t defaultVal)
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

bool Wrapidjson::GetDouble(const rapidjson::Value &value, const char *name, double *out,
                           double defaultVal)
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

bool Wrapidjson::GetBool(const rapidjson::Value &value, const char *name, bool *out,
                         bool defaultVal)
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

void Wrapidjson::AddString(rapidjson::Value &v, rapidjson::Document::AllocatorType &allocator,
                           const std::string &name, const std::string &value)
{
    v.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), allocator),
                rapidjson::Value().SetString(value.c_str(), value.size(), allocator), allocator);
}

void Wrapidjson::AddString(rapidjson::Document &d, const std::string &name,
                           const std::string &value)
{
    AddString(d, d.GetAllocator(), name, value);
}

void Wrapidjson::AddBool(rapidjson::Document &d, const std::string &name, bool value)
{
    d.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), d.GetAllocator()),
                rapidjson::Value().SetBool(value), d.GetAllocator());
}

void Wrapidjson::AddInt(rapidjson::Document &d, const std::string &name, int value)
{
    d.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), d.GetAllocator()),
                rapidjson::Value().SetInt(value), d.GetAllocator());
}

void Wrapidjson::AddUint(rapidjson::Document &d, const std::string &name, unsigned int value)
{
    d.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), d.GetAllocator()),
                rapidjson::Value().SetUint(value), d.GetAllocator());
}

void Wrapidjson::AddInt64(rapidjson::Document &d, const std::string &name, int64_t value)
{
    d.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), d.GetAllocator()),
                rapidjson::Value().SetInt64(value), d.GetAllocator());
}

void Wrapidjson::AddUint64(rapidjson::Document &d, const std::string &name, uint64_t value)
{
    d.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), d.GetAllocator()),
                rapidjson::Value().SetUint64(value), d.GetAllocator());
}

void Wrapidjson::AddDouble(rapidjson::Document &d, const std::string &name, double value)
{
    d.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), d.GetAllocator()),
                rapidjson::Value().SetDouble(value), d.GetAllocator());
}

void Wrapidjson::AddObject(rapidjson::Document &d, const std::string &name, rapidjson::Value &value)
{
    d.AddMember(rapidjson::Value().SetString(name.c_str(), name.size(), d.GetAllocator()), value,
                d.GetAllocator());
}

std::string Wrapidjson::ToString(const rapidjson::Value &v)
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    v.Accept(writer);
    return buffer.GetString();
}

std::string Wrapidjson::ToString()
{
    if (m_root.IsObject())
        return ToString(m_root);
    else
        return "";
}

bool Wrapidjson::Parse(const std::string &buf, std::string *err)
{
    m_root.Parse(buf.c_str());
    if (m_root.HasParseError())
    {
        if (err)
            *err = rapidjson::GetParseError_En(m_root.GetParseError());
        return false;
    }
    if (!m_root.IsObject())
    {
        if (err)
            *err = "document is not object";
        return false;
    }

    return true;
}
