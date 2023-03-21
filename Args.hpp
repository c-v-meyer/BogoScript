#ifndef BOGOSCRIPT_ARGS_HPP
#define BOGOSCRIPT_ARGS_HPP

#include <variant>
#include <algorithm>
#include <type_traits>

#include "TypeValueCompound.hpp"

namespace bogoscript {
    struct Args {
    private:
        using Index = signed char;

        const std::initializer_list<TypeValueCompound>& args;
        Index varargPos = -1;

    public:
        class Iterator {
            Args& args;
            Index position;

        public:
            Iterator(Args& args, const Index position)
                : args {args}
                , position {position} {}
            [[nodiscard]] Iterator& operator++() noexcept {
                ++position;
                return *this;
            }

            [[nodiscard]] const TypeValueCompound& operator*() const {
                return args[position];
            }

            friend bool operator==(const Iterator& value1, const Iterator& value2) noexcept;
        };

        Args(const std::initializer_list<TypeValueCompound>& args)
            : args {args} {
            if (args.size() > 64)
                throw "Number of arguments greater than 64!";
        }
        [[nodiscard]] explicit operator bool() noexcept {
            if (++varargPos < args.size()) [[likely]]
                return trueValue;
            varargPos--;
            return falseValue;
        }

        [[nodiscard]] const TypeValueCompound& getNextVararg() const {
            if (varargPos == -1) throw "Varargs list not initialized!";
            if (varargPos >= args.size()) throw "Varargs out of bounds!";
            return std::data(args)[varargPos];
        }
        const TypeValueCompound& operator[](const std::make_unsigned_t<Index> index) const {
            if (index >= args.size())
                throw "Varargs access out of bounds!";
            return std::data(args)[index];
        }

        [[nodiscard]] const std::initializer_list<TypeValueCompound>& getArgs() const noexcept {
            return args;
        }

        [[nodiscard]] bool isSingleTyped() const noexcept {
            const auto type = std::data(args)[0].type;
            return std::ranges::all_of(args, [&](const TypeValueCompound& el) { return type == el.type; });
        }

        [[nodiscard]] bool containsType(const Type type) const noexcept {
            return std::ranges::any_of(args, [&](const TypeValueCompound& el) { return type == el.type; });
        }

        [[nodiscard]] Iterator begin() const noexcept {
            return {const_cast<Args&>(*this), 0};
        }

        [[nodiscard]] Iterator end() const noexcept {
            return {const_cast<Args&>(*this), static_cast<Index>(args.size())};
        }
    };

    [[nodiscard]] inline bool operator==(const Args::Iterator& value1, const Args::Iterator& value2) noexcept {
        return value1.position == value2.position;
    }
}

#endif