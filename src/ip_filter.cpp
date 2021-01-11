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
    setIp.insert(ip);
}

void ListIP::print() const
{
    std::for_each(setIp.begin(), setIp.end(), [this](const IP &ip) { this->print_ip(ip); });
}

void ListIP::print(unsigned filterValue) const
{
    std::for_each(setIp.begin(), setIp.end(), [this, filterValue](const IP &ip) {
        if (ip[0] == filterValue)
                this->print_ip(ip);

    });
}

void ListIP::print(unsigned filterFirst, unsigned filterSecond) const
{
    std::for_each(setIp.begin(), setIp.end(), [this, filterFirst, filterSecond](const IP &ip) {
        if (ip[0] == filterValue)
                this->print_ip(ip);

    });
}
