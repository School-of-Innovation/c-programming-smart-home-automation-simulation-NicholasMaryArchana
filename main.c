/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */
#include <stdio.h>

#define MAX_ROOMS 5  // max number of rooms

// Function prototypes
void initializeSystem(int numRooms, int light[], int temp[], int motion[], int lock[]);
void displayMenu();
void controlLights(int numRooms, int light[]);
void readTemperature(int numRooms, int temp[]);
void detectMotion(int numRooms, int motion[]);
void securitySystem(int numRooms, int lock[]);
void analyzeHouseStatus(int numRooms, int light[], int temp[], int motion[], int lock[]);

int main() {
    int numRooms;
    int light[MAX_ROOMS];
    int temp[MAX_ROOMS];
    int motion[MAX_ROOMS];
    int lock[MAX_ROOMS];

    printf("Enter number of rooms: ");
    scanf("%d", &numRooms);
    
    if (numRooms > MAX_ROOMS) {
        printf("The maximum number of rooms is %d.\n", MAX_ROOMS);
        return 1;
    }

    // Initialize the system
    initializeSystem(numRooms, light, temp, motion, lock);

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights(numRooms, light);
                break;
            case 2:
                readTemperature(numRooms, temp);
                break;
            case 3:
                detectMotion(numRooms, motion);
                break;
            case 4:
                securitySystem(numRooms, lock);
                break;
            case 5:
                analyzeHouseStatus(numRooms, light, temp, motion, lock);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Initialize system: set default states for lights, temperature, motion, and locks
void initializeSystem(int numRooms, int light[], int temp[], int motion[], int lock[]) {
    for (int i = 0; i < numRooms; i++) {
        light[i] = 0;    // Light OFF
        temp[i] = 22;    // Default temperature (in °C)
        motion[i] = 0;   // No motion detected
        lock[i] = 1;     // Door is locked
    }
    printf("System Initialized. Lights OFF, Doors Locked, No Motion Detected.\n");
}

// Display the menu of options
void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

// Control the lights (toggle ON/OFF for a specific room)
void controlLights(int numRooms, int light[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", numRooms);
    scanf("%d", &room);
    if (room >= 1 && room <= numRooms) {
        if (light[room - 1] == 0) {
            light[room - 1] = 1;  // Light ON
            printf("Light in Room %d is now ON.\n", room);
        } else {
            light[room - 1] = 0;  // Light OFF
            printf("Light in Room %d is now OFF.\n", room);
        }
    } else {
        printf("Invalid room number.\n");
    }
}

// Read and display the temperature of a specific room
void readTemperature(int numRooms, int temp[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", numRooms);
    scanf("%d", &room);
    if (room >= 1 && room <= numRooms) {
        printf("Temperature in Room %d: %d°C\n", room, temp[room - 1]);
    } else {
        printf("Invalid room number.\n");
    }
}

// Detect motion in a specific room
void detectMotion(int numRooms, int motion[]) {
    int room;
    printf("Enter room number to check motion (1-%d): ", numRooms);
    scanf("%d", &room);
    if (room >= 1 && room <= numRooms) {
        if (motion[room - 1] == 1) {
            printf("Motion detected in Room %d.\n", room);
        } else {
            printf("No motion detected in Room %d.\n", room);
        }
    } else {
        printf("Invalid room number.\n");
    }
}

// Lock/Unlock security system in a specific room
void securitySystem(int numRooms, int lock[]) {
    int room;
    printf("Enter room number to lock/unlock security (1-%d): ", numRooms);
    scanf("%d", &room);
    if (room >= 1 && room <= numRooms) {
        if (lock[room - 1] == 1) {
            lock[room - 1] = 0;  // Unlock
            printf("Security Lock in Room %d is now UNLOCKED.\n", room);
        } else {
            lock[room - 1] = 1;  // Lock
            printf("Security Lock in Room %d is now LOCKED.\n", room);
        }
    } else {
        printf("Invalid room number.\n");
    }
}

// Analyze and display the status of the entire house
void analyzeHouseStatus(int numRooms, int light[], int temp[], int motion[], int lock[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s Motion, %s\n", 
               i + 1, 
               light[i] == 1 ? "ON" : "OFF", 
               temp[i], 
               motion[i] == 1 ? "Detected" : "No", 
               lock[i] == 1 ? "Locked" : "Unlocked");
    }
}

