#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<bits/stdc++.h>

typedef void (*ScriptFunction)(void);
typedef std::map<std::string, ScriptFunction> FunctionMap;

using OptionList = std::vector<std::string> ;

class Menu{
	private:
		Menu() {};
		static Menu* s_Instance;

		std::string m_AppName;
		std::string m_AppVersion;
		OptionList m_MenuOptions;
		FunctionMap m_Functions;
		int m_Selected;
	
	public:
		inline static Menu* GetInstance(){
			return s_Instance = (s_Instance != nullptr) ? s_Instance : new Menu();
		}

		inline void initApp(std::string name, std::string version
		, OptionList options){
			m_AppName = name;
			m_AppVersion = version;
			m_MenuOptions = options;
		};

		inline bool RegisterFunction(std::string name, ScriptFunction fn){
			std::vector<std::string>::iterator it;
			
			it = std::find(m_MenuOptions.begin(), m_MenuOptions.end(), name);
			if(it == m_MenuOptions.end()){
				std::cout<<"Couldn't find the option name"<<std::endl;
				return false;
			}
			
			m_Functions[name] = fn;
			return true;
		}

		void ShowMenu();
		void GetOption();
		bool ProcessMenuOptions();
		void Clean();
};

#endif