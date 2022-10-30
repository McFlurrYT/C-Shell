#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <fstream>

#include "pch.h"
#include "C-Shell.h"

void cshell::console::setTitle(std::string _title)
{
	title = _title;
	SetConsoleTitle(std::wstring(_title.begin(), _title.end()).c_str());
}

std::string cshell::console::getTitle()
{
	return title;
}

int cshell::console::getLength()
{
	int result = 1;
	for (int i = 0; i < input.length(); i++)
		if (input.at(i) == ' ')
			result++;
	return result;
}

std::string cshell::console::getArg(int argn)
{
	if (argn < getLength())
		return argments[argn];
	else
		return "";
}

void cshell::console::setArgments()
{
	std::istringstream inputstringstream(input);
	for (int i = 0; i < getLength(); i++)
		inputstringstream >> argments[i];
}

bool cshell::console::sew(int start, int output)
{
	if (start < getLength() && output < getLength())
	{
		std::ostringstream outputstringstream;
		for (int i = start; i < getLength(); i++)
		{
			outputstringstream << argments[i] << ' ';
		}
		argments[output] = outputstringstream.str();
		return true;
	}
	else
		return false;
}

bool cshell::console::isOpen()
{
	return running;
}

void cshell::console::update()
{
	system("powershell wget -O lastest.version https://github.com/McFlurrYT/Lastest-C-Shell-Version/releases/download/Lastest_Version/lastest.version");
	std::string fileread[3];
	std::ifstream infile("lastest.version");

	if (infile.is_open())
	{
		for (int i = 0; i < 3; i++)
			getline(infile, fileread[i]);
	}
	if (fileread[0] == rel_type && fileread[1].at(1) == '0' && fileread[1] != ver)
	{
		std::ofstream outfile;
		outfile.open("update.bat");
		outfile << "@echo off\n";
		outfile << "del C-Shell-Windows.dll\n";
		outfile << "powershell wget -O C-Shell-Windows.dll " << fileread[2] << "\n";
		outfile << "for %%a in (\".\\*.exe\") do \"%%~a\"\n";
		outfile << "exit\n";
		outfile.close();
		system("start update.bat");
		exit(-1);
	}
}

void cshell::console::close()
{
	running = false;
}

void cshell::console::Load()
{
	std::getline(std::cin, input);
	argments = new std::string[getLength()];
	setArgments();

	if (getArg(0) == "version")
	{
		std::cout << "\n\n" << "Powered By : C-Shell" << " Version of C-Shell : " << ver << ' ' << rel_type << ' ' << ver_info << "\n\n";
	}
}