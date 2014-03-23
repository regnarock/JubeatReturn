#include <sstream>
#include <iostream>
#include <windows.h>
#include "SettingsIO.h"

SettingsIO::SettingsIO(std::string const &filename)
{
	Open(filename);
}

SettingsIO::SettingsIO()
{

}

SettingsIO::~SettingsIO()
{

}

void SettingsIO::Open(std::string const &filename)
{
	// In fact this is done at "get" call, so this is somehow useless :/
	// Blame ms for doing things the crap way, no need to check if file exists or stuff
	m_filename = filename;
}

int SettingsIO::GetInt(std::string const &section, std::string const &key)
{
	int result = GetPrivateProfileInt(section.c_str(), key.c_str(), 0,
		m_filename.c_str());
  
	return result;
}

std::string SettingsIO::GetString(std::string const &section, std::string const &key)
{
	std::string result;
	char resultRaw[255];
	char defaultVal[255];

	GetPrivateProfileString(section.c_str(), key.c_str(), defaultVal, resultRaw, 255,
		m_filename.c_str());
	result = resultRaw;

	return result;
}

float SettingsIO::GetFloat(std::string const &section, std::string const &key)
{
	float result = 0.0f;
	char resultRaw[255];
	char defaultVal[255];
	std::stringstream resultStr;

	GetPrivateProfileString(section.c_str(), key.c_str(), defaultVal, resultRaw, 255,
		m_filename.c_str());
	resultStr.str(resultRaw);
	resultStr >> result;
	return result;
}
/*
bool CIniReader::ReadBoolean(char *section, char *key, bool DefaultValue)
{
  char Result[255];
  char Default[255];
  bool bolResult;

  sprintf_s(Default, 255, "%s", DefaultValue ? "True" : "False");
  GetPrivateProfileString(section, key, Default, Result, 255, m_FileName);

  bolResult = ( strcmp(Result, "True") == 0 ||
    strcmp(Result, "true") == 0 ) ? true : false;

  return bolResult;
}*/