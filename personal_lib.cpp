#include <iostream>
#include <map>
#include <fstream>
#include <list>
#include <sstream>

struct book {
    std::string title;
    std::string author;
    int pages;
    bool read = false;
    int rating = 1;

};




book newBook(std::string t, std::string a, int p){

    //std::cout << "test" <<std::endl;
    book entry;
    entry.author = a;
    entry.title = t;
    entry.pages = p;
    entry.rating = 7;
    entry.read = true;
    return entry;
}


std::map<std::string, book> initDataBase(std::string file_name){
    std::map<std::string, book> db;
    std::string temp_auth;
    std::string temp_title;
    int temp_pages;


    std::fstream file;
    file.open(file_name, std::ios::in);
    if (file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            // std::cout << line << "\n";
            
           std::istringstream ss(line);
           std::string token;

            int dir = 0;
            while (std::getline(ss, token, ',')) {
                switch (dir)
                {
                case 0:
                    // std::cout << token << "\n";
                    temp_title = token;
                    break;
                case 1:
                    // std::cout << token << "\n";
                    temp_auth = token;
                    break;
                case 2:
                    // std::cout << token << "\n";
                    temp_pages = std::stoi(token);
                    break;
                }
                db.insert( std::make_pair( temp_title, newBook(temp_title,temp_auth,temp_pages) ) );
            }
        }
    }
    file.close();

    return db;
}

/*
    Prints lots of books from a database
*/
void printBooks(std::map<std::string, book> database){

    for (auto i = database.begin(); i != database.end(); i++){
        // std::cout << i->first << " \t\t\t" << i->second.title << std::endl;
        
        std::cout << i->second.title << " by " << i->second.author << std::endl << i->second.pages << " pages"<< std::endl << i->second.rating << "/7 rating" << std::endl;
        if (i->second.read){
            std::cout << "status: READ" << std::endl << std::endl;
        }else{
            std::cout << "status: UNREAD" << std::endl << std::endl;

        }
    }

    return;
}








int main(){


    std::map<std::string, book> db = initDataBase("data.txt");

    printBooks(db);

    

    return 0;
}
