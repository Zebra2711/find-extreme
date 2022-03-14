//http://www.cplusplus.com/forum/beginner/200148/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// read lines (up to a maximum of max_lines) from an input stream into a vector
std::vector<std::string> get_lines( std::istream& stm, std::size_t max_lines = -1U )
{
    std::vector<std::string> lines_read ;

    std::string line ;
    while( lines_read.size() < max_lines && std::getline( stm, line ) ) lines_read.push_back(line) ;

    return lines_read ;
}

// insert lines in lines_to_be_added into vector lines at position curr_line
void insert_lines( std::vector<std::string>& lines, std::size_t curr_line,
                   std::vector<std::string> lines_to_be_added )
{
   curr_line = std::min( curr_line, lines.size() ) ;
   lines.insert( lines.begin()+curr_line, lines_to_be_added.begin(), lines_to_be_added.end() ) ;
}

// overwrite the lines in the file with the contents of the vector
void overwrite_file( const std::string& file_name, const std::vector<std::string>& lines )
{
    std::ofstream file(file_name) ; // open for output, truncate existing
    for( const std::string& ln : lines ) file << ln << '\n' ;
}

int main3()
{
    const std::string file_name = "text.cpp" ;

    std::vector<std::string> lines ;

    {
        std::ifstream file(file_name) ; // open the file for input
        lines = get_lines(file) ; // place all the lines in the file into the vector
    }

    {
        std::size_t num_lines ;
        std::cout << "how many lines to be added? " && std::cin >> num_lines ;
        //num_lines=1;

        std::size_t current_line ;
        std::cout << "at line (the first line is line# zero)? " && std::cin >> current_line ;
        //current_line=3;

        // extract and discard the new line remaining in the input buffer
        std::cin.ignore( 1000000, '\n' ) ;

        std::cout << "enter " << num_lines << "lines:\n" ;
        // get the lines entered by the user (up to a max of num_lines)
        std::vector<std::string> lines_to_be_added = get_lines( std::cin, num_lines ) ;

        // insert the lines entered into the vector of lines
        insert_lines( lines, current_line, lines_to_be_added ) ;

        overwrite_file( file_name, lines ) ; // overwrite the file with the modified contents
    }
}
