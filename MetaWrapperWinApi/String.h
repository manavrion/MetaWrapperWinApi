#pragma once
#include <string>

namespace MetaFrame {

    typedef wchar_t wchar;

    struct String : public std::wstring {
        String() : std::wstring() {}
        String(const wchar *s) : std::wstring(s) {}
        String(const std::wstring &s) : std::wstring(s) {}
        String(const String &s) : std::wstring(s.c_str()) {}
        String(long long ll) {
            wchar buffer[32];
            _itow(ll, buffer, 10);
            this->operator=(buffer);
        }
        //auto cast
        operator const wchar*()const {
            return this->c_str();
        }

        explicit operator const std::string()const {
            std::string ret;
            for (auto ch : *this) {
                ret.push_back((char)ch);
            }
            return ret;
        }

        friend String operator+(const String &s1, const String &s2) {
            return String(std::wstring(s1.c_str()) + std::wstring(s2.c_str()));
        }
        friend String operator+(const String &s1, const wchar *a) {
            return s1 + String(a);
        }
        friend String operator+(const wchar *a, const String &s1) {
            return String(a) + String(s1);
        }

        int toValueInt() {
            return _wtoi(this->c_str());
        }
    };

    struct ByteString : public std::string {
        ByteString() : std::string() {}
        ByteString(const char *s) : std::string(s) {}
        ByteString(const std::string &s) : std::string(s) {}
        ByteString(const ByteString &s) : std::string(s.c_str()) {}
        ByteString(long long ll) {
            char buffer[32];
            _itoa(ll, buffer, 10);
            this->operator=(buffer);
        }
        //auto cast
        operator const char*()const {
            return this->c_str();
        }

        friend ByteString operator+(const ByteString &s1, const ByteString &s2) {
            return ByteString(std::string(s1.c_str()) + std::string(s2.c_str()));
        }
        friend ByteString operator+(const ByteString &s1, const char *a) {
            return s1 + ByteString(a);
        }
        friend ByteString operator+(const char *a, const ByteString &s1) {
            return ByteString(a) + ByteString(s1);
        }

        int toValueInt() {
            return atoi(this->c_str());
        }
    };

}
