#include "stdafx.h"

#include "EncodingLib.h"
#include "StringToBytesConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EncodingLibTests
{
	TEST_CLASS(ByteStreamWriterTests)
	{
		StringToBytesConverter stringToBytes;		
		ByteStreamWriter writer;
		stringstream stream;

	public:

		ByteStreamWriterTests()
			: writer(stream)
		{

		}

		TEST_METHOD_INITIALIZE(Initialize)
		{
			stringToBytes.then(writer);
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
			stringToBytes.receive(bytes);
		}
		
		void Wrote(const char* expected)
		{
			Assert::AreEqual(string(expected), stream.str());
		}
	};
}