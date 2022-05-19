#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int IGNORE_CHARS = 256;
const char * INPUT_ERROR_STRING = "Input error! Please try again. ";

void playGame();
bool wantToPlayAgain();

int getSecretPhrase(char secretPhrase[], int maxLength);
char * makeHiddenPhrase(const char* secretPhrase, int secretPhraseLength);
void drawBoard(int numberOfGuessesLeft, const  char * optrHiddenPhrase);

char getCharacter(const char * prompt , const char * error);
char getCharacter(const char * prompt , const char * error , const char validInputs[] , int validInputLength);

int main(){

	do{

		playGame();

	}while(wantToPlayAgain());

	return 0;
}




void playGame(){
const int MAX_LENGTH_OF_SECRET_PHRASE = 256;
const int MAX_NUMBER_OF_GUESSES = 6;

char secretPhrase[MAX_LENGTH_OF_SECRET_PHRASE];
char * optrHiddenPhrase = nullptr;
int numberOfGuessesLeft = MAX_NUMBER_OF_GUESSES;

int secretPhraseLength = getSecretPhrase(secretPhrase,MAX_LENGTH_OF_SECRET_PHRASE);

optrHiddenPhrase =  makeHiddenPhrase(secretPhrase , secretPhraseLength);

drawBoard(numberOfGuessesLeft,optrHiddenPhrase);

}



bool  wantToPlayAgain(){

	const char validInputs[] = { 'y','n'};
	char response = getCharacter("Would you like to play again? (y/n)", INPUT_ERROR_STRING, validInputs, 2);

	return response == 'y';
}

int  getSecretPhrase(char secretPhrase[], int maxLength){
	
	bool failure;
	int length;
	do{
		failure = false;

		cout<<"Please enter the secret phrase: ";
		cin.get(secretPhrase,maxLength);

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS,'\n');
			cout<<INPUT_ERROR_STRING<<endl;

			failure = true;
		}
		else
		{	
			length = strlen(secretPhrase);

			if(length == 0){
				cout<<"You must enter a word that's longer than 0 characters. Please try again."<<endl
					;
			}
		}
	}while(failure);

	return length;
}

char * makeHiddenPhrase(const char* secretPhrase , int secretPhraseLength){

	char * hiddenPhrase = new char[secretPhraseLength + 1 ];

	for(int i = 0; i < secretPhraseLength; i++){

		if(secretPhrase[i] != ' '){

			hiddenPhrase[i] = '-';
		}
		else {
			hiddenPhrase[i] = ' ';
		}
	}

	hiddenPhrase[secretPhraseLength] = '\0';

	return hiddenPhrase;
		
}

void drawBoard(int numberOfGuessesLeft, const char * optrHiddenPhrase){

switch(numberOfGuessesLeft){

	case 0 : {
			 cout<<" +---+"<<endl;
			 cout<<" |   |"<<endl;
			 cout<<" |   0"<<endl;
			 cout<<" |  /|\\"<<endl;
			 cout<<" |  / \\"<<endl;
			 cout<<"-+-"<<endl<<endl;
		 }
		 break;
	case 1 : {
			 cout<<" +---+"<<endl;
			 cout<<" |   |"<<endl;
			 cout<<" |   0"<<endl;
			 cout<<" |  /|\\"<<endl;
			 cout<<" |  /"<<endl;
			 cout<<"-+-"<<endl<<endl;
		 }break;
	case 2 : {
	
		 	 cout<<" +---+"<<endl;
			 cout<<" |   |"<<endl;
			 cout<<" |   0"<<endl;
			 cout<<" |  /|\\"<<endl;
			 cout<<" |"<<endl;
			 cout<<"-+-"<<endl<<endl;
	
	 }break;
	 case 3 : {
	
		 	 cout<<" +---+"<<endl;
			 cout<<" |   |"<<endl;
			 cout<<" |   0"<<endl;
			 cout<<" |  /|"<<endl;
			 cout<<" |"<<endl;
			 cout<<"-+-"<<endl<<endl;
	 }break;
	 case 4 : {
	
		 	 cout<<" +---+"<<endl;
			 cout<<" |   |"<<endl;
			 cout<<" |   0"<<endl;
			 cout<<" |  /"<<endl;
			 cout<<" |"<<endl;
			 cout<<"-+-"<<endl<<endl;

	 }break;
	 
	  case 5 : {
	
		 	 cout<<" +---+"<<endl;
			 cout<<" |   |"<<endl;
			 cout<<" |   0"<<endl;
			 cout<<" |"<<endl;
			 cout<<" |"<<endl;
			 cout<<"-+-"<<endl<<endl;

	 }break;
	 
	  case 6 : {
	
		 	 cout<<" +---+"<<endl;
			 cout<<" |   |"<<endl;
			 cout<<" |"<<endl;
			 cout<<" |"<<endl;
			 cout<<" |"<<endl;
			 cout<<"-+-"<<endl<<endl;

	 }break;
	 
	 default : {
	 break;
	 }
			 

}
cout<<"Secret phrase : "<<optrHiddenPhrase<<endl<<endl;
}


char getCharacter(const char* prompt , const char* error){

	char input;
	bool failure;

	do{
		failure = false;

		cout<<prompt;
		cin>>input;

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS,'\n');
			cout<<error<<endl;
			failure = true;
		}else{
			cin.ignore(IGNORE_CHARS,'\n');

			if(isalpha(input)){
				
				input = tolower(input);
			}else{
				cout<<error<<endl;
				failure = true;
			}
		}
	}while(failure);

	return input;
}
char getCharacter(const char* prompt , const char* error , const char validInputs[] , int validInputLength)
{


	char input;
	bool failure;

	do{
		failure = false;

		cout<<prompt;
		cin>>input;

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS,'\n');
			cout<<error<<endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS,'\n');

			if(isalpha(input)){

				input = tolower(input);

				for(int i = 0; i < validInputLength; i++){

					if(input == validInputs[i]){
						return input;
					}
				}
			}
			cout<<error<<endl;
			failure = true;
		}
	}while(failure);

	return input;
}

