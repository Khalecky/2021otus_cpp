#pragma once

#include <string>
#include <vector>
#include <set>

class ListIP
{
    using IP = std::vector<unsigned>;
    // структура-множество для хранения IP в нужном обратном лексикографическом порядке
    using SetIp = std::multiset<IP, std::greater<IP> >;

    SetIp setIp;

    void print_ip(const IP &ip) const;

public:

    void append(const std::vector<std::string> &ip_str);
    void print() const;
    void print(unsigned) const;
};
