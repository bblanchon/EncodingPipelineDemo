#include "stdafx.h"

#include "EncodingLib.h"
#include "BitStringReader.h"
#include "ByteStringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(BitsToBytesConverterTests)
	{
		BitStringReader      reader;
		BitsToBytesConverter bitsToBytes;
		ByteStringWriter     writer;

	public:

		TEST_METHOD_INITIALIZE(Initialize)
		{
			reader
				.then(bitsToBytes)
				.then(writer);
		}

		TEST_METHOD(Receive_Nothing_Emit_Nothing)
		{
			Receive("");
			Emitted("");
		}

		TEST_METHOD(Receive_00000000_Emit_00)
		{
			Receive("00000000");
			Emitted("00");
		}

		TEST_METHOD(Receive_0_Emit_00)
		{
			Receive("0");
			Emitted("00");
		}

		TEST_METHOD(Receive_1_Emit_80)
		{
			Receive("1");
			Emitted("80");
		}

		TEST_METHOD(Receive_01_Emit_40)
		{
			Receive("01");
			Emitted("40");
		}

		TEST_METHOD(Receive_11111111_Emit_FF)
		{
			Receive("11111111");
			Emitted("FF");
		}

		TEST_METHOD(Receive_000000000_Emit_0000)
		{
			Receive("000000000");
			Emitted("0000");
		}

		TEST_METHOD(Receive_111111111_Emit_FF80)
		{
			Receive("111111111");
			Emitted("FF80");
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