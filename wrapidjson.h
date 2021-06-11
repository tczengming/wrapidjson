#ifndef __WRAPIDJSON_H__
#define __WRAPIDJSON_H__

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

class Wrapidjson
{
public:
    Wrapidjson();

    static bool HasString(const rapidjson::Value &value, const char *name);
    static bool HasInt(const rapidjson::Value &value, const char *name);
    static bool HasInt64(const rapidjson::Value &value, const char *name);
    static bool HasUint(const rapidjson::Value &value, const char *name);
    static bool HasUint64(const rapidjson::Value &value, const char *name);
    static bool HasDouble(const rapidjson::Value &value, const char *name);
    static bool HasBool(const rapidjson::Value &value, const char *name);
    static bool HasArray(const rapidjson::Value &value, const char *name);
    static bool HasObject(const rapidjson::Value &value, const char *name);

    static bool GetString(const rapidjson::Value &value, const char *name, std::string *out,
                          const std::string &defaultVal = "");
    static bool GetInt(const rapidjson::Value &value, const char *name, int *out,
                       int defaultVal = 0);
    static bool GetInt64(const rapidjson::Value &value, const char *name, int64_t *out,
                         int64_t defaultVal = 0);
    static bool GetUint(const rapidjson::Value &value, const char *name, uint32_t *out,
                        uint32_t defaultVal = 0);
    static bool GetUint64(const rapidjson::Value &value, const char *name, uint64_t *out,
                          uint64_t defaultVal = 0);
    static bool GetDouble(const rapidjson::Value &value, const char *name, double *out,
                          double defaultVal = 0.0);
    static bool GetBool(const rapidjson::Value &value, const char *name, bool *out,
                        bool defaultVal = false);

    static void AddString(rapidjson::Document &d, const std::string &name,
                          const std::string &value);
    static void AddString(rapidjson::Value &v, rapidjson::Document::AllocatorType &allocator,
                          const std::string &name, const std::string &value);
    static void AddBool(rapidjson::Document &d, const std::string &name, bool value);
    static void AddInt(rapidjson::Document &d, const std::string &name, int value);
    static void AddUint(rapidjson::Document &d, const std::string &name, unsigned int value);
    static void AddInt64(rapidjson::Document &d, const std::string &name, int64_t value);
    static void AddUint64(rapidjson::Document &d, const std::string &name, uint64_t value);
    static void AddDouble(rapidjson::Document &d, const std::string &name, double value);
    static void AddObject(rapidjson::Document &d, const std::string &name, rapidjson::Value &value);

    void AddString(const std::string &name, const std::string &value);
    void AddBool(const std::string &name, bool value);
    void AddInt(const std::string &name, int value);
    void AddUint(const std::string &name, unsigned int value);
    void AddInt64(const std::string &name, int64_t value);
    void AddUint64(const std::string &name, uint64_t value);
    void AddDouble(const std::string &name, double value);
    void AddObject(const std::string &name, rapidjson::Value &value);
    static std::string ToString(const rapidjson::Value &v);
    std::string ToString();

    bool Parse(const std::string &buf, std::string *err);
    rapidjson::Document &RootRef();

private:
    static bool Has(const rapidjson::Value &value, const char *name);

    rapidjson::Document m_root;
};

inline bool Wrapidjson::Has(const rapidjson::Value &value, const char *name)
{
    return value.IsObject() && value.HasMember(name);
}

inline void Wrapidjson::AddString(const std::string &name, const std::string &value)
{
    Wrapidjson::AddString(m_root, name, value);
}

inline void Wrapidjson::AddBool(const std::string &name, bool value)
{
    Wrapidjson::AddBool(m_root, name, value);
}

inline void Wrapidjson::AddInt(const std::string &name, int value)
{
    Wrapidjson::AddInt(m_root, name, value);
}

inline void Wrapidjson::AddUint(const std::string &name, unsigned int value)
{
    Wrapidjson::AddUint(m_root, name, value);
}

inline void Wrapidjson::AddInt64(const std::string &name, int64_t value)
{
    Wrapidjson::AddInt64(m_root, name, value);
}

inline void Wrapidjson::AddUint64(const std::string &name, uint64_t value)
{
    Wrapidjson::AddUint64(m_root, name, value);
}

inline void Wrapidjson::AddDouble(const std::string &name, double value)
{
    Wrapidjson::AddDouble(m_root, name, value);
}

inline void Wrapidjson::AddObject(const std::string &name, rapidjson::Value &value)
{
    Wrapidjson::AddObject(m_root, name, value);
}

inline rapidjson::Document &Wrapidjson::RootRef()
{
    return m_root;
}

#endif /*WRAPIDJSON_H*/
