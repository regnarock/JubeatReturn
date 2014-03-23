#pragma once

class SettingsIO
{
private:
	std::string m_filename;

public:
	SettingsIO(std::string const &filename);
	SettingsIO();
	~SettingsIO();

	void Open(std::string const &filename);

	int GetInt(std::string const &section, std::string const &key);
	float GetFloat(std::string const &section, std::string const &key);
	std::string GetString(std::string const &section, std::string const &key);
	/*
	template<typename T>
	bool Get<bool>(std::wstring const &section, std::wstring const &key);*/
};