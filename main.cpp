#include "core.h"

int main(){
	Core::GetInstance()->RunApplication();
	while(Core::GetInstance()->IsRunning()){
		Core::GetInstance()->Draw();
		Core::GetInstance()->Update();
	}

	Core::GetInstance()->Clean();
}