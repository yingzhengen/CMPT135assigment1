#include <iostream>
using namespace std;

class CMPT135_String
{
private:
	char* buffer; //This will be the dynamic array to hold the characters
public:
	//static member function to compute the length of null-terminated char arrays
	static int cstrlen(const char* cStr);
	//Constructors
	CMPT135_String();
	CMPT135_String(const char& c);
	CMPT135_String(const char* cStr); //*cStr is a null-terminated char array
	CMPT135_String(const CMPT135_String& s);
	//Destructor
	~CMPT135_String();
	//Assignment operators
	CMPT135_String& operator= (const CMPT135_String& s);
	CMPT135_String& operator= (const char& c);
	CMPT135_String& operator= (const char* cStr); //*cStr is a null-terminated char array
	//Getter member functions
	int getLength() const;
	char& operator[](const int& index) const;
	//Setter member functions
	void append(const CMPT135_String& s);
	void append(const char& c);
	void append(const char* cStr); //*cStr is a null-terminated char array
	//Other member functions
	int findCharIndex(const char& c) const;
	int reverseFindCharIndex(const char& c) const;
	CMPT135_String getSubString(const int& startIndex, const int& len) const;
	bool isSubString(const CMPT135_String& s) const;
	bool isSubString(const char* cStr) const; //*cStr is a null-terminated char array
	void reverse();
	int countChar(const char c);
	void removeChar(const char& c);
	void replaceChar(const char& c1, const char& c2);
	//Operator member functions
	CMPT135_String operator+ (const CMPT135_String& s) const;
	CMPT135_String operator+ (const char* cStr) const; //*cStr is a null-terminated char array
	CMPT135_String operator+ (const char& c) const;
	CMPT135_String& operator+= (const CMPT135_String& s);
	CMPT135_String& operator+= (const char* cStr); //*cStr is a null-terminated char array
	CMPT135_String& operator+= (const char& c);
	bool operator== (const CMPT135_String& s) const;
	bool operator== (const char* cStr) const; //*cStr is a null-terminated char array
	bool operator!= (const CMPT135_String& s) const;
	bool operator!= (const char* cStr) const; //*cStr is a null-terminated char array
	bool operator< (const CMPT135_String& s) const;
	bool operator< (const char* cStr) const; //*cStr is a null-terminated char array
	bool operator> (const CMPT135_String& s) const;
	bool operator> (const char* cStr) const; //*cStr is a null-terminated char array
	bool operator<= (const CMPT135_String& s) const;
	bool operator<= (const char* cStr) const; //*cStr is a null-terminated char array
	bool operator>= (const CMPT135_String& s) const;
	bool operator>= (const char* cStr) const; //*cStr is a null-terminated char array
	//Friend Functions (for operators)
	friend CMPT135_String operator+ (const char* cStr, const CMPT135_String& s);
	//*cStr is a null-terminated char array
	friend CMPT135_String operator+ (const char& c, const CMPT135_String& s);
	friend bool operator== (const char* cStr, const CMPT135_String& s);
	//*cStr a null-terminated char array
	friend bool operator!= (const char* cStr, const CMPT135_String& s);
	//*cStr is a null-terminated char array
	friend bool operator< (const char* cStr, const CMPT135_String& s);
	//*cStr is a null-terminated char array
	friend bool operator> (const char* cStr, const CMPT135_String& s);
	//*cStr is a null-terminated char array
	friend bool operator<= (const char* cStr, const CMPT135_String& s);
	//*cStr is a null-terminated char array
	friend bool operator>= (const char* cStr, const CMPT135_String& s);
	//*cStr is a null-terminated char array
	friend ostream& operator<< (ostream& outputStream, const CMPT135_String& s);
	friend istream& operator>> (istream& inputStream, CMPT135_String& s);
};
int CMPT135_String::cstrlen(const char* cStr)
{
	/*
	This function returns the number of printable characters in the null-terminated
	character array cStr. That is, it returns the number of characters in the
	array excluding the terminating null character.
	If the pointer cStr does not have any allocated memory but instead it is
	a nullptr, then this function returns 0.
	This means there are two different cases for which this function returns 0.
	The first case is if the cStr pointer has a nullptr value and the second case
	is when cStr is a dynamic array of size 1 with cStr[0] = '\0'
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	if (cStr == nullptr) return 0;
	int len = 0;
	while (cStr[len] != '\0') len++;
	return len;
}
//Constructors
CMPT135_String::CMPT135_String()
{
	/*
	This function constructs a default CMPT135_String object whose pointer member
	variable is initialized to nullptr.
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	buffer = nullptr;
}
CMPT135_String::CMPT135_String(const char& c)
{
	/*
	This function constructs a non-default CMPT135_String that contains one printable
	character (which is the argument) and a null character at the end.
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	buffer = new char[2];
	buffer[0] = c;
	buffer[1] = '\0';
}
CMPT135_String::CMPT135_String(const char* cStr) //*cStr is a null-terminated char array
{
	/*
	This function constructs a non-default CMPT135_String that contains all the printable
	characters of the argument and a null character at the end.
	*/
	buffer = new char[cstrlen(cStr) + 1];
	for (int i = 0; i < cstrlen(cStr) ; i++)
	{
		buffer[i] = cStr[i];
	}
	buffer[cstrlen(cStr)] = '\0';
}
CMPT135_String::CMPT135_String(const CMPT135_String & s)
{
	/*
	This function constructs a CMPT135_String object which is a copy of the argument s
	*/
	buffer = new char[s.cstrlen(s.buffer) + 1];
	for (int i = 0; i < s.cstrlen(s.buffer); i++)
	{
		buffer[i] = s.buffer[i];
		
	}
	buffer[s.cstrlen(s.buffer)] = '\0';
}
//Destructor
CMPT135_String::~CMPT135_String()
{
	/*
	This function destructs a CMPT135_String object. That is it deletes its buffer and
	assign the buffer a nullptr value
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	if (buffer != nullptr)
	{
		delete[] buffer;
		buffer = nullptr;
	}
}
//Assignment operators
CMPT135_String& CMPT135_String::operator= (const CMPT135_String& s)
{
	/*
	This function assigns a copy of the value of the argument s to the calling object
	*/
	this->~CMPT135_String();
	buffer = new char[s.cstrlen(s.buffer) + 1];
	for (int i = 0; i < s.cstrlen(s.buffer); i++)
	{
		buffer[i] = s.buffer[i];
	}
	buffer[s.cstrlen(s.buffer)] = '\0';
	return *this;

}
CMPT135_String& CMPT135_String::operator= (const char& c)
{
	/*
	This function assigns a copy of the character argument to the calling object
	*/
	this->~CMPT135_String();
	buffer = new char[2];
	buffer[0] = c;
	buffer[1] = '\0';
	return *this;
}
CMPT135_String& CMPT135_String::operator= (const char* cStr) //*cStr is a null-terminated char array
{
	/*
	This function assigns a copy of the null-terminated character array argument to the calling
	object
	*/
	this->~CMPT135_String();
	buffer = new char[cstrlen(cStr) + 1];
	for (int i = 0; i < cstrlen(cStr); i++)
	{
		buffer[i] = cStr[i];
	}
	buffer[cstrlen(cStr)] = '\0';
	return *this;
}

//Getter member functions
int CMPT135_String::getLength() const
{
	/*
	This function returns the length of the buffer of the calling objects as computed by the static
	member function CMPT135_String::cstrlen
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	return CMPT135_String::cstrlen(buffer);
}
/********************************************************************************/
/****************************** questioning *************************************/
/********************************************************************************/
/********************************************************************************/
char& CMPT135_String::operator[](const int& index) const
{
	/*
	This function returns the character at the given index of the calling object.
	If the index is out of the valid bounds, then error message should be printed.
	This function may crash the application if index out of bound error occurs.
	*/
	if (index > getLength())
	{
		cout << "Error:the index is out of the valid bounds." << endl;
		
	}
	return buffer[index];
}

/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/

//Setter member functions
void CMPT135_String::append(const CMPT135_String& s)
{
	/*
	This function appends a copy of the value of the argument s to the calling object.
	*/
	int const newLen = getLength() + s.getLength() + 1;
	char* temp = new char[newLen];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = buffer[i];
	}
	for (int j = 0; j <s.getLength(); j++)
	{
		temp[getLength() + j] = s[j];
	}
	temp[newLen-1] = '\0';
	*this = temp;
}
void CMPT135_String::append(const char& c)
{
	/*
	This function appends a copy of the character argument to the calling object
	*/
	int const newLen = getLength() + 2;
	char* temp = new char[newLen];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = buffer[i];
	}
	temp[getLength()] = c;
	temp[newLen - 1] = '\0';
	*this = temp;

}
void CMPT135_String::append(const char* cStr) //*cStr is a null-terminated char array
{
	/*
	This function appends a copy of the null-terminated character array to the calling object
	*/
	int const newLen = getLength() + cstrlen(cStr)+1;
	char* temp = new char[newLen];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = buffer[i];
	}
	for (int j = 0; j < cstrlen(cStr); j++)
	{
		temp[getLength() + j] = cStr[j];
	}
	temp[newLen - 1] = '\0';
	*this = temp;
}
//Other member functions
int CMPT135_String::findCharIndex(const char& c) const
{
	/*
	This function returns the smallest valid index of the calling object such that the character
	of the calling object at that index is equal to the character argument. If no such index exists,
	then this function returns -1
	*/
	for (int i = 0; i < getLength(); i++)
	{
		if (buffer[i] == c)
			return i;

	}
	return false;
}
int CMPT135_String::reverseFindCharIndex(const char& c) const
{
	/*
	This function returns the largest valid index of the calling object such that the character
	of the calling object at that index is equal to the character argument. If no such index exists,
	then this function returns -1
	*/
	for (int i = getLength()-1; i >=0; i--)
	{
		if (buffer[i] == c)
			return i;

	}
	return false;
}
CMPT135_String CMPT135_String::getSubString(const int& startIndex, const int& length) const
{
	/*
	This function returns a substring of the calling object starting from the given startIndex
	and whose length is given by the length argument. If there are no enough characters starting
	from
	the given start index, then this function will return only the available characters.
	*/
	char* subS = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		if (buffer[startIndex+i] != '\0')
		{
			subS[i] = buffer[startIndex + i];
		}
		else
		{
			subS[i] = '\0';
			break;
		}
	}
	CMPT135_String s(subS);
	return s;
	
}
bool CMPT135_String::isSubString(const CMPT135_String& s) const
{
	/*
	This function tests if the calling object is a substring of the argument s.
	If it is it returns true otherwise it returns false
	*/
	for (int i = 0; i < getLength(); i++)
	{
		int count = 0;
		if(buffer[i] == s.buffer[0])
		for (int j = 0,n =0; j < s.getLength(); j++,n++)
		{
			if (buffer[i + n] == s.buffer[j] && (i + n) < getLength())
				count++;
			else
				break;
		}
		if (count == s.getLength())
			return true;
	}
		return false;
}
bool CMPT135_String::isSubString(const char* cStr) const //*cStr is a null-terminated char array
{
	/*
	This function tests if the calling object is a substring of the argument null-terminated
	character
	array. If it is it returns true otherwise it returns false
	*/
	
	for (int i = 0; i < getLength(); i++)
	{
		int count = 0;
		if (buffer[i] == cStr[0])
			for (int j = 0, n = 0; j < cstrlen(cStr); j++, n++)
			{
				if (buffer[i + n] == cStr[j] && (i + n) < getLength())
					count++;
				else
					break;
			}
		if (count == cstrlen(cStr))
			return true;
	}
	return false;
}
void CMPT135_String::reverse()
{
	/*
	This function reverses the calling object.
	*/
	if (getLength == 0)
		return;
	char* temp = new char[getLength()];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = buffer[getLength() - 1 - i];
	}
	*this = temp;

}
int CMPT135_String::countChar(const char c)
{
	/*
	This function returns how many times the character argument is found in the calling object
	*/
	if (getLength() == 0)
		return 0;
	int count = 0;
	for (int i = 0; i < getLength(); i++)
	{
		if (buffer[i] == c)
			count++;
	}
	return count;
}
void CMPT135_String::removeChar(const char& c)
{
	/*
	This function removes every occurence of the character argument from the calling object
	*/
	char* temp = new char[getLength()];
	for (int i = 0,j=0; i < getLength(); i++,j++)
	{
		if (buffer[i] == c)
		{
			i++;
			continue;
		}
		temp[j] = buffer[i];
	}

}
void CMPT135_String::replaceChar(const char& c1, const char& c2)
{
	/*
	This function replaces every occurence of the argument character c1 in the calling object by
	the argument character c2
	*/
	char* temp = new char[getLength()];
	for (int i= 0; i < getLength(); i++)
	{
		if (buffer[i] == c1)
			temp[i] = c2;
		else
			temp[i] = buffer[i];
	}
}
//Operator member functions
CMPT135_String CMPT135_String::operator+ (const CMPT135_String& s) const
{
	/*
	This function returns a new CMPT135_String object made up all the characters of the
	calling object followed by the characters of the argument s
	*/
	int const newLen = getLength() + s.getLength() + 1;
	char* temp = new char[newLen];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = buffer[i];
	}
	for (int j = 0; j < s.getLength(); j++)
	{
		temp[getLength() + j] = s[j];
	}
	temp[newLen - 1] = '\0';
	return temp;
	
}
CMPT135_String CMPT135_String::operator+ (const char* cStr) const //*cStr is a null-terminated char array
{
	/*
	This function returns a new CMPT135_String object made up all the characters of the
	calling object followed by the characters of the null-terminated character array argument cStr
	*/
	int const newLen = getLength() + cstrlen(cStr) + 1;
	char* temp = new char[newLen];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = buffer[i];
	}
	for (int j = 0; j < cstrlen(cStr); j++)
	{
		temp[getLength() + j] = cStr[j];
	}
	temp[newLen - 1] = '\0';
	return temp;
}
CMPT135_String CMPT135_String::operator+ (const char& c) const
{
	/*
	This function returns a new CMPT135_String object made up all the characters of the
	calling object followed by the character argument c
	*/
	int const newLen = getLength() + 2;
	char* temp = new char[newLen];
	for (int i = 0; i < getLength(); i++)
	{
		temp[i] = buffer[i];
	}
	temp[getLength()] = c;
	temp[newLen - 1] = '\0';
	return temp;
}
CMPT135_String& CMPT135_String::operator+= (const CMPT135_String& s)
{
	/*
	This function appends a copy of the characters of s to the calling object and then
	returns the calling object
	*/
	CMPT135_String temp(*this);
	*this = temp + s;
	return *this;
}