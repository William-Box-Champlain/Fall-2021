#include "Book.h"
Book::Book() {
	bName = "";
	bAuthor = "";
	bPublisher = "";
}
Book::Book(std::string title, std::string author, std::string publisher) {
	this->bName = title;
	this->bAuthor = author;
	this->bPublisher = publisher;
}
void Book::addTitle(std::string title) {
	this->bName = title;
}
void Book::addAuthor(std::string author) {
	this->bAuthor = author;
}
void Book::addPublisher(std::string publisher) {
	this->bPublisher = publisher;
}
void Book::addInfo(std::string title, std::string author, std::string publisher) {
	addTitle(title);
	addAuthor(author);
	addPublisher(publisher);
}
std::string Book::getTitle() {
	return bName;
}
std::string Book::getAuthor() {
	return bAuthor;
}
std::string Book::getPublisher() {
	return bPublisher;
}
std::string Book::getInfo() {
	std::stringstream ss;
	ss << getTitle() << " " << getAuthor() << " " << getPublisher();
	std::string output = ss.str();
	return output;
}