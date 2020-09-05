
#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <chrono>
#include <ctime>
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

//std::experimental::filesystem::copy_options
/* enum class copy_options {
    none = 0,
    skip_existing = 1,
    overwrite_existing = 2,
    update_existing = 4,
    recursive = 8,
    copy_symlinks = 16,
    skip_symlinks = 32,
    directories_only = 64,
    create_symlinks = 128,
    create_hard_links = 256
}; */

TEST_CASE("decomposition") {
    //testing some simple non-member functions involving paths
    fs::path root = "/";
    fs::path home = "/Users/fennec2000/";
    fs::path curr = fs::current_path();
    cout << "root path: " << root << endl;
    CHECK(curr.root_path() == root);

    cout << "home: " << home << endl;
    cout << "current path: " << curr << endl;
    cout << "root name of current path: " << curr.root_name() << endl;
    cout << "root path of current path: " << curr.root_path() << endl;
    cout << "relative path of current path: " << curr.relative_path() << endl;
    cout << "parent path of current path: " << curr.parent_path() << endl;
    cout << "current filename: " << curr.filename() << endl;
    CHECK(curr.filename() == "filesystem\ library");

}

TEST_CASE("queries and std::filesystem functions") {
    fs::path mystery = "/Users/fennec2000/Desktop/Software_Engineering_Interview/src/C++_STL_Practice/C++17 New Features/filesystem library";
    fs::path imaginary = "/Users/fennec2000/fake_folder/";
    cout << boolalpha << "current path == mystery? " << fs::equivalent(fs::current_path(), mystery) << endl;
    cout << boolalpha << "does imaginary path (" << imaginary << ") exist? " << fs::exists(imaginary) << endl;
    CHECK(fs::equivalent(fs::current_path(), mystery));
    CHECK_FALSE(fs::exists(imaginary));

    fs::space_info curr_space = fs::space(fs::current_path());
    cout << "capacity of current path: " << curr_space.capacity << endl;
    cout << "free space of current path: " << curr_space.free << endl;
    cout << "available size of current path: " << curr_space.available << endl;

    //testing std::experimental::filesystem::file_size, resize_file
    //testing std::filesystem::path::stem, extension
    ofstream outfile("textfile.txt");
    fs::path textfile = "./textfile.txt";
    cout << "stem of \"textfile.txt\": " << textfile.stem() << endl;
    cout << "extension of \"textfile.txt\": " << textfile.extension() << endl;
    outfile << "a line of text" << endl;
    cout << "file size of \"textfile.txt\": " << fs::file_size("./textfile.txt");
    outfile.close();
    cout << "resizing file \"textfile\" to 120... " << endl;
    fs::resize_file("./textfile.txt", 120);
    cout << "file size of \"textfile.txt\": " << fs::file_size("./textfile.txt");

    fs::path desktop("/Users/fennec2000/Desktop/");
    cout << boolalpha << "is desktop an absolute path? " << desktop.is_absolute() << endl;
    cout << boolalpha << "is desktop a relative path? " << desktop.is_relative() << endl;
    cout << boolalpha << "canonical path of desktop: " << fs::canonical(desktop) << endl;
    cout << boolalpha << "desktop has root path? " << desktop.has_root_path() << endl;
    cout << boolalpha << "desktop has root name? " << desktop.has_root_name() << endl;
    cout << boolalpha << "desktop has root directory? " << desktop.has_root_directory() << endl;
    cout << boolalpha << "desktop has relative path? " << desktop.has_relative_path() << endl;
    cout << boolalpha << "desktop has parent path? " << desktop.has_parent_path() << endl;
    cout << boolalpha << "desktop has filename? " << desktop.has_filename() << endl;
    cout << boolalpha << "desktop has stem? " << desktop.has_stem() << endl;
    cout << boolalpha << "desktop has extension? " << desktop.has_extension() << endl;
    CHECK(desktop.is_absolute());
    CHECK_FALSE(desktop.is_relative());
    CHECK(desktop.has_root_path());
    CHECK(desktop.has_root_name());
    CHECK(desktop.has_root_directory());
    CHECK(desktop.has_relative_path());
    CHECK(desktop.has_parent_path());
    CHECK(desktop.has_stem());
    CHECK_FALSE(desktop.has_extension());

}

TEST_CASE("time") {
    fs::file_time_type lwt1 = fs::last_write_time("./textfile.txt");
//    time_t cftime1 = chrono::system_clock::to_time_t(lwt1);
//    cout << "last write time for \"textfile.txt\": " << asctime(localtime(&cftime1)) << endl;
//
//    cout << "last write time changed... " << endl;
//    fs::last_write_time("./textfile.txt", lwt1 + 10min);
//    fs::file_time_type lwt2 = fs::last_write_time("./textfile.txt");
//    time_t cftime2 = chrono::system_clock::to_time_t(lwt);
//    cout << "last write time for \"textfile.txt\": " <<  asctime(localtime(&cftime2)) << endl;
//    CHECK_FALSE(cftime1 == cftime2);

}

TEST_CASE("creating/removing directories") {
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
}

TEST_CASE("modifiers") {
    cout << "current path: " << fs::current_path() << endl;
    fs::create_directories("./modifiers/f1/f2/f3/");
    ofstream newOutFile("./modifiers/f1/f2/f3/textfile2.txt");
    newOutFile << "qwertyuiopasdfghjklzxcvbnm" << endl;
    newOutFile.close();

    fs::path modifiers("./modifiers");
    modifiers.make_preferred();
    cout << "removing f3 directory filename... " << endl;
    fs::path("./modifiers/f1/f2/f3").remove_filename();
    cout << boolalpha << "does f3 still have filename? " << fs::path("./modifiers/f1/f2/f3").has_filename() << endl;
    CHECK_FALSE(fs::path("./modifiers/f1/f2/f3").has_filename());

    cout << "replace filename from f2 to folder2... " << endl;
    fs::path("./modifiers/f1/f2").replace_filename("folder2");
    CHECK(fs::path(modifiers/"f1/f2").filename() == "folder2");

    //testing fs::filesystem::patH::clear
    fs::copy("./modifiers/f1/f2/f3/textfile2.txt", "./modifiers/f1/f2", fs::copy_options::update_existing);
    cout << boolalpha << "is \"./modifiers/f1/f2\" empty? " << fs::path("./modifiers/f1/f2").empty() << endl;
    CHECK_FALSE(fs::path("./modifiers/f1/f2").empty());
    cout << "clearing f3 directory... " << endl;
    fs::path(modifiers/"f1/f2/f3").clear();
    CHECK(fs::path(modifiers/"f1/f2/f3").empty());

    //testing fs::filesystem::path::replace_extension
    fs::path(modifiers/"f1/f2/textfile2.txt").replace_extension("cpp");
    CHECK(fs::path(modifiers/"f1/f2/textfile2").extension() == "cpp");

}

