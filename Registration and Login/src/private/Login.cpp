#include "Login.h"


Login g_login;

bool Login::saveCredentials()
{
    std::ofstream outFile(".\\Data\\LoginData.txt", std::ios::app);

    if(!outFile)
        std::cout<<"Error in opening file\n";
    else
    {
        outFile<<"\t"<<m_loginID<<" :"<<m_password<<"\n";
        outFile.close();
        return true;
    }
    return false;
}

bool Login::checkCredentials()
{
    std::ifstream inFile(".\\Data\\LoginData.txt");

    if(!inFile)
        std::cout << "Error in opening file\n";
    else
    {
        std::string line;

        while(std::getline(inFile, line))
        {
            std::stringstream ss(line);
            ss<<line;
            std::string userID, userPass;
            char delimiter;

            ss>>userID>>delimiter>>userPass;

            if(m_loginID == userID && m_password == userPass)
            {
                std::cout << "Login successful\n";
                return true;
            }
        }
    }
    return false;
}

bool Login::isIdUnique()
{
    std::ifstream inFile(".\\Data\\LoginData.txt");

    if(!inFile)
        std::cout << "Error in opening file\n";
    else
    {
        std::string line;

        while(std::getline(inFile, line))
        {
            std::stringstream ss(line);
            ss<<line;
            std::string userID;
            
            ss>>userID;

            if(m_loginID == userID)
            {
                std::cout << "Login successful\n";
                return true;
            }
        }
    }
    return true;
}

bool Login::isPasswordValid()
{
    if(m_password.length() < 8)
    {
        std::cout << "Password must be at least 8 characters long\n";
        return false;
    }
    return true;
}
