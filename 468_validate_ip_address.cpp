#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValidIPV4 (const string& str)
    {
        const auto len = str.length();
        size_t ii = 0, sections = 1;
        int num = 0, subLen = 0;
        while (ii <= len){
            auto ch = str[ii];
            if (ch == '.' || ii == len)
            {
                cout << num << " ";
                if (!subLen || num > 255 || (num < pow(10,subLen-1) && subLen != num+1 )){
                    return false;
                }
                subLen = 0;
                num = 0;
                sections += ch == '.'?1:0;
            }
            else{
                ++subLen;
                if (subLen > 3){
                    return false;
                }
                num = num*10 + ch-'0';
            }
            ++ii;
        }
        return sections == 4;
    }

    bool isValidIPV6 (const string& str)
    {
        size_t cur = 0;
        int sections = 0;
        while(cur != string::npos) {
            auto pos = str.find(':', cur);
            auto sub = pos != string::npos?str.substr(cur, pos-cur):str.substr(cur);
            if (sub.empty() || sub.length()>4){
                return false;
            }
            bool isValidChars = std::all_of(sub.begin(), sub.end(), [](const auto ch){return isdigit(ch) || (tolower(ch)  >='a' && tolower(ch) <= 'f') ;});
            if (! isValidChars)
            {
                return false;
            }
            ++sections;
            if (sections > 8)
            {
                return false;
            }
            cur = pos == string::npos?pos:++pos;
        }
        return sections == 8;
    }
    string validIPAddress(string IP) {
        bool isIpv4 = isValidIPV4(IP), isIpv6 = isValidIPV6(IP);
        if (isIpv4){
            return "IPv4";
        }
        else if (isIpv6)
        {
            return "IPv6";
        }
        return "Neither";
    }
};

int main(){
    Solution sol;
    std::cout << sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << std::endl;
    std::cout << sol.validIPAddress("123.123.234.34") << std::endl;
    std::cout << sol.validIPAddress("123.123.234.1") << std::endl;
    std::cout << sol.validIPAddress("123.123.04.34") << std::endl;
    std::cout << sol.validIPAddress("123.0.0.34") << std::endl;
    std::cout << sol.validIPAddress("2001.12e3.2b34.0034") << std::endl;
    //std::cout << sol.validIPAddress("2001.12e3.2b34.34.0.0.0.ab") << std::endl;
    //std::cout << sol.validIPAddress("2001.12e3.2b34.34..0.0.ab") << std::endl;
    std::cout << sol.validIPAddress("1.1.1.1.") << std::endl;
}
