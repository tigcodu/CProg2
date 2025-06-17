#include <stdio.h>

struct Weather {
	int tempCel;
	int humid;
	char loc[80];
	int dayNum;
};

void inputData(struct Weather days[5]) {
	for (int i = 0; i < 5; i++) {
		printf("Enter weather data:\n");
		printf("Temperature (in Celsius): ");
		scanf("%d", &days[i].tempCel); 
		printf("Humidity: ");
		scanf("%d", &days[i].humid);
		getchar();
		printf("Location: ");
		fgets(days[i].loc, sizeof(days[i].loc), stdin);
		days[i].dayNum = i + 1;
		printf("\n");
	}
}

void saveData(struct Weather days[5]) {
	FILE *fp = fopen("D:\\_Files\\Coding\\txts\\weather_data.txt", "w");
	if (fp == NULL) {
        perror("Error opening file.");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%d\t%d\t%s\t%d\n", days[i].tempCel, days[i].humid, days[i].loc, days[i].dayNum);
    }
    fclose(fp);
}

void displayData() {
	struct Weather display[5];
	FILE *fp = fopen("D:\\_Files\\Coding\\txts\\weather_data.txt", "r");
	printf("-----Weather Data-----\n");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%d\t%d\t%[^\t]\t%d\n", &display[i].tempCel, &display[i].humid, display[i].loc, &display[i].dayNum);
		printf("Day %d\n", display[i].dayNum);
		printf("Temperature: %d\n", display[i].tempCel);
		printf("Humidity: %d\n", display[i].humid);
		printf("Location: %s\n", display[i].loc);
	}
	fclose(fp);
}

void avgTempHumid(struct Weather days[5]) {
	float sumTemp = 0, sumHumid = 0;
	for (int i = 0; i < 5; i++) {
		sumTemp += days[i].tempCel;
		sumHumid += days[i].humid;
	}
	float avgTemp = sumTemp / 5;
	float avgHumid = sumHumid / 5;
	printf("Average Temperature: %.2f\n", avgTemp);
	printf("Average Humidity: %.2f\n", avgHumid);
}

void tempHighLow(struct Weather days[5]) {
	int high = 0;
	int low = 0;
	for (int i = 1; i < 5; i++) {
		if (days[i].tempCel > days[high].tempCel) {
			high = i;
		}
		if (days[i].tempCel < days[low].tempCel) {
			low = i;
		}
	}
	printf("\nHighest temperature:\n");
	printf("Day %d\n", days[high].dayNum);
	printf("Temperature: %d\n", days[high].tempCel);
	printf("\nLowest temperature:\n");
	printf("Day %d\n", days[low].dayNum);
	printf("Temperature: %d\n", days[low].tempCel);
}

int main() {
	
	struct Weather days[5];
	
	inputData(days);
	saveData(days);
	displayData();
	avgTempHumid(days);
	tempHighLow(days);
	
	return 0;
}