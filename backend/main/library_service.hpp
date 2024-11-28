#pragma once

#include "book.hpp"
#include "user.hpp"
#include <memory>
#include <vector>

struct LibraryService {
  LibraryService();

  void borrow_book(int user_id, int book_id);
  void return_book(int user_id, int book_id);

private:
  std::vector<std::shared_ptr<Book>> books;
  std::vector<std::shared_ptr<User>> users;

  std::shared_ptr<User> find_user_by_id(int user_id);
  std::shared_ptr<Book> find_book_by_id(int book_id);
};
