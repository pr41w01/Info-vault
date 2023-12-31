#include <stdio.h>
#include <time.h>

int main() {
    // Get the current time in seconds since the Unix epoch
    time_t currentTime;
    time(&currentTime);

    // Convert the time to a string and print it
    char* timeString = ctime(&currentTime);
    printf("Current time: %s", timeString);

    // Convert the time to a more structured format
    struct tm* localTime = localtime(&currentTime);
    
    // Print individual components of the time
  
    return 0;
}

