#pragma once

#include <string>

using namespace std;

int GetNumberFromUser(int minValue, int maxValue);
bool LoginUser();
void AddAccount();
void DeleteAccount();
void UpdateAccount();
void ViewAccount();
void Deposit();
void Withdraw();
void AccountMenu();
void MainMenu();

std::string SafeGetLine();