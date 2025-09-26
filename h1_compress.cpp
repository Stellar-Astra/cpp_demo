// Copyright (c) 2025 Donna Bye. All rights reserved.

/**
 * h1_compress.cpp
 * ----------------
 * Purpose:
 * This program demonstrates a simple memory storage system that applies
 * data compression techniques to reduce storage size while preserving
 * the ability to recover and search the stored data.
 *
 * Key Features:
 *  - Defines entries using a struct and categorises them with an enum.
 *  - Generates a fixed number of sample entries with repeated patterns.
 *  - Uses the zlib library to compress and decompress entry content.
 *  - Stores compressed entries in a container (unordered_map).
 *  - Calculates and reports compression ratio and space saved.
 *  - Demonstrates collapsing and previewing decompressed entries.
 *  - Supports searching entries by genre.
 *
 * Educational Value:
 * This project applies core programming concepts: structs, enums, arrays,
 * references, functions and external libraries. It also extends beyond
 * the unit’s basics by integrating compression algorithms to illustrate
 * efficiency in memory management.
 */



#include "splashkit.h"
#include <unordered_map>
#include <zlib.h>
#include <iomanip>
#include <sstream>

using namespace std;


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
    write_line("Calculating compression statistics...\n");

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

    ostringstream ratio_stream, saving_stream;
    ratio_stream << fixed << setprecision(2) << ratio;
    saving_stream << fixed << setprecision(2) << saving;

    /** Print the statistics */
    write_line("Original Size: " + to_string(original_size) + " bytes");
    write_line("Compressed Size: " + to_string(compressed_size) + " bytes");
    write_line("Compression Ratio: " + ratio_stream.str() + ":1");
    write_line("Space Saved: " + saving_stream.str() + "%\n");
}


// Function to collapse and preview a few memories, passing by reference
void collapse_entries(const Entry entries[], const unordered_map<string, string> &compressed_entries)
{
    write_line("\nCollapsing sample entries: ");

    for (int i = 0; i < 3; i++)
    {
        /** Select a random entry */
        int idx = rnd(MAX_ENTRIES);
        Entry e = entries[idx];
        /** Decompress the content */
        string decompressed = decompress_content(compressed_entries.at(e.id), e.content.size());
        /** Print entry details and a preview of the content */
        write_line("ID: " + e.id + ", Genre: " + (e.genre == PERSONAL ? "Personal" : "Business"));
        write_line("Content Preview: " + decompressed.substr(0, 40) + "...\n");
    }
}


// Function to find memories by genre, passing by reference
void find_by_genre(const Entry entries[], Genre search_genre)
{
    /** Count the number of entries in the specified genre */
    int count = 0;
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        /** Check if the entry matches the search genre */
        if (entries[i].genre == search_genre)
            count++;
    }

    /** Print the count of entries found */
    write_line("Found " + to_string(count) + " entries in the " + (search_genre == PERSONAL ? "Personal" : "Business") + " genre.");
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
    collapse_entries(entries, compressed_entries);
    find_by_genre(entries, PERSONAL);
    find_by_genre(entries, BUSINESS);

    write_line("\nDemonstration Complete.");
    return 0;
}