#include <base64.hpp>
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace Base64Test
{  
  std::string decoded = "Man is distinguished, not only by his reason, "
    "but by this singular passion from other animals, which is a lust "
    "of the mind, that by a perseverance of delight in the continued "
    "and indefatigable generation of knowledge, exceeds the short "
    "vehemence of any carnal pleasure.";
  
  std::string encoded =
    "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz"
    "IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg"
    "dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu"
    "dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo"
    "ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

  TEST(Base64Test, EncodeTest)
  {
    std::vector<char> bytes{ begin(decoded), end(decoded) };
    auto result = CodexMachina::encode(bytes);
    ASSERT_EQ(encoded.size(), result.size());
    ASSERT_EQ(encoded, result);
  }

  TEST(Base64Test, DecodeTest)
  {
    auto result = CodexMachina::decode(encoded);
    ASSERT_EQ(decoded.size(), result.size());
    for (size_t i = 0; i < decoded.size(); ++i)
    {
      auto e = decoded[i];
      auto a = result[i];
      ASSERT_EQ(e, a);
    }
  }
}