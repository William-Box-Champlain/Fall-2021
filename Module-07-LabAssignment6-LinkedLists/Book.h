#pragma once
#include <string>
#include <sstream>
class Book
{
public:
	Book();
	Book(std::string title, std::string author, std::string publisher);

	void addTitle(std::string title);
	void addAuthor(std::string author);
	void addPublisher(std::string publisher);
	void addInfo(std::string title, std::string author, std::string publisher);

	std::string getTitle();
	std::string getAuthor();
	std::string getPublisher();
	std::string getInfo();

private:
	std::string bName;
	std::string bAuthor;
	std::string bPublisher;
};