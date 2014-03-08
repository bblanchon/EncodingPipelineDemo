#include "stdafx.h"

#include "EncodingLib.h"
#include "BitsToStringConverter.h"
#include "StringToBitsConverter.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(UsbBitStufferTests)
	{
		UsbBitStuffer bitStuffer;
		BitsToStringConverter bitsToString;
		StringToBitsConverter stringToBits;
		
	public:

		TEST_METHOD_INITIALIZE(Initialize)
		{
			stringToBits.setConsumer(bitStuffer);
			bitStuffer.setConsumer(bitsToString);
		}
		
		TEST_METHOD(Receive_Zero_Emit_Zero)
		{
			ReceiveBits__("0");
			AssertEmitted("0");
		}

		TEST_METHOD(Receive_One_Emit_One)
		{
			ReceiveBits__("1");
			AssertEmitted("1");
		}

		TEST_METHOD(Receive_7zeros_Emit_7zeros)
		{
			ReceiveBits__("0000000");
			AssertEmitted("0000000");
		}

		TEST_METHOD(Receive_6ones_Emit_6ones)
		{
			ReceiveBits__("111111");
			AssertEmitted("111111");
		}

		TEST_METHOD(Receive_7ones_Emit_6ones_zero_one)
		{
			ReceiveBits__("1111111");
			AssertEmitted("11111101");
		}

		TEST_METHOD(Receive_13ones_Emit_6ones_zero_6ones_zero_one)
		{
			ReceiveBits__("1111111111111");
			AssertEmitted("111111011111101");
		}

		void ReceiveBits__(const char * bits)
		{
			stringToBits.receive(bits);
		}

		void AssertEmitted(const char * expected)
		{
			Assert::AreEqual(expected, bitsToString.c_str());
		}
	};
}