#ifndef TXT_H
#define TXT_H

#include <string>
#include <fstream>

namespace l1
{
	class Txt
	{
	private:
		std::string* stringArray;
		int sizeArray;

	public:
		Txt(const std::string& fileName = "");
		Txt(const Txt& obj);
		Txt(Txt&& obj) noexcept;
		~Txt();

		Txt& operator=(const Txt& obj);
		Txt& operator=(Txt&& obj) noexcept;

		int size() const;
	};
}

#endif