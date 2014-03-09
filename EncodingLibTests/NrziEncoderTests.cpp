#include "stdafx.h"

#include "EncodingLib.h"
#include "BitStringWriter.h"
#include "BitStringReader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(NrziForwardConverterTests)
	{
		NrziEncoder nrzi;
		BitStringWriter writer;
		BitStringReader reader;

	public:
		
		TEST_METHOD_INITIALIZE(Initialize)
		{
			reader
				.then(nrzi)
				.then(writer);
		}

		TEST_METHOD(Receive_One_Emit_Zero)
		{
			Receive("1");
			Emitted("0");
		}

		TEST_METHOD(Receive_Zero_Emit_One)
		{
			Receive("0");
			Emitted("1");
		}

		TEST_METHOD(Receive_2ones_Emit_2zeros)
		{
			Receive("11");
			Emitted("00");
		}

		TEST_METHOD(Receive_2zeros_Emit_One_Zero)
		{
			Receive("00");
			Emitted("10");
		}
		
		TEST_METHOD(Receive_Zero_One_Emit_2ones)
		{
			Receive("01");
			Emitted("11");
		}

		TEST_METHOD(Receive_One_Zero_Emit_Zero_One)
		{
			Receive("10");
			Emitted("01");
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