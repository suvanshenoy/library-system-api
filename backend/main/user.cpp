#include "user.hpp"

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

user::user(int id, const std::string &name) : id(id), name(name) {}

int user::get_id() const { return id; }

std::string user::get_name() const { return name; }

const std::vector<std::shared_ptr<Book>> &User::get_borrowed_books() const {
  return borrowed_books;
}

void user::borrow_book(std::shared_ptr<Book> book) {
  borrowed_books.push_back(book);
}

void user::return_book(int book_id) {
  borrowed_books.erase(
      std::remove_if(borrowed_books.begin(), borrowed_books.end(),
                     [book_id](const std::shared_ptr<Book> &book) {
                       return book->getId() == book_id;
                     }),
      borrowed_books.end());
}
