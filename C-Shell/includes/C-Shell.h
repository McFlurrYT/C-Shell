#pragma once
#define C_Shell_EXPORTS
#ifdef C_Shell_EXPORTS
#define C_Shell_API __declspec(dllexport)
#else
#define C_Shell_API __declspec(dllimport)
#endif

#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <fstream>

#include "pch.h"

namespace cshell {
	class C_Shell_API console {
	public:
		
		void setTitle(std::string _title);
		std::string getTitle();

		std::string getArg(int argn);
		bool sew(int start, int output);
		int getLength();

		bool isOpen();
		void update();
		void close();

		void Load();

	private:

		std::string title;
		
		bool running = true;

		std::string* argments = new std::string[1];
		std::string input;

		std::string ver = "v0.1.1";
		std::string rel_type = "Alpha";
		std::string ver_info = "First Alpha Release";

		void setArgments();

	};
}