#include "stdafx.h"

#include "EncodingLib.h"
#include "BitsToStringConverter.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{		
	TEST_CLASS(BytesToBitsConverterTests)
	{
		BytesToBitsConverter bytesToBits;
 		BitsToStringConverter bitsToString;

	public:

		TEST_METHOD_INITIALIZE(Initialize)
		{
			bytesToBits.setConsumer(bitsToString);
		}
		
		TEST_METHOD(Receive_Nothing_Emit_Nothing)
		{			
			AssertEmitted("");
		}

		TEST_METHOD(Receive_00_Emit_00000000)
		{
			bytesToBits.receive(0x00);
			AssertEmitted("00000000");
		}

		TEST_METHOD(Receive_FF_Emit_11111111)
		{
			bytesToBits.receive(0xFF);
			AssertEmitted("11111111");
		}

		TEST_METHOD(Receive_F0_Emit_11110000)
		{
			bytesToBits.receive(0xF0);
			AssertEmitted("11110000");
		}

		TEST_METHOD(Receive_F00F_Emit_1111000000001111)
		{
			bytesToBits.receive(0xF0);
			bytesToBits.receive(0x0F);
			AssertEmitted("1111000000001111");
		}

		void AssertEmitted(const char* expected)
		{
			Assert::AreEqual(expected, bitsToString.c_str());
		}
	};
}