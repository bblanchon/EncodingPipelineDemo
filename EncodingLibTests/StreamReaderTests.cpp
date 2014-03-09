#include "stdafx.h"

#include "EncodingLib.h"
#include "ByteStringWriter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(StreamReaderTests)
	{
		StreamReader reader;
		ByteStringWriter bytesToString;

	public:

		TEST_METHOD_INITIALIZE(Initialize)
		{
			reader.then(bytesToString);
		}
		
		TEST_METHOD(Read_Hello_Emit_48656C6C6F)
		{
			Read("Hello");
			Emitted("48656C6C6F");
		}

		TEST_METHOD(Read_Nothing_Emit_Nothing)
		{
			Read("");
			Emitted("");
		}

		void Read(const char* bytes)
		{
			std::stringstream buf(bytes);
			
			reader.readFrom(buf);
		}

		void Emitted(const char* expected)
		{
			Assert::AreEqual(expected, bytesToString.c_str());
		}
	};
}