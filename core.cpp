#include "core.h"
#include "menu.h"
#include "timezones.h"

Core* Core::s_Instance = nullptr;

bool Core::RunApplication(){
	OptionList options = {
		"Get timezone by city", 
		"Get cities by timezone",
		"Show Cities"
	};
	Menu::GetInstance()->initApp("TimeZone", "v0.1", options);
	Menu::GetInstance()->
	RegisterFunction("Show Cities", &GetAllCities);
	Menu::GetInstance()->
	RegisterFunction("Get cities by timezone", &GetCities);

	timezones.push_back(Timezone("Moscow", "MSK", 3));
	timezones.push_back(Timezone("Paris", "PRS", 2));
	timezones.push_back(Timezone("Amsterdam", "AMS", 2));
	timezones.push_back(Timezone("NewYork", "NYC", -4));
	timezones.push_back(Timezone("Tehran", "TEH", 4));
	timezones.push_back(Timezone("Tokyo", "TKY", 9));
	return m_IsRunning = true;
}

bool Core::ExitApplication(){
	return m_IsRunning = false;
}

void Core::Draw(){
	Menu::GetInstance()->ShowMenu();
}

void Core::Update(){
	Menu::GetInstance()->GetOption();
	Menu::GetInstance()->ProcessMenuOptions();
	//TODO - update application state
}

void Core::Clean(){
	//TODO - free the memory
}