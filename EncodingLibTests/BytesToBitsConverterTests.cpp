#include "stdafx.h"

#include "EncodingLib.h"
#include "BitStringWriter.h"
#include "ByteStringReader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{		
	TEST_CLASS(BytesToBitsConverterTests)
	{
		ByteStringReader stringToBytes;
		BytesToBitsConverter bytesToBits;
 		BitStringWriter bitsToString;

	public:

		TEST_METHOD_INITIALIZE(Initialize)
		{
			stringToBytes
				.then(bytesToBits)
				.then(bitsToString);
		}
		
		TEST_METHOD(Receive_Nothing_Emit_Nothing)
		{			
			Receive("");
			Emitted("");
		}

		TEST_METHOD(Receive_00_Emit_00000000)
		{
			Receive("00");
			Emitted("00000000");
		}

		TEST_METHOD(Receive_FF_Emit_11111111)
		{
			Receive("FF");
			Emitted("11111111");
		}

		TEST_METHOD(Receive_F0_Emit_11110000)
		{
			Receive("F0");
			Emitted("11110000");
		}

		TEST_METHOD(Receive_F00F_Emit_1111000000001111)
		{
			Receive("F00F");
			Emitted("1111000000001111");
		}

		void Receive(const char* bytes)
		{
			stringToBytes.read(bytes);
		}

		void Emitted(const char* expected)
		{
			Assert::AreEqual(expected, bitsToString.c_str());
		}
	};
}