#ifndef TIMEZONE_H
#define TIMEZONE_H

#include <string>
#include <iostream>

#define SEQ  1
#define MAXMASK 16777216

class Timezone{
	private:
		std::string m_Name;
		std::string m_Abbreviation;
		int id;

	public:
		Timezone(std::string name, std::string abbr);

		inline std::string GetName() {return m_Name;}
		inline std::string GetAbbr() {return m_Abbreviation;}
		inline int GetId() {return id;}
};


void AddCity(std::string name, std::string abbr, int offset);
void GetAllCities();
void GetCities();
void GetTimezones();

#endif