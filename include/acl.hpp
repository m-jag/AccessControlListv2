#ifndef ACL_H
#define ACL_H
#include <vector>
#include <string>
#include <memory>
#include <iostream>

namespace acl {
    typedef struct User_s {
        uint64_t uuid;
        std::string username;
    } User;

    class ACL {
        private:
        std::vector<std::shared_ptr<User>> user_list;
        public:
        ACL();
        ~ACL();
        void CreateUser(std::string username);
        void DeleteUser(std::string username);
        User GetUser(std::string username);
        static std::string serializeUser(User user);
        static acl::User deserializeUser(std::string serializedUser);
        std::vector<std::shared_ptr<User>> GetUserList(void);
        std::string getSerializedUserList(void);
        void saveUserList(std::string filepath);
        void loadUserList(std::string filepath);

    };
    
}

std::ostream& operator<<(std::ostream& os, const acl::User &user);

#endif