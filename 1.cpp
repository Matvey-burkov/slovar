#include <iostream>
#include <map>
#include <fstream>
 
 
std::map<std::string, std::string> get_saved_words(std::map<std::string, std::string> dict){
    
    std::ifstream file("translate.txt"); 
    while(!file.eof()){ 
        std::string ru_word, en_word; 
        file >> ru_word >> en_word; 
        dict.insert(std::pair<std::string, std::string>(ru_word,en_word)); 
    }
    file.close();
    return dict; 
}
 
 

void save_word(std::string ru_word, std::string en_word){
    std::ofstream file("translate.txt", std::ios_base::app); 
    file << ru_word << " " << en_word << "\n"; 
    file.close(); 
}
 
 

std::map<std::string, std::string> add_new_word(std::map<std::string, std::string> dict){
   
    std::string ru_word, en_word; 
    std::pair<std::map<std::string, std::string>::iterator, bool> resault; 
    
    std::cout << "enter your word \n>>"; std::cin >> ru_word;
    std::cout << "enter en translate \n>>"; std::cin >> en_word; 
    
    resault = dict.insert(std::pair<std::string, std::string>(ru_word,en_word)); 
    if(resault.second == false) std::cout << "This word already exist!" << "\n"; 
    else save_word(ru_word,en_word); 
    return dict; 
}
 
 

void get_word_translate(std::map<std::string, std::string> dict){
   
    std::string ru_word, en_word; 
    bool word_not_finded(true); 
    
    std::cout << "enter your ru word\n>>"; std::cin >> ru_word; 
    
    std::map<std::string, std::string>::iterator it; 
    for(it = dict.begin(); it != dict.end(); it++){
        if(it->first == ru_word){ 
            std::cout << "translate: " << it->second << "\n";
            word_not_finded = !word_not_finded; 
            break; 
        }
    }
        if(word_not_finded) std::cout << "translate for this word not found!\n"; 
                                                                                 
 
 
int main(){ 
    setlocale(LC_ALL, "ru"); 
    
    std::map<std::string, std::string> dict; 
    dict = get_saved_words(dict);  
    std::string user_choice; 
    
    while(true){ 
        std::cout << "[0]exit\n"
                  << "[1]add new word pair\n"
                  << "[2]get word translate\n"
                  << ">>";                              
        std::cin >> user_choice; 
        
        if(user_choice == "0") break; 
        else if(user_choice == "1") dict = add_new_word(dict); 
        else if(user_choice == "2") get_word_translate(dict); 
        else std::cout << "unkown command!\n"; 
    }
    return 0;
}
