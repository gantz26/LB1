#include "Txt.h"

using namespace l1;

Txt::Txt(const std::string& fileName)
	: sizeArray(0)
{
	std::ifstream input(fileName);

	if (!input.is_open())
	{
		stringArray = nullptr;
	}
	else
	{
		std::string tempStr;
		while (!input.eof())
		{
			std::getline(input, tempStr);
			++sizeArray;
		}

		input.clear();
		input.seekg(0, std::ios::beg);

		stringArray = new std::string[sizeArray];
		for (int i = 0; i < sizeArray; ++i)
		{
			std::getline(input, stringArray[i]);
		}
	}

	input.close();
}

Txt::Txt(const Txt& obj)
{
	sizeArray = obj.sizeArray;
	stringArray = new std::string[sizeArray];

	for (int i = 0; i < sizeArray; ++i)
	{
		stringArray[i] = obj.stringArray[i];
	}
}

Txt::Txt(Txt&& obj) noexcept
{
	sizeArray = obj.sizeArray;
	stringArray = obj.stringArray;

	obj.sizeArray = 0;
	obj.stringArray = nullptr;
}

Txt::~Txt()
{
	if (stringArray != nullptr)
	{
		delete[] stringArray;
	}
}

Txt& Txt::operator=(const Txt& obj)
{
	if (&obj == this)
	{
		return *this;
	}

	delete[] stringArray;
	sizeArray = obj.sizeArray;
	stringArray = new std::string[sizeArray];

	for (int i = 0; i < sizeArray; ++i)
	{
		stringArray[i] = obj.stringArray[i];
	}

	return *this;
}

Txt& Txt::operator=(Txt&& obj) noexcept
{
	if (&obj == this)
	{
		return *this;
	}

	delete[] stringArray;
	sizeArray = obj.sizeArray;
	stringArray = obj.stringArray;

	obj.sizeArray = 0;
	obj.stringArray = nullptr;

	return *this;
}

int Txt::size() const
{
	return sizeArray;
}
