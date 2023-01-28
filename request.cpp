#include <string>
#include <cstring>
#include <curl/curl.h>
#include "request.h"

static size_t WriteMemoryCallback(void *contents, size_t sizeOfMember, size_t numMembers, void *mem) {
  size_t realSize = sizeOfMember * numMembers;
  ((std::string *)mem)->append((char *)contents, realSize);
  return realSize;
}

Request::Request(const std::string &url): m_url{url}, m_res{} {
  m_res.reserve(1);
}

bool Request::execute() {
  CURL *curl_handle;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  /* init the curl session */
  curl_handle = curl_easy_init();

  /* specify URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, m_url.c_str());

  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

  /* pass member variable to the callback function */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &m_res);

  /* some servers do not like requests that are made without a user-agent field, so we provide one */
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

  /* get it! */
  res = curl_easy_perform(curl_handle);

  /* check for errors */
  if(res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    return false;
  }

  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);

  /* we are done with libcurl, so clean it up */
  curl_global_cleanup();

  return true;
}

const std::string& Request::getRes() const {
  return m_res;
}