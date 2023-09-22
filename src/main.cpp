#include <cstdio>
#include <string>
#include <iostream>
#include "utils.hpp"
#include "acl.hpp"

int main(int argc, char ** argv)
{
    std::string hello_world = "hello world!";
    printf("%s\n", hello_world.c_str());

    acl::ACL acl;
    printf("Number of Users: %ld\n", acl.GetUserList().size());
    acl.CreateUser("Tim");
    printf("Number of Users: %ld\n", acl.GetUserList().size());
    acl.CreateUser("Tom");
    printf("Number of Users: %ld\n", acl.GetUserList().size());
    acl.CreateUser("Bob");
    printf("Number of Users: %ld\n", acl.GetUserList().size());
    acl::User bob = acl.GetUser("Bob");
    std::cout << bob;
    std::string serializedUser = acl::ACL::serializeUser(bob);
    std::cout << "Serialized User: " << utils::convertBytesToHex(serializedUser) << std::endl;
    std::string serializedList = acl.getSerializedUserList();
    std::cout << "Serialized User List: " << utils::convertBytesToHex(serializedList) << std::endl;
    acl.saveUserList("test.dat");
    acl.loadUserList("test.dat");
    
    acl.DeleteUser("Tim");
    printf("Number of Users: %ld\n", acl.GetUserList().size());
}