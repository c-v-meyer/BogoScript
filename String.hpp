#ifndef BOGOSCRIPT_STRING_HPP
#define BOGOSCRIPT_STRING_HPP

#include <string>
#include <cstring>
#include <new>

#include "Literal.hpp"

namespace bogoscript {
	namespace types {
        struct String final : Literal {
        private:
            inline constexpr static std::size_t conversionBufferSize = 64;
            static thread_local wchar_t conversionBuffer[conversionBufferSize];

        public:
            using BaseType = std::wstring;
            BaseType value;
            String(BaseType&& value) noexcept
                : value {value} {}
            explicit String(const char* value) noexcept {
                const auto valueLen {std::strlen(value)};
                bool needToDeleteBuffer;
                wchar_t* buffer;
                if (valueLen >= conversionBufferSize) [[unlikely]] {
                    needToDeleteBuffer = true;
                    buffer = new wchar_t[valueLen + 1];
                } else [[likely]] {
                    needToDeleteBuffer = false;
                    buffer = conversionBuffer;
                }
                std::memset(buffer, 0, conversionBufferSize * sizeof(wchar_t));
#ifdef _MSC_VER
                {
                    std::size_t convertedLen;
                    auto result = mbstowcs_s(&convertedLen, buffer, valueLen + 1, value, valueLen);
				}
#else
                std::mbstowcs(buffer, value, valueLen);
#endif
                this->value = buffer;
                if (needToDeleteBuffer) [[unlikely]]
                    delete[] buffer;
            }
            explicit String(const wchar_t* value) noexcept
                : value {value} {}
            operator BaseType() const noexcept {
                return value;
            }
            friend inline bool operator==(const String& value1, const String& value2) noexcept;
            friend inline bool operator!=(const String& value1, const String& value2) noexcept;
            friend inline bool operator<(const String& value1, const String& value2);
            friend inline bool operator>(const String& value1, const String& value2);
            friend inline bool operator<=(const String& value1, const String& value2);
            friend inline bool operator>=(const String& value1, const String& value2);
            friend inline bool operator&&(const String& value1, const String& value2);
            friend inline bool operator||(const String& value1, const String& value2);
        };
        inline bool operator==(const String& value1, const String& value2) noexcept {
            return value1.value == value2.value;
        }
        inline bool operator!=(const String& value1, const String& value2) noexcept {
            return value1.value != value2.value;
        }
        inline bool operator<(const String&, const String&) {
            throw "Tried to <-compare two strings!";
        }
        inline bool operator>(const String&, const String&) {
            throw "Tried to >-compare two strings!";
        }
        inline bool operator<=(const String&, const String&) {
            throw "Tried to <=-compare two strings!";
        }
        inline bool operator>=(const String&, const String&) {
            throw "Tried to >=-compare two strings!";
        }
        inline bool operator&&(const String&, const String&) {
            throw "Tried to &&-compare two strings!";
        }
        inline bool operator||(const String&, const String&) {
            throw "Tried to ||-compare two strings!";
        }
	}
}

#endif