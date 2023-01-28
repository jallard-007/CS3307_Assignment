/**
 * Header file for the Request class
 * Author: Justin Nicolas Allard
 * Date: Jan 27, 2023
*/

#ifndef REQUEST_H
#define REQUEST_H
#include <string>

class Request {
  private:
    const std::string m_url;
    std::string m_res;

  public:
    Request() = delete;
    Request(const std::string&);
    ~Request() = default;
    bool execute();
    const std::string& getRes() const;
};

#endif
