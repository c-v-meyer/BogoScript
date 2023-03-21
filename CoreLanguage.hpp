#ifndef BOGOSCRIPT_CORELANGUAGE_HPP
#define BOGOSCRIPT_CORELANGUAGE_HPP

#include <string>
#include <clocale>
#include <iostream>

#include "StandardLibrary.hpp"

using namespace std::string_literals;

#define Nothing ::bogoscript::nullValue
#define True ::bogoscript::trueValue
#define False ::bogoscript::falseValue

#define End BogoscriptInternalCParen BogoscriptInternalCParen;

#define Rem BogoscriptInternalWrapRemark BogoscriptInternalOParen (

#define Return BogoscriptInternalLeave BogoscriptInternalOParen BogoscriptInternalWrapReturn BogoscriptInternalOParen

#define Let ::bogoscript::setVariable(std::move(static_cast<::bogoscript::types::String::BaseType>($name)), BogoscriptInternalStringify BogoscriptInternalOParen
#define LetGlobal ::bogoscript::setVariable(std::move(""s), BogoscriptInternalStringify BogoscriptInternalOParen
#define Be BogoscriptInternalCParen, BogoscriptInternalWrapExpression BogoscriptInternalOParen

#define Get ::bogoscript::getVariable(std::move(static_cast<::bogoscript::types::String::BaseType>($name)), BogoscriptInternalStringify BogoscriptInternalOParen

#define Del ::bogoscript::deleteVariable(std::move(static_cast<::bogoscript::types::String::BaseType>($name)), BogoscriptInternalStringify BogoscriptInternalOParen

#define Call ::bogoscript::call(BogoscriptInternalStringify BogoscriptInternalOParen
#define With BogoscriptInternalCParen, BogoscriptInternalWrapArgs BogoscriptInternalOParen

#define Fun ::bogoscript::defineFunction(std::move(BogoscriptInternalStringify BogoscriptInternalOParen
#define Does BogoscriptInternalCParen), [](::bogoscript::TypeValueCompound&& bogoscriptInternalScopeName,\
    const std::initializer_list<::bogoscript::TypeValueCompound>& bogoscriptInternal2Args) -> ::bogoscript::TypeValueCompound BogoscriptInternalWrapCurly BogoscriptInternalOParen\
        ::bogoscript::Args bogoscriptInternalArgs{bogoscriptInternal2Args};
#define IsNative BogoscriptInternalCParen

#define Forever BogoscriptInternalLeave BogoscriptInternalOParen while ((true
#define While BogoscriptInternalLeave BogoscriptInternalOParen while (BogoscriptInternalWrapBoolExpression BogoscriptInternalOParen
#define Do BogoscriptInternalCParen BogoscriptInternalCParen BogoscriptInternalWrapCurly BogoscriptInternalOParen
#define Continue continue;
#define Break break;

#define If BogoscriptInternalLeave BogoscriptInternalOParen if (BogoscriptInternalWrapBoolExpression BogoscriptInternalOParen
#define Elif BogoscriptInternalCParen else if (BogoscriptInternalWrapBoolExpression BogoscriptInternalOParen
#define Else BogoscriptInternalCParen else if constexpr ((true

#define $ bogoscriptInternalArgs
#define $arg bogoscriptInternalArgs.getNextVararg()
#define $name bogoscriptInternalScopeName
#define $0 bogoscriptInternalArgs[0]
#define $1 bogoscriptInternalArgs[1]
#define $2 bogoscriptInternalArgs[2]
#define $3 bogoscriptInternalArgs[3]
#define $4 bogoscriptInternalArgs[4]
#define $5 bogoscriptInternalArgs[5]
#define $6 bogoscriptInternalArgs[6]
#define $7 bogoscriptInternalArgs[7]
#define $8 bogoscriptInternalArgs[8]
#define $9 bogoscriptInternalArgs[9]
#define $10 bogoscriptInternalArgs[10]
#define $11 bogoscriptInternalArgs[11]
#define $12 bogoscriptInternalArgs[12]
#define $13 bogoscriptInternalArgs[13]
#define $14 bogoscriptInternalArgs[14]
#define $15 bogoscriptInternalArgs[15]
#define $16 bogoscriptInternalArgs[16]
#define $17 bogoscriptInternalArgs[17]
#define $18 bogoscriptInternalArgs[18]
#define $19 bogoscriptInternalArgs[19]
#define $20 bogoscriptInternalArgs[20]
#define $21 bogoscriptInternalArgs[21]
#define $22 bogoscriptInternalArgs[22]
#define $23 bogoscriptInternalArgs[23]
#define $24 bogoscriptInternalArgs[24]
#define $25 bogoscriptInternalArgs[25]
#define $26 bogoscriptInternalArgs[26]
#define $27 bogoscriptInternalArgs[27]
#define $28 bogoscriptInternalArgs[28]
#define $29 bogoscriptInternalArgs[29]
#define $30 bogoscriptInternalArgs[30]
#define $31 bogoscriptInternalArgs[31]
#define $32 bogoscriptInternalArgs[32]
#define $33 bogoscriptInternalArgs[33]
#define $34 bogoscriptInternalArgs[34]
#define $35 bogoscriptInternalArgs[35]
#define $36 bogoscriptInternalArgs[36]
#define $37 bogoscriptInternalArgs[37]
#define $38 bogoscriptInternalArgs[38]
#define $39 bogoscriptInternalArgs[39]
#define $40 bogoscriptInternalArgs[40]
#define $41 bogoscriptInternalArgs[41]
#define $42 bogoscriptInternalArgs[42]
#define $43 bogoscriptInternalArgs[43]
#define $44 bogoscriptInternalArgs[44]
#define $45 bogoscriptInternalArgs[45]
#define $46 bogoscriptInternalArgs[46]
#define $47 bogoscriptInternalArgs[47]
#define $48 bogoscriptInternalArgs[48]
#define $49 bogoscriptInternalArgs[49]
#define $50 bogoscriptInternalArgs[50]
#define $51 bogoscriptInternalArgs[51]
#define $52 bogoscriptInternalArgs[52]
#define $53 bogoscriptInternalArgs[53]
#define $54 bogoscriptInternalArgs[54]
#define $55 bogoscriptInternalArgs[55]
#define $56 bogoscriptInternalArgs[56]
#define $57 bogoscriptInternalArgs[57]
#define $58 bogoscriptInternalArgs[58]
#define $59 bogoscriptInternalArgs[59]
#define $60 bogoscriptInternalArgs[60]
#define $61 bogoscriptInternalArgs[61]
#define $62 bogoscriptInternalArgs[62]
#define $63 bogoscriptInternalArgs[63]

#define BogoscriptInternalConcat(x, y) BogoscriptInternal2Concat(x, y)
#define BogoscriptInternal2Concat(x, y) BogoscriptInternal3Concat(x, y)
#define BogoscriptInternal3Concat(x, y) x##y

#define BogoscriptInternalForEach1(separator, action, x) action(x)
#define BogoscriptInternalForEach2(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach1(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach3(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach2(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach4(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach3(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach5(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach4(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach6(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach5(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach7(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach6(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach8(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach7(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach9(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach8(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach10(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach9(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach11(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach10(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach12(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach11(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach13(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach12(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach14(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach13(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach15(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach14(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach16(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach15(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach17(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach16(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach18(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach17(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach19(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach18(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach20(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach19(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach21(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach20(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach22(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach21(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach23(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach22(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach24(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach23(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach25(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach24(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach26(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach25(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach27(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach26(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach28(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach27(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach29(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach28(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach30(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach29(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach31(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach30(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach32(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach31(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach33(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach32(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach34(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach33(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach35(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach34(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach36(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach35(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach37(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach36(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach38(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach37(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach39(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach38(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach40(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach39(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach41(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach40(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach42(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach41(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach43(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach42(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach44(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach43(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach45(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach44(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach46(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach45(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach47(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach46(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach48(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach47(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach49(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach48(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach50(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach49(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach51(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach50(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach52(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach51(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach53(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach52(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach54(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach53(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach55(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach54(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach56(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach55(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach57(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach56(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach58(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach57(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach59(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach58(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach60(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach59(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach61(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach60(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach62(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach61(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach63(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach62(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach64(separator, action, x, ...) action(x) separator() BogoscriptInternalForEach63(separator, action, __VA_ARGS__)

#define BogoscriptInternalForEachNArg(...) BogoscriptInternal2ForEachNArg(__VA_ARGS__, BogoscriptInternalForEachRSeqN())
#define BogoscriptInternal2ForEachNArg(...) BogoscriptInternalForEachArgN(__VA_ARGS__) 
#define BogoscriptInternalForEachArgN(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44, arg45, arg46, arg47, arg48, arg49, arg50, arg51, arg52, arg53, arg54, arg55, arg56, arg57, arg58, arg59, arg60, arg61, arg62, arg63, arg64, N, ...) N 
#define BogoscriptInternalForEachRSeqN() 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define BogoscriptInternal2ForEach(N, separator, action, ...) BogoscriptInternalConcat(BogoscriptInternalForEach, N)(separator, action, __VA_ARGS__)
#define BogoscriptInternalForEach(separator, action, ...) BogoscriptInternal2ForEach(BogoscriptInternalForEachNArg(__VA_ARGS__), separator, action, __VA_ARGS__)

#define BogoscriptInternalStringify(x) L## #x##s
#define BogoscriptInternalLeave(...) __VA_ARGS__
#define BogoscriptInternalWrapBoolExpression(x) static_cast<bool>(BogoscriptInternalWrapExpression(x))
#define BogoscriptInternalWrapReturn(x) auto _retVal = x; ::bogoscript::clearScope(static_cast<::bogoscript::types::String::BaseType>(bogoscriptInternalScopeName)); return _retVal
#define BogoscriptInternalWrapExpression(x) [&]()->::bogoscript::TypeValueCompound{return x;}()
#define BogoscriptInternalWrapRemark(x)
#define BogoscriptInternalWrapArgs(...) {__VA_OPT__(BogoscriptInternalForEach(BogoscriptInternalComma, BogoscriptInternalWrapExpression, __VA_ARGS__))}
#define BogoscriptInternalWrapCurly(...) {__VA_ARGS__}
#define BogoscriptInternalOParen (
#define BogoscriptInternalCParen )

#define BogoscriptInternalExpand(...) __VA_ARGS__
#define BogoscriptInternalComma() ,

#ifdef NativeFunctions
#define BogoscriptInternalUserDefinedNativeFunctions bogoscriptNativeFunctions();
#else
#define BogoscriptInternalUserDefinedNativeFunctions
#endif

#define BOGOSCRIPT(...)\
    int main(void) {\
		std::setlocale(LC_ALL, "en_US.utf8");\
		::bogoscript::outStream.imbue(std::locale("en_US.utf8"));\
        ::bogoscript::standardNativeFunctions();\
        const auto bogoscriptInternalScopeName{::bogoscript::TypeValueCompound(L""s)};\
        BogoscriptInternalExpand(BogoscriptInternalStandardLibrary)\
        BogoscriptInternalUserDefinedNativeFunctions\
        __VA_ARGS__\
    }

#endif