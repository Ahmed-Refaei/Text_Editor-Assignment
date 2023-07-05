#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "TextManip.h"
#include "TextManip.cpp"

using namespace std;

int main()
{
    int choice;
    cout << "Hello Dear User! \n";
    cout << "This Is A List Of Choices For What You Can Do: \n"
         << "01- Add New Text To The End of The File. \n"
         << "02- Display The Content Of The File. \n"
         << "03- Empty The File. \n"
         << "04- Encrypt The File Content. \n"
         << "05- Decrypt The File Content. \n"
         << "06- Merge Another File. \n"
         << "07- Count The Number Of Words In The File. \n"
         << "08- Count The Number Of Characters In The File. \n"
         << "09- Count The Number Of Lines In The File. \n"
         << "10- Search For a Word In The File. \n"
         << "11- Count a Number Of Times A Word Exists In The File. \n"
         << "12- Turn The File Content To Uppercase. \n"
         << "13- Turn The File Content To Lowercase. \n"
         << "14- Capitalize First Letter In Each Word. \n"
         << "15- Save. \n"
         << "00- Exit "
         << endl;

    while (true)
    {
        char c, choice2;
        cout << "Enter The File Name: ";
        cin >> name;
        file.open(name, ios::in);
        if (!file.fail())
        {
            while (!file.eof())
            {
                file.get(c);
                text.push_back(c);
            }
            file.close();
            cout << "File Opened Successfuly.\n";

        }
        else
        {
            cout << "File Does Not Exist!, A New File Was Created.\n";
            file.open(name, ios::out);
            file.close();   
        }
        while (true)
        {
            do
            {
                cout << "What Do You Need: ";
                cin >> choice;
                cin.clear();
                cin.sync();
            } while (choice < 0 || choice > 15);
            if (choice == 1)
            {
                Add_text(text);
            }
            else if (choice == 2)
            {
                display_data();
            }
            else if (choice == 3)
            {
                empty_file();
            }
            else if (choice == 4)
            {

                encryptor(text);
            }
            else if (choice == 5)
            {
                decryptor(text);
            }
            else if (choice == 6)
            {
                merge_files();
            }
            else if (choice == 7)
            {
                word_counter();
            }
            else if (choice == 8)
            {
                char_counter();
            }
            else if (choice == 9)
            {
                line_counter();
            }
            else if (choice == 10)
            {
                search_word();
            }
            else if (choice == 11)
            {
                count_existence();
            }
            else if (choice == 12)
            {
                convert_to_upper(text);
            }
            else if (choice == 13)
            {
                convert_to_lower(text);
            }
            else if (choice == 14)
            {
                capitalize_first(text);
            }
            else if (choice == 15)
            {
                save(text);
            }
            else if (choice == 0)
            {
                break;
            }
        }
        do
        {
            cout << "Press L To Load Another File, or Press Q to Quit.\n";
            cin >> choice2;
            choice2 = tolower(choice2);
        } while (choice2 != 'l' && choice2 != 'q');
        if (choice2 == 'q')
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

