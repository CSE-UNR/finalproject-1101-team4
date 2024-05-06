//Colby Jones and Brooke Trujillo
//5-1-2024
//This is the final project for CS 135.
//This program is essentailly an image loader/ editor/ saver. 

#include<stdio.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_FILE_LENGTH 20
void loadImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int* imgLength, int* imgWidth);
void displayImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int imgSize, int imgLength, int imgWidth);
void saveToFile(char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth);

int main(){
	
	//stores each pixel as a value in a 2d array
	char imageInfo[MAX_HEIGHT][MAX_WIDTH];
	
	//keeps track of the user's menu choice
	int menuChoice;
	
	//resolution of the image
	int imgRes;
	
	//int variables for saving the size of the user image.
	int imgLength=0;
	int imgWidth=0;
	
	//name of file being edited
	char fileName[MAX_FILE_LENGTH];
	
	printf("Welcome to the Image Processor!\n");
	
	do{
		printf("Please select an option. Press 0 to Exit, and 1-4 for the other options\n");
	
		printf("1. Load an image\n2. Display current image\n3. Edit an image\n4. Save an image\n0. Exit\n");
		
		scanf("%d", &menuChoice);
		
	switch(menuChoice){
		case 0:
			printf("Okay. See you later!\n");
			break;
		case 1:
			printf("Okay, what file do you want to load?\n");
			scanf("%s", fileName);
			
			loadImage(imageInfo, fileName, &imgLength, &imgWidth);
			
			imgRes= imgLength* imgWidth;
			break;
			
		case 2:
			displayImage(imageInfo, fileName, imgRes, imgLength, imgWidth);
			break;
			
		case 4:
			saveToFile(imageInfo, imgLength, imgWidth);
			break;
		default:
			printf("Invalid input. Please try again.");
			break;
		
	}
	}while(menuChoice !=0);
	
	return 0;
}
void loadImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int* imgLength, int* imgWidth){
	
	//file pointer for file IO
	FILE* imgLoad;
	char temp[MAX_WIDTH];
	
	imgLoad= fopen(fileName, "r");
	
	//for loop that assigns each image pixel to an address in the array and the "brightness" value
	for(int i=0; i<= MAX_HEIGHT; i++){
	printf("Row %d \n", i);
		if(fscanf(imgLoad, "%s", &temp[i])==1){
			for(int j=0; temp[j]!= '\0'; j++){
					if(i=0){
						*imgWidth= j;
					}
					
					fscanf(imgLoad, "%c", &imagePixels[i][j]);
					
		
					switch(imagePixels[i][j]){
				
						case'0':
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
						default:
							imagePixels[i][j]= 'X';
							break;
					}
			printf("%c", imagePixels[i][j]);
			}
			*imgLength= i+1;
	}
	}
	fclose(imgLoad);	
}

void displayImage(char imagePixels[][MAX_WIDTH], char fileName[MAX_FILE_LENGTH], int imgSize, int imgLength, int imgWidth){

	printf("Image Name: %s\n", fileName);
	printf("This image is %d by %d pixels\n", imgLength, imgWidth);	
	printf("The total amount of pixels in this image is %d\n", imgSize);
	
	for(int i=0; i<imgLength; i++){
		for(int j=1; j<imgWidth; j++){
			printf("%c", imagePixels[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void saveToFile(char imagePixels[][MAX_WIDTH], int imgLength, int imgWidth){

}
