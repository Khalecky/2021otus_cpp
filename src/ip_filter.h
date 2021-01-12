#pragma once

#include <string>
#include <vector>
#include <set>

class ListIP
{
    using IP_BYTE = unsigned char;
    using IP = std::vector<IP_BYTE>;
    // структура-множество для хранения IP в нужном обратном лексикографическом порядке
    using ContainerIp = std::multiset<IP, std::greater<IP>>;

    ContainerIp containerIp;

    void print_ip(const IP &ip) const;
    void print_range_ip(const ContainerIp::iterator &from, const ContainerIp::iterator &to) const;
    void print_range_by_bytes_order(const IP &bytesOrder) const;

public:
    void append(const std::vector<std::string> &ip_str);
    void print() const;

    //наверное надо бы variadic
    void filter(IP_BYTE) const;
    void filter(IP_BYTE, IP_BYTE) const;

    void filter_any(IP_BYTE) const;
};
