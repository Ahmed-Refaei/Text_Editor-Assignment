#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "TextManip.h"

using namespace std;

void line_counter()
{
    int lines = 0;
    string line, text = "";
    file.open(name, ios::in); // read
    if (file.is_open())
    {
        while (getline(file, line))
        {
            lines++;
        }
    }
    cout << "The File Has " << lines << " Lines.\n";
    file.close();
}
void char_counter()
{
    int chars = 0;
    string line, text = "";
    file.open(name, ios::in); // read
    if (file.is_open())
    {
        while (getline(file, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] < 91 && line[i] > 64)
                {
                    chars++;
                }
                else if (line[i] > 96 && line[i] < 123)
                {
                    chars++;
                }
            }
        }
    }
    cout << "The File Has " << chars << " Letters.\n";
    file.close();
}
void word_counter()
{
    int words = 0;
    string line, text = "";
    file.open(name, ios::in); // read
    if (file.is_open())
    {
        while (getline(file, line))
        {
            for (int i = 1; i < line.length(); i++)
            {
                if ((line[i] > 20 && line[i] < 47) && line[i - 1] > 96 && line[i] < 123)
                {
                    words++;
                }
                else if ((line[i] > 20 && line[i] < 47) && line[i - 1] < 91 && line[i - 1] > 64)
                {
                    words++;
                }
                else if (line[i] > 96 && line[i] < 123 && i == line.length() - 1)
                {
                    words++;
                }
                else if (line[i] < 91 && line[i] > 64 && i == line.length() - 1)
                {
                    words++;
                }
            }
        }
    }
    cout << "The File Has " << words << " Words.\n";
    file.close();
}
int same_word(string word1, string word2)
{
    int match = 0;
    if (word1.length() == word2.length())
    {
        for (int i = 0; i < word1.length(); i++)
        {
            if (word1[i] == word2[i] || word1[i] == word2[i] + 32 || word1[i] == word2[i] - 32)
            {
                match++;
            }
        }
        if (match == word1.length())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void search_word()
{
    int words = 0;
    string s_word;
    int match;
    cout << "enter the word you want to search for:";
    cin >> s_word;
    string line, text = "";
    file.open(name, ios::in); // read
    if (file.is_open())
    {
        while (getline(file, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                if ((line[i] > 20 && line[i] < 47) && line[i - 1] > 96 && line[i] < 123)
                {
                    words++;
                    match = same_word(s_word, text);
                    text = "";
                }
                else if ((line[i] > 20 && line[i] < 47) && line[i - 1] < 91 && line[i - 1] > 64)
                {
                    words++;
                }
                else if (line[i] > 96 && line[i] < 123 && i == line.length() - 1)
                {
                    words++;
                    text += line[i];
                    match = same_word(s_word, text);
                    text = "";
                }
                else if (line[i] < 91 && line[i] > 64 && i == line.length() - 1)
                {
                    words++;
                    text += line[i];
                    match = same_word(s_word, text);
                    text = "";
                }
                else
                {
                    text += line[i];
                }
            }
        }
        if (match > 0)
        {
            cout << "Word Was Found In The File " << endl;
        }
        else
        {
            cout << "Word Was Not Found In The File" << endl;
        }
    }
    file.close();
}

void merge_files()
{
    fstream file_1, file_2, file_new;
    string file1, file2, new_file, line;
    cout << "enter file name with extension" << endl;
    cout << "enter first file name: ";
    cin >> file1;
    cout << "enter second file name: ";
    cin >> file2;
    cout << "enter the merged file name: ";
    cin >> new_file;
    file_1.open(file1, ios::in); // read
    file_2.open(file2, ios::in);
    file_new.open(new_file, ios::out);
    // merged_file.open(new_file)
    if (file_1.is_open())
    {
        while (getline(file_1, line))
        {
            file_new << line << endl;
        }
    }
    file_new.close();
    file_new.open(new_file, ios::app);
    if (file_2.is_open())
    {
        while (getline(file_2, line))
        {
            file_new << line << endl;
        }
    }
    cout << "The Two Files Merged Successfully." << endl;
    file_1.close();
    file_2.close();
    file_new.close();
}

void convert_to_upper(vector<char> &text)
{
    char c;
    file.open(name, ios::in);
    text.erase(text.end() - 1); // Removes The Last Element in The Vector
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = toupper(text[i]);
    }
    file.close();
    cout << "Done! \n";
}

void convert_to_lower(vector<char> &text)
{
    char c;
    file.open(name, ios::in);
    text.erase(text.end() - 1); // Removes The Last Element In The Vector.
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = tolower(text[i]);
    }
    file.close();
    cout << '\n'
         << "Done! \n";
}

void capitalize_first(vector<char> &text)
{
    char letter;
    file.open(name, ios::in);
    text.erase(text.end() - 1);
    text[0] = toupper(text[0]);
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            text[i + 1] = toupper(text[i + 1]);
        }
    }
    cout << "\nDone!" << endl;
    file.close();
}

string tolower(string word)
{
    string new_word;
    for (int i = 0; i < word.length(); i++)
    {
        if (isalpha(word[i]))
        {
            new_word += tolower(word[i]);
        }
    }
    return new_word;
}

void count_existence()
{
    fstream file;
    string word, compared_word;
    int counter = 0;
    file.open(name, ios::in);
    cout << "Please Enter The Word: ";
    cin >> word;
    while (!file.eof())
    {
        file >> compared_word;
        if (tolower(word) == tolower(compared_word))
        {
            counter++;
        }
    }
    cout << "The Word Appeared " << counter << " Times.\n";
    file.close();
}
// function to encrypt words
void encryptor(vector<char> &text)
{
    char a;
    file.open(name, ios::in);
    text.erase(text.end() - 1);
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = text[i] + 1;
    }
    cout << "Done! \n";
    file.close();
}
// function to decrypt words
void decryptor(vector<char> &text)
{
    char a;
    file.open(name, ios::in);
    text.erase(text.end() - 1);
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = text[i] - 1;
    }
    cout << "\nDone! \n";
    file.close();
}
// function to display data
void display_data()
{
    file.open(name, ios::in);
    string word;
    getline(file, word);
    while (file)
    {
        // to organize the display in lines
        cout << '\n'
             << word;
        getline(file, word);
    }
    file.close();
    cout << '\n'
         << "Done! \n";
}
// function to add new text
void Add_text(vector<char> &text)
{
    char c;
    file.open(name, ios::app);
    file.put('\n'); // to write on a new line
    while (1)
    {
        cin.get(c);
        if ((c) == 26)
            break;
        file.put(c);
    }
    file.close();
    // Add The New Text to The Vector
    text.clear();      // Clear The Old Vector
    file.open(name, ios::in);
    while (!file.eof())
    {
        file.get(c);
        text.push_back(c);
    }
    cout << "\nDone! \n";
    file.close();
}
// function to empty file
void empty_file()
{
    file.open(name, std::ofstream::out | std::ofstream::trunc); // truncate
    file.close();
    cout << "Done \n";
}

void save(vector<char> text)
{
    ofstream output_file;
    char new_name[100];
    cout << "Enter The New File Name: ";
    cin >> new_name;
    output_file.open(new_name, ios::out);
    for (int i = 0; i < text.size(); i++)
    {
        output_file.put(text[i]);
    }
    output_file.close();
    cout << "File Saved Successfully.\n";
}
