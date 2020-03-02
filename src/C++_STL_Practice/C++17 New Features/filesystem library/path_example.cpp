
//#define CATCH_CONFIG_MAIN
//#include "../../../catch.hpp"
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <thread>
using namespace std;
namespace fs = std::filesystem;

//std::experimental::filesystem::path
/* path(); */
/* path( const path& p ); */
/* path( path&& p ); */
/* template< class Source >
path( const Source& source );
 */
/* template< class InputIt >
path( InputIt first, InputIt last );
*/
/* template< class Source >
path( const Source& source, const std::locale& loc );
*/
/* template< class InputIt >
path( InputIt first, InputIt last, const std::locale& loc );
 */

//NON-MEMBER FUNCTIONS
//std::experimental::filesystem::copy
/* void copy( const path& from, const path& to ); */
/* void copy( const path& from, const path& to, error_code& ec ); */
/* void copy( const path& from, const path& to, copy_options options ); */
/* void copy( const path& from, const path& to, copy_options options, error_code& ec ); */
/* copy_options::none, copy_options::skip_symlinks, copy_options::create_symlinks,

//std::experimental::filesystem::create_directory, create_directories
/* bool create_directory( const path& p ); */
/* bool create_directory( const path& p, error_code& ec ); */
/* bool create_directory( const path& p, const path& existing_p ); */
/* bool create_directory( const path& p, const path& existing_p, error_code& ec ); */
/* bool create_directories( const path& p ); */
/* bool create_directories( const path& p, error_code& ec ); */

//std::experimental::filesystem::exists
/* bool exists( file_status s ); */
/* bool exists( const path& p ); */
/* bool exists( const path& p, error_code& ec ); */

//std::experimental::filesystem::equivalent
/* bool equivalent( const path& p1, const path& p2 ); */
/* bool equivalent( const path& p1, const path& p2, error_code& ec ); */

//std::experimental::filesystem::file_size
/* std::uintmax_t file_size( const path& p ); */
/* std::uintmax_t file_size( const path& p, error_code& ec ); */

//std::experimental::filesystem::resize_file
/* void resize_file(const path& p, std::uintmax_t new_size); */
/* void resize_file(const path& p, std::uintmax_t new_size, error_code& ec); */

//std::experimental::filesystem::last_write_time
/* file_time_type last_write_time(const path& p); */
/* file_time_type last_write_time(const path& p, error_code& ec) */
/* void last_write_time(const path& p, file_time_type new_time); */
/* void last_write_time(const path& p, file_time_type new_time, error_code& ec); */

//std::experimental::filesystem::permissions
/*  void permissions(const path& p, perms prms); */
/* void permissions(const path& p, perms prms, error_code& ec); */

//std::experimental::filesystem::remove, remove_all
/* bool remove(const path& p); */
/* bool remove(const path& p, error_code& ec); */
/* std::uintmax_t remove_all(const path& p); */
/* std::uintmax_t remove_all(const path& p, error_code& ec); */

//std::experimental::filesystem::space
/* struct space_info {
    uintmax_t capacity;
    uintmax_t free;
    uintmax_t available;
}; */

int main() {
    //testing some simple non-member functions involving paths
    fs::path root = "/";
    fs::path home = "/Users/fennec2000/";
    fs::path mystery = "/Users/fennec2000/Desktop/Software_Engineering_Interview/src/C++_STL_Practice/C++17 New Features/filesystem library";
    fs::path curr = fs::current_path();
    fs::path imaginary = "/Users/fennec2000/fake_folder/";
    cout << "root: " << root << endl;
    cout << "home: " << home << endl;
    cout << "current path: " << curr << endl;
    cout << boolalpha << "current path == mystery? " << fs::equivalent(curr, mystery) << endl;
    cout << boolalpha << "does imaginary path (" << imaginary << ") exist? " << fs::exists(imaginary) << endl;
    fs::space_info curr_space = fs::space(curr);
    cout << "capacity of current path: " << curr_space.capacity << endl;
    cout << "free space of current path: " << curr_space.free << endl;
    cout << "available size of current path: " << curr_space.available << endl;

    //testing std::experimental::filesystem::file_size, resize_file
    ofstream outfile("textfile.txt");
    outfile << "a line of text" << endl;
    cout << "file size of \"textfile.txt\": " << fs::file_size("./textfile.txt");
    outfile.close();
    cout << "resizing file \"textfile\" to 120... " << endl;
    fs::resize_file("./textfile.txt", 120);
    cout << "file size of \"textfile.txt\": " << fs::file_size("./textfile.txt");
    fs::file_time_type lwt = fs::last_write_time("./textfile.txt");


//    time_t cftime = decltype(lwt)::clock::to_time_t(lwt);
//    cout << "last write time for \"textfile.txt\": " << asctime(localtime(&cftime)) << endl;

//    cout << "last write time changed... " << endl;
//    fs::last_write_time("./textfile.txt", lwt + literals::chrono_literals::min(10));
//    lwt = fs::last_write_time("./textfile.txt");
//    cftime = decltype(lwt)::clock::to_time_t(lwt);
//    cout << "last write time for \"textfile.txt\": " <<  asctime(localtime(&cftime)) << endl;

    //creating a new directory
    fs::create_directory("./newDir1");
    ofstream newOutFile("./newDir1/another.txt");
    newOutFile << "some words... " << endl;
    newOutFile.close();
    fs::create_directory("./newDir2", "./newDir1");
    fs::copy("./newDir1/another.txt", "./newDir2", fs::copy_options::overwrite_existing);
    fs::create_directories("/Users/fennec2000/Desktop/Software_Engineering_Interview/src/newDir3/a/b/c");

    //deleting all of newDir3
    fs::remove_all("/Users/fennec2000/Desktop/Software_Engineering_Interview/src/newDir3/a");

    this_thread::sleep_for(chrono::seconds(1));
    system("pwd; ls -1Fl;");


    return 0;
}




