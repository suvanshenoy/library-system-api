#pragma once

#include "book.hpp"
#include <memory>
#include <string>
#include <vector>

struct User {
  User(int id, const std::string &name);

  int get_id() const;
  std::string get_name() const;
  const std::vector<std::shared_ptr<Book>> &get_borrowed_books() const;
  void borrow_book(std::shared_ptr<Book> book);
  void return_book(int book_id);

private:
  int id;
  std::string name;
  std::vector<std::shared_ptr<Book>> borrowed_books;
};
