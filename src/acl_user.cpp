#include <algorithm>
#include <fstream>
#include "acl.hpp"
#include "utils.hpp"

acl::ACL::ACL()
{
    this->user_list = std::vector<std::shared_ptr<acl::User>>();
}

acl::ACL::~ACL()
{
    this->user_list.clear();
}

/** User Manipulation **/

void acl::ACL::CreateUser(std::string username)
{
    std::shared_ptr<acl::User> new_user(new acl::User);
    new_user->uuid = this->user_list.size() + 1;
    new_user->username.assign(username);
    this->user_list.push_back(new_user);
}

void acl::ACL::DeleteUser(std::string username)
{
    this->user_list.erase(
        std::remove_if(this->user_list.begin(), 
                        this->user_list.end(), 
                        [&](std::shared_ptr<acl::User> user) {
                            return user->username.compare(username) == 0;
                        }), 
        this->user_list.end());
}

acl::User acl::ACL::GetUser(std::string username)
{
    acl::User user;

    std::vector<std::shared_ptr<acl::User>>::iterator users_iterator = std::find_if(this->user_list.begin(), 
                this->user_list.end(), 
                [&](std::shared_ptr<acl::User> user) {
                    return user->username.compare(username) == 0;
                });
    if (users_iterator != this->user_list.end())
    {
        user = **users_iterator;
    }

    return user;
}


/* User List */
std::vector<std::shared_ptr<acl::User>> acl::ACL::GetUserList(void)
{
    return this->user_list;
}

/** Serialization / Deserialization **/

std::string acl::ACL::serializeUser(acl::User user) {
    return std::string((char *)&user, sizeof(acl::User));
}

acl::User acl::ACL::deserializeUser(std::string serializedUser) {
    return *((acl::User *)serializedUser.data());
}

std::string acl::ACL::getSerializedUserList(void) {
    std::string serializedUserList;

    std::for_each(this->user_list.begin(), this->user_list.end(),
        [&](std::shared_ptr<acl::User> user) { serializedUserList.append(serializeUser(*user)); });

    return serializedUserList;
}

void acl::ACL::saveUserList(std::string filepath) {
    std::fstream outfile;
    outfile.open(filepath, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
    outfile << this->getSerializedUserList();
    outfile.close();
}

void acl::ACL::loadUserList(std::string filepath) {
    std::fstream infile;
    std::string serializedUserList;
    infile.open(filepath, std::ios_base::in | std::ios_base::binary);
    infile >> serializedUserList;
    infile.close();

    if (!serializedUserList.empty())
    {
        std::cout << "Loaded User List: " << utils::convertBytesToHex(serializedUserList) << std::endl;
    }
    else
    {
        std::cout << "Empty User List :(" << std::endl;
    }
}

/** Friend Functions **/

std::ostream& operator<<(std::ostream& os, const acl::User &user) { 
    os << "---------------------------" << std::endl;
    os << "Struct: acl::User"<< std::endl;
    os << "Uuid: " << user.uuid << std::endl;
    os << "Username: " << user.username << std::endl;
    os << "---------------------------" << std::endl;
    return os;
}