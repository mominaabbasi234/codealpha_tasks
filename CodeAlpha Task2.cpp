#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LoginSystem
{
private:
    string username, password;

public:

    bool usernameExists(string user)
    {
        ifstream file("users.txt");

        string u, p;

        while (file >> u >> p)
        {
            if (u == user)
            {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }

    void registerUser()
    {
        cout << "\n========== USER REGISTRATION ==========\n";

        cout << "Enter Username: ";
        cin >> username;

        if (username.length() < 4)
        {
            cout << "Username must be at least 4 characters.\n";
            return;
        }

        if (usernameExists(username))
        {
            cout << "Username already exists!\n";
            return;
        }

        cout << "Enter Password: ";
        cin >> password;

        if (password.length() < 6)
        {
            cout << "Password must be at least 6 characters.\n";
            return;
        }

        ofstream file("users.txt", ios::app);

        file << username << " " << password << endl;

        file.close();

        cout << "\nRegistration Successful!\n";
    }

    void loginUser()
    {
        cout << "\n========== USER LOGIN ==========\n";

        string user, pass;

        cout << "Enter Username: ";
        cin >> user;

        cout << "Enter Password: ";
        cin >> pass;

        ifstream file("users.txt");

        string u, p;
        bool found = false;

        while (file >> u >> p)
        {
            if (u == user && p == pass)
            {
                found = true;
                break;
            }
        }

        file.close();

        if (found)
        {
            cout << "\nLogin Successful!";
            cout << "\nWelcome, " << user << "!\n";
        }
        else
        {
            cout << "\nInvalid Username or Password!\n";
        }
    }
};

int main()
{
    LoginSystem system;

    int choice;

    do
    {
        cout << "\n======================================";
        cout << "\n     LOGIN & REGISTRATION SYSTEM";
        cout << "\n======================================";
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.registerUser();
            break;

        case 2:
            system.loginUser();
            break;

        case 3:
            cout << "\nThank you for using the system.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}