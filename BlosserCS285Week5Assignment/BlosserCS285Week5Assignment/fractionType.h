#include <iostream>
#include <string>

#ifndef FRACTIONTYPE_H
#define FRACTIONTYPE_H

#include <exception>

using namespace std;

class fractionException :public exception
{
private:
	const char* message;

public:
	fractionException(const char* msg) :message(msg){}
	virtual const char* what() const throw()
	{
		return message;
	}
};



template <class fractionTemp>
class fractionType
{
	template <class fractionTemp>
	friend ostream& operator << (ostream& out, const fractionType<fractionTemp>& rightFR);

	template <class factionTemp>
	friend istream& operator >> (istream& in, fractionType<fractionTemp>& rightFR);

public:
	fractionTemp numerator;
	fractionTemp denominator;
	fractionTemp fraction1;
	fractionTemp fraction2;

public:
	fractionType()
	{
		numerator = 1;
		denominator = 1;
	}

	fractionType<fractionTemp>(fractionTemp num, fractionTemp den)
	{
		if (den == 0)
		{
			throw fractionException("The denominator cannot equal zero.");
			denominator = 1;
		}

		if (num == 0)
		{
			throw fractionException("You cannot divide by zero.");
			numerator = 1;
		}
	}

	~fractionType()
	{

	}

	fractionType<fractionTemp> operator+(fractionType<fractionTemp> rightFR)
	{
		fractionType temp;
		temp.numerator = numerator * rightFR.denominator + rightFR.numerator * denominator;
		temp.denominator = denominator * rightFR.denominator;
		return temp;
	}


	fractionType<fractionTemp> operator*(fractionType<fractionTemp> rightFR)
	{
		fractionType temp;
		temp.numerator = numerator * rightFR.denominator * rightFR.numerator * denominator;
		temp.denominator = denominator * rightFR.denominator;
		return temp;
	}

	fractionType<fractionTemp> operator-(fractionType<fractionTemp> rightFR)
	{
		fractionType temp;
		temp.numerator = numerator * rightFR.denominator - rightFR.numerator * denominator;
		temp.denominator = denominator * rightFR.denominator;
		return temp;
	}

	fractionType<fractionTemp> operator/(fractionType<fractionTemp> rightFR)
	{
		fractionType temp;
		if (rightFR.numerator == 0)
		{
			throw fractionException("You cannot divide by zero.");
			return *this;
		}

		else
		{
			temp.numerator = numerator * rightFR.denominator;
			temp.denominator = rightFR.numerator * denominator;
			return temp;
		}
	}

	bool operator==(fractionType<fractionTemp> rightFR)
	{
		return (numerator * rightFR.denominator == denominator * rightFR.numerator);
	}

	bool operator!=(fractionType<fractionTemp> rightFR)
	{
		return (numerator * rightFR.denominator != denominator * rightFR.numerator);
	}

	bool operator<=(fractionType<fractionTemp> rightFR)
	{
		return (numerator * rightFR.denominator <= denominator * rightFR.numerator);
	}

	bool operator<(fractionType<fractionTemp> rightFR)
	{
		return (numerator * rightFR.denominator < denominator * rightFR.numerator);
	}

	bool operator>=(fractionType<fractionTemp> rightFR)
	{
		return (numerator * rightFR.denominator >= denominator * rightFR.numerator);
	}

	bool operator>(fractionType<fractionTemp> rightFR)
	{
		return (numerator * rightFR.denominator > denominator * rightFR.numerator);
	}
};

template<class fractionTemp>
ostream& operator << (ostream& out, const fractionType<fractionTemp>& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;
	return out;
}

template<class fractionTemp>
istream& operator >> (istream& in, fractionType<fractionTemp>& fraction)
{
	char entry;
	in >> fraction.numerator;
	if (in.fail())
	{
		throw (fractionException("Invalid Input"));
		in.ignore(1);
	}

	in >> entry;
	in >> fraction.denominator;
	if (in.fail())
	{
		throw (fractionException("Invalid Input"));
	}
	return in;
}

#endif


