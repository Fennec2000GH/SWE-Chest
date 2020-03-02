
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
namespace fs = filesystem;

//std::experimental::filesystem::file_status

//MEMBER FUNCTIONS
//std::experimental::filesystem::file_status__file_status
//CONSTRUCTORS
/* file_status( const file_status& ) = default; */
/* file_status( file_status&& ) = default; */
/* explicit file_status( file_type type = file_type::none,perms permissions = perms::unknown); */

//std::experimental::filesystem::file_status::type
/* file_type type() const; */
/* void type( file_type type ); */

//std::experimental::filesystem::file_status::permissions
/* perms permissions() const; */
/* void permissions( perms perm ); */

//credit: cppreference
void demo_perms(fs::perms p) {
    cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
         << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
         << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
         << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
         << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
         << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
         << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
         << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
         << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
         << '\n';
}

int main() {
    //testing for type of file
    ofstream OutputFile;
    OutputFile.open("./newDir1/another.txt", ios::out | ios::app);
    OutputFile << "some words... " << endl;
    OutputFile.close();
//    fs::file_type ft = OutputFile.fs::file_status::type();
//    cout << ft << endl;

    //testing for std::experimental::filesystem::permissions
    demo_perms(fs::status("./textfile.txt").permissions());

    return 0;
}



