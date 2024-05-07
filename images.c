//Brooke Trujillo & Colby Jones
//5-5-2024

#include <stdio.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_FILE_LENGTH 20

//prototypes
void loadImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int* imgLength, int* imgWidth);
void displayImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int imgSize, int imgLength, int imgWidth);
void editingMenu(int editChoice, char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth);
void cropImage();
void brightImage();
void dimImage();
void saveToFile(char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth);

//main function
int main(){
	//stores each pixel as a value in a 2d array
	char imageInfo[MAX_HEIGHT][MAX_WIDTH];
	
	//resolution of the image
	int imgRes;
	
	//int variables for saving the size of the user image.
	int imgLength=0, imgWidth=0;
	
	//name of file being edited
	char fileName[MAX_FILE_LENGTH];
	
	int menuChoice, editChoice;
	char input;
	FILE *fp;	
	
	printf("Welcome to the Image Processor!\n");
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
				printf("Okay, what file do you want to load?\n");
				scanf("%s", fileName);
				
				loadImage(imageInfo, fileName, &imgLength, &imgWidth);
				
				imgRes= imgLength* imgWidth;
			break;
			//displays image
			case 2:
				displayImage(imageInfo, fileName, imgRes, imgLength, imgWidth);
			break;
			//brings up edit menu
			case 3:
				editingMenu(editChoice, imageInfo, imgLength, imgWidth);
			break;
			//closes the program
			case 0:
				printf("\nGoodbye!\n\n");
			break;
			default:
			printf("Invalid input. Please try again.");
			break;
		}
	}while (menuChoice != 0);
return 0; 
}

//definitions
void loadImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int* imgLength, int* imgWidth){
	
	//file pointer for file IO
	FILE* imgLoad;
	char temp;
	
	imgLoad= fopen(fileName, "r");
	
	//for loop that assigns each image pixel to an address in the array and the "brightness" value
	for(int i=0; i< MAX_HEIGHT; i++){
	printf("Row %d: ", i+1);
		for(int j=0; j< MAX_WIDTH; j++){
			
			if(fscanf(imgLoad, "%c", &temp)==1 && temp!= '\n'){
					
					imagePixels[i][j]= temp;
					
					switch(imagePixels[i][j]){
					
						case '0':
							imagePixels[i][j]= '0';
							break;
					
						case '1':
							imagePixels[i][j]= '1';
							break;
						case '2':
							imagePixels[i][j]= '2';
							break;
						case '3':
							imagePixels[i][j]= '3';
							break;
						case '4':
							imagePixels[i][j]= '4';
							break;
							
							
					}
					
				*imgWidth= j+1;
				*imgLength= i+1;
			}
			printf("%c", imagePixels[i][j]);
			else{
				imagePixels[i][j]= '\n';
			}
		}
		
	}
	fclose(imgLoad);	
}

void displayImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int imgSize, int imgLength, int imgWidth){

	printf("Image Name: %s\n", fileName);
	printf("This image is %d by %d pixels\n", imgLength, imgWidth);	
	printf("The total amount of pixels in this image is %d\n", imgSize);
	
	for(int i=0; i<imgLength; i++){
		for(int j=0; imagePixels[i][j]!= '\n'; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void editingMenu(int editChoice, char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth){
char input;
do{
		//editing Menu
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
				
				printf("Would you like to save the file? (y/n) ");
				scanf(" %c", &input);
				if (input != 'n'){
					saveToFile(imagePixels, imgLength, imgWidth);
				}
			break;
			//bright Image
			case 2:
				brightImage();
				
				printf("Would you like to save the file? (y/n) ");
				scanf(" %c", &input);
				if (input != 'n'){
					saveToFile(imagePixels, imgLength, imgWidth);
				}
			break;
			//dimImage
			case 3:
				dimImage();
				
				printf("Would you like to save the file? (y/n) ");
				scanf(" %c", &input);
				if (input != 'n'){
					saveToFile(imagePixels, imgLength, imgWidth);
				}
			break;
			//back to main menue
			case 0:
			break;
			default:
			printf("Invalid input. Please try again.");
			break;
		}
	}while (editChoice != 0);
}
void cropImage(int imagePixels[][MAX_WIDTH]){
int tl;
int tr;
int bl;
int br;

//for cropping the image
for(int i=tl; i<bl; i++){
		for(int j=tl; j<tr; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void brightImage(){
}
void dimImage(){
}
void saveToFile(char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth){

}

