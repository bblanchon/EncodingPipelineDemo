#include "stdafx.h"

#include "EncodingLib.h"
#include "BitsToStringConverter.h"
#include "StringToBitsConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(NrziForwardConverterTests)
	{
		NrziForwardConverter bitStuffer;
		BitsToStringConverter bitsToString;
		StringToBitsConverter stringToBits;

	public:
		
		TEST_METHOD_INITIALIZE(Initialize)
		{
			stringToBits.setConsumer(bitStuffer);
			bitStuffer.setConsumer(bitsToString);
		}

		TEST_METHOD(Receive_One_Emit_Zero)
		{
			ReceiveBits__("1");
			AssertEmitted("0");
		}

		TEST_METHOD(Receive_Zero_Emit_One)
		{
			ReceiveBits__("0");
			AssertEmitted("1");
		}

		TEST_METHOD(Receive_2ones_Emit_2zeros)
		{
			ReceiveBits__("11");
			AssertEmitted("00");
		}

		TEST_METHOD(Receive_2zeros_Emit_One_Zero)
		{
			ReceiveBits__("00");
			AssertEmitted("10");
		}
		
		TEST_METHOD(Receive_Zero_One_Emit_2ones)
		{
			ReceiveBits__("01");
			AssertEmitted("11");
		}

		TEST_METHOD(Receive_One_Zero_Emit_Zero_One)
		{
			ReceiveBits__("10");
			AssertEmitted("01");
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