#include "menu.h"
#include "core.h"

Menu* Menu::s_Instance = nullptr;

void Menu::ShowMenu(){
	std::cout<<"--===="<<m_AppName<<"====--"<<std::endl;
	for(int i=0;i<m_MenuOptions.size(); ++i){
		std::cout<< i+1 <<") "<< m_MenuOptions[i] << std::endl;
	}
	std::cout<<"\n"<<"version: "<< m_AppVersion<<std::endl;	
}

void Menu::GetOption(){
	std::cout<<"Enter your option [1-"<<m_MenuOptions.size()<<"]: "<<std::endl;
	std::cin>>m_Selected;
}

bool Menu::ProcessMenuOptions() {
	if(m_Selected == 0) {
		Clean();
		return Core::GetInstance()->ExitApplication();
	}
	if(m_Selected > m_MenuOptions.size())
		return false;

	auto iter = m_Functions.find(m_MenuOptions[m_Selected - 1]);
	if(iter == m_Functions.end()){
		std::cout<<"Couldn't find the option name"<<std::endl;
		return false;
	}

	std::cout<<"\n\n";
	(*iter->second)();
	std::cout<<"\n\n";
	return true;
}

void Menu::Clean() {
	m_MenuOptions.clear();
	m_Functions.clear();
}