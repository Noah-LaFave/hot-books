#include <iostream>
#include <map>



struct book {
    std::string title;
    std::string author;
    int pages;
    bool read = false;
    int rating;

};




book newBook(){

    std::cout << "test" <<std::endl;
    book entry;
    entry.author = "me mf";
    entry.title = "the memoir of noah";
    entry.pages = 1137;
    entry.rating = 7;
    entry.read = true;
    return entry;
}


/*
    Prints lots of books from a database
*/
void printBooks(std::map<std::string, book> database){

    for (auto i = database.begin(); i != database.end(); i++){
        // std::cout << i->first << " \t\t\t" << i->second.title << std::endl;
        
        std::cout << i->second.title << " by " << i->second.author << std::endl << i->second.pages << " pages"<< std::endl << i->second.rating << "/7 rating" << std::endl;
        if (i->second.read){
            std::cout << "status: READ" << std::endl;
        }else{
            std::cout << "status: UNREAD" << std::endl;

        }
    }

    return;
}

int main(){


    
    book test = newBook();
    book t1 = newBook();
    t1.title = "the untold story of me";
    std::map<std::string, book> m = {{t1.title, t1}, {test.title, test}};
    printBooks(m);

    

    return 0;
}
