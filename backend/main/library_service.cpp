#include "library_service.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

LibraryService::LibraryService() {
  books.push_back(std::make_shared<Book>(1, "1984", "George Orwell"));
  books.push_back(
      std::make_shared<Book>(2, "To Kill a Mockingbird", "Harper Lee"));
  users.push_back(std::make_shared<User>(1, "Alice"));
  users.push_back(std::make_shared<User>(2, "Bob"));
}

void LibraryService::borrow_book(int user_id, int book_id) {
  auto user = find_user_by_id(user_id);
  auto book = find_user_by_id(book_id);

  if (!user) {
    throw std::runtime_error("User not found");
  }
  if (!book || !book->is_available()) {
    throw std::runtime_error("Book not available");
  }

  book->set_available(false);
  user->borrow_book(book);
  std::cout << user->get_name() << " borrowed \"" << book->get_title() << "\""
            << "\n";
}

void LibraryService::return_book(int user_id, int book_id) {
  auto user = find_user_by_id(user_id);
  auto book = find_user_by_id(book_id);

  if (!user || !book) {
    throw std::runtime_error("User or book not found");
  }

  book->set_available(true);
  user->return_book(book_id);
  std::cout << user->get_name() << " returned \"" << book->get_title() << "\""
            << "\n";
}

std::shared_ptr<User> LibraryService::find_user_by_id(int user_id) {
  auto it = std::find_if(users.begin(), users.end(),
                         [user_id](const std::shared_ptr<User> &user) {
                           return user->get_id() == user_id;
                         });
  return (it != users.end()) ? *it : nullptr;
}

std::shared_ptr<Book> LibraryService::find_book_by_id(int book_id) {
  auto it = std::find_if(books.begin(), books.end(),
                         [book_id](const shared_ptr<Book> &book) {
                           return book->get_d() == book_id;
                         });
  return (it != books.end()) ? *it : nullptr;
}
