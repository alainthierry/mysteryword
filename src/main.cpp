////
//// 03/09/2019
//// Created By Alain ILIHO
////
////
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


//Mix picked word for getting the mystery word

string mixWords(string mysteryWord){

    int position(0);
    for (int i = 0; i < mysteryWord.size(); ++i){

        position = rand() % mysteryWord.size();

        mysteryWord +=mysteryWord[position];
        mysteryWord.erase(position, 1);
    }
    return mysteryWord;
    
}

//Pick randomly a word in the dictionary

string pickWord(){

    ifstream file("dico.txt");
    vector<string> listOfWords ;
    string word;
    int pickedWordIndex;

    if(file){
        while(getline(file, word)){

            listOfWords.push_back(word);
        }
    }
    else{
        cout << "ERROR :The file cannot be opened !" << endl;
    }
    // Picking the random word and return it
    pickedWordIndex = rand() % listOfWords.size();
    return (listOfWords[pickedWordIndex]);
}


// Playing once 

void playing(unsigned int trying){
    
    string randomWord;
    string mysteryWord;
    string seasedWord;
    int nbTimes(1);
    
    randomWord = pickWord();
    mysteryWord = mixWords(randomWord);
    
    do{
        cout << "          " << mysteryWord;
        cout << "\nDevinez le mot mystere ci-dessus : ";
        
        cin >> seasedWord;
        if(seasedWord == randomWord){
            cout << "Bravo !" << endl;
            break;
        }
        else{
            cout << "c'est pas le bon mot ";
            
            if( trying-nbTimes >= 2){
                cout << "et il vous reste "<< trying-nbTimes << " essais " << endl;
            }
            else if(trying-nbTimes == 1 ){
                cout << "et il vous reste "<< trying-nbTimes << " essai" << endl;
            }
            else{
                cout << "et vous avez perdu ! " << endl;
                cout << "======Le mot correct est======: " << randomWord << endl;
                
            }
        }
        nbTimes ++;

    }while(nbTimes <= trying);

}

void playingManyTimes() {

    // number of trying
    unsigned int trying(5);
     // The main loop
    bool launched(true);
    // Anwsers
    char answerO('O');
    char answerN('N');
    // Getting player answer
    char answer;
    
    do{
        
        playing(trying);
        launched = false;
        
        cout << "Cliquez sur (O) pour faire une autre partie et ";
        cout << "(N) pour quitter le jeu." << endl;
        cin >> answer;
        
        switch(answer){

            case 'O':
                launched = true;
                break;

            case'N':
                cout << "Au revoir !" << endl;
                launched = false;
                break;
            default:
                launched = false;
                break;
        }
        
    }while(launched);

}

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(0));

    playingManyTimes();
    
    return (0);
}
