#pragma once

#include <string>

struct Book {
  Book(int id, const std::string &title, const std::string &author);

  int get_id() const;
  std::string get_title() const;
  std::string get_author() const;
  bool is_available() const;
  void set_available(bool available);

private:
  int id;
  std::string title;
  std::string author;
  bool available;
};
