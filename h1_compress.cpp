#include "splashkit.h"
#include <unordered_map>
#include <zlib.h>

using std::unordered_map;  
using std::string;
using std::to_string;


// Constant for number of entries 
const int MAX_ENTRIES = 1000;


// Enum for entry genres
enum Genre
{
    PERSONAL,
    BUSINESS
};


// Entry struct
struct Entry
{
    string title;
    Genre genre;
    string content;
};


// Function to compress entry content, passing by reference
string compress_content(const string &content)
{
    
    return content;
}


// Function to decompress memory content, passing by reference
string decompress_content(const string &compressed_content)
{
    
    return compressed_content;
}


// Function to generate demo memories
void generate_entries(Entry entries[])
{
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
    }
}


// Function to show compression statistics, passing by reference
void show_stats(const Entry entries[])
{
    for (int i = 0; i < MAX_ENTRIES; i++)
    {

    }
    
}


// Function to collapse and preview a few memories, passing by reference
void collapse_entries(const Entry entries[])
{
    for (int i = 0; i < 3; i++)
    {
        
    }
    
}


// Function to find memories by genre, passing by reference 
void find_by_genre(const Entry entries[], Genre genre)
{
    int count = 0;
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        
    }
    
    write_line(" ");
}


// Main function 
int main()
{
    write_line("==============================");
    write_line(" MEMORY SYSTEM DEMONSTRATION"  );
    write_line("==============================");

    Entry entries[MAX_ENTRIES];
    generate_entries(entries);
    

    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        
    }


    show_stats(entries);
    collapse_entries(entries);
   


    write_line("Demonstration Complete.");
    return 0;
}