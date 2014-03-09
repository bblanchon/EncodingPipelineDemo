#include "stdafx.h"

#include "EncodingLib.h"
#include "ByteStringReader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(StreamWriterTests)
	{
		ByteStringReader reader;		
		StreamWriter     writer;

		stringstream     stream;

	public:

		StreamWriterTests()
			: writer(stream)
		{

		}

		TEST_METHOD_INITIALIZE(Initialize)
		{
			reader.then(writer);
		}

		TEST_METHOD(Receive_48656C6C6F_Write_Hello)
		{
			Receive("48656C6C6F");
			Wrote("Hello");
		}

		TEST_METHOD(Receive_Nothing_Write_Nothing)
		{
			Receive("");
			Wrote("");
		}

		void Receive(const char* bytes)
		{
			reader.read(bytes);
		}
		
		void Wrote(const char* expected)
		{
			Assert::AreEqual(string(expected), stream.str());
		}
	};
}