//Brooke Trujillo & Colby Jones
//5-5-2024

#include <stdio.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_FILE_LENGTH 20

//prototypes
void loadImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int* imgLength, int* imgWidth);
void displayImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int imgSize, int imgLength, int imgWidth);
void editingMenu(int editChoice, char fileName[MAX_FILE_LENGTH], char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth);
void cropImage();
void brightImage(char fileName[MAX_FILE_LENGTH], char imagePixels[][MAX_WIDTH],int imgLength, int imgWidth);
void dimImage(char fileName[MAX_FILE_LENGTH], char imagePixels[][MAX_WIDTH],int imgLength, int imgWidth);
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
				printf("Okay, what file do you want to load? ");
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
				editingMenu(editChoice, fileName, imageInfo, imgLength, imgWidth);
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
		for(int j=0; j< MAX_WIDTH; j++){
			if(fscanf(imgLoad, "%c", &temp)==1 && temp != '\n'){

				imagePixels[i][j]= temp;
					
				switch(imagePixels[i][j]){	
					case '0':
						imagePixels[i][j]= ' ';
						break;
					case '1':
						imagePixels[i][j]= '.';
						break;
					case '2':
						imagePixels[i][j]= 'o';
						break;
					case '3':
						imagePixels[i][j]= 'O';
						break;
					case '4':
						imagePixels[i][j]= '0';
						break;
				}
				*imgWidth= j+1;
			
				*imgLength= i+1;
			}
			else{
			imagePixels[i][j]= '\n';
			break;
			}
		}
	}
	fclose(imgLoad);	
}

void displayImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int imgSize, int imgLength, int imgWidth){

	printf("Image Name: %s\n", fileName);
	printf("This image is %d by %d pixels\n", imgLength, imgWidth);	
	printf("The total amount of pixels in this image is %d\n\n", imgSize);
	
	for(int i=0; i<imgLength; i++){
		for(int j=0; j< imgWidth; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void editingMenu(int editChoice, char fileName[MAX_FILE_LENGTH], char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth){
char input;
	do{
		//editing Menu
		printf("\n\n**EDITING**\n");
		printf("1: Crop image\n");
		printf("2: Brighten image\n");
		printf("3: Dim image\n");
		printf("0: Return to main menu\n\n");
		printf("Choose from one of the options above: ");
		scanf(" %d", &editChoice);
		
		switch(editChoice){
			//crop Image 
			case 1:
				cropImage(imagePixels, &imgLength, &imgWidth);
				
				printf("Would you like to save the file? (y/n) ");
				scanf(" %c", &input);
				if (input != 'n'){
					saveToFile(imagePixels, imgLength, imgWidth);
				}
			break;
			//bright Image
			case 2:
				brightImage(fileName, imagePixels, imgLength, imgWidth);
				
				printf("Would you like to save the file? (y/n) ");
				scanf(" %c", &input);
				if (input != 'n'){
					saveToFile(imagePixels, imgLength, imgWidth);
				}
			break;
			//dimImage
			case 3:
				dimImage(fileName, imagePixels, imgLength, imgWidth);
				
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
void cropImage(int imagePixels[][MAX_WIDTH],int*imageHeight, int*imageWidth){
int top, bottom, left, right;

//these variables are used to find the new size of the image by comparing the distance between top/bottom, and left/ right
int newWidth, newHeight;

printf("Time to crop! Please choose the size you want for the crop of your new image\n");
printf("Top:\n");
scanf("%d", &top);

printf("Bottom:\n");
scanf("%d", &bottom);

newHeight= bottom - top;

printf("Left:\n");
scanf("%d", &left);

printf("Right:\n");
scanf("%d", &right);

newWidth= right-left;

//sets the image width/height temporarily to the new ones
*imageHeight= newHeight;
*imageWidth= newWidth;

	//for cropping the image
	for(int i=0; i< newHeight; i++){
		for(int j=0; j<=newWidth; j++){
			if(j=newWidth){
				imagePixels[i][j+1]= '\n';
			}
			else {
			imagePixels[i][j]= imagePixels[top+i][left+j];
			}
		}
	}
}
void brightImage(char fileName[MAX_FILE_LENGTH], char imagePixels[][MAX_WIDTH],int imgLength, int imgWidth){
	char pixel;
	
	printf("\nOriginal Image:\n");
	
	for(int i=0; i<imgLength; i++){
		for(int j=0; j< imgWidth; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(int i=0; i<imgLength; i++){
		for(int j=0; j< imgWidth; j++){
			pixel = imagePixels[i][j];
				switch(pixel){
					case ' ':
						imagePixels[i][j] = '.';
					break; 
					case '.':
						imagePixels[i][j] = 'o';
					break;
					case 'o':
						imagePixels[i][j] = 'O';
					break;
					case 'O':
						imagePixels[i][j] = '0';
					break;
					case '0':
					break;
				}
		}
	}
	printf("\n");
	printf("\nEdited Image:\n");
	for(int i=0; i<imgLength; i++){
		for(int j=0; j< imgWidth; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void dimImage(char fileName[MAX_FILE_LENGTH], char imagePixels[][MAX_WIDTH],int imgLength, int imgWidth){
char pixel;
	
	printf("\nOrignal Image:\n");
	
	for(int i=0; i<imgLength; i++){
		for(int j=0; j< imgWidth; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(int i=0; i<imgLength; i++){
		for(int j=0; j< imgWidth; j++){
			pixel = imagePixels[i][j];
				switch(pixel){
					case '0':
						imagePixels[i][j] = 'O';
					break; 
					case 'O':
						imagePixels[i][j] = 'o';
					break;
					case 'o':
						imagePixels[i][j] = '.';
					break;
					case '.':
						imagePixels[i][j] = ' ';
					break;
					case ' ':
					break;
				}
		}
	}
	printf("\n");
	printf("\nNew Image:\n");
	for(int i=0; i<imgLength; i++){
		for(int j=0; j< imgWidth; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void saveToFile(char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth){
	FILE* imgSave;
	
	//name of the file the user wants to save to
	char saveFile[MAX_FILE_LENGTH];
	
	printf("Which file would you like to save to?\n");
	scanf("%s", saveFile);
	
	imgSave= fopen(saveFile, "w");
	
	//for loop that converts the brightness pixels (space, ., o, etc.) to numbers, and writes them into a file
	for(int i=0; i<imgLength; i++){
		for(int j=0; j<=imgWidth; j++){
			switch(imagePixels[i][j]){
				case ' ':
					imagePixels[i][j]= '0';
					break;
				case '.':
					imagePixels[i][j]= '1';
					break;
				case 'o':
					imagePixels[i][j]= '2';
					break;
				case 'O':
					imagePixels[i][j]= '3';
					break;
				case '0':
					imagePixels[i][j]= '4';
					break;
				case '\n':imagePixels[i][j]== '\n';
					fprintf(imgSave, "%c", imagePixels[i][j]);
					break;
			}	
			fprintf(imgSave, "%c", imagePixels[i][j]);
		}
	}
	fclose(imgSave);
}

