#ifndef TIMEZONE_H
#define TIMEZONE_H

#include <string>
#include <iostream>

class Timezone{
	private:
		std::string m_Name;
		std::string m_Abbreviation;
		int m_Offset;

	public:
		Timezone(std::string name, std::string abbr, int offset) {
			m_Name = name;
			m_Abbreviation = abbr;
			m_Offset = offset;
		}

		inline int GetOffset() {return m_Offset;}
		inline std::string GetName() {return m_Name;}
		inline std::string GetAbbr() {return m_Abbreviation;}
};

std::vector<Timezone> timezones;

void GetAllCities(){
	
	for(int i=0; i<timezones.size(); ++i){
		std::cout<<timezones[i].GetName() << "\t" \
		<< timezones[i].GetOffset() << std::endl;
	}
}

void GetCities(){
	int offset;
	std::cout<<"Enter timezone offset: ";
	std::cin>>offset;

	for(int i=0; i<timezones.size(); ++i){
		if( timezones[i].GetOffset() & offset){
			std::cout<< timezones[i].GetName()<<std::endl;
		}
	}
}

void GetTimezones(){
	
	
}

#endif