#include "book.hpp"
#include <string>

book::book(int id, const std::string &title, const std::string &author)
    : id(id), title(title), author(author), available(true) {}

int Book::get_id() const { return id; }

std::string book::get_title() const { return title; }

std::string book::get_author() const { return author; }

bool book::is_available() const { return available; }

void book::set_available(bool available) { this->available = available; }
