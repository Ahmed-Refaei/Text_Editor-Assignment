#ifndef TextManip_H
#define TextManip_H

using namespace std;

void line_counter();
void char_counter();
void word_counter();
int same_word(string word1, string word2);
void search_word();
void merge_files();
void convert_to_upper(vector<char> &text);
void convert_to_lower(vector<char> &text);
void capitalize_first(vector<char> &text);
void count_existence();
void encryptor(vector<char> &text);
void decryptor(vector<char> &text);
void display_data();
void Add_text(vector<char> &text);
void empty_file();
void save(vector<char> text);
string tolower(string word);
vector<char> text;
char name[100];
fstream file;


#endif