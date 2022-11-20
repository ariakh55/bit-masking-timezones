#ifndef CORE_H	
#define CORE_H

class Core{
	private:
		Core(){};
		static Core* s_Instance;
		bool m_IsRunning;

	public:
		inline static Core* GetInstance() {
			return s_Instance = (s_Instance != nullptr) ? s_Instance : new Core();
		}

		inline bool IsRunning() {return m_IsRunning;}

		bool RunApplication();
		bool ExitApplication();
		void Draw();
		void Update();
		void Clean();
};

#endif