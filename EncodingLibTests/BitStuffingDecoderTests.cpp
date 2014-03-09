#include "stdafx.h"

#include "EncodingLib.h"
#include "BitStringWriter.h"
#include "BitStringReader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(BitStuffingDecoderTests)
	{
        BitStringReader    reader;
		BitStuffingDecoder decoder;
		BitStringWriter    writer;

	public:

		TEST_METHOD_INITIALIZE(Initialize)
		{
            reader.then(decoder).then(writer);
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

		TEST_METHOD(Receive_6one_zero_Emit_6ones)
		{
			Receive("1111110");
			Emitted("111111");
		}

		TEST_METHOD(Receive_6ones_zero_one_Emit_7ones)
		{
			Receive("11111101");
			Emitted("1111111");
		}

		TEST_METHOD(Receive_6ones_zero_6ones_zero_Emit_12ones)
		{
			Receive("11111101111110");
			Emitted("111111111111");
		}


		TEST_METHOD(Receive_6ones_zero_6ones_zero_one_Emit_13ones)
		{
			Receive("111111011111101");
			Emitted("1111111111111");
		}

		TEST_METHOD(Receive_5ones_zero_5ones_Emit_5ones_zero_5ones)
		{
			Receive("11111011111");
			Emitted("11111011111");
		}

		void Receive(const char * bits)
		{
			reader.read(bits);
		}

		void Emitted(const char * expected)
		{
			Assert::AreEqual(expected, writer.c_str());
		}
	};
}