#include "timezones.h"
#include <vector>
#include <string>
#include<bits/stdc++.h>


std::vector<Timezone> cities;
int timezones[25];

int sequence = SEQ;

Timezone::Timezone(std::string name, std::string abbr){
	m_Name = name;
	m_Abbreviation = abbr;
	id = sequence++;
}

void GetCitiesUtil(int offset){
	for(int i=0; i<cities.size(); ++i){
		int cityId = cities[i].GetId();
		int cityMask = 1 << cityId;
		if(timezones[offset] & cityMask){
			std::cout << "\t City "<< cities[i].GetName()<<std::endl;
		}
	}
}

void AddCity(std::string name, std::string abbr, int offset){
	Timezone city = Timezone(name, abbr);
	cities.push_back(city);
	int  id_mask = (1 << city.GetId());
	timezones[12 + offset] |= id_mask;
}

void GetAllCities(){
	for(int i=0, gmt = -12; i<25; ++i, ++gmt){
		if(timezones[i] > 0){
			std::cout<<"Timezone GMT"<<gmt<<" :"<<std::endl;
			GetCitiesUtil(i);
		}
	}
}

void GetCities(){
	int offset;
	std::cout<<"Enter timezone offset: ";
	std::cin>>offset;
	offset += 12;

	GetCitiesUtil(offset);
}

void GetTimezones(){
	std::string name;
	std::cout<<"Enter city name: ";
	std::cin>>name;

	int index = -1;
	for(int i = 0; i < cities.size(); ++i){
		if(cities[i].GetName() == name) {
			index = i;
			break;
		}
	}

	if(index == -1){
		std::cout<<"Couldn't find the city"<<std::endl;
		return;
	}

	Timezone city = cities[index];
	int cityMask = 1 << city.GetId();
	for(int i=0 ; i<25; ++i){
		if(timezones[i] & cityMask){
			std::cout<<"Timezone GMT"<<(-12) + i<<std::endl;
			break;
		}
	}
}