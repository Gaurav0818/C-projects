#pragma once
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

class Login
{
public:
    Login() = default;
    ~Login() = default;

    void setID(const std::string& id) { m_loginID = id; }
    void setPassword(const std::string& password) { m_password = password; }

    std::string getID() const { return m_loginID;}
    std::string getPassword() const { return m_password;}

    bool saveCredentials();
    bool checkCredentials();
    bool isIdUnique();
    bool isPasswordValid();
    
private:
    std::string m_loginID, m_password, m_filePath;
};


extern Login g_login;
