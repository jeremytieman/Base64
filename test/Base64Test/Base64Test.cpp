#include "stdafx.h"
#include "CppUnitTest.h"

#include <Base64.h>
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CodexMachina;
using namespace std;

namespace Base64Test
{
    TEST_CLASS(Base64)
    {
        string decoded = "Man is distinguished, not only by his reason, "
            "but by this singular passion from other animals, which is a lust "
            "of the mind, that by a perseverance of delight in the continued "
            "and indefatigable generation of knowledge, exceeds the short "
            "vehemence of any carnal pleasure.";
        string encoded =
            "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz"
            "IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg"
            "dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu"
            "dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo"
            "ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
    public:

        TEST_METHOD(Base64Encoding)
        {
            vector<char> bytes{ begin(decoded), end(decoded) };
            auto result = encode(bytes);
            Assert::AreEqual(encoded.size(), result.size(), L"Size mismatch.");

            for (size_t i = 0; i < encoded.size(); ++i)
            {
                auto e = encoded[i];
                auto a = result[i];
                Assert::AreEqual(e, a, L"Character mismatch");
            }
        }

        TEST_METHOD(Base64Decoding)
        {
            auto result = decode(encoded);
            Assert::AreEqual(decoded.size(), result.size(), L"Size mismatch");

            for (size_t i = 0; i < decoded.size(); ++i)
            {
                auto e = decoded[i];
                auto a = result[i];
                Assert::AreEqual(e, a, L"Character mismatch");
            }
        }
    };
}