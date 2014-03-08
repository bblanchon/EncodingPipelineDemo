#include "stdafx.h"

#include "EncodingLib.h"
#include "BitsToStringConverter.h"
#include "StringToBitsConverter.h"

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
			stringToBits
				.then(bitStuffer)
				.then(bitsToString);
		}
		
		TEST_METHOD(Receive_Zero_Emit_Zero)
		{
			Receive("0");
			Emitted("0");
		}

		TEST_METHOD(Receive_One_Emit_One)
		{
			Receive("1");
			Emitted("1");
		}

		TEST_METHOD(Receive_7zeros_Emit_7zeros)
		{
			Receive("0000000");
			Emitted("0000000");
		}

		TEST_METHOD(Receive_6ones_Emit_6one_zero)
		{
			Receive("111111");
			Emitted("1111110");
		}

		TEST_METHOD(Receive_7ones_Emit_6ones_zero_one)
		{
			Receive("1111111");
			Emitted("11111101");
		}

		TEST_METHOD(Receive_12ones_Emit_6ones_zero_6ones_zero)
		{
			Receive("111111111111");
			Emitted("11111101111110");
		}


		TEST_METHOD(Receive_13ones_Emit_6ones_zero_6ones_zero_one)
		{
			Receive("1111111111111");
			Emitted("111111011111101");
		}

		void Receive(const char * bits)
		{
			stringToBits.receive(bits);
		}

		void Emitted(const char * expected)
		{
			Assert::AreEqual(expected, bitsToString.c_str());
		}
	};
}