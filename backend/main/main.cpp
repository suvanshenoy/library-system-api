#include "library_service.hpp"
#include <cstring>
#include <httplib.h>
#include <iostream>
#include <string>

int main() {
  LibraryService library_service;
  httplib::Server library_server;
  constexpr std::string_view host = "localhost";
  constexpr int port = 5000;

  library_server.Post(
      "/borrow", [&](const httplib::Request &req, httplib::Response &res) {
        int user_id = std::stoi(req.get_param_value("userId"));
        int book_id = std::stoi(req.get_param_value("bookId"));
        try {
          library_service.borrow_book(user_id, book_id);
          res.set_content("Book borrowed successfully", "text/plain");
        } catch (const std::exception &e) {
          res.status = 400;
          res.set_content(e.what(), "text/plain");
        }
      });

  library_server.Post(
      "/return", [&](const httplib::Request &req, httplib::Response &res) {
        int user_id = std::stoi(req.get_param_value("userId"));
        int book_id = std::stoi(req.get_param_value("bookId"));

        try {
          library_service.return_book(user_id, book_id);
          res.set_content("Book returned successfully", "text/plain");
        } catch (const std::exception &e) {
          res.status = 400;
          res.set_content(e.what(), "text/plain");
        }
      });

  std::cout << "[status] server is running on "
            << "http://" << host << ":" << port << "\n";
  library_server.listen(host.data(), port);
  return 0;
}
