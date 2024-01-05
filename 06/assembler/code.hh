#include <map>
#include <string>
#include <stdexcept>
class Code {
private:
    std::map<std::string, std::string> map_dest;
    std::map<std::string, std::string> map_comp;
    std::map<std::string, std::string> map_jump;
    std::string convert(const std::map<std::string, std::string> &m, const std::string &s) const;
public:
    explicit Code();
    std::string dest(const std::string &s) const;
    std::string comp(const std::string &s) const;
    std::string jump(const std::string &s) const;
};
