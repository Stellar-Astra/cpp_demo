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

/** Convert a buffer to a string, points to the original data */
string buffer_to_string(const vector<Bytef> &buffer, uLong length)
{
    return string(reinterpret_cast<const char*>(buffer.data()), length);
}


// Function to compress entry content, passing by reference
string compress_content(const string &content)
{
    /** Compress the content using zlib */
    uLong src_len = content.size();
    uLong dest_len = compressBound(src_len);
    vector<Bytef> buffer(dest_len);

    /** Perform the compression */
    compress(buffer.data(), &dest_len, reinterpret_cast<const Bytef*>(content.data()), src_len);

    /** Return the compressed content as a string */
    return buffer_to_string(buffer, dest_len);
}


// Function to decompress memory content, passing by reference
string decompress_content(const string &compressed, uLong original_size)
{
    /** Decompress the content using zlib */
    vector<Bytef> buffer(original_size);
    uLong dest_len = original_size;

    /** Perform the decompression */
    uncompress(buffer.data(), &dest_len, reinterpret_cast<const Bytef*>(compressed.data()), compressed.size());

    /** Return the decompressed content as a string */
    return buffer_to_string(buffer, dest_len);
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
    /** Initialize the memory system */
    write_line("==============================");
    write_line(" MEMORY SYSTEM DEMONSTRATION"  );
    write_line("==============================");

    
    /** Generate demo entries */
    Entry entries[MAX_ENTRIES];
    generate_entries(entries);
    

    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        
    }

    /** Show statistics, collapse some entries, and find by genre */
    show_stats(entries);
    collapse_entries(entries);
    find_by_genre(entries, PERSONAL);
   

    write_line("Demonstration Complete.");
    return 0;
}