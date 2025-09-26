#include "splashkit.h"
#include <unordered_map>
#include <zlib.h>

using std::string;
using std::to_string;
using std::unordered_map;

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
    string id;
    Genre genre;
    string content;
};

/** Convert a buffer to a string, points to the original data */
string buffer_to_string(const vector<Bytef> &buffer, uLong length)
{
    return string(reinterpret_cast<const char *>(buffer.data()), length);
}

// Function to compress entry content, passing by reference
string compress_content(const string &content)
{
    /** Compress the content using zlib */
    uLong src_len = content.size();
    uLong dest_len = compressBound(src_len);
    vector<Bytef> buffer(dest_len);

    /** Perform the compression */
    compress(buffer.data(), &dest_len, reinterpret_cast<const Bytef *>(content.data()), src_len);

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
    uncompress(buffer.data(), &dest_len, reinterpret_cast<const Bytef *>(compressed.data()), compressed.size());

    /** Return the decompressed content as a string */
    return buffer_to_string(buffer, dest_len);
}


// Function to generate demo memories
void generate_entries(Entry entries[])
{
    /** Generate demo entries with sample content */
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        /** Initialize entry fields */
        entries[i].id = "entry_" + to_string(i);
        entries[i].genre = (i % 2 == 0) ? PERSONAL : BUSINESS;
        entries[i].content = "Sample entry content " + to_string(i) + " with some repeated text repeated text repeated text.";
    }
}


// Function to show compression statistics, passing by reference
void show_stats(const Entry entries[], const unordered_map<string, string> &compressed_entries)
{
    /** Calculate original and compressed sizes */
    size_t original_size = 0, compressed_size = 0;

    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        /** Accumulate sizes */
        original_size += entries[i].content.size();
        compressed_size += compressed_entries.at(entries[i].id).size();
    }

    /** Calculate compression ratio and space saved */
    double ratio = (double)original_size / compressed_size;
    double saving = 100.0 * (1.0 - ((double)compressed_size / original_size));

    /** Print the statistics */
    write_line("Original Size: " + to_string(original_size) + " bytes");
    write_line("Compressed Size: " + to_string(compressed_size) + " bytes");
    write_line("Compression Ratio: " + to_string(ratio) + ":1");
    write_line("Space Saved: " + to_string(saving) + "%\n");
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
    write_line(" MEMORY SYSTEM DEMONSTRATION");
    write_line("==============================");

    /** Generate demo entries */
    Entry entries[MAX_ENTRIES];
    generate_entries(entries);

    /** Compress the entries */
    unordered_map<string, string> compressed_entries;

    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        compressed_entries[entries[i].id] = compress_content(entries[i].content);
    }

    /** Print number of generated entries  */
    write_line("Generated " + to_string(MAX_ENTRIES) + " entries\n");

    /** Show statistics, collapse some entries, and find by genre */
    show_stats(entries, compressed_entries);
    collapse_entries(entries);
    find_by_genre(entries, PERSONAL);
    find_by_genre(entries, BUSINESS);

    write_line("\nDemonstration Complete.");
    return 0;
}