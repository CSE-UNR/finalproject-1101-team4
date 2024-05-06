//Brooke Trujillo & Colby Jones
//5-5-2024

#include <stdio.h>


//prototypes
void loadImage();
void displayImage();
void edditingMenu();
void cropImage();
void brightImage();
void dimImage();
void saveToFile();

//main function
int main(){
	
	int menuChoice, editChoice;
	
	FILE *fp;	
	do{
		//Main Menu
		printf("\n**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n\n");
		printf("Choose from one of the options above: ");
		scanf(" %d", &menuChoice);
		
		switch(menuChoice){
			//loads image 
			case 1:
			loadImage();
			break;
			//displays image
			case 2:
			displayImage();
			break;
			//brings up edit menu
			case 3:
			edditingMenu();
			break;
			//closes the program
			case 0:
				printf("\nGoodbye!\n\n");
			break;
		}
	}while (menuChoice != 0);
return 0; 
}

//definitions
void loadImage(){
}
void displayImage(){
}
void edditingMenu(int editChoice){
do{
		//edditing Menu
		printf("\n\n**EDITING**\n");
		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("0: Return to main menu\n\n");
		printf("Choose from one of the options above: ");
		scanf(" %d", &editChoice);
		

		switch(editChoice){
			//crop Image 
			case 1:
				cropImage();
			break;
			//bright Image
			case 2:
				brightImage();
			break;
			//dimImage
			case 3:
				dimImage();
			break;
			//back to main menue
			case 0:
			break;
		}
	}while (editChoice != 0);
}
void cropImage(){
}
void brightImage(){
}
void dimImage(){
}
void saveToFile(){
}

