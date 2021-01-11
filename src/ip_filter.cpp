#include "ip_filter.h"
#include <algorithm>
#include <iostream>

void ListIP::print_ip(const IP &ip) const
{
    for (IP::const_iterator ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
    {
        if (ip_part != ip.cbegin())
        {
            std::cout << ".";
        }
        std::cout << *ip_part;
    }
    std::cout << std::endl;
}

void ListIP::append(const std::vector<std::string> &ip_str)
{
    IP ip;
    for (auto part_ip : ip_str)
    {
        ip.push_back(stoi(part_ip));
    }
    containerIp.insert(ip);
}

void ListIP::print_range_ip(const ContainerIp::iterator &from, const ContainerIp::iterator &to) const
{
    std::for_each(from, to, [this](const IP &ip) { this->print_ip(ip); });
}

void ListIP::print() const
{
    print_range_ip(containerIp.begin(), containerIp.end());
}


void ListIP::print_range_by_bytes_order(const IP &bytesOrder) const
{
    auto cmp = [&bytesOrder] (const IP &ip) {
        for (size_t i = 0; i < bytesOrder.size(); ++i) {
            if (bytesOrder[i] != ip[i]) {
                return false;
            }
        }
        return true; 
    };

    auto from = std::find_if(containerIp.begin(), containerIp.end(), cmp);
    if (from == containerIp.end())
    {
        return;
    }
    auto to = std::find_if_not(from, containerIp.end(), cmp);

    print_range_ip(from, to);

}

void ListIP::filter(unsigned byte) const
{    
    print_range_by_bytes_order(IP{byte});
}

void ListIP::filter(unsigned byte1, unsigned byte2) const
{
    print_range_by_bytes_order( IP{byte1, byte2} );
}

void ListIP::filter_any(unsigned byte) const
{
    auto print_match = [this, byte](const IP& ip) {
        if (std::any_of(ip.begin(), ip.end(), [byte](unsigned ip_part) { return ip_part == byte;})) {
            this->print_ip(ip);
        }
    };
    
    std::for_each(containerIp.begin(), containerIp.end(), print_match);
}