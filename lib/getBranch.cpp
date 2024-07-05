#include "getBranch.h"

size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    std::string& buf = *static_cast<std::string*>(userdata);
    buf.append(ptr, std::next(ptr, nmemb * size));
    return nmemb * size;
}

json Branch::getBranch(std::string branch) const
{
    CURL *m_curl;
    CURLcode m_res;
    m_curl = curl_easy_init();
    json result;
    if (!m_curl)
    {
        curl_easy_cleanup(m_curl);
        throw "Error curl init";
    }
    std::string url_ = url + branch;
    std::string str_;
    curl_easy_setopt(m_curl, CURLOPT_URL, url_.c_str());
    curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &str_);
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    m_res = curl_easy_perform(m_curl);
    if (m_res != CURLE_OK)
    {
        throw "Error connection on https://rdb.altlinux.org";
    } else
    {
        result = json::parse(str_.c_str());
    }
    curl_easy_cleanup(m_curl);
    return result;
}
